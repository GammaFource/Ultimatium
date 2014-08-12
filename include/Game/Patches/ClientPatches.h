#ifndef __GAMEPATCHES_H__
#define __GAMEPATCHES_H__

#include "Common.h"

typedef enum
{
	DVAR_ARCHIVE = 1,
	DVAR_LATCHED = 0x20,
	DVAR_ROM = 0x40,
	DVAR_CHEAT = 0x80
} Dvar_Flags_t;

typedef union
{
	char* string;
	int integer;
	float value;
	bool boolean;
} dvar_value;

typedef struct dvar_s
{
	const char* name;
	char unknown[20]; 
	dvar_value current;
} dvar_t;


typedef enum {
	NA_BAD = 0,				
	NA_BOT,
	NA_LOOPBACK,
	NA_BROADCAST,
	NA_IP,
	NA_IP6,
	NA_MULTICAST6,
	NA_UNSPEC
} netadrtype_t;



#define NET_ADDRSTRMAXLEN 48	
typedef struct {
	netadrtype_t	type;

	byte	ip[4];
	byte	ip6[16];

	unsigned short	port;
	unsigned long	scope_id;	
} netadr_t;

class ClientPatches
{
public:	
	static bool Init(char* username, char* password);
	static void PatchSP();
	static void PatchMP();	
};

#endif /* __GAMEPATCHES_H_ */