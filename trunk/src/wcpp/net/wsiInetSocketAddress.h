#pragma once

#include "wsiSocketAddress.h"


class wsiInetAddress;


class wsiInetSocketAddress : public wsiSocketAddress
{
public:
    static const ws_iid sIID;
public:

    WS_METHOD( ws_boolean , Equals       )(wsiObject * obj) = 0;
    WS_METHOD( ws_result  , GetAddress   )(wsiInetAddress ** ret) = 0;
    WS_METHOD( ws_result  , GetHostName  )(wsiString ** ret) = 0;
    WS_METHOD( ws_int     , GetPort      )(void) = 0;
    WS_METHOD( ws_int     , HashCode     )(void) = 0;
    WS_METHOD( ws_boolean , IsUnresolved )(void) = 0;
    WS_METHOD( ws_result  , ToString     )(wsiString ** ret) = 0;

};

