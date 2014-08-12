/*==========================================================
GammaForce operation

Project: Ultimatium
Game: Black Ops (T5)
Module: Steam_api emulator
Reason of existance: Patch some strings for SP mode.

Author: FaceTaker
==========================================================*/

#include "include\Common.h"

void PatchSPStrings()
{	
	strcpy((char*)0x9D839C, "Ultimatium Version: " ver);	
	strcpy((char*)0x9E94C0, "Ultimatium");	
}