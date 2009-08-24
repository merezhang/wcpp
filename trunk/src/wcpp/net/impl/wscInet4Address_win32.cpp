#pragma once

#include "wscInet4Address_win32.h"
#include <wcpp/lang/wscThrowable.h>
#include <wcpp/lang/wscArray.h>
#if (WS_PLATFORM == WS_PLATFORM_WIN32) // (win32 platform begin)


WS_IMPL_ClassName_OF( wscInet4Address_win32 )


wscInet4Address_win32::wscInet4Address_win32(sockaddr_in & ipv4_addr) : m_ipv4_addr( ipv4_addr )
{
}


wscInet4Address_win32::~wscInet4Address_win32(void)
{
}


ws_boolean  wscInet4Address_win32::Equals               (wsiObject * obj)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}


ws_result   wscInet4Address_win32::GetAddress           (wsiByteArray ** ret)
{
    ws_result rlt = NewObj<wscByteArray>( ret , sizeof(m_ipv4_addr) );
    if (rlt != WS_RLT_SUCCESS) return rlt;
    ws_byte * buf = (*ret)->Data();
    ws_int    len = (*ret)->Length();
    wspr::ws_memcpy( buf , & m_ipv4_addr , sizeof(m_ipv4_addr) );
    return rlt;
}


ws_result   wscInet4Address_win32::GetCanonicalHostName (wsiString ** ret)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}


ws_result   wscInet4Address_win32::GetHostAddress       (wsiString ** ret)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}


ws_result   wscInet4Address_win32::GetHostName          (wsiString ** ret)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}


ws_int      wscInet4Address_win32::HashCode             (void)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}


ws_boolean  wscInet4Address_win32::IsAnyLocalAddress    (void)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}


ws_boolean  wscInet4Address_win32::IsLinkLocalAddress   (void)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}


ws_boolean  wscInet4Address_win32::IsLoopbackAddress    (void)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}


ws_boolean  wscInet4Address_win32::IsMCGlobal           (void)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}


ws_boolean  wscInet4Address_win32::IsMCLinkLocal        (void)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}


ws_boolean  wscInet4Address_win32::IsMCNodeLocal        (void)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}


ws_boolean  wscInet4Address_win32::IsMCOrgLocal         (void)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}


ws_boolean  wscInet4Address_win32::IsMCSiteLocal        (void)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}


ws_boolean  wscInet4Address_win32::IsMulticastAddress   (void)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}


ws_boolean  wscInet4Address_win32::IsReachable          (ws_int timeout)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}


ws_boolean  wscInet4Address_win32::IsReachable          (wsiNetworkInterface * netif, ws_int ttl, ws_int timeout)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}


ws_boolean  wscInet4Address_win32::IsSiteLocalAddress   (void)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}


ws_result   wscInet4Address_win32::ToString             (wsiString ** ret)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}


#endif // (WS_PLATFORM == WS_PLATFORM_WIN32)
