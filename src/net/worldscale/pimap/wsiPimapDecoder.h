#pragma once

#include <wcpp/lang/wsiObject.h>


class wsiDatagramPacket;
class wsiPimapPacket;


#define WS_IID_OF_wsiPimapDecoder     \
    { 0x8617486d, 0xb430, 0x43bc, { 0x8a, 0x2b, 0xb2, 0x6c, 0xa3, 0x3d, 0xc9, 0x1a } }
// {8617486D-B430-43bc-8A2B-B26CA33DC91A}


class wsiPimapDecoder : public wsiObject
{
public:
    static const ws_iid sIID;
public:
    WS_METHOD( ws_result , Decode )( wsiDatagramPacket * src , wsiPimapPacket * dest ) = 0;
};

