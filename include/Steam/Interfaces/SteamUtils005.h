#ifndef __STEAMUTILS005_H__
#define __STEAMUTILS005_H__

#include "Common.h"
// We should not do this here, but I'm lazy to split this up in two files...
class SteamUtils005 : public ISteamUtils005
{
public:
	uint32 GetSecondsSinceAppActive()
	{
		Log::Debug( "SteamUtils", "Called GetSecondsSinceAppActive stub" );
		return 0;
	}

	uint32 GetSecondsSinceComputerActive()
	{
		Log::Debug( "SteamUtils", "Called GetSecondsSinceComputerActive stub" );
		return 0;
	}

	EUniverse GetConnectedUniverse()
	{
		Log::Debug( "SteamUtils", "Called GetConnectedUniverse stub" );
		return k_EUniversePublic;
	}

	uint32 GetServerRealTime()
	{
		Log::Debug( "SteamUtils", "Called GetServerRealTime stub" );
		return 0;
	}
	
	const char *GetIPCountry()
	{
		Log::Debug( "SteamUtils", "Called GetIPCountry stub" );
		return "GR";
	}

	bool GetImageSize( int iImage, uint32 *pnWidth, uint32 *pnHeight )
	{
		Log::Debug( "SteamUtils", "Called GetImageSize stub" );
		return false;
	}

	bool GetImageRGBA( int iImage, uint8 *pubDest, int nDestBufferSize )
	{
		Log::Debug( "SteamUtils", "Called GetImageRGBA stub" );
		return false;
	}

	bool GetCSERIPPort( uint32 *unIP, uint16 *usPort )
	{
		Log::Debug( "SteamUtils", "Called GetCSERIPPort stub" );
		return false;
	}

	uint8 GetCurrentBatteryPower()
	{
		Log::Debug( "SteamUtils", "Called GetCurrentBatteryPower stub" );
		return 255;
	}
	
	uint32 GetAppID()
	{
		Log::Debug( "SteamUtils", "Called GetAppID stub" );
		return 440;
	}

	void SetOverlayNotificationPosition( ENotificationPosition eNotificationPosition )
	{
		Log::Debug( "SteamUtils", "Called SetOverlayNotificationPosition stub" );
	}

	bool IsAPICallCompleted( SteamAPICall_t hSteamAPICall, bool *pbFailed )
	{
		Log::Debug( "SteamUtils", "Called IsAPICallCompleted stub" );
		return false;
	}

	ESteamAPICallFailure GetAPICallFailureReason( SteamAPICall_t hSteamAPICall )
	{
		Log::Debug( "SteamUtils", "Called GetAPICallFailureReason stub" );
		return k_ESteamAPICallFailureNone;
	}

	bool GetAPICallResult( SteamAPICall_t hSteamAPICall, void *pCallback, int cubCallback, int iCallbackExpected, bool *pbFailed )
	{
		Log::Debug( "SteamUtils", "Called GetAPICallResult stub" );
		return false;
	}

	void RunFrame()
	{
		Log::Debug( "SteamUtils", "Called RunFrame stub" );
	}

	uint32 GetIPCCallCount()
	{
		Log::Debug( "SteamUtils", "Called GetIPCCallCount stub" );
		return 0;
	}

	void SetWarningMessageHook( SteamAPIWarningMessageHook_t pFunction )
	{
		Log::Debug( "SteamUtils", "Called SetWarningMessageHook stub" );
	}

	bool IsOverlayEnabled()
	{
		Log::Debug( "SteamUtils", "Called IsOverlayEnabled stub" );
		return false;
	}

	bool BOverlayNeedsPresent()
	{
		Log::Debug( "SteamUtils", "Called BOverlayNeedsPresent stub" );
		return false;
	}

	SteamAPICall_t CheckFileSignature( const char *szFileName )
	{
		Log::Debug( "SteamUtils", "Called CheckFileSignature stub" );
		return 0;
	}
};

#endif /* __STEAMUTILS005_H__ */