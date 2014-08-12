#pragma once

typedef enum SteamInterface_t {
	STEAMAPPS_003,
	STEAMFRIENDS_007,
	STEAMGAMESERVER_010,
	STEAMMASTERSERVERUPDATER_001,
	STEAMNETWORKING_004,
	STEAMUSER_014,
	STEAMUSERSTATS_007,
	STEAMUTILS_005,
	STEAMMATCHMAKING_009
} steamInterface_t;

class SteamClient {
public:
	static void Initialize();
	static void* GetInterface(steamInterface_t steamInterface);
};
