/*==========================================================
GammaForce operation

Project: Ultimatium
Game: Black Ops (T5)
Module: Steam_api emulator
Reason of existance: Additional commands for the client.

Author: FaceTaker
==========================================================*/

/*==========================================================
 All credits goes to vorhon for this
==========================================================*/

#include "Common.h"

typedef void(__cdecl* xcommand_t)(void);

struct cmdDef_s
{
	cmdDef_s*       lastCmdDef; 
	char            name[16];       
	xcommand_t      callback;       
	DWORD           unknown;        
}; 

typedef cmdDef_s*(__cdecl* Cmd_AddCommand_t)(char* name, xcommand_t callback, cmdDef_s* cmdDef);
Cmd_AddCommand_t Cmd_AddCommand = (Cmd_AddCommand_t)0x67BDC0;

typedef void(__cdecl* Com_Printf_t)(int i, const char* fmt, ...);
Com_Printf_t Com_Printf = (Com_Printf_t)0x612A90;

void Cmd_Helloworld_f()
{
	printf("Hello world!\n");
}

void newComPrintf(int i, const char* fmt, ...)
{
	char va[52];
	va_list arg;
	va_start(arg, fmt);
	vsnprintf(va, 52, fmt, arg);
	va_end(arg);
	printf(va);
}

void PatchOps_Commands()
{
	static cmdDef_s cmd;

	Cmd_AddCommand("helloworld", Cmd_Helloworld_f, &cmd);
}