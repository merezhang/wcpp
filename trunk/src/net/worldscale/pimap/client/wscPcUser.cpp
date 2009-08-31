#include "wscPcUser.h"
#include <wcpp/net/wsiInetSocketAddress.h>


WS_IMPL_ClassName_OF( wscPcUser )


wscPcUser::wscPcUser(void)
{
}


wscPcUser::~wscPcUser(void)
{
}


ws_result wscPcUser::SetServerAddress(wsiInetSocketAddress *addr)
{
    m_ServerAddress.Set( addr );
    return WS_RLT_SUCCESS;
}


ws_result wscPcUser::GetServerAddress(wsiInetSocketAddress **ret)
{
    if (ret==WS_NULL) return WS_RLT_NULL_POINTER;
    if (*ret) return WS_RLT_NULL_POINTER;
    m_ServerAddress.Get( ret );
    if (*ret) return WS_RLT_SUCCESS;
    return WS_RLT_FAILED;
}

