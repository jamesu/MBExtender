// PluginLoader.cpp : Defines the exported functions for the DLL application.
//

#include <vector>
#include <string>
#include <boost/filesystem.hpp>
#include "FuncInterceptor.h"
#include "BasicPluginInterface.h"
#include "SharedObject.h"
#include <TorqueLib/TGE.h>

#if defined(__APPLE__)
// The Mac executable changes the working directory to the root of the app folder
#define PATH_PREFIX "./Contents/MacOS/"
#else
#define PATH_PREFIX "./"
#endif

#if defined(_WIN32)
const char *const TorqueLibPath = PATH_PREFIX "TorqueLib.dll";
#elif defined(__APPLE__)
const char *const TorqueLibPath = PATH_PREFIX "TorqueLib.dylib";
#elif defined(__linux)
const char *const TorqueLibPath = PATH_PREFIX "TorqueLib.so";
#endif

typedef void(*initMath_t)();
typedef void(*installOverrides_t)(TorqueFunctionInterceptor *interceptor);
typedef void(*initPlugin_t)(PluginInterface *plugin);

namespace
{
	CodeInjection::CodeAllocator* codeAlloc;
	CodeInjection::FuncInterceptor* hook;
	BasicTorqueFunctionInterceptor* basicInterceptor;

	SharedObject* mathLib;
	
	struct LoadedPlugin
	{
		boost::filesystem::path path;
		SharedObject *library;
		BasicPluginInterface *pluginInterface;
	};
	std::vector<LoadedPlugin>* loadedPlugins;

	void loadPlugins()
	{
		boost::filesystem::path pluginDir(PATH_PREFIX "plugins");
		if (!boost::filesystem::exists(pluginDir) || !boost::filesystem::is_directory(pluginDir))
		{
			TGE::Con::warnf("   No \"plugins\" directory found!");
			return;
		}
		
		std::vector<boost::filesystem::path> paths;
		std::copy(boost::filesystem::directory_iterator(pluginDir), boost::filesystem::directory_iterator(), std::back_inserter(paths));
		for (auto &path : paths)
		{
			if (path.extension() != SharedObject::DefaultExtension)
				continue;
			
			std::string pathStr = path.generic_string();
			TGE::Con::printf("   Loading %s", pathStr.c_str());
			SharedObject *library = new SharedObject(pathStr.c_str());
			if (library->loaded())
			{
				LoadedPlugin info = { path, library, new BasicPluginInterface(basicInterceptor, pathStr) };
				loadedPlugins->push_back(info);
			}
			else
			{
				delete library;
				TGE::Con::errorf("   Unable to load %s!", pathStr.c_str());
			}
		}
	}

	void callPluginInit(const char *message, const char *fnName)
	{
		if (loadedPlugins->size() == 0)
			return;
		TGE::Con::printf("%s", message);
		for (auto &plugin : *loadedPlugins)
		{
			std::string pathStr = plugin.path.generic_string();
			TGE::Con::printf("   Initializing %s", pathStr.c_str());

			// If it exports an initialization function, call it
			auto initFunc = reinterpret_cast<initPlugin_t>(plugin.library->getSymbol(fnName));
			if (initFunc)
				initFunc(plugin.pluginInterface);
			else
				TGE::Con::warnf("   WARNING: %s does not have a %s() function!", pathStr.c_str(), fnName);
		}
		TGE::Con::printf("");
	}

	void pluginPreInit()
	{
		callPluginInit("MBExtender: Initializing Plugins, Stage 1:", "preEngineInit");
	}

	void pluginPostInit()
	{
		callPluginInit("MBExtender: Initializing Plugins, Stage 2:", "postEngineInit");
	}

	void setPluginVariables()
	{
		for (auto &plugin : *loadedPlugins)
		{
			// Set the Plugin::Loaded variable corresponding to the plugin
			std::string varName = plugin.path.stem().generic_string();
			varName = "Plugin::Loaded" + varName;
			TGE::Con::setBoolVariable(varName.c_str(), true);
		}
	}

	void loadMathLibrary()
	{
		TGE::Con::printf("   Initializing memory interface");
		mathLib = new SharedObject(TorqueLibPath);
		if (mathLib->loaded())
		{
			auto initFunc = reinterpret_cast<initMath_t>(mathLib->getSymbol("init"));
			if (initFunc)
			{
				initFunc();
				return;
			}
		}
		TGE::Con::errorf("   Unable to load %s! Some plugins may fail to load!", TorqueLibPath);
	}

	void installUserOverrides()
	{
		if (!mathLib || !mathLib->loaded())
			return;

		TGE::Con::printf("   Installing user overrides");
		auto installFunc = reinterpret_cast<installOverrides_t>(mathLib->getSymbol("installUserOverrides"));
		if (installFunc)
			installFunc(basicInterceptor);
		else
			TGE::Con::errorf("   TorqueLib is out-of-date and does not support user overrides!");
	}

	auto originalNsInit = TGE::Namespace::init;
	void newNsInit()
	{
		originalNsInit();

		TGE::Con::printf("MBExtender Init:");
		loadMathLibrary();
		loadPlugins();
		installUserOverrides();
		TGE::Con::printf("");
		pluginPreInit();
	}

	auto originalParticleInit = TGE::ParticleEngine::init;
	void newParticleInit()
	{
		originalParticleInit();

		pluginPostInit();
		setPluginVariables();
	}

	// Handles onClientProcess() callbacks
	auto originalClientProcess = TGE::clientProcess;
	void newClientProcess(U32 timeDelta)
	{
		BasicPluginInterface::executeProcessList(timeDelta);
		originalClientProcess(timeDelta);
	}
}

void installHooks()
{
	loadedPlugins = new std::vector<LoadedPlugin>();
	codeAlloc = new CodeInjection::CodeAllocator();
	hook = new CodeInjection::FuncInterceptor(codeAlloc);
	basicInterceptor = new BasicTorqueFunctionInterceptor(hook);
	
	// Intercept ParticleEngine::init() because it's the last module that loads before main.cs is executed
	originalNsInit = hook->intercept(TGE::Namespace::init, newNsInit);
	originalParticleInit = hook->intercept(TGE::ParticleEngine::init, newParticleInit);

	// Intercept clientProcess() to call plugin callbacks
	originalClientProcess = hook->intercept(TGE::clientProcess, newClientProcess);
}
