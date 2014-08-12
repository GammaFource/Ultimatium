#include "Common.h"
#include "VTAuth.h"

#define VTILIB extern "C" __declspec(dllimport)
#define VTILIB extern "C" __declspec(dllexport)
#define VTICALL __cdecl

//IEntityDef* et;

VTILIB bool VTICALL VTI_Initialize();

VTILIB bool VTICALL VTI_Connect(char *addr, int port);

VTILIB IEntityDef* VTICALL VTI_PerformAuth(int version, char *username, char *password);

VTILIB char* VTICALL VTI_GetSelfNickname();

VTILIB VultrotID_t VTICALL VTI_GetSelfVultrotID();

VTILIB char* VTICALL VTI_GetSID();

VTILIB char* VTICALL VTI_GetFriendName(VultrotID_t id);

VTILIB int VTICALL VTI_GetFriendCount();

VTILIB EPersonaState VTICALL VTI_GetFriendState(VultrotID_t id);

VTILIB void VTICALL VTI_FriendsInit(IEntityDef* entity);

VTILIB int VTICALL VTI_GetFriendByID(int id);