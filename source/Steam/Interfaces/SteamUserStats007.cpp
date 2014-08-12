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

bool SteamUserStats007::RequestCurrentStats()
{
	return true;
}

bool SteamUserStats007::GetStat( const char *pchName, int32 *pData )
{
	return true;
}

bool SteamUserStats007::GetStat( const char *pchName, float *pData )
{
	return true;
}

bool SteamUserStats007::SetStat( const char *pchName, int32 nData )
{
	return false;
}

bool SteamUserStats007::SetStat( const char *pchName, float fData )
{
	return false;
}

bool SteamUserStats007::UpdateAvgRateStat( const char *pchName, float flCountThisSession, double dSessionLength )
{
	return false;
}

bool SteamUserStats007::GetAchievement( const char *pchName, bool *pbAchieved )
{
	*pbAchieved = false;
	return false;
}

bool SteamUserStats007::SetAchievement( const char *pchName )
{
	return false;
}

bool SteamUserStats007::ClearAchievement( const char *pchName )
{
	return false;
}

bool SteamUserStats007::GetAchievementAndUnlockTime( const char *pchName, bool *pbAchieved, RTime32 *prtTime )
{
	return true;
}

bool SteamUserStats007::StoreStats()
{
	return true;
}

int SteamUserStats007::GetAchievementIcon( const char *pchName )
{
	return 0;
}

const char* SteamUserStats007::GetAchievementDisplayAttribute( const char *pchName, const char *pchKey )
{
	return "";
}

bool SteamUserStats007::IndicateAchievementProgress( const char *pchName, uint32 nCurProgress, uint32 nMaxProgress )
{
	return false;
}

SteamAPICall_t SteamUserStats007::RequestUserStats( CSteamID steamIDUser )
{
	return 0;
}

bool SteamUserStats007::GetUserStat( CSteamID steamIDUser, const char *pchName, int32 *pData )
{
	return false;
}

bool SteamUserStats007::GetUserStat( CSteamID steamIDUser, const char *pchName, float *pData )
{
	return false;
}

bool SteamUserStats007::GetUserAchievement( CSteamID steamIDUser, const char *pchName, bool *pbAchieved )
{
	return false;
}

bool SteamUserStats007::GetUserAchievementAndUnlockTime( CSteamID steamIDUser, const char *pchName, bool *pbAchieved, RTime32 *prtTime )
{
	return false;
}

bool SteamUserStats007::ResetAllStats( bool bAchievementsToo )
{
	return false;
}

#pragma managed

SteamAPICall_t SteamUserStats007::FindOrCreateLeaderboard( const char *pchLeaderboardName, ELeaderboardSortMethod eLeaderboardSortMethod, ELeaderboardDisplayType eLeaderboardDisplayType )
{
	Log::Debug("SteamUserStats", "Called FindOrCreateLeaderboard stub");

	/*int leaderboardID = NNI_FindLeaderboard(pchLeaderboardName);
	if(leaderboardID == -1)
	{
		NNI_CreateLeaderboard(pchLeaderboardName);
		leaderboardID = NNI_FindLeaderboard(pchLeaderboardName);
	}

	if(leaderboardID == -1)
	{
		leaderboardID ++;
	}

	SteamAPICall_t callID = Callbacks::RegisterCall();

	LeaderboardFindResult_t* response = (LeaderboardFindResult_t*) malloc(sizeof(LeaderboardFindResult_t));

	response->m_hSteamLeaderboard = leaderboardID;
	response->m_bLeaderboardFound = 1;

	Callbacks::Return(response, LeaderboardFindResult_t::k_iCallback, callID, sizeof(LeaderboardFindResult_t));

	return callID;*/
	return NULL;
}

SteamAPICall_t SteamUserStats007::FindLeaderboard( const char *pchLeaderboardName )
{
	Log::Debug("SteamUserStats", "Called FindLeaderboard stub");

	/*int leaderboardID = NNI_FindLeaderboard(pchLeaderboardName);

	if(leaderboardID == -1)
	{
		leaderboardID ++;
	}

	SteamAPICall_t callID = Callbacks::RegisterCall();

	LeaderboardFindResult_t* response = (LeaderboardFindResult_t*) malloc(sizeof(LeaderboardFindResult_t));

	response->m_hSteamLeaderboard = leaderboardID;
	response->m_bLeaderboardFound = (leaderboardID == 0) ? 1 : 0;

	Callbacks::Return(response, LeaderboardFindResult_t::k_iCallback, callID, sizeof(LeaderboardFindResult_t));

	return callID;*/
	return NULL;
}

