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
#include "VTILib.h"

#pragma unmanaged

void SteamGameServer010::LogOn() {
	//Logger(lSAPI, "SteamGameServer010", "LogOn");
}

void SteamGameServer010::LogOff() 
{
	
}

bool SteamGameServer010::LoggedOn() {
	
	return true;
}

bool SteamGameServer010::Secure() {
	
	return false;
}

CSteamID SteamGameServer010::GetSteamID() {
	
	return CSteamID(VTI_GetSelfVultrotID(), k_EUniversePublic, k_EAccountTypeIndividual);
}

bool SteamGameServer010::SendUserConnectAndAuthenticate( uint32 unIPClient, const void *pvAuthBlob, uint32 cubAuthBlobSize, CSteamID *pSteamIDUser )
{
	return true;
}

CSteamID SteamGameServer010::CreateUnauthenticatedUserConnection() {
	
	return CSteamID(SteamCommon::GetSteamID()->GetAccountID(), k_EUniversePublic, k_EAccountTypeIndividual);
}

void SteamGameServer010::SendUserDisconnect( CSteamID steamIDUser ) {
	
}

bool SteamGameServer010::UpdateUserData( CSteamID steamIDUser, const char *pchPlayerName, uint32 uScore ) {
	
	return true;
}

bool SteamGameServer010::SetServerType( uint32 unServerFlags, uint32 unGameIP, uint16 unGamePort, uint16 unSpectatorPort, uint16 usQueryPort, const char *pchGameDir, const char *pchVersion, bool bLANMode ) {
	
	return true;
}

void SteamGameServer010::UpdateServerStatus( int cPlayers, int cPlayersMax, int cBotPlayers, const char *pchServerName, const char *pSpectatorServerName, const char *pchMapName ) {
	
}

void SteamGameServer010::UpdateSpectatorPort( uint16 unSpectatorPort ) { }

void SteamGameServer010::SetGameTags( const char *pchGameType ) { }

bool SteamGameServer010::GetUserAchievementStatus( CSteamID steamID, const char *pchAchievementName ) {
	
	return false;
}

void SteamGameServer010::GetGameplayStats( ) {}

SteamAPICall_t SteamGameServer010::GetServerReputation( )
{
	return 0;
}

bool SteamGameServer010::RequestUserGroupStatus( CSteamID steamIDUser, CSteamID steamIDGroup ) {
	
	return false;
}

uint32 SteamGameServer010::GetPublicIP() {
	
	return 0;
}

void SteamGameServer010::SetGameData( const char *pchGameData) {
	
}

EUserHasLicenseForAppResult SteamGameServer010::UserHasLicenseForApp( CSteamID steamID, AppId_t appID ) {
	return k_EUserHasLicenseResultHasLicense;
}

HAuthTicket SteamGameServer010::GetAuthSessionTicket( void *pTicket, int cbMaxTicket, uint32 *pcbTicket )
{
	return 0;
}

EBeginAuthSessionResult SteamGameServer010::BeginAuthSession( const void *pAuthTicket, int cbAuthTicket, CSteamID steamID )
{
	return k_EBeginAuthSessionResultOK;
}

void SteamGameServer010::EndAuthSession( CSteamID steamID )
{

}

void SteamGameServer010::CancelAuthTicket( HAuthTicket hAuthTicket )
{

}