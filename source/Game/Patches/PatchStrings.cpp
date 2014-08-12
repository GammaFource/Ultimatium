 /*==========================================================
 GammaForce operation

 Project: Ultimatium
 Game: Black Ops (T5)
 Module: Steam_api emulator
 Reason of existance: Some brand string patches.

 Author: FaceTaker
 ==========================================================*/
#include "Common.h"

void PatchStrings()
{	
	strcpy((char*)0xA575A4, "Ultimatium Version: " ver);
	strcpy((char*)0xA92684, "COD_ULTIMATIUM_MP");	
	strcpy((char*)0xA59C0C, "Welcome on Ultimatium!!!");
	strcpy((char*)0xA8BA78, "GammaForce"); 
	strcpy((char*)0xAC2590, "GammaForce"); 
	strcpy((char*)0xA307F0, "GammaForce"); 
	strcpy((char*)0xA7BE40, "GammaForce");
	strcpy((char*)0xAC16B4, "Could not connect to GammaForce's DemonWare master server. Please, try again later.");		
	strcpy((char*)0xA28DF4, "UltimPublic"); 
	strcpy((char*)0xA2CA70, "UltimPrivate"); 	
	strcpy((char*)0xA52590, "Welcome to Ultimatium!");	
	strcpy((char*)0xAB3EF8, "Ultimatium Console"); 
}