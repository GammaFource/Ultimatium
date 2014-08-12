#ifndef __VTAUTH_H__
#define __VTAUTH_H__
typedef __int64 VultrotID_t;
enum EAuthResponse
{
	k_EAuthResponseSuccess,
	k_EAuthResponseWrongVersion,
	k_EAuthResponseWrongUsername,
	k_EAuthResponseWrongPassword,
	k_EAuthResponseBanned,
	k_EAuthResponseAccountInUse,
	k_EAuthResponseWrongGameVersion,
	k_EAuthResponseUnknown
};

class IEntityDef
{
public:
	char	*m_sNickname;
	char	*m_ssid;
	char	*m_sPassword;	
	EAuthResponse m_eAuthResult;
	EPersonaState m_ePersonaState;
	VultrotID_t	m_iVultrotID;
};

typedef struct auth_packet_s
{
	char	subtype;
	int		opcode;
	int		version;
	char	*username;
	char	*sid;
	char	*password;
	EAuthResponse ar;
	VultrotID_t vultrotID;
} auth_packet_t;

#endif /* __VTAUTH_H__ */