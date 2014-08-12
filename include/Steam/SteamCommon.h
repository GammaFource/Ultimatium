#ifndef __STEAMCOMMON_H__
#define __STEAMCOMMON_H__

#include "Common.h"
#include "Steam/SteamAPI.h"

class SteamCommon
{
public:
	static void Init();
	static SteamAPICall_t RequestEncryptedAppTicket(const void *pUserData, int cbUserData);
	static CSteamID* GetSteamID();
	static char* GetEncryptedAppTicket();
	static char* GetPlayerName();
	static void SetPlayerName(const char* newName);	

private:
	static CSteamID* steamID;	
	static char encryptedAppTicket[128];
	static char playerName[255];	
};

#endif /* __STEAMCOMMON_H__ */