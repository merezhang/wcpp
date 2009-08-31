#pragma once

#include <wcpp/lang/wsiObject.h>


class wsiDatagramPacket;
class wsiPimapPacket;


#define WS_IID_OF_wsiPimapCoder     \
    { 0x6cdcae72, 0xc73f, 0x4795, { 0x8d, 0x55, 0x6c, 0xbb, 0xc3, 0x15, 0x82, 0x90 } }
// {6CDCAE72-C73F-4795-8D55-6CBBC3158290}


class wsiPimapCoder : public wsiObject
{
public:
    static const ws_iid sIID;
public:
    WS_METHOD( ws_result , Code )( wsiPimapPacket * src , wsiDatagramPacket * dest ) = 0;
};

