#include "wscInetSocketAddress.h"
#include <wcpp/lang/wscThrowable.h>
#include "wscInetAddress.h"


WS_IMPL_ClassName_OF( wscInetSocketAddress )


wscInetSocketAddress::wscInetSocketAddress(wsiInetAddress * addr , ws_int port) : m_port(0)
{
    m_port = port;
    m_address.Set( addr );
}


wscInetSocketAddress::wscInetSocketAddress(wsiString * hostname , ws_int port) : m_port(0)
{
    m_port = port;
    ws_ptr<wsiInetAddress> addr;
    wscInetAddress::GetByName( &addr , hostname );
    m_address.Set( addr );
}


wscInetSocketAddress::~wscInetSocketAddress(void)
{
}


ws_boolean wscInetSocketAddress::InternalEquals(wsiObject *obj)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}


ws_int wscInetSocketAddress::InternalHashCode(void)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}


ws_result wscInetSocketAddress::InternalToString(wsiString **ret)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}


ws_result wscInetSocketAddress::GetAddress(wsiInetAddress **ret)
{
    if (ret==WS_NULL) return WS_RLT_NULL_POINTER;
    if (*ret) return WS_RLT_NULL_POINTER;
    m_address.Get( ret );
    if (*ret) return WS_RLT_SUCCESS;
    return WS_RLT_FAILED;
}


ws_result wscInetSocketAddress::GetHostName(wsiString **ret)
{
    if (ret==WS_NULL) return WS_RLT_NULL_POINTER;
    if (*ret) return WS_RLT_NULL_POINTER;
    m_hostName.Get( ret );
    if (*ret) return WS_RLT_SUCCESS;
    return WS_RLT_FAILED;
}


ws_int wscInetSocketAddress::GetPort(void)
{
    return m_port;
}


ws_boolean wscInetSocketAddress::IsUnresolved(void)
{
    ws_ptr<wsiInetAddress> addr;
    m_address.Get( &addr );
    return (!addr);
}

