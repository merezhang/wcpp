#pragma once
#include <wcpp/lang/wsiObject.h>


class wsiDatagramPacket;


#define WS_IID_OF_wsiPsExchangeBuffer       \
    { 0x14973f03, 0x8e4c, 0x4fde, { 0xb7, 0x73, 0x2a, 0x2d, 0xe3, 0x41, 0xd0, 0x9d } }
// {14973F03-8E4C-4fde-B773-2A2DE341D09D}


class wsiPsExchangeBuffer : public wsiObject
{
public:
    static const ws_iid sIID;
public:
    WS_METHOD( ws_result , AllocatePacket )(wsiDatagramPacket ** ret   ) = 0;
    WS_METHOD( ws_result , PushPacket     )(wsiDatagramPacket *  packet) = 0;
    WS_METHOD( ws_result , PopPacket      )(wsiDatagramPacket ** ret   ) = 0;
    WS_METHOD( ws_result , RecyclePacket  )(wsiDatagramPacket *  packet) = 0;
};

