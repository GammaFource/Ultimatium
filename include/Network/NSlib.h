#ifndef __NSLIB_H__
#define __NSLIB_H__

struct NNI_LeaderboardEntry
{
	int* details;
	int score;
	int userID;
	int detailsCount;
};

void NNI_Init(bool dedicated);
void NNI_StartDedicated();
void NNI_BanUser(int acType);
int NNI_DisplayLogin();
int NNI_DisplayInterface();
char* NNI_GetUsername();
uint32_t NNI_GetAccountID();
char* NNI_GetServerAddress();
char* NNI_GetSessionID();
char* NNI_GetFriendName(int friendID);
int NNI_GetFriendsCount();
int NNI_GetFriendById(int id);
bool NNI_IsFriendOf(int id);
bool NNI_IsFriendOnline(int id);
void NNI_CreateLeaderboard(const char* leaderboardName);
int NNI_FindLeaderboard(const char* leaderboardName);
void NNI_CreateLeaderboardEntry(long leaderboardID, int detailsCount, int score, int* details);
int NNI_GetLeaderboardsEntryCount(long leaderboardID);
char* NNI_GetLeaderboardName(long leaderboardID);
void NNI_DownloadLeaderboardEntries(long leaderboardID, int min, int max);
NNI_LeaderboardEntry* NNI_GetLeaderboardEntry(long leaderboardID, long entryID);
//NNI_LeaderboardEntry* LeaderboardEntry;
int* Array_CLIToArray(cli::array<int, 1>^ input);
char* NNI_GetClanTag(long clanID);
char* NNI_GetClanName(long clanID);
int NNI_GetClanCount();
bool NNI_IsUserInClan(long clientID);
bool NNI_IsFriendInAnyServer(long clientID);
int NNI_GetFriendsCountByClan(long clanID);
int NNI_GetFriendsCountByServer(long serverID);
int NNI_GetFriendsFromClanByIndex(int index, long clanID);
int NNI_GetFriendsFromServerByIndex(int index, long clanID);
bool NNI_IsFriendInClan(long friendID, long clanID);
bool NNI_IsFriendInServer(long friendID, long serverID);
long NNI_CACValidationServerID();

#endif /* __NSLIB_H__ */