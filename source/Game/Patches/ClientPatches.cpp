/*==========================================================
GammaForce operation

Project: Ultimatium
Game: Black Ops (T5)
Module: Steam_api emulator
Reason of existance: Basic client patches.

Author: FaceTaker
==========================================================*/

#include "Common.h"
#include "Game/Patches/ClientPatches.h"
#include "Steam/SteamCommon.h"
#include "Steam/SteamAPI.h"

#pragma unmanaged
void PatchStrings();
void UI_AddString(const char* str, const char* replc);
void PatchOps_UIStrings();
void PatchMP();
void PatchSP();
void PatchSPStrings();
void PatchMPDedicated();
bool InitializeVTIAuth(char* username, char* password);
bool InitializeVTIDedicatedAuth();

hostent* WINAPI custom_gethostbyname(const char* name)
{	
	char* hostname = (char*)name;
	hostname = "127.0.0.1";
	return gethostbyname(hostname);
}

bool InitSystem(char* username, char* password, bool dedicated)
{
	if (!dedicated)
	{
		if (strcmp("CoDBlackOps", (char*)0xA203BC) == 0)
		{
			//If we want our system to log everything
			Log::Init("debug.txt", LogLevel_All);

			PatchMP();
			PatchStrings();
			PatchOps_UIStrings();
			return InitializeVTIAuth(username, password);
		}
		else if (strcmp("BlackOpsZombie", (char*)0x9BCD68) == 0)
		{
			PatchSP();
			PatchSPStrings();
			return InitializeVTIAuth(username, password);
		}
		else
		{
			ExitProcess(0x1);
			return false;			
		}
	}
	else if (strcmp("CoDBlackOps", (char*)0xA203BC) == 0)
	{
		PatchMPDedicated();
		PatchStrings();
		return InitializeVTIDedicatedAuth();
	}
	else
	{
		MessageBoxW(NULL, L"Unable to find the correct version of the game.", L"Error", MB_OK | MB_ICONERROR);
		ExitProcess(0x1);
	}
}

void PatchMP()
{		
	*(DWORD*)0xA124A4 = (DWORD)custom_gethostbyname;	
	*(BYTE*)0x8B9C04 = 0xEB;		

	//UI string patches (thanks to vorhon for this part)
	UI_AddString("TICKER_MESSAGE_CATEGORY_COD_CAPS", "GammaForce");
	UI_AddString("MENU_MULTIPLAYER_CAPS", "GAMMAFORCE");
	UI_AddString("TICKER_MESSAGE_CATEGORY_COD_CAPS", "GammaForce");
	UI_AddString("TICKER_MESSAGE_DEFAULT_OFFLINE", "GammaForce rocks, btw.");
}

void PatchMPDedicated()
{
	*(DWORD*)0xA124A4 = (DWORD)custom_gethostbyname;
	*(DWORD*)0x406E83 = 0x39A5F38;
	*(BYTE*)0x87C0EF = 0xEB;
	*(BYTE*)0x8B9C04 = 0xEB;
	memset((void*)0x87C0E5, 0x90, 5);
}