const char* SteamUserStats007::GetLeaderboardName( SteamLeaderboard_t hSteamLeaderboard )
{
	Log::Debug("SteamUserStats", "Called GetLeaderboardName stub");

	return "";
	//return NULL;
}

int SteamUserStats007::GetLeaderboardEntryCount( SteamLeaderboard_t hSteamLeaderboard )
{
	Log::Debug("SteamUserStats", "Called GetLeaderboardEntryCount stub");

	return 0;
	//return NULL;
}

ELeaderboardSortMethod SteamUserStats007::GetLeaderboardSortMethod( SteamLeaderboard_t hSteamLeaderboard )
{
	Log::Debug("SteamUserStats", "Called GetLeaderboardSortMethod stub");

	// Always ascending ;)
	return k_ELeaderboardSortMethodAscending;
}

ELeaderboardDisplayType SteamUserStats007::GetLeaderboardDisplayType( SteamLeaderboard_t hSteamLeaderboard )
{
	Log::Debug("SteamUserStats", "Called GetLeaderboardDisplayType stub");

	return k_ELeaderboardDisplayTypeNumeric;
}

SteamAPICall_t SteamUserStats007::DownloadLeaderboardEntries( SteamLeaderboard_t hSteamLeaderboard, ELeaderboardDataRequest eLeaderboardDataRequest, int nRangeStart, int nRangeEnd )
{
	Log::Debug("SteamUserStats", "Called DownloadLeaderboardEntries stub");

	//NNI_DownloadLeaderboardEntries((long)hSteamLeaderboard, nRangeStart, nRangeEnd);

	//// LeaderboardScoresDownloaded_t
	//SteamAPICall_t callID = Callbacks::RegisterCall();

	//LeaderboardScoresDownloaded_t* response = (LeaderboardScoresDownloaded_t*) malloc(sizeof(LeaderboardScoresDownloaded_t));

	//response->m_hSteamLeaderboard = hSteamLeaderboard;
	//response->m_cEntryCount = nRangeEnd - nRangeStart;
	//response->m_hSteamLeaderboardEntries = hSteamLeaderboard;

	//Callbacks::Return(response, LeaderboardScoresDownloaded_t::k_iCallback, callID, sizeof(LeaderboardScoresDownloaded_t));

	//return callID;
	return NULL;
}


bool SteamUserStats007::GetDownloadedLeaderboardEntry( SteamLeaderboardEntries_t hSteamLeaderboardEntries, int index, LeaderboardEntry001_t *pLeaderboardEntry, int32 *pDetails, int cDetailsMax )
{
	Log::Debug("SteamUserStats", "Called GetDownloadedLeaderboardEntry stub");
	
	/*NNI_LeaderboardEntry* entry = NNI_GetLeaderboardEntry((long)hSteamLeaderboardEntries, (long)(index));
	if(entry == NULL)
	{
		return false;
	}

	pLeaderboardEntry->m_nGlobalRank = 1;
	pLeaderboardEntry->m_nScore = entry->score;
	pLeaderboardEntry->m_steamIDUser = CSteamID(entry->userID, 1, k_EUniversePublic, k_EAccountTypeIndividual);
	pLeaderboardEntry->m_cDetails = entry->detailsCount;

	pDetails = entry->details;*/

	return true;
}

SteamAPICall_t SteamUserStats007::UploadLeaderboardScore( SteamLeaderboard_t hSteamLeaderboard, ELeaderboardUploadScoreMethod eLeaderboardUploadScoreMethod, int32 nScore, int32 *pScoreDetails, int cScoreDetailsCount )
{
	Log::Debug("SteamUserStats", "Called UploadLeaderboardScore stub");

	//NNI_CreateLeaderboardEntry((long)hSteamLeaderboard, cScoreDetailsCount, nScore, pScoreDetails);
	//
	//// LeaderboardScoresDownloaded_t
	//SteamAPICall_t callID = Callbacks::RegisterCall();

	//LeaderboardScoreUploaded_t* response = (LeaderboardScoreUploaded_t*) malloc(sizeof(LeaderboardScoreUploaded_t));

	//response->m_bScoreChanged = true;
	//response->m_bSuccess = 1;
	//response->m_hSteamLeaderboard = hSteamLeaderboard;
	//response->m_nScore = nScore;
	//response->m_nGlobalRankNew = 1;
	//response->m_nGlobalRankPrevious = 1;

	//Callbacks::Return(response, LeaderboardScoreUploaded_t::k_iCallback, callID, sizeof(LeaderboardScoreUploaded_t));

	//return callID;
	return NULL;
}


SteamAPICall_t SteamUserStats007::GetNumberOfCurrentPlayers()
{
	return 0;
}
