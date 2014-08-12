/*==========================================================
GammaForce operation

Project: Ultimatium
Game: Black Ops (T5)
Module: Steam_api emulator
Reason of existance: Steam needed functions.

Author: FaceTaker
==========================================================*/

#include "Common.h"
#include "Steam/SteamCommon.h"
#include "VTILib.h"

#pragma managed

using namespace System;
CSteamID* SteamCommon::steamID = NULL;
char SteamCommon::encryptedAppTicket[128];
void SteamCommon::Init()
{
	steamID = new CSteamID(VTI_GetSelfVultrotID(), 1, k_EUniversePublic, k_EAccountTypeIndividual);		
}

SteamAPICall_t SteamCommon::RequestEncryptedAppTicket(const void *pUserData, int cbUserData)
{
	Log::Trace("SteamCommon", "Requested encrypted App ticket");

	uint64 userID = GetSteamID()->ConvertToUint64();

	// Fill the ticket with the info
	memset(encryptedAppTicket, 0, sizeof(encryptedAppTicket));

	strcpy((char*)encryptedAppTicket, VTI_GetSID());
	memcpy(&encryptedAppTicket[32], pUserData, min(cbUserData, sizeof(encryptedAppTicket)));
	memcpy(&encryptedAppTicket[cbUserData + 32], &userID, sizeof( userID ));

	// Register the calls
	SteamAPICall_t callID = Callbacks::RegisterCall();

	EncryptedAppTicketResponse_t* response = (EncryptedAppTicketResponse_t*) malloc(sizeof(EncryptedAppTicketResponse_t));
	response->m_eResult = k_EResultOK;

	Callbacks::Return(response, EncryptedAppTicketResponse_t::k_iCallback, callID, sizeof(EncryptedAppTicketResponse_t));

	// Return the callID
	return callID;
}

CSteamID* SteamCommon::GetSteamID()
{
	steamID = new CSteamID(VTI_GetSelfVultrotID(), 1, k_EUniversePublic, k_EAccountTypeIndividual);
	return steamID;
}

char* SteamCommon::GetEncryptedAppTicket()
{
	Log::Debug("SteamCommon", "Returning Encrypted AppTicket");

	return encryptedAppTicket;
}

char* SteamCommon::GetPlayerName()
{
	char* username = VTI_GetSelfNickname();

	Log::Debug("SteamCommon", "Username %s", username);

	return username;
}

void SteamCommon::SetPlayerName(const char* newName)
{
	
}

