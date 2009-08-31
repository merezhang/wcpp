#pragma once

#include <wcpp/lang/wsiObject.h>


class wsiDatagramSocket;
class wsiPcExchangeBuffer;
class wsiPcTransmitter;
class wsiPcEventDispatcher;
class wsiPcUser;


#define WS_IID_OF_wsiPcWorkingContext       \
    { 0x77f8dc36, 0x42f9, 0x4ecc, { 0xb7, 0xb4, 0x69, 0x90, 0xce, 0xdf, 0x36, 0x8f } }
// {77F8DC36-42F9-4ecc-B7B4-6990CEDF368F}


class wsiPcWorkingContext : public wsiObject
{
public:
    static const ws_iid sIID;
public:
    WS_METHOD( ws_result  , SetStopFlag       )(void) = 0;
    WS_METHOD( ws_boolean , GetStopFlag       )(void) = 0;

    WS_METHOD( ws_result , GetUser )(wsiPcUser ** ret) = 0;
    WS_METHOD( ws_result , SetUser )(wsiPcUser * user) = 0;

    WS_METHOD( ws_result  , GetDatagramSocket  )(wsiDatagramSocket    ** ret) = 0;
    WS_METHOD( ws_result  , GetExchangeBuffer  )(wsiPcExchangeBuffer  ** ret) = 0;
    WS_METHOD( ws_result  , GetTransmitter     )(wsiPcTransmitter     ** ret) = 0;
    WS_METHOD( ws_result  , GetEventDispatcher )(wsiPcEventDispatcher ** ret) = 0;

    WS_METHOD( ws_result  , SetDatagramSocket  )(wsiDatagramSocket    * p) = 0;
    WS_METHOD( ws_result  , SetExchangeBuffer  )(wsiPcExchangeBuffer  * p) = 0;
    WS_METHOD( ws_result  , SetTransmitter     )(wsiPcTransmitter     * p) = 0;
    WS_METHOD( ws_result  , SetEventDispatcher )(wsiPcEventDispatcher * p) = 0;
};

