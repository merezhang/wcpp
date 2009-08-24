#pragma once

#include "wsiInetAddress.h"


#define WS_IID_OF_wsiInet4Address       \
    { 0xbff8bb21, 0xdb0f, 0x4292, { 0xb0, 0xe2, 0xa0, 0x61, 0x4c, 0x64, 0x5f, 0x8f } }
// {BFF8BB21-DB0F-4292-B0E2-A0614C645F8F}


class wsiInet4Address : public wsiInetAddress
{
public:
    static const ws_iid sIID;

public:
    WS_METHOD( ws_boolean , Equals             )(wsiObject * obj) = 0;
    WS_METHOD( ws_result  , GetAddress         )(wsiByteArray ** ret) = 0;
    WS_METHOD( ws_result  , GetHostAddress     )(wsiString ** ret) = 0;
    WS_METHOD( ws_int     , HashCode           )(void) = 0;
    WS_METHOD( ws_boolean , IsAnyLocalAddress  )(void) = 0;
    WS_METHOD( ws_boolean , IsLinkLocalAddress )(void) = 0;
    WS_METHOD( ws_boolean , IsLoopbackAddress  )(void) = 0;
    WS_METHOD( ws_boolean , IsMCGlobal         )(void) = 0;
    WS_METHOD( ws_boolean , IsMCLinkLocal      )(void) = 0;
    WS_METHOD( ws_boolean , IsMCNodeLocal      )(void) = 0;
    WS_METHOD( ws_boolean , IsMCOrgLocal       )(void) = 0;
    WS_METHOD( ws_boolean , IsMCSiteLocal      )(void) = 0;
    WS_METHOD( ws_boolean , IsMulticastAddress )(void) = 0;
    WS_METHOD( ws_boolean , IsSiteLocalAddress )(void) = 0;

};

