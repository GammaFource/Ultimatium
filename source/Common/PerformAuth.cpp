/*==========================================================
GammaForce operation

Project: Ultimatium
Game: Black Ops (T5)
Module: Steam_api emulator
Reason of existance: VTI Auth function calls.

Author: FaceTaker
==========================================================*/

#include "include\Common.h"
#include "VTAuth.h"

bool InitializeVTIAuth(char* username, char* password)
{
	if (!VTI_Initialize())
	{
		MessageBoxW(NULL, L"Unable to initiate VTILib, contact support", L"Error", MB_OK | MB_ICONERROR);
		ExitProcess(0x1);
		return false;
	}
	if (!VTI_Connect("127.0.0.1", 4088))
	{
		MessageBoxW(NULL, L"VTI Server may be offline or under maintenance. Please try again later", L"Error", MB_OK | MB_ICONERROR);
		ExitProcess(0x1);
		return false;
	}	
	IEntityDef* def = VTI_PerformAuth(1, username, password);
	if (def->m_eAuthResult == k_EAuthResponseWrongUsername)
	{
		MessageBoxW(NULL, L"Your login details are unable to get verified. Please try again", L"Error", MB_OK | MB_ICONERROR);		
		return false;
	}
	else if (def->m_eAuthResult == k_EAuthResponseWrongPassword)
	{
		MessageBoxW(NULL, L"Your login details are unable to get verified. Please try again", L"Error", MB_OK | MB_ICONERROR);		
		return false;
	}
	else if (def->m_eAuthResult == k_EAuthResponseBanned)
	{
		MessageBoxW(NULL, L"Youare banned from GammaForce", L"Error", MB_OK | MB_ICONERROR);
		ExitProcess(0x1);
		return false;
	}
	else if (def->m_eAuthResult == k_EAuthResponseAccountInUse)
	{
		MessageBoxW(NULL, L"Your account is aready online", L"Error", MB_OK | MB_ICONERROR);
		ExitProcess(0x1);
		return false;
	}
	else if (def->m_eAuthResult == k_EAuthResponseUnknown)
	{
		MessageBoxW(NULL, L"Your login details are unable to get verified. Please try again", L"Error", MB_OK | MB_ICONERROR);		
		return false;
	}	
	return true;
}

bool InitializeVTIDedicatedAuth()
{	
	return true;
}