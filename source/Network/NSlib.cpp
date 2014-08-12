//#include "Common.h"
//#include "Game/Patches/GamePatches.h"
//#include "Network/NSlib.h"
//#include <Shlwapi.h>
//
//
//#pragma managed
//
////using namespace NSlib::Types;
//
//char username[255];
//char sessionID[32];
//char server[255];
//char lastFriendName[255];
//char lastLeaderboardName[255];
//char lastClanTag[255];
//char lastClanName[255];
//int* lastArray;
//
//void NNI_Init(bool dedicated)
//{
//	bool onlyLocal = false;
//
//	if(NNI::NNIMain::Init(dedicated) == false)
//	{
//		//Log::Error("NetworkService_Init", "Cannot initialize library");
//		if(GamePatches::isMpExe == true)
//		{
//			ModalMessages::ShowError("Error", "Cannot connect to the server");
//			ExitProcess(0x00000002);
//		}
//		else
//		{
//			onlyLocal = true;
//		}
//	}
//
//	if(onlyLocal == false)
//	{
//		while(NNI::NNIMain::VersionCheckDone() == false);
//		
//		if(NNI::NNIMain::VersionOk() == false)
//		{
//			ModalMessages::ShowError("Error", "Please run the updater (force update) to get the new version");
//			ExitProcess(0x00000003);
//		}
//
//		//Log::Debug("Main_DoInit()", "NetworkService OK");
//		if(dedicated == false)
//		{
//			
//		    // Try to login the user
//		    int loginResult = 0;
//
//		    while( (loginResult = NNI_DisplayLogin()) <= 2 )
//		    {
//		    	if(loginResult == -1)
//			    {
//			    	ModalMessages::ShowError("Error", "Client disconnected from Nemexis masterserver");
//			    	ExitProcess(0x00000005);
//			    }
//			    else if(loginResult == 0)
//			    {
//			    	// User closed the form...
//			    	ExitProcess(0x00000006);
//			    }
//			    else if(loginResult == 1)
//			    {
//			    	ModalMessages::ShowError("Error", "Wrong username/password combination");
//			    }
//			    else if(loginResult == 2)
//			    {
//			    	break;
//			    }
//		    }	
//		}
//		else
//		{
//			NNI_StartDedicated();
//		}
//	}
//
//	if(dedicated == false)
//	{
//	    // Display the main interface
//	    if(NNI_DisplayInterface() != 2)
//	    {
//	    	ExitProcess(0x00000007);
//	    }
//	}
//}
//
//int NNI_DisplayLogin()
//{
//	return NNI::NNIMain::DisplayLogin();
//}
//
//void NNI_BanUser(int acType)
//{
//	NNI::NNIMain::BanUser(acType);
//}
//
//void NNI_StartDedicated()
//{
//	NNI::NNIMain::StartDedicated();
//}
//
//char* NNI_GetUsername()
//{
//	System::String^ str = NNI::NNIMain::AccountName;
//
//	int i = 0;
//	for(i = 0; i < str->Length; i ++)
//	{
//		username[i] = (char)str[i];
//	}
//
//	username[i] = '\0';
//
//	return username;
//}
//
//uint32_t NNI_GetAccountID()
//{
//	return (uint32_t)(NNI::NNIMain::ClientID);
//}
//
//int NNI_DisplayInterface()
//{
//	return NNI::NNIMain::DisplayMainInterface();
//}
//
//char* NNI_GetServerAddress()
//{
//	System::String^ str = NNI::NNIMain::Server;
//
//	int i = 0;
//	for(i = 0; i < str->Length; i ++)
//	{
//		server[i] = (char)str[i];
//	}
//
//	server[i] = '\0';
//
//	return server;
//}
//
//char* NNI_GetSessionID()
//{
//	System::String^ str = NNI::NNIMain::SessionID;
//
//	int i = 0;
//	for(i = 0; i < str->Length; i ++)
//	{
//		sessionID[i] = (char)str[i];
//	}
//
//	sessionID[i] = '\0';
//
//	return sessionID;
//}
//
//char* NNI_GetFriendName(int friendID)
//{
//	System::String^ str = NNI::Friends::GetFriendName(friendID);
//
//	int i = 0;
//	for(i = 0; i < str->Length; i ++)
//	{
//		lastFriendName[i] = (char)str[i];
//	}
//
//	lastFriendName[i] = '\0';
//
//	return lastFriendName;
//}
//
//int NNI_GetFriendsCount()
//{
//	return NNI::Friends::GetFriendCount();
//}
//
//int NNI_GetFriendById(int id)
//{
//	return NNI::Friends::GetFriendById(id);
//}
//
//bool NNI_IsFriendOf(int id)
//{
//	return NNI::Friends::IsFriend(id);
//}
//
//bool NNI_IsFriendOnline(int id)
//{
//	return NNI::Friends::IsFriendOnline(id);
//}
//
//void NNI_CreateLeaderboard(const char* leaderboardName)
//{
//	System::String^ name = gcnew String(leaderboardName);
//
//	NNI::Services::LeaderboardsService::CreateLeaderboard(name);
//}
//
//int NNI_FindLeaderboard(const char* leaderboardName)
//{
//	System::String^ name = gcnew String(leaderboardName);
//
//	return NNI::Services::LeaderboardsService::FindLeaderboard(name);
//}
//
//void NNI_CreateLeaderboardEntry(long leaderboardID, int detailsCount, int score, int* details)
//{
//	cli::array<int, 1>^ detailsManaged;
//
//	for(int i = 0; i < detailsCount; i ++)
//	{
//		detailsManaged->SetValue(details[i], i);
//	}
//
//	NNI::Services::LeaderboardsService::AddLeaderboardEntry(leaderboardID, score, detailsManaged, detailsCount);
//}
//
//int NNI_GetLeaderboardsEntryCount(long leaderboardID)
//{
//	return NNI::Services::LeaderboardsService::GetLeaderboardsEntryCount(leaderboardID);
//}
//
//char* NNI_GetLeaderboardName(long leaderboardID)
//{
//	System::String^ str = NNI::Services::LeaderboardsService::GetLeaderboardName(leaderboardID);
//
//	int i = 0;
//	for(i = 0; i < str->Length; i ++)
//	{
//		lastLeaderboardName[i] = (char)str[i];
//	}
//
//	lastLeaderboardName[i] = '\0';
//
//	return lastLeaderboardName;
//}
//
//void NNI_DownloadLeaderboardEntries(long leaderboardID, int min, int max)
//{
//	NNI::Services::LeaderboardsService::DownloadLeaderboardsEntries(leaderboardID, min, max);
//}
//
//NNI_LeaderboardEntry* NNI_GetLeaderboardEntry(long leaderboardID, long entryID)
//{
//	NSLib::Types::LeaderboardEntry^ entry;
//	try
//	{
//		entry = NNI::Services::LeaderboardsService::GetLeaderboardEntry(leaderboardID, entryID);
//
//		NNI_LeaderboardEntry* common = (NNI_LeaderboardEntry*)malloc(sizeof(NNI_LeaderboardEntry));
//
//		common->detailsCount = entry->detailsCount;
//		common->score = entry->score;
//		common->userID = (int)(entry->userID);
//		common->details = Array_CLIToArray(entry->details);
//
//		return common;
//	}
//	catch(Exception^ ex)
//	{
//		return NULL;
//	}
//	//return NULL;
//}
//
//int* Array_CLIToArray(cli::array<int, 1>^ input)
//{
//	lastArray = (int*)(malloc(sizeof(int) * input->Length));
//
//	int i = 0;
//
//	for each(int value in input)
//	{
//		lastArray[i] = value;
//
//		i++;
//	}
//
//	return lastArray;
//}
//
//char* NNI_GetClanTag(long clanID)
//{
//	System::String^ str = NNI::NNIMain::ClanTag;
//
//	int i = 0;
//	for(i = 0; i < str->Length; i ++)
//	{
//		lastClanTag[i] = (char)str[i];
//	}
//
//	lastClanTag[i] = '\0';
//
//	return lastClanTag;
//}
//
//char* NNI_GetClanName(long clanID)
//{
//	System::String^ str = NNI::NNIMain::ClanName;
//
//	int i = 0;
//	for(i = 0; i < str->Length; i ++)
//	{
//		lastClanName[i] = (char)str[i];
//	}
//
//	lastClanName[i] = '\0';
//
//	return lastClanName;
//}
//
//int NNI_GetClanCount()
//{
//	return NNI::Services::ClanService::GetClanCount();
//}
//
//bool NNI_IsUserInClan(long userID)
//{
//	return NNI::Services::ClanService::IsUserInClan(userID);
//}
//
//bool NNI_IsFriendInAnyServer(long userID)
//{
//	return NNI::Services::FriendsService::IsFriendInAnyServer(userID);
//}
//
//int NNI_GetFriendsCountByClan(long clanID)
//{
//	return NNI::Services::FriendsService::GetFriendsCountByClan(clanID);
//}
//
//int NNI_GetFriendsCountByServer(long serverID)
//{
//	return NNI::Services::FriendsService::GetFriendsCountByServer(serverID);
//}
//
//int NNI_GetFriendsFromClanByIndex(int index, long clanID)
//{
//	return NNI::Services::FriendsService::GetFriendFromClanByIndex(index, clanID);
//}
//
//int NNI_GetFriendsFromServerByIndex(int index, long serverID)
//{
//	return NNI::Services::FriendsService::GetFriendFromServerByIndex(index, serverID);
//}
//
//bool NNI_IsFriendInClan(long friendID, long clanID)
//{
//	return NNI::Services::FriendsService::IsFriendInClan(friendID, clanID);
//}
//
//bool NNI_IsFriendInServer(long friendID, long serverID)
//{
//	return NNI::Services::FriendsService::IsFriendInServer(friendID, serverID);
//}
//
//long NNI_CACValidationServerID()
//{
//	return NNI::NNIMain::CACServerID;
//}