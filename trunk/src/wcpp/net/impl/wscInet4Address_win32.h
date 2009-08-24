#pragma once

#include <wcpp/net/wscInet4Address.h>
#if (WS_PLATFORM == WS_PLATFORM_WIN32) // (win32 platform begin)
#include <windows.h>


#define WS_ClassName_OF_wscInet4Address_win32       "wcpp.net.impl.wscInet4Address_win32"


class wscInet4Address_win32 : public wscInet4Address
{
public:
    static const ws_char * const s_class_name;
private:
    sockaddr_in    m_ipv4_addr;
public:
    wscInet4Address_win32(sockaddr_in & ipv4_addr);
    ~wscInet4Address_win32(void);

protected:

    WS_METHOD( ws_boolean , Equals               )(wsiObject * obj);
    WS_METHOD( ws_result  , GetAddress           )(wsiByteArray ** ret);
    WS_METHOD( ws_result  , GetCanonicalHostName )(wsiString ** ret);
    WS_METHOD( ws_result  , GetHostAddress       )(wsiString ** ret);
    WS_METHOD( ws_result  , GetHostName          )(wsiString ** ret);
    WS_METHOD( ws_int     , HashCode             )(void);

    WS_METHOD( ws_boolean , IsAnyLocalAddress    )(void);
    WS_METHOD( ws_boolean , IsLinkLocalAddress   )(void);
    WS_METHOD( ws_boolean , IsLoopbackAddress    )(void);
    WS_METHOD( ws_boolean , IsMCGlobal           )(void);
    WS_METHOD( ws_boolean , IsMCLinkLocal        )(void);
    WS_METHOD( ws_boolean , IsMCNodeLocal        )(void);
    WS_METHOD( ws_boolean , IsMCOrgLocal         )(void);
    WS_METHOD( ws_boolean , IsMCSiteLocal        )(void);
    WS_METHOD( ws_boolean , IsMulticastAddress   )(void);
    WS_METHOD( ws_boolean , IsReachable          )(ws_int timeout);
    WS_METHOD( ws_boolean , IsReachable          )(wsiNetworkInterface * netif, ws_int ttl, ws_int timeout);
    WS_METHOD( ws_boolean , IsSiteLocalAddress   )(void);
    WS_METHOD( ws_result  , ToString             )(wsiString ** ret);

};


#endif // (WS_PLATFORM == WS_PLATFORM_WIN32)
