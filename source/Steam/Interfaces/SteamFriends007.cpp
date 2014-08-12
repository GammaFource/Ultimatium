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

const char* SteamFriends007::GetPersonaName()
{
	Log::Debug("SteamFriends007", "Called GetPersonaName stub");

	char* username = SteamCommon::GetPlayerName();

	return username;
}

void SteamFriends007::SetPersonaName(const char* pchPersonaName)
{
	Log::Debug("SteamFriends007", "Called SetPersonaName stub");
	SteamCommon::SetPlayerName(pchPersonaName);
}

EPersonaState SteamFriends007::GetPersonaState()
{
	Log::Debug("SteamFriends007", "Called GetPersonaState stub");
	return k_EPersonaStateOnline;
}

int SteamFriends007::GetFriendCount(EFriendFlags eFriendFlags)
{
	Log::Debug("SteamFriends007", "Called GetFriendCount stub");
	return VTI_GetFriendCount();
}

CSteamID SteamFriends007::GetFriendByIndex(int iFriend, int iFriendFlags)
{
	Log::Debug("SteamFriends007", "Called GetFriendByIndex stub");
	return CSteamID(VTI_GetFriendByID(iFriend), k_EUniversePublic, k_EAccountTypeIndividual);
}

EFriendRelationship SteamFriends007::GetFriendRelationship(CSteamID steamIDFriend)
{
	Log::Debug("SteamFriends007", "Called GetFriendRelationship stub");
	

	return k_EFriendRelationshipFriend;
}

EPersonaState SteamFriends007::GetFriendPersonaState(CSteamID steamIDFriend)
{
	Log::Debug("SteamFriends007", "Called GetFriendPersonaState stub");
	

	return VTI_GetFriendState(steamIDFriend.GetAccountID());
}

const char* SteamFriends007::GetFriendPersonaName(CSteamID steamIDFriend)
{
	Log::Debug("SteamFriends007", "Called GetFriendPersonaName stub");
	return VTI_GetFriendName(steamIDFriend.GetAccountID());
}

bool SteamFriends007::GetFriendGamePlayed(CSteamID steamIDFriend, FriendGameInfo_t* pFriendGameInfo)
{
	Log::Debug("SteamFriends007", "Called GetFriendGamePlayed stub");
	return true;
}

const char* SteamFriends007::GetFriendPersonaNameHistory(CSteamID steamIDFriend, int iPeronaName)
{
	Log::Debug("SteamFriends007", "Called GetFriendPersonaNameHistory stub");
	return VTI_GetFriendName(steamIDFriend.GetAccountID());
}

bool SteamFriends007::HasFriend(CSteamID steamIDFriend, EFriendFlags eFriendFlags)
{
	Log::Debug("SteamFriends007", "Called HasFriend stub");
	return false;
}

int SteamFriends007::GetClanCount()
{	
	return NULL;
}

CSteamID SteamFriends007::GetClanByIndex(int iClan)
{
	Log::Debug("SteamFriends007", "Called GetClanByIndex stub");
	return CSteamID(iClan, k_EUniversePublic, k_EAccountTypeClan);
}

const char* SteamFriends007::GetClanName(CSteamID steamIDClan)
{
	Log::Debug("SteamFriends007", "Called GetClanName stub");
	return "";	
}

const char* SteamFriends007::GetClanTag(CSteamID steamIDClan)
{
	Log::Debug("SteamFriends007", "Called GetClanTag stub");	
	return "test34";
}

int SteamFriends007::GetFriendCountFromSource(CSteamID steamIDSource)
{
	Log::Debug("SteamFriends007", "Called GetFriendCountFromSource stub");
	return 0;
}

CSteamID SteamFriends007::GetFriendFromSourceByIndex(CSteamID steamIDSource, int iFriend)
{
	Log::Debug("SteamFriends007", "Called GetFriendFromSourceByIndex stub");
	return CSteamID();
	
}

bool SteamFriends007::IsUserInSource(CSteamID steamIDUser, CSteamID steamIDSource)
{
	Log::Debug("SteamFriends007", "Called IsUserInSource stub");	
	return false;
	
}

void SteamFriends007::SetInGameVoiceSpeaking(CSteamID steamIDUser, bool bSpeaking)
{
	Log::Debug("SteamFriends007", "Called SetInGameVoiceSpeaking stub");
}

void SteamFriends007::ActivateGameOverlay(const char* pchDialog)
{
	Log::Debug("SteamFriends007", "Called ActivateGameOverlay stub");
}

void SteamFriends007::ActivateGameOverlayToUser(const char* pchDialog, CSteamID steamID)
{
	Log::Debug("SteamFriends007", "Called ActivateGameOverlayToUser stub");
}

void SteamFriends007::ActivateGameOverlayToWebPage(const char* pchUrl)
{
	Log::Debug("SteamFriends007", "Called ActivateGameOverlayToWebPage stub");
}

void SteamFriends007::ActivateGameOverlayToStore(AppId_t nAppID)
{
	Log::Debug("SteamFriends007", "Called ActivateGameOverlayToStore stub");
}

void SteamFriends007::SetPlayedWith(CSteamID steamIDUserPlayedWith)
{
	Log::Debug("SteamFriends007", "Called SetPlayedWith stub");
}

void SteamFriends007::ActivateGameOverlayInviteDialog(CSteamID steamIDLobby)
{
	Log::Debug("SteamFriends007", "Called ActivateGameOverlayInviteDialog stub");
}

int SteamFriends007::GetSmallFriendAvatar(CSteamID steamIDFriend)
{
	Log::Debug("SteamFriends007", "Called GetSmallFriendAvatar stub");
	return 0;
}

int SteamFriends007::GetMediumFriendAvatar(CSteamID steamIDFriend)
{
	Log::Debug("SteamFriends007", "Called GetMediumFriendAvatar stub");
	return 0;
}

int SteamFriends007::GetLargeFriendAvatar(CSteamID steamIDFriend)
{
	Log::Debug("SteamFriends007", "Called GetLargeFriendAvatar stub");
	return 0;
}
