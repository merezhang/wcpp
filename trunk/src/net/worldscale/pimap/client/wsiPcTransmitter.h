#pragma once

#include <wcpp/lang/wsiObject.h>


class wsiPimapPacket;
class wsiInetSocketAddress;


#define WS_IID_OF_wsiPcTransmitter      \
    { 0xf7dc8d93, 0xf3c1, 0x4f12, { 0xa8, 0xe7, 0xd5, 0x40, 0xd, 0x8, 0xcb, 0x8c } }
// {F7DC8D93-F3C1-4f12-A8E7-D5400D08CB8C}


class wsiPcTransmitter : public wsiObject
{
public:
    static const ws_iid sIID;
public:
    WS_METHOD( ws_result , SendRequest )(wsiPimapPacket * packet, wsiInetSocketAddress * sockAddr) = 0;
};

