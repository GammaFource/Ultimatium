/*==========================================================
GammaForce operation

Project: Ultimatium
Game: Black Ops (T5)
Module: Steam_api emulator
Reason of existance: Steam interfaces.

Author: FaceTaker
==========================================================*/

#include "include\Common.h"
#include "Steam/Interfaces/SteamUser014.h"
#include "Steam/Interfaces/SteamApps003.h"
#include "Steam/Interfaces/SteamFriends007.h"
#include "Steam/Interfaces/SteamUserStats007.h"
#include "Steam/Interfaces/SteamNetworking004.h"
#include "Steam/Interfaces/SteamUtils005.h"
#include "Steam/Interfaces/SteamMasterServerUpdater001.h"
#include "Steam/Interfaces/SteamGameServer010.h"




SteamApps003*					steamApps = NULL;
SteamFriends007*				steamFriends = NULL;
SteamMasterServerUpdater001*	steamMasterServerUpdater = NULL;
SteamUser014*					steamUser = NULL;
SteamNetworking004*				steamNetworking = NULL;
SteamUserStats007*				steamUserStats = NULL;
SteamUtils005*					steamUtils = NULL;
SteamGameServer010*				steamGameServer = NULL;

bool wasInitialized = false;

void SteamClient::Initialize() {
	steamApps = new SteamApps003;
	steamFriends = new SteamFriends007;
	steamMasterServerUpdater = new SteamMasterServerUpdater001;
	steamUser = new SteamUser014;
	steamNetworking = new SteamNetworking004;
	steamUserStats = new SteamUserStats007;
	steamUtils = new SteamUtils005;
	steamGameServer = new SteamGameServer010;	

	wasInitialized = true;
}

void* SteamClient::GetInterface(steamInterface_t steamInterface) {
	if (!wasInitialized) {
		SteamClient::Initialize();
	}

	if (steamInterface == STEAMAPPS_003)
		return steamApps;
	if (steamInterface == STEAMFRIENDS_007)
		return steamFriends;
	if (steamInterface == STEAMGAMESERVER_010)
		return steamGameServer;
	if (steamInterface == STEAMMASTERSERVERUPDATER_001)
		return steamMasterServerUpdater;
	if (steamInterface == STEAMNETWORKING_004)
		return steamNetworking;
	if (steamInterface == STEAMUSER_014)
		return steamUser;
	if (steamInterface == STEAMUSERSTATS_007)
		return steamUserStats;
	if (steamInterface == STEAMUTILS_005)
		return steamUtils;	

	return NULL;
}