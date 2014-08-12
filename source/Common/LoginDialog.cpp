/*==========================================================
GammaForce operation

Project: Ultimatium
Game: Black Ops (T5)
Module: Steam_api emulator
Reason of existance: Ask for user credintials.

Author: FaceTaker
==========================================================*/

#include "include\Common.h"
#include <tchar.h>
#include <wincred.h>
#include <Shlwapi.h>
#pragma unmanaged
bool InitSystem(char* username, char* password, bool dedicated);
char AuthUsername[CREDUI_MAX_USERNAME_LENGTH];
char AuthPassword[CREDUI_MAX_PASSWORD_LENGTH];
bool DisplayLoginForm(const wchar_t** wusername, const wchar_t** wpassword)
{
	CREDUI_INFOW info;
	static WCHAR username[CREDUI_MAX_USERNAME_LENGTH * sizeof(WCHAR)] = { 0 };
	static WCHAR password[CREDUI_MAX_PASSWORD_LENGTH * sizeof(WCHAR)] = { 0 };
	DWORD uLen = CREDUI_MAX_USERNAME_LENGTH;
	DWORD pLen = CREDUI_MAX_PASSWORD_LENGTH;
	LPVOID outStuff;
	ULONG outSize = 0;
	ULONG outPackage = 0;
	BOOL save = false;
	memset(&info, 0, sizeof(info));
	info.cbSize = sizeof(info);
	info.pszCaptionText = L"Authentication for Ultimatium";
	info.pszMessageText = L"Please log in using your forum credentials.";
	HRESULT result = CredUIPromptForWindowsCredentialsW(&info, 0, &outPackage, NULL, 0, &outStuff, &outSize, NULL, CREDUIWIN_GENERIC);
	if (result == ERROR_SUCCESS)
	{
		CredUnPackAuthenticationBufferW(0, outStuff, outSize, username, &uLen, NULL, 0, password, &pLen);
		*wusername = username;
		*wpassword = password;
	}
	return (result == ERROR_SUCCESS);
}

void BeginAuth()
{
	const wchar_t* user;
	const wchar_t* pass;
	bool aborted = false;	
	while (!aborted)
	{
		aborted = !DisplayLoginForm(&user, &pass);

		if (!aborted)
		{
			char username[CREDUI_MAX_USERNAME_LENGTH];
			char password[CREDUI_MAX_PASSWORD_LENGTH];
			WideCharToMultiByte(CP_UTF8, 0, user, -1, username, sizeof(username), NULL, NULL);
			WideCharToMultiByte(CP_UTF8, 0, pass, -1, password, sizeof(password), NULL, NULL);		

			strncpy(AuthUsername, username, sizeof(username));
			strncpy(AuthPassword, password, sizeof(password));

			bool result = InitSystem(AuthUsername, AuthPassword, false);

			if (result)
			{
				return;
			}
		}

		
	}
}

void AuthDedicated()
{
	bool result = InitSystem("", "", true);
	if (!result)
	{
		MessageBoxW(NULL, L"Could not initiate your dedicated session, please try again.", L"Error", MB_OK | MB_ICONERROR);
	}
}