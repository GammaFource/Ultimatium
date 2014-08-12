/*==========================================================
GammaForce operation

Project: Ultimatium
Game: Black Ops (T5)
Module: Steam_api emulator
Reason of existance: Steam emulation exports.

Author: FaceTaker
==========================================================*/

#include "Common.h"
#include "Steam/SteamAPI.h"
#include <Shlwapi.h>
#include "Steam/SteamCommon.h"
#include "Game/Patches/ClientPatches.h"
#include "VTILib.h"


#pragma managed
GF_API bool GF_MAIN SteamAPI_Init()
{
	Log::Debug("MainDLL", "Called SteamAPI_Init stub");
	
	SteamCommon::Init();	
	
	return true;
}

GF_API bool GF_MAIN SteamAPI_InitSafe()
{
	Log::Debug("MainDLL", "Called SteamAPI_InitSafe stub");
	return true;
}

GF_API void GF_MAIN SteamAPI_RegisterCallResult(CCallbackBase* result, SteamAPICall_t callID)
{
	Log::Debug("MainDLL", "Called SteamAPI_RegisterCallResult stub");
	Callbacks::RegisterCallResult(result, callID);
}

GF_API void GF_MAIN SteamAPI_RegisterCallback(CCallbackBase *callback, int type)
{
	Log::Debug("MainDLL", "Called SteamAPI_RegisterCallback stub");
	Callbacks::Register(callback, type);
}

GF_API void GF_MAIN SteamAPI_RunCallbacks()
{
	Log::Debug("MainDLL", "Called SteamAPI_RunCallbacks stub");
	Callbacks::Run();
}

GF_API void GF_MAIN SteamAPI_SetMiniDumpComment(const char* msg)
{
	Log::Debug("MainDLL", "Called SteamAPI_SetMiniDumpComment stub");
}

GF_API bool GF_MAIN SteamAPI_SetTryCatchCallbacks(bool bTryCatchCallbacks)
{
	Log::Debug("MainDLL", "Called SteamAPI_SetTryCatchCallbacks stub");
	return bTryCatchCallbacks;
}

GF_API void GF_MAIN SteamAPI_Shutdown()
{
	Log::Debug("MainDLL", "Called SteamAPI_Shutdown stub");
}

GF_API void GF_MAIN SteamAPI_UnregisterCallResult(CCallbackBase* result, SteamAPICall_t callID)
{
	Log::Debug("MainDLL", "Called SteamAPI_UnregisterCallResult stub");
}

GF_API void GF_MAIN SteamAPI_UnregisterCallback(CCallbackBase *callback, int type)
{
	Log::Debug("MainDLL", "Called SteamAPI_UnregisterCallback stub");
	Callbacks::UnregisterCall(callback);
}

GF_API void GF_MAIN SteamAPI_WriteMiniDump(uint32 structuredExceptionDoce, void *exceptionInfo, uint32 buildID)
{
	Log::Debug("MainDLL", "Called SteamAPI_WriteMiniDump stub");
}

GF_API void* GF_MAIN SteamApps()
{
	Log::Debug("MainDLL", "Called SteamApps stub");
	return SteamClient::GetInterface(STEAMAPPS_003);
}

GF_API void* GF_MAIN SteamClient()
{
	Log::Debug("MainDLL", "Called SteamClient stub");
	return NULL;
}

GF_API void* GF_MAIN SteamContentServer()
{
	Log::Debug("MainDLL", "Called SteamContentServer stub");
	return NULL;
}

GF_API void* GF_MAIN SteamContentServerUtils()
{
	Log::Debug("MainDLL", "Called SteamContentServerUtils stub");
	return NULL;
}

GF_API bool GF_MAIN SteamContentServer_Init(unsigned int localIP, unsigned short port)
{
	Log::Debug("MainDLL", "Called SteamContentServer_Init stub");
	return false;
}

GF_API void GF_MAIN SteamContentServer_RunCallbacks()
{
	Log::Debug("MainDLL", "Called SteamContentServer_RunCallbacks stub");
}

GF_API void GF_MAIN SteamContentServer_Shutdown()
{
	Log::Debug("MainDLL", "Called SteamContentServer_Shutdown stub");
}

GF_API void* GF_MAIN SteamFriends()
{
	Log::Debug("MainDLL", "Called SteamFriends stub");
	return SteamClient::GetInterface(STEAMFRIENDS_007);
}

GF_API void* GF_MAIN SteamGameServer()
{
	Log::Debug("MainDLL", "Called SteamGameServer stub");
	return SteamClient::GetInterface(STEAMGAMESERVER_010);
}

GF_API void* GF_MAIN SteamGameServerUtils()
{
	Log::Debug("MainDLL", "Called SteamGameServerUtils stub");
	return NULL;
}

