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
#include <Shlwapi.h>

#pragma unmanaged

HSteamUser SteamUser014::GetHSteamUser()
{
	return NULL;
}

bool SteamUser014::BLoggedOn()
{
	return true;
}

CSteamID SteamUser014::GetSteamID()
{
	if (StrStrI(GetCommandLine(), "dedicated") != NULL)
	{
		return CSteamID(0xDED1CA7E, 1, k_EUniversePublic, k_EAccountTypeGameServer);
	}
	else
	{
		return CSteamID(SteamCommon::GetSteamID()->GetAccountID(), k_EUniversePublic, k_EAccountTypeIndividual);		
	}	
}

int SteamUser014::InitiateGameConnection( void *pAuthBlob, int cbMaxAuthBlob, CSteamID steamIDGameServer, uint32 unIPServer, uint16 usPortServer, bool bSecure )
{
	Log::Debug("SteamUser014", "Called InitiateGameConnection stub");
	return 0;
}

void SteamUser014::TerminateGameConnection( uint32 unIPServer, uint16 usPortserver )
{

}

void SteamUser014::TrackAppUsageEvent( CGameID gameID, EAppUsageEvent eAppUsageEvent, const char *pchExtraInfo )
{

}

bool SteamUser014::GetUserDataFolder( char *pchBuffer, int cubBuffer )
{
	return false;
}

void SteamUser014::StartVoiceRecording()
{

}

void SteamUser014::StopVoiceRecording()
{

}

EVoiceResult SteamUser014::GetAvailableVoice( uint32 *pcbCompressed, uint32 *pcbUncompressed )
{
	return k_EVoiceResultNoData;
}

EVoiceResult SteamUser014::GetVoice( bool bWantCompressed, void *pDestBuffer, uint32 cbDestBufferSize, uint32 *nBytesWritten, bool bWantUncompressed, void *pUncompressedDestBuffer, uint32 cbUncompressedDestBufferSize, uint32 *nUncompressBytesWritten )
{
	return k_EVoiceResultNoData;
}

EVoiceResult SteamUser014::DecompressVoice( void *pCompressed, uint32 cbCompressed, void *pDestBuffer, uint32 cbDestBufferSize, uint32 *nBytesWritten )
{
	return k_EVoiceResultNoData;
}

HAuthTicket SteamUser014::GetAuthSessionTicket( void *pTicket, int cbMaxTicket, uint32 *pcbTicket )
{
	return 0;
}

EBeginAuthSessionResult SteamUser014::BeginAuthSession( const void *pAuthTicket, int cbAuthTicket, CSteamID steamID )
{
	return k_EBeginAuthSessionResultOK;
}

void SteamUser014::EndAuthSession( CSteamID steamID )
{

}

void SteamUser014::CancelAuthTicket( HAuthTicket hAuthTicket )
{

}

EUserHasLicenseForAppResult SteamUser014::UserHasLicenseForApp( CSteamID steamID, AppId_t appID )
{
	return k_EUserHasLicenseResultHasLicense;
}

bool SteamUser014::IsBehindNAT()
{
	return false;
}

bool SteamUser014::AdvertiseGame( CSteamID steamIDGameServer, uint32 unIPServer , uint16 usPortServer )
{
	return false;
}

SteamAPICall_t SteamUser014::RequestEncryptedAppTicket( const void *pUserData, int cbUserData )
{
	return SteamCommon::RequestEncryptedAppTicket(pUserData, cbUserData);
}

bool SteamUser014::GetEncryptedAppTicket( void *pTicket, int cbMaxTicket, uint32 *pcbTicket )
{
	char* ticket = SteamCommon::GetEncryptedAppTicket();

	memcpy(pTicket, ticket, 128);
	*pcbTicket = 128;

	return true;
}
