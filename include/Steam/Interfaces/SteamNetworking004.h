#ifndef __STEAMNETWORKING004_H__
#define __STEAMNETWORKING004_H__

#include "Common.h"

// We should not do this here, but I'm lazy to split this up in two files...
class SteamNetworking004 : public ISteamNetworking004
{
public:
	bool SendP2PPacket( CSteamID steamIDRemote, const void *pubData, uint32 cubData, EP2PSend eP2PSendType, int iVirtualPort )
	{
		Log::Debug( "SteamNetworking", "Called SendP2PPacket stub" );
		return false;
	}

	bool IsP2PPacketAvailable( uint32 *pcubMsgSize, int iVirtualPort )
	{
		Log::Debug( "SteamNetworking", "IsP2PPacketAvailable stub" );
		return false;
	}

	bool ReadP2PPacket( void *pubDest, uint32 cubDest, uint32 *pcubMsgSize, CSteamID *psteamIDRemote, int iVirtualPort )
	{
		Log::Debug( "SteamNetworking", "Called ReadP2PPacket stub" );
		return false;
	}
	
	bool AcceptP2PSessionWithUser( CSteamID steamIDRemote )
	{
		Log::Debug( "SteamNetworking", "Called AcceptP2PSessionWithUser stub" );
		return false;
	}

	bool CloseP2PSessionWithUser( CSteamID steamIDRemote )
	{
		Log::Debug( "SteamNetworking", "Called CloseP2PSessionWithUser stub" );
		return false;
	}

	bool GetP2PSessionState( CSteamID steamIDRemote, P2PSessionState_t *pConnectionState )
	{
		Log::Debug( "SteamNetworking", "Called GetP2PSessionState stub" );
		return false;
	}

	SNetListenSocket_t CreateListenSocket( int nVirtualP2PPort, uint32 nIP, uint16 nPort, bool bAllowUseOfPacketRelay )
	{
		Log::Debug( "SteamNetworking", "Called CreateListenSocket stub" );
		return 0;
	}

	SNetSocket_t CreateP2PConnectionSocket( CSteamID steamIDTarget, int nVirtualPort, int nTimeoutSec, bool bAllowUseOfPacketRelay )
	{
		Log::Debug( "SteamNetworking", "Called CreateP2PConnectionSocket stub" );
		return 0;
	}

	SNetSocket_t CreateConnectionSocket( uint32 nIP, uint16 nPort, int nTimeoutSec )
	{
		Log::Debug( "SteamNetworking", "Called CreateConnectionSocket stub" );
		return 0;
	}

	bool DestroySocket( SNetSocket_t hSocket, bool bNotifyRemoteEnd )
	{
		Log::Debug( "SteamNetworking", "Called DestroySocket stub" );
		return false;
	}
	
	bool DestroyListenSocket( SNetListenSocket_t hSocket, bool bNotifyRemoteEnd )
	{
		Log::Debug( "SteamNetworking", "Called DestroyListenSocket stub" );
		return false;
	}

	bool SendDataOnSocket( SNetSocket_t hSocket, void *pubData, uint32 cubData, bool bReliable )
	{
		Log::Debug( "SteamNetworking", "Called SendDataOnSocket stub" );
		return false;
	}

	bool IsDataAvailableOnSocket( SNetSocket_t hSocket, uint32 *pcubMsgSize )
	{
		Log::Debug( "SteamNetworking", "Called IsDataAvailableOnSocket stub" );
		return false;
	}

	bool RetrieveDataFromSocket( SNetSocket_t hSocket, void *pubDest, uint32 cubDest, uint32 *pcubMsgSize )
	{
		Log::Debug( "SteamNetworking", "Called RetrieveDataFromSocket stub" );
		return false;
	}

	bool IsDataAvailable( SNetListenSocket_t hListenSocket, uint32 *pcubMsgSize, SNetSocket_t *phSocket )
	{
		Log::Debug( "SteamNetworking", "Called IsDataAvailable stub" );
		return false;
	}

	bool RetrieveData( SNetListenSocket_t hListenSocket, void *pubDest, uint32 cubDest, uint32 *pcubMsgSize, SNetSocket_t *phSocket )
	{
		Log::Debug( "SteamNetworking", "Called RetrieveData stub" );
		return false;
	}

	bool GetSocketInfo( SNetSocket_t hSocket, CSteamID *pSteamIDRemote, int *peSocketStatus, uint32 *punIPRemote, uint16 *punPortRemote )
	{
		Log::Debug( "SteamNetworking", "Called GetSocketInfo stub" );
		return false;
	}

	bool GetListenSocketInfo( SNetListenSocket_t hListenSocket, uint32 *pnIP, uint16 *pnPort )
	{
		Log::Debug( "SteamNetworking", "Called GetListenSocketInfo stub" );
		return false;
	}

	ESNetSocketConnectionType GetSocketConnectionType( SNetSocket_t hSocket )
	{
		Log::Debug( "SteamNetworking", "Called GetSocketConnectionType stub" );
		return k_ESNetSocketConnectionTypeNotConnected;
	}

	int GetMaxPacketSize( SNetSocket_t hSocket )
	{
		Log::Debug( "SteamNetworking", "Called GetMaxPacketSize stub" );
		return 4096;
	}
};

#endif /* __STEAMNETWORKING004_H__ */
