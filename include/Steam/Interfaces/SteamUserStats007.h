#ifndef __STEAMUSERSTATS007_H__
#define __STEAMUSERSTATS007_H__

#include "Common.h"

class SteamUserStats007 : public ISteamUserStats007
{
public:
	bool RequestCurrentStats();
	bool GetStat( const char *pchName, int32 *pData );
	bool GetStat( const char *pchName, float *pData );
	bool SetStat( const char *pchName, int32 nData );
	bool SetStat( const char *pchName, float fData );
	bool UpdateAvgRateStat( const char *pchName, float flCountThisSession, double dSessionLength );
	bool GetAchievement( const char *pchName, bool *pbAchieved );
	bool SetAchievement( const char *pchName );
	bool ClearAchievement( const char *pchName );
	bool GetAchievementAndUnlockTime( const char *pchName, bool *pbAchieved, RTime32 *prtTime );
	bool StoreStats();
	int GetAchievementIcon( const char *pchName );
	const char *GetAchievementDisplayAttribute( const char *pchName, const char *pchKey );
	bool IndicateAchievementProgress( const char *pchName, uint32 nCurProgress, uint32 nMaxProgress );
	SteamAPICall_t RequestUserStats( CSteamID steamIDUser );
	bool GetUserStat( CSteamID steamIDUser, const char *pchName, int32 *pData );
	bool GetUserStat( CSteamID steamIDUser, const char *pchName, float *pData );
	bool GetUserAchievement( CSteamID steamIDUser, const char *pchName, bool *pbAchieved );
	bool GetUserAchievementAndUnlockTime( CSteamID steamIDUser, const char *pchName, bool *pbAchieved, RTime32 *prtTime );
	bool ResetAllStats( bool bAchievementsToo );
	SteamAPICall_t FindOrCreateLeaderboard( const char *pchLeaderboardName, ELeaderboardSortMethod eLeaderboardSortMethod, ELeaderboardDisplayType eLeaderboardDisplayType );
	SteamAPICall_t FindLeaderboard( const char *pchLeaderboardName );
	const char *GetLeaderboardName( SteamLeaderboard_t hSteamLeaderboard );
	int GetLeaderboardEntryCount( SteamLeaderboard_t hSteamLeaderboard );
	ELeaderboardSortMethod GetLeaderboardSortMethod( SteamLeaderboard_t hSteamLeaderboard );
	ELeaderboardDisplayType GetLeaderboardDisplayType( SteamLeaderboard_t hSteamLeaderboard );
	SteamAPICall_t DownloadLeaderboardEntries( SteamLeaderboard_t hSteamLeaderboard, ELeaderboardDataRequest eLeaderboardDataRequest, int nRangeStart, int nRangeEnd );
	bool GetDownloadedLeaderboardEntry( SteamLeaderboardEntries_t hSteamLeaderboardEntries, int index, LeaderboardEntry001_t *pLeaderboardEntry, int32 *pDetails, int cDetailsMax );
	SteamAPICall_t UploadLeaderboardScore( SteamLeaderboard_t hSteamLeaderboard,ELeaderboardUploadScoreMethod eLeaderboardUploadScoreMethod, int32 nScore, int32 *pScoreDetails, int cScoreDetailsCount );
	SteamAPICall_t GetNumberOfCurrentPlayers();
};

#endif /* __STEAMUSERSTATS007_H__ */