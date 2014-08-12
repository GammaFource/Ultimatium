/*
 * This file is part of iberianOps Client - BlackOps (T5)
 * -------------------------------------------------------------------------
 * This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-sa/3.0/.
 *
 * Creator: NTAuthority
 */

#ifndef __NEWHOOKING_H__
#define __NEWHOOKING_H__

#include "Common.h"

#define CALL_NEAR32 0xE8U
#define JMP_NEAR32 0xE9U
#define NOP 0x90U

struct NewCallHook {
	BYTE bOriginalCode[5];
	PBYTE pPlace;
	void* pOriginal;
	void* hook;

	void initialize(DWORD place, void *hookToInstall = NULL);
	void installHook(void* hookToInstall = NULL);
	void releaseHook();
};
/*
struct PointerHook {
	PVOID* pPlace;
	PVOID pOriginal;

	void initialize(PVOID* place);
	int installHook(void (*hookToInstall)(), bool unprotect);
	int releaseHook(bool unprotect);
};
*/
struct NewStompHook {
	BYTE bOriginalCode[15];
	BYTE bCountBytes;
	PBYTE pPlace;
	void* hook;
	bool jump;

	void initialize(DWORD place, void *hookToInstall = NULL, BYTE countBytes = 5, bool useJump = true);
	void installHook(void* hookToInstall = NULL);
	void releaseHook();
};

void HookInstall(DWORD address, DWORD hookToInstall, int bCountBytes=5);

#endif /* __NEWHOOKING_H__ */