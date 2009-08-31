#pragma once

#include <wcpp/lang/wsiObject.h>


class wsiPimapPacket;


#define WS_IID_OF_wsiPcExchangeBuffer     \
    { 0xb022c538, 0x1b4c, 0x4553, { 0x83, 0x97, 0x7b, 0x58, 0xa7, 0x6b, 0xc5, 0x95 } }
// {B022C538-1B4C-4553-8397-7B58A76BC595}


class wsiPcExchangeBuffer : public wsiObject
{
public:
    static const ws_iid sIID;
public:
    WS_METHOD( ws_result , OnSend     )(wsiPimapPacket * packet) = 0;
    WS_METHOD( ws_result , OnReceive  )(wsiPimapPacket **   ret) = 0;
};