GF_API bool GF_MAIN SteamGameServer_BSecure()
{
	Log::Debug("MainDLL", "Called SteamGameServer_BSecure stub");
	return true;
}

GF_API HSteamPipe GF_MAIN SteamGameServer_GetHSteamPipe()
{
	Log::Debug("MainDLL", "Called SteamGameServer_GetHSteamPipe stub");
	return 0;
}

GF_API HSteamUser GF_MAIN SteamGameServer_GetHSteamUser()
{
	Log::Debug("MainDLL", "Called SteamGameServer_GetHSteamUser stub");
	return 0;
}
GF_API int32 GF_MAIN SteamGameServer_GetIPCCallCount()
{
	Log::Debug("MainDLL", "Called SteamGameServer_GetIPCCallCount stub");
	return 0;
}

GF_API uint64 GF_MAIN SteamGameServer_GetSteamID()
{
	Log::Debug("MainDLL", "Called SteamGameServer_GetSteamID stub");
	return 0;
}

GF_API bool GF_MAIN SteamGameServer_Init(uint32 ip, uint16 port, uint16 gamePort, EServerMode serverMode, int gameAppID, const char* gameDir, const char* versionString)
{
	Log::Debug("MainDLL", "Called SteamGameServer_Init stub");
	return false;
}

GF_API bool GF_MAIN SteamGameServer_InitSafe(uint32 ip, uint16 port, uint16 gamePort, EServerMode serverMode, int gameAppID, const char* gameDir, const char* versionStrinng, unsigned long dongs)
{
	Log::Debug("MainDLL", "Called SteamGameServer_InitSafe stub");
	return false;
}

GF_API void GF_MAIN SteamGameServer_RunCallbacks()
{
	Log::Debug("MainDLL", "Called SteamGameServer_RunCallbacks stub");
}

GF_API void GF_MAIN SteamGameServer_Shutdown()
{
	Log::Debug("MainDLL", "Called SteamGameServer_Shutdown stub");
}

GF_API void* GF_MAIN SteamMasterServerUpdater()
{
	Log::Debug("MainDLL", "Called SteamMasterServeruUpdater stub");
	return SteamClient::GetInterface(STEAMMASTERSERVERUPDATER_001);
}

GF_API void* GF_MAIN SteamMatchmaking()
{
	Log::Debug("MainDLL", "Called SteamMatchmaking stub");
	return NULL;
}

GF_API void* GF_MAIN SteamMatchmakingServers()
{
	Log::Debug("MainDLL", "Called SteamMatchmakingServers stub");
	return NULL;
}

GF_API void* GF_MAIN SteamNetworking()
{
	Log::Debug("MainDLL", "Called SteamNetworking stub");
	return SteamClient::GetInterface(STEAMNETWORKING_004);
}

GF_API void* GF_MAIN SteamRemoteStorage()
{
	Log::Debug("MainDLL", "Called SteamRemoteStorage stub");
	return NULL;
}

GF_API void* GF_MAIN SteamUser()
{
	Log::Debug("MainDLL", "Called SteamUser stub");
	return SteamClient::GetInterface(STEAMUSER_014);
}

GF_API void* GF_MAIN SteamUserStats()
{
	Log::Debug("MainDLL", "Called SteamUserStats stub");
	return SteamClient::GetInterface(STEAMUSERSTATS_007);
}

GF_API void* GF_MAIN SteamUtils()
{
	Log::Debug("MainDLL", "Called SteamUtils stub");
	return SteamClient::GetInterface(STEAMUTILS_005);
}

GF_API HSteamUser GF_MAIN Steam_GetHSteamUserCurrent()
{
	Log::Debug("MainDLL", "Called Steam_GetHSteamuserCurrent stub");
	return 0;
}

GF_API void GF_MAIN Steam_RegisterInterfaceFuncs(void *module)
{
	Log::Debug("MainDLL", "Called SteamRegisterInterfaceFuncs stub");
}

GF_API void GF_MAIN Steam_RunCallbacks(HSteamPipe hSteamPipe, bool bGameServerCallbacks)
{
	Log::Debug("MainDLL", "Called Steam_RunCallbacks stub");
}

GF_API bool GF_MAIN SteamAPI_RestartApp(int appid)
{
	Log::Debug("MainDLL", "Called SteamAPI_RestartApp stub");
	return false;
}

GF_API bool GF_MAIN SteamAPI_RestartAppIfNecessary(uint32 appID)
{
	Log::Debug("MainDLL", "Called SteamAPI_RestartAppIfNecessary stub");
	return false;
}

GF_API bool GF_MAIN SteamAPI_IsSteamRunning()
{
	Log::Debug("MainDLL", "Called SteamAPI_IsSteamRunning stub");
	return true;
}

GF_API void *g_pSteamClientGameServer = NULL;


