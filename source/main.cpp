/*==========================================================
GammaForce operation

Project: Ultimatium
Game: Black Ops (T5)
Module: Steam_api emulator
Reason of existance: The entrance of our dll.

Author: FaceTaker
==========================================================*/

#include "Common.h"
#include "Steam/SteamAPI.h"
#include "Steam/SteamCommon.h"
#include "Game/Patches/ClientPatches.h"
#include <Shlwapi.h>

#pragma unmanaged
DWORD dwOldProtect, dwNewProtect;
void BeginAuth();
void AuthDedicated();
static BYTE originalCode[5];
static PBYTE originalEP = 0;

void Main_UnprotectModule(HMODULE hModule)
{
	PIMAGE_DOS_HEADER header = (PIMAGE_DOS_HEADER)hModule;
	PIMAGE_NT_HEADERS ntHeader = (PIMAGE_NT_HEADERS)((DWORD)hModule + header->e_lfanew);	
	SIZE_T size = ntHeader->OptionalHeader.SizeOfImage;
	DWORD oldProtect;
	VirtualProtect((LPVOID)hModule, size, PAGE_EXECUTE_READWRITE, &oldProtect);
}

void Sys_RunInit();

void Main_DoInit()
{	
	HMODULE hModule;
	if (SUCCEEDED(GetModuleHandleEx(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS, (LPCSTR)Main_DoInit, &hModule)))
	{
		Main_UnprotectModule(hModule);
	}
	if (StrStrI(GetCommandLine(), "dedicated") == NULL)
	{
		BeginAuth();
	}
	else
	{
		AuthDedicated();		
	}	
	memcpy(originalEP, &originalCode, sizeof(originalCode));
	__asm jmp originalEP
}

void Main_SetSafeInit()
{	
	HMODULE hModule = GetModuleHandle(NULL); 
	if (hModule)
	{
		PIMAGE_DOS_HEADER header = (PIMAGE_DOS_HEADER)hModule;
		PIMAGE_NT_HEADERS ntHeader = (PIMAGE_NT_HEADERS)((DWORD)hModule + header->e_lfanew);
		Main_UnprotectModule(hModule);		
		PBYTE ep = (PBYTE)((DWORD)hModule + ntHeader->OptionalHeader.AddressOfEntryPoint);
		memcpy(originalCode, ep, sizeof(originalCode));		
		int newEP = (int)Main_DoInit - ((int)ep + 5);
		ep[0] = 0xE9; 
		memcpy(&ep[1], &newEP, 4);
		originalEP = ep;
	}
}

BOOL APIENTRY DllMain( HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved )
{
	if( ul_reason_for_call == DLL_PROCESS_ATTACH )
	{
		Main_SetSafeInit();
	}
	return TRUE;
}
