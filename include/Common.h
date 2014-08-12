#ifndef __COMMON_H__
#define __COMMON_H__

#pragma comment(lib, "kernel32.lib")
#define _WIN32_WINNT 0x0502
using namespace std;
#include <Windows.h>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <sys/stat.h>
#include <vector>
#include <WinSock.h>
#include "Steam/OpenSteamWorks/SteamTypes.h"
#include "Steam/OpenSteamWorks/Steamclient.h"
#include "Steam/OpenSteamWorks/Interface_OSW.h"
#include "Steam/OpenSteamWorks/SteamAPI.h"
#include "Steam/Callbacks.h"
#include <stdint.h>
#include "Common/Log.h"
#include "SteamClient.h"
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdio.h>
#include <map>
#include "Version.h"
char* GetUserNameFromVTI();
char* GetSIDFromVTI();
int GetUserIDFromVTI();
#define GF_API extern "C" __declspec(dllexport)
#define GF_MAIN __cdecl
#include "VTILib.h"
#endif /* __COMMON_H__ */
