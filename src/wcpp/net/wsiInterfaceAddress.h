#pragma once

#include <wcpp/lang/wsiObject.h>


class wsiInetAddress;


class wsiInterfaceAddress : public wsiObject
{
public:
    static const ws_iid sIID;
public:
    WS_METHOD( ws_boolean , Equals                 )(wsiObject * obj) = 0;
    WS_METHOD( ws_result  , GetAddress             )(wsiInetAddress ** ret) = 0;
    WS_METHOD( ws_result  , GetBroadcast           )(wsiInetAddress ** ret) = 0;
    WS_METHOD( ws_short   , GetNetworkPrefixLength )(void) = 0;
    WS_METHOD( ws_int     , HashCode               )(void) = 0;
    WS_METHOD( ws_result  , ToString               )(wsiString ** ret) = 0;
};

