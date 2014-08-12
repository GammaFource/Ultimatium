/*==========================================================
GammaForce operation

Project: Ultimatium
Game: Black Ops (T5)
Module: Steam_api emulator
Reason of existance: Steam emulation code.

Author: FaceTaker
==========================================================*/

#include "Common.h"
#include "Steam/SteamAPI.h"
#include "Steam/SteamCommon.h"

#pragma unmanaged

bool SteamApps003::IsSubscribed()
{
	return true;
}

bool SteamApps003::IsLowViolence()
{
	return false;
}

bool SteamApps003::IsCybercafe()
{
	return false;
}

bool SteamApps003::IsVACBanned()
{
	Log::Debug("SteamApps", "Called IsVACBanned");
	return false;
}

const char* SteamApps003::GetCurrentGameLanguage()
{
	return "english";
}
	
const char* SteamApps003::GetAvailableGameLanguages()
{
	return "english";
}

bool SteamApps003::IsSubscribedApp(AppId_t appID)
{
	return true;
}

bool SteamApps003::IsDlcInstalled(AppId_t appID)
{
	// DLC checks - only return true if the DLC files exist
	if (appID == 42715) // DLC2
	{
		if (GetFileAttributes("main\\iw_26.iwd") != INVALID_FILE_ATTRIBUTES && 
			GetFileAttributes("main\\iw_27.iwd") != INVALID_FILE_ATTRIBUTES && 
			GetFileAttributes("main\\iw_28.iwd") != INVALID_FILE_ATTRIBUTES)
		{
			if (GetFileAttributes("zone\\common\\mp_stadium.ff") != INVALID_FILE_ATTRIBUTES || 
				GetFileAttributes("zone\\common\\mp_kowloon.ff") != INVALID_FILE_ATTRIBUTES || 
				GetFileAttributes("zone\\common\\mp_berlinwall2.ff") != INVALID_FILE_ATTRIBUTES || 
				GetFileAttributes("zone\\common\\mp_discovery.ff") != INVALID_FILE_ATTRIBUTES)
			{
				return true;
			}
		}
	}

	if (appID == 42717) // DLC3
	{
		if (GetFileAttributes("main\\iw_29.iwd") != INVALID_FILE_ATTRIBUTES && 
			GetFileAttributes("main\\iw_30.iwd") != INVALID_FILE_ATTRIBUTES && 
			GetFileAttributes("main\\iw_31.iwd") != INVALID_FILE_ATTRIBUTES &&
			GetFileAttributes("main\\iw_32.iwd") != INVALID_FILE_ATTRIBUTES)
		{
			if (GetFileAttributes("zone\\common\\mp_zoo.ff") != INVALID_FILE_ATTRIBUTES || 
				GetFileAttributes("zone\\common\\mp_hotel.ff") != INVALID_FILE_ATTRIBUTES || 
				GetFileAttributes("zone\\common\\mp_gridlock.ff") != INVALID_FILE_ATTRIBUTES || 
				GetFileAttributes("zone\\common\\mp_outskirts.ff") != INVALID_FILE_ATTRIBUTES)
			{
				return true;
			}
		}
	}

	if (appID == 42722) // DLC4
	{
		if (GetFileAttributes("main\\iw_33.iwd") != INVALID_FILE_ATTRIBUTES && 
			GetFileAttributes("main\\iw_34.iwd") != INVALID_FILE_ATTRIBUTES && 
			GetFileAttributes("main\\iw_35.iwd") != INVALID_FILE_ATTRIBUTES)
		{
			if (GetFileAttributes("zone\\common\\mp_area51.ff") != INVALID_FILE_ATTRIBUTES || 
				GetFileAttributes("zone\\common\\mp_drivein.ff") != INVALID_FILE_ATTRIBUTES || 
				GetFileAttributes("zone\\common\\mp_silo.ff") != INVALID_FILE_ATTRIBUTES || 
				GetFileAttributes("zone\\common\\mp_golfcourse.ff") != INVALID_FILE_ATTRIBUTES)
			{
				return true;
			}
		}
	}

	if (appID == 42716) // DLC2 SP
	{
		if (GetFileAttributes("main\\iw_26.iwd") != INVALID_FILE_ATTRIBUTES && 
			GetFileAttributes("main\\iw_27.iwd") != INVALID_FILE_ATTRIBUTES && 
			GetFileAttributes("main\\iw_28.iwd") != INVALID_FILE_ATTRIBUTES)
		{
			if (GetFileAttributes("zone\\common\\zombie_cosmodrome.ff") != INVALID_FILE_ATTRIBUTES)
			{
				return true;
			}
		}
	}

	if (appID == 42718) // DLC3 SP
	{
		if (GetFileAttributes("main\\iw_29.iwd") != INVALID_FILE_ATTRIBUTES && 
			GetFileAttributes("main\\iw_30.iwd") != INVALID_FILE_ATTRIBUTES && 
			GetFileAttributes("main\\iw_31.iwd") != INVALID_FILE_ATTRIBUTES &&
			GetFileAttributes("main\\iw_32.iwd") != INVALID_FILE_ATTRIBUTES)
		{
			if (GetFileAttributes("zone\\common\\zombie_coast.ff") != INVALID_FILE_ATTRIBUTES)
			{
				return true;
			}
		}
	}

	if (appID == 42723) // DLC4 SP
	{
		if (GetFileAttributes("main\\iw_33.iwd") != INVALID_FILE_ATTRIBUTES && 
			GetFileAttributes("main\\iw_34.iwd") != INVALID_FILE_ATTRIBUTES && 
			GetFileAttributes("main\\iw_35.iwd") != INVALID_FILE_ATTRIBUTES)
		{
			if (GetFileAttributes("zone\\common\\zombie_temple.ff") != INVALID_FILE_ATTRIBUTES)
			{
				return true;
			}
		}
	}

	if (appID == 42719) // DLC1 SP
	{
		if (GetFileAttributes("main\\iw_36.iwd") != INVALID_FILE_ATTRIBUTES && 
			GetFileAttributes("main\\iw_37.iwd") != INVALID_FILE_ATTRIBUTES && 
			GetFileAttributes("main\\iw_38.iwd") != INVALID_FILE_ATTRIBUTES && 
			GetFileAttributes("main\\iw_39.iwd") != INVALID_FILE_ATTRIBUTES && 
			GetFileAttributes("main\\iw_40.iwd") != INVALID_FILE_ATTRIBUTES && 
			GetFileAttributes("main\\iw_41.iwd") != INVALID_FILE_ATTRIBUTES)
		{
			if (GetFileAttributes("zone\\common\\zombie_moon.ff") != INVALID_FILE_ATTRIBUTES && 
				GetFileAttributes("zone\\common\\zombie_cod5_prototype.ff") != INVALID_FILE_ATTRIBUTES && 
				GetFileAttributes("zone\\common\\zombie_cod5_sumpf.ff") != INVALID_FILE_ATTRIBUTES && 
				GetFileAttributes("zone\\common\\zombie_cod5_asylum.ff") != INVALID_FILE_ATTRIBUTES && 
				GetFileAttributes("zone\\common\\zombie_cod5_factory.ff") != INVALID_FILE_ATTRIBUTES)
			{
				return true;
			}
		}
	}

	return false;
}
