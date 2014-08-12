/*==========================================================
GammaForce operation

Project: Ultimatium
Game: Black Ops (T5)
Module: Steam_api emulator
Reason of existance: User interface string patches.

Author: FaceTaker
==========================================================*/

/*==========================================================
All credits goes to vorhon for this
==========================================================*/

#include "Common.h"


void *DetourFunction(BYTE *source, const BYTE *destination, const int length)
{
	BYTE *jmp = (BYTE *)malloc(length + 5);
	DWORD dwBack;

	VirtualProtect(source, length, PAGE_EXECUTE_READWRITE, &dwBack);

	memcpy(jmp, source, length);
	jmp += length;

	jmp[0] = 0xE9;
	*(DWORD *)(jmp + 1) = (DWORD)(source + length - jmp) - 5;

	source[0] = 0xE9;
	*(DWORD*)(source + 1) = (DWORD)(destination - source) - 5;

	for (int i = 5; i < length; i++)
	{
		source[i] = 0x90;
	}

	VirtualProtect(source, length, dwBack, &dwBack);

	return (jmp - length);
}

#define TRANSLSTRING 0x420CB0

map<const char*, const char*> uiStrings;
typedef map<const char*, const char*>::iterator uiStringsItr;

const char*(__cdecl* o_UI_TranslateString)(const char*);

void UI_AddString(const char* str, const char* replc)
{
	if (str && replc)
	{
		uiStrings.insert(make_pair(str, replc));
	}
}

void UI_RemoveString(const char* str)
{
	if (str)
	{
		for (uiStringsItr itr = uiStrings.begin();
			itr != uiStrings.end(); itr++)
		{
			if (_stricmp(itr->first, str) == 0)
			{
				uiStrings.erase(itr);
				itr++;
			}
		}
	}
}

bool UI_IsStringAvailable()
{
	return !uiStrings.empty();
}

bool UI_CleanStringsList()
{
	if (!UI_IsStringAvailable())
	{
		return false;
	}

	uiStrings.clear();
	return true;
}

const char* UI_TranslateString(const char* str)
{
	if (UI_IsStringAvailable())
	{
		for (uiStringsItr itr = uiStrings.begin();
			itr != uiStrings.end(); itr++)
		{
			if (_stricmp(itr->first, str) == 0)
			{
				return itr->second;
			}
		}
	}

	return o_UI_TranslateString(str);
}

DWORD strjmp = 0x4A09B5;

void __declspec(naked) UI_TranslateStringStub()
{
	__asm
	{
		mov eax, [esp + 4]
			push eax
			call UI_TranslateString
			add esp, 4

			test al, al
			jz jmpToFunc

			retn

		jmpToFunc :
		mov eax, 58C0A18h
			jmp strjmp
	}
}

void PatchOps_UIStrings()
{
	o_UI_TranslateString = (const char*(__cdecl*)(const char*))
		DetourFunction((PBYTE)TRANSLSTRING, (PBYTE)UI_TranslateString, 5);
}