/*
 * This file is part of iberianOps Client - BlackOps (T5)
 * -------------------------------------------------------------------------
 * This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-sa/3.0/.
 *
 * Creator: Almamu
 */

#ifndef __STATS_H__
#define __STATS_H__
/*
typedef enum
{
	STATS_HEADER_ONLINE_RANK = 1,
	STATS_HEADER_TRAINING = 2,
}Stats_Header_t;

typedef struct dwFileData_s
{
	char* fileName;
	char pad[4];
	char fileType;
	char pad2[3];
	// char pad3[0x9FF4];
	char pad3[0xE7];
	char* popupName;
	void* someKindOfStruct;
	int unknown;
	void (*successCallback)(int);
	void (*errorCallback)(int, int);
	char pad4[0x9F0D];
}dwFileData_t;

struct statsFile_t
{
  int unknown;
  int statsVersion;
  char pad[40952]; // 264 -> steamID?
};

typedef struct
{
	char pad[3168];
	dwFileData_t* file;
	char pad2[58277];
}unknownData_t;

typedef struct userStats_s
{
	dwFileData_t* someImportantData; // User stats?
	dvar_t* stat_version;
	dvar_t* fshSearchTaskDelay;
	dvar_t* dwFileFetchTryMaxAttempts;
	char pad2[16];
	int statsRequestedLastInterval;
	int userID;
	__int64 address; // (or SteamID?)used to return the CACvalidation message
	char someBlobData1[0x4258]; // 200 -> some type of struct, 204 integer, 208 and 212 functions
	char someBlobData2[0x4190];
	int steamUserIDLow;
	int steamUserIDHigh;
	char someBlobData3[0x12E0];
	char* accountName;
	char someBlobData4[0x4AB5];	
	char pad4[204792]; // 147050 -> fshSearchTaskDelay; 147054 -> dwFileFetchTryInvervalBase 147046 -> stat_version for training?
}userStats_t;

	char someBlobData1[0xC4];
	char* popupName;
	void* someKindOfStruct;
	int unknown;
	void (*successCallback)(int);
	void (*errorCallback)(int, int);

// userStats_t size = 245796
// We should be able to hook in the calls to external stats upload, save the stats to a file
// and send a OOB(OutOfBand)message using address(ourselves)and tell us the stats are okay
// 0x533D10(1, userStats_t->statsRequestedLastInterval, userStats_t->address, "statsOk\n");
// Or we should be able to call SV_GetCACSuccesfull just giving the steamID, so we can retrieve the stats from the DWMessage
// and send it back to ourselves
// I bet that the only method that will work is the first, its easier to do, but we'll need another hook
// when loading the user stats, and I still do not know where the hell the stats are loaded
// at the moment we can send them to the DemonWare server though NSServer and store them just like a game server(when CACValidation occurs)does
// I still need to guess where the hell the current global stats are stored, but I can use one of the functions for get the user global stats and training stats
// But I still need to find a way to load them back, so... fuck this shit, time to do some code work

// We will keep this outside the class for some time
typedef void (__cdecl* NET_OutOfBandPrint_t)(int type, int lastInterval, __int64 steamID, const char* message);
NET_OutOfBandPrint_t NET_OutOfBandPrint = (NET_OutOfBandPrint_t)0x533D10;

typedef userStats_t* (__cdecl* STATS_GetUserStats_t)(int controller, int statsToFetch, char* a3);
STATS_GetUserStats_t STATS_GetUserStats = (STATS_GetUserStats_t)0x912540;*/

class Stats
{
public:
	static void PatchMP();
};
#endif /* __STATS_H__ */