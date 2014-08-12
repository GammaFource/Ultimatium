/*==========================================================
GammaForce operation

Project: Ultimatium
Game: Black Ops (T5)
Module: Steam_api emulator
Reason of existance: Basic client patches.

Author: FaceTaker
==========================================================*/

#include "include\Common.h"

hostent* WINAPI custom_gethostbyname(const char* name);

void PatchSP()
{
	*(DWORD*)0x9A3470 = (DWORD)custom_gethostbyname;
	*(WORD*)0x693842 = 0x9090;	
}