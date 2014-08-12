#ifndef __STEAMFRIENDS007_H__
#define __STEAMFRIENDS007_H__

#include "Common.h"

class SteamFriends007 : public ISteamFriends007
{
public:
	const char* GetPersonaName();
	void SetPersonaName(const char* pchPersonaName);
	EPersonaState GetPersonaState();
	int GetFriendCount(EFriendFlags eFriendFlags);
	CSteamID GetFriendByIndex(int iFriend, int iFriendFlags);
	EFriendRelationship GetFriendRelationship(CSteamID steamIDFriend);
	EPersonaState GetFriendPersonaState(CSteamID steamIDFriend);
	const char* GetFriendPersonaName(CSteamID steamIDFriend);
	bool GetFriendGamePlayed(CSteamID steamIDFriend, FriendGameInfo_t* pFriendGameInfo);
	const char* GetFriendPersonaNameHistory(CSteamID steamIDFriend, int iPeronaName);
	bool HasFriend(CSteamID steamIDFriend, EFriendFlags eFriendFlags);
	int GetClanCount();
	CSteamID GetClanByIndex(int iClan);
	const char* GetClanName(CSteamID steamIDClan);
	const char* GetClanTag(CSteamID steamIDClan);
	int GetFriendCountFromSource(CSteamID steamIDSource);
	CSteamID GetFriendFromSourceByIndex(CSteamID steamIDSource, int iFriend);
	bool IsUserInSource(CSteamID steamIDUser, CSteamID steamIDSource);
	void SetInGameVoiceSpeaking(CSteamID steamIDUser, bool bSpeaking);
	void ActivateGameOverlay(const char* pchDialog);
	void ActivateGameOverlayToUser(const char* pchDialog, CSteamID steamID);
	void ActivateGameOverlayToWebPage(const char* pchUrl);
	void ActivateGameOverlayToStore(AppId_t nAppID);
	void SetPlayedWith(CSteamID steamIDUserPlayedWith);
	void ActivateGameOverlayInviteDialog(CSteamID steamIDLobby);
	int GetSmallFriendAvatar(CSteamID steamIDFriend);
	int GetMediumFriendAvatar(CSteamID steamIDFriend);
	int GetLargeFriendAvatar(CSteamID steamIDFriend);
};

#endif /* __STEAMFRIENDS007_H__ */