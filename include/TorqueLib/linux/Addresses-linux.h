#ifndef TORQUELIB_ADDRESSES_UNIX_H
#define TORQUELIB_ADDRESSES_UNIX_H

// Functions
#define TGEADDR_SIMOBJECT_GETIDSTRING 0x8084A10
#define TGEADDR_SIMOBJECT_SETHIDDEN 0x80849D0
#define TGEADDR_CONTAINER_CASTRAY 0x81CA010
#define TGEADDR_FILESTREAM_OPEN 0x808F440
#define TGEADDR_FILE_OPEN 0x8200E70
#define TGEADDR_FILE_GETPOSITION 0x8201AC0
#define TGEADDR_FILE_SETPOSITION 0x8201AE0
#define TGEADDR_FILE_GETSIZE 0x8201B70
#define TGEADDR_FILE_FLUSH 0x8201BE0
#define TGEADDR_FILE_CLOSE 0x8201C20
#define TGEADDR_FILE_GETSTATUS 0x8201C80
#define TGEADDR_FILE_READ 0x8201CE0
#define TGEADDR_FILE_WRITE 0x8201D80
#define TGEADDR_FILE_DTOR 0x8201A80
#define TGEADDR_FILE_SETSTATUS_1 0x8201CD0
#define TGEADDR_PATHEDINTERIOR_ADVANCE 0x819D490
#define TGEADDR_PATHEDINTERIOR_COMPUTENEXTPATHSTEP 0x819CF40
#define TGEADDR__STRINGTABLE_INSERT 0x8093220
#define TGEADDR_CON_INIT 0x8077070
#define TGEADDR_CON_PRINTF 0x8077750
#define TGEADDR_CON__PRINTF 0x80775B0
#define TGEADDR_CON_WARNF_1V 0x80777B0
#define TGEADDR_CON_WARNF_2V 0x8077770
#define TGEADDR_CON_ERRORF_1V 0x80777D0
#define TGEADDR_CON_ERRORF_2V 0x8077790
#define TGEADDR_CON_ADDCOMMAND_5_STRING 0x8078870
#define TGEADDR_CON_ADDCOMMAND_5_VOID 0x80788C0
#define TGEADDR_CON_ADDCOMMAND_5_INT 0x8078910
#define TGEADDR_CON_ADDCOMMAND_5_FLOAT 0x8078960
#define TGEADDR_CON_ADDCOMMAND_5_BOOL 0x80789B0
#define TGEADDR_CON_ADDCOMMAND_6_STRING 0x8078640
#define TGEADDR_CON_ADDCOMMAND_6_VOID 0x80786B0
#define TGEADDR_CON_ADDCOMMAND_6_INT 0x8078720
#define TGEADDR_CON_ADDCOMMAND_6_FLOAT 0x8078790
#define TGEADDR_CON_ADDCOMMAND_6_BOOL 0x8078800
#define TGEADDR_CON_SETVARIABLE 0x80780F0
#define TGEADDR_CON_SETLOCALVARIABLE 0x8078160
#define TGEADDR_CON_SETBOOLVARIABLE 0x80781E0
#define TGEADDR_CON_SETINTVARIABLE 0x8078260
#define TGEADDR_CON_SETFLOATVARIABLE 0x80782E0
#define TGEADDR_CON_EXECUTE 0x8078A90
#define TGEADDR_CON_EVALUATE 0x8078A00
#define TGEADDR_CON_EVALUATEF 0x8077A70
#define TGEADDR_CON_GETRETURNBUFFER 0x8070B10
#define TGEADDR_CON_EXPANDSCRIPTFILENAME 0x8077970
#define TGEADDR_PLATFORM_DUMPPATH 0x82016A0
#define TGEADDR_PLATFORM_GETWORKINGDIRECTORY 0x8201E50
#define TGEADDR_PLATFORM_ISSUBDIRECTORY 0x82018C0
#define TGEADDR_PLATFORM_GETFILETIMES 0x8201210
#define TGEADDR_NAMESPACE_INIT 0x807C710
#define TGEADDR_PARTICLEENGINE_INIT 0x8164E10
#define TGEADDR_SIM_FINDOBJECT 0x80865B0
#define TGEADDR_NET_INIT 0x8214700
#define TGEADDR_MARBLE_DOPOWERUP 0x814CE80
#define TGEADDR_MARBLE_ADVANCEPHYSICS 0x81478F0
#define TGEADDR_ABSTRACTCLASSREP_INITIALIZE 0x807DD00
#define TGEADDR_CLIENTPROCESS 0x80F2A00
#define TGEADDR_DSPRINTF 0x8219340
#define TGEADDR_DVSPRINTF 0 // TODO: Implement
#define TGEADDR_DFREE 0x81A92B0
#define TGEADDR_DQSORT 0x8219EA0
#define TGEADDR_VECTORRESIZE 0x8093970
#define TGEADDR_CAMERA_ADVANCEPHYSICS 0x80EF220
#define TGEADDR_RESMANAGER_OPENSTREAM_STR 0x8092BA0
#define TGEADDR_RESMANAGER_OPENSTREAM_RESOURCEOBJECT 0x8091B30
#define TGEADDR_RESMANAGER_CLOSESTREAM 0x8092BE0
#define TGEADDR_RESMANAGER_FIND 0x8091D70
#define TGEADDR_RESMANAGER_GETSIZE 0x8092920
#define TGEADDR_RESMANAGER_GETCRC 0x8091820
#define TGEADDR_RESMANAGER_SEARCHPATH 0x8091200
#define TGEADDR_RESMANAGER_SETMODZIP 0x8091300
#define TGEADDR_NET_BIND 0x8214260
#define TGEADDR_TIMEMANAGER_PROCESS 0 // TODO: Implement
#define TGEADDR_GAMEBASE_PACKUPDATE 0 // TODO: Implement
#define TGEADDR_GAMEBASE_UNPACKUPDATE 0 // TODO: Implement
#define TGEADDR_INTERIORINSTANCE_PACKUPDATE 0 // TODO: Implement
#define TGEADDR_INTERIORINSTANCE_UNPACKUPDATE 0 // TODO: Implement
#define TGEADDR_TSSTATIC_PACKUPDATE 0 // TODO: Implement
#define TGEADDR_TSSTATIC_UNPACKUPDATE 0 // TODO: Implement
#define TGEADDR_BITSTREAM_WRITEINT 0 // TODO: Implement
#define TGEADDR_BITSTREAM_READINT 0 // TODO: Implement

// Class fields
#define TGEOFF_CONSOLEOBJECT_VTABLE 0x0
#define TGEOFF_SIMOBJECT_ID 0x20
#define TGEOFF_SCENEOBJECT_TRANSFORM 0x9C
#define TGEOFF_SCENEOBJECT_WORLDBOX 0x140
#define TGEOFF_GAMEBASE_CONTROLLINGCLIENT 0x270
#define TGEOFF_FILE_HANDLE 0x0
#define TGEOFF_FILE_CAPABILITIES 0x8
#define TGEOFF_ABSTRACTCLASSREP_CLASSNAME 0x28
#define TGEOFF_STREAM_VTABLE 0x4
#define TGEOFF_STREAM_STATUS 0x0
#define TGEOFF_GAMEINTERFACE_VTABLE 0 // TODO: Implement

// Globals
#define TGEADDR_MSERVERCONNECTION 0x83454C0
#define TGEADDR_GCLIENTCONTAINER 0x8345E00
#define TGEADDR_GSERVERCONTAINER 0x8345DA0
#define TGEADDR_STRINGTABLE 0x82F94A0
#define TGEADDR_RESOURCEMANAGER 0x82F9440
#define TGEADDR_GAME 0 // TODO: Implement

// Virtual functions
enum
{
	TGEVIRT_STREAM_DTOR = 2,
	TGEVIRT_STREAM__READ,
	TGEVIRT_STREAM__WRITE,
	TGEVIRT_STREAM_HASCAPABILITY,
	TGEVIRT_STREAM_GETPOSITION,
	TGEVIRT_STREAM_SETPOSITION,
	TGEVIRT_STREAM_GETSTREAMSIZE,
	TGEVIRT_STREAM_READSTRING,
	TGEVIRT_STREAM_WRITESTRING
};
enum
{
	TGEVIRT_CONSOLEOBJECT_DESTRUCTOR = 3,
	TGEVIRT_NETOBJECT_PACKUPDATE = 23,
	TGEVIRT_NETOBJECT_UNPACKUPDATE = 24,
	TGEVIRT_SCENEOBJECT_DISABLECOLLISION = 26,
	TGEVIRT_SCENEOBJECT_ENABLECOLLISION,
	TGEVIRT_SCENEOBJECT_ISDISPLACABLE,
	TGEVIRT_SCENEOBJECT_GETMOMENTUM,
	TGEVIRT_SCENEOBJECT_SETMOMENTUM,
	TGEVIRT_SCENEOBJECT_GETMASS,
	TGEVIRT_SCENEOBJECT_DISPLACEOBJECT,
	TGEVIRT_SCENEOBJECT_SETTRANSFORM,
	TGEVIRT_SHAPEBASE_GETCAMERATRANSFORM = 86
};
enum
{
	TGEVIRT_GAMEINTERFACE_POSTEVENT = 6 // TODO: Implement
};

#endif // TORQUELIB_ADDRESSES_UNIX_H
