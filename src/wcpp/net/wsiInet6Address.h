#pragma once

#include "wsiInetAddress.h"


#define WS_IID_OF_wsiInet6Address       \
    { 0xf8b1b7bb, 0x6a01, 0x4fb9, { 0x88, 0xac, 0xff, 0x2b, 0x43, 0x9a, 0xad, 0x32 } }
// {F8B1B7BB-6A01-4fb9-88AC-FF2B439AAD32}


class wsiInet6Address : public wsiInetAddress
{
public:
    static const ws_iid sIID;

public:
    WS_METHOD( ws_boolean , Equals                  )(wsiObject * obj) = 0;
    WS_METHOD( ws_result  , GetAddress              )(wsiByteArray ** ret) = 0;
    WS_METHOD( ws_result  , GetHostAddress          )(wsiString ** ret) = 0;
    WS_METHOD( ws_result  , GetScopedInterface      )(wsiNetworkInterface ** ret) = 0;
    WS_METHOD( ws_int     , GetscapedId             )(void) = 0;
    WS_METHOD( ws_int     , HashCode                )(void) = 0;
    WS_METHOD( ws_boolean , IsAnyLocalAddress       )(void) = 0;
    WS_METHOD( ws_boolean , IsIPv4CompatibleAddress )(void) = 0;
    WS_METHOD( ws_boolean , IsLinkLocalAddress      )(void) = 0;
    WS_METHOD( ws_boolean , IsLoopbackAddress       )(void) = 0;
    WS_METHOD( ws_boolean , IsMCGlobal              )(void) = 0;
    WS_METHOD( ws_boolean , IsMCLinkLocal           )(void) = 0;
    WS_METHOD( ws_boolean , IsMCNodeLocal           )(void) = 0;
    WS_METHOD( ws_boolean , IsMCOrgLocal            )(void) = 0;
    WS_METHOD( ws_boolean , IsMCSiteLocal           )(void) = 0;
    WS_METHOD( ws_boolean , IsMulticastAddress      )(void) = 0;
    WS_METHOD( ws_boolean , IsSiteLocalAddress      )(void) = 0;

/*
static
    WS_METHOD( ws_result , GetByAddress            )(void) = 0;
    WS_METHOD( ws_result , GetByAddress            )(void) = 0;
*/

};

