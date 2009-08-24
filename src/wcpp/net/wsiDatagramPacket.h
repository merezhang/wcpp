#pragma once

#include <wcpp/lang/wsiObject.h>
#include <wcpp/lang/wsiArray.h>


class wsiInetAddress;
class wsiSocketAddress;


#define WS_IID_OF_wsiDatagramPacket     \
    { 0x6fc0e6e1, 0x795f, 0x4964, { 0x8e, 0x25, 0xc0, 0x49, 0xfb, 0x75, 0x2c, 0xb7 } }
// {6FC0E6E1-795F-4964-8E25-C049FB752CB7}


class wsiDatagramPacket : public wsiObject
{
public:

    static const ws_iid sIID;

public:

    WS_METHOD( ws_result , GetAddress       )(wsiInetAddress ** ret) = 0;
    WS_METHOD( ws_result , GetData          )(wsiByteArray ** ret) = 0;
    WS_METHOD( ws_int    , GetLength        )(void) = 0;
    WS_METHOD( ws_int    , GetOffset        )(void) = 0;
    WS_METHOD( ws_int    , GetPort          )(void) = 0;
    WS_METHOD( ws_result , GetSocketAddress )(wsiSocketAddress ** ret) = 0;
    WS_METHOD( ws_result , SetAddress       )(wsiInetAddress * iaddr) = 0;
    WS_METHOD( ws_result , SetData          )(wsiByteArray * buf) = 0;
    WS_METHOD( ws_result , SetData          )(wsiByteArray * buf , ws_int offset , ws_int length) = 0;
    WS_METHOD( ws_result , SetLength        )(ws_int length) = 0;
    WS_METHOD( ws_result , SetPort          )(ws_int iport) = 0;
    WS_METHOD( ws_result , SetSocketAddress )(wsiSocketAddress * address) = 0;

};

