#include "wscPsUser.h"


WS_IMPL_ClassName_OF( wscPsUser )


wscPsUser::wscPsUser(ws_uint32 uid) : m_UserId(uid)
{
}


wscPsUser::~wscPsUser(void)
{
}


ws_uint32 wscPsUser::GetUserId(void)
{
    return m_UserId;
}

