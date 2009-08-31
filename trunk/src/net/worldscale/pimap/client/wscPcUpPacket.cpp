#include "wscPcUpPacket.h"


wscPcUpPacket::wscPcUpPacket(void)
{
}


wscPcUpPacket::~wscPcUpPacket(void)
{
}


ws_result wscPcUpPacket::Login(wsiString *username, wsiString *psw)
{
    SetFunction( FUNC_LOGIN::FID );
    PutParam( FUNC_LOGIN::PID_USER_NAME , TYPE_STRING , username );
    PutParam( FUNC_LOGIN::PID_PASSWORD  , TYPE_STRING , psw );
    return WS_RLT_SUCCESS;
}


ws_result wscPcUpPacket::Logout(void)
{
    SetFunction( FUNC_LOGOUT::FID );
    return WS_RLT_SUCCESS;
}

