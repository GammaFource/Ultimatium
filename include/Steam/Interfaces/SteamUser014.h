#ifndef __STEAMUSER014_H__
#define __STEAMUSER014_H__

#include "Common.h"

class SteamUser014 : public ISteamUser014
{
public:
	HSteamUser GetHSteamUser();
	bool BLoggedOn();
	CSteamID GetSteamID();
	int InitiateGameConnection( void *pAuthBlob, int cbMaxAuthBlob, CSteamID steamIDGameServer, uint32 unIPServer, uint16 usPortServer, bool bSecure );
	void TerminateGameConnection( uint32 unIPServer, uint16 usPortserver );
	void TrackAppUsageEvent( CGameID gameID, EAppUsageEvent eAppUsageEvent, const char *pchExtraInfo = "" );
	bool GetUserDataFolder( char *pchBuffer, int cubBuffer );
	void StartVoiceRecording();
	void StopVoiceRecording();
	EVoiceResult GetAvailableVoice( uint32 *pcbCompressed, uint32 *pcbUncompressed );
	EVoiceResult GetVoice( bool bWantCompressed, void *pDestBuffer, uint32 cbDestBufferSize, uint32 *nBytesWritten, bool bWantUncompressed, void *pUncompressedDestBuffer, uint32 cbUncompressedDestBufferSize, uint32 *nUncompressBytesWritten );
	EVoiceResult DecompressVoice( void *pCompressed, uint32 cbCompressed, void *pDestBuffer, uint32 cbDestBufferSize, uint32 *nBytesWritten );
	HAuthTicket GetAuthSessionTicket( void *pTicket, int cbMaxTicket, uint32 *pcbTicket );
	EBeginAuthSessionResult BeginAuthSession( const void *pAuthTicket, int cbAuthTicket, CSteamID steamID );
	void EndAuthSession( CSteamID steamID );
	void CancelAuthTicket( HAuthTicket hAuthTicket );
	EUserHasLicenseForAppResult UserHasLicenseForApp( CSteamID steamID, AppId_t appID );
	bool IsBehindNAT();
	bool AdvertiseGame( CSteamID steamIDGameServer, uint32 unIPServer , uint16 usPortServer );
	SteamAPICall_t RequestEncryptedAppTicket( const void *pUserData, int cbUserData );
	bool GetEncryptedAppTicket( void *pTicket, int cbMaxTicket, uint32 *pcbTicket );
};

#endif /* __STEAMUSER014_H__ */