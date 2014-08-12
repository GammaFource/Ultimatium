/*==========================================================
GammaForce operation

Project: Ultimatium
Game: Black Ops (T5)
Module: Steam_api emulator
Reason of existance: Steam emulation code.

Author: FaceTaker
==========================================================*/

#include "Common.h"
#include "Steam/SteamAPI.h"
#include "Steam/SteamCommon.h"

#pragma unmanaged

void SteamMasterServerUpdater001::SetActive( bool bActive ) { }
void SteamMasterServerUpdater001::SetHeartbeatInterval( int iHeartbeatInterval ) { }
bool SteamMasterServerUpdater001::HandleIncomingPacket( const void *pData, int cbData, uint32 srcIP, uint16 srcPort ) { return true; }
int SteamMasterServerUpdater001::GetNextOutgoingPacket( void *pOut, int cbMaxOut, uint32 *pNetAdr, uint16 *pPort ) { return 0; }
void SteamMasterServerUpdater001::SetBasicServerData(unsigned short nProtocolVersion, bool bDedicatedServer,	const char *pRegionName, const char *pProductName, unsigned short nMaxReportedClients, bool bPasswordProtected,	const char *pGameDescription ) { }
void SteamMasterServerUpdater001::ClearAllKeyValues() { }
void SteamMasterServerUpdater001::SetKeyValue( const char *pKey, const char *pValue ) {
}

void SteamMasterServerUpdater001::NotifyShutdown() { }
bool SteamMasterServerUpdater001::WasRestartRequested() { return false; }
void SteamMasterServerUpdater001::ForceHeartbeat() { }
bool SteamMasterServerUpdater001::AddMasterServer( const char *pServerAddress ) { return true; }
bool SteamMasterServerUpdater001::RemoveMasterServer( const char *pServerAddress ) { return true; }
int SteamMasterServerUpdater001::GetNumMasterServers() { return 0; }
int SteamMasterServerUpdater001::GetMasterServerAddress( int iServer, char *pOut, int outBufferSize ) { return 0; }
