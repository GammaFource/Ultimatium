#ifndef __STEAMAPPS003_H__
#define __STEAMAPPS003_H__

#include "Common.h"

class SteamApps003 : public ISteamApps003
{
public:
	bool IsSubscribed();
	bool IsLowViolence();
	bool IsCybercafe();
	bool IsVACBanned();
	const char* GetCurrentGameLanguage();
	const char* GetAvailableGameLanguages();
	bool IsSubscribedApp(AppId_t appID);
	bool IsDlcInstalled( AppId_t appID );
};

#endif /* __STEAMAPPS003_H__ */