#pragma once

#include "wsiSocketAddress.h"


class wsiInetAddress;


#define WS_IID_OF_wsiInetSocketAddress      \
    { 0x479030b, 0x629b, 0x4cf4, { 0x85, 0xe9, 0xcd, 0xa5, 0xb9, 0x3f, 0xd1, 0xde } }
// {0479030B-629B-4cf4-85E9-CDA5B93FD1DE}


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

