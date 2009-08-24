#pragma once
#include <wcpp/lang/wsiobject.h>


class wsiSocketAddress;
class wsiInetAddress;
class wsiDatagramPacket;
class wsiDatagramChannel;


#define WS_IID_OF_wsiDatagramSocket		\
	{ 0xb8508ed7, 0x1c00, 0x4495, { 0x85, 0x23, 0x17, 0x33, 0x74, 0xac, 0x4d, 0xa2 } }
// {B8508ED7-1C00-4495-8523-173374AC4DA2}


class wsiDatagramSocket : public wsiObject
{
public:

    static const ws_iid sIID;

public:

    WS_METHOD( ws_result  , Bind                   )(wsiSocketAddress * addr) = 0;
    WS_METHOD( ws_result  , Close                  )(void) = 0;
    WS_METHOD( ws_result  , Connect                )(wsiInetAddress * address, ws_int port) = 0;
    WS_METHOD( ws_result  , Connect                )(wsiSocketAddress * addr) = 0;
    WS_METHOD( ws_result  , Disconnect             )(void) = 0;
    WS_METHOD( ws_boolean , GetBroadcast           )(void) = 0;
    WS_METHOD( ws_result  , GetChannel             )(wsiDatagramChannel ** ret) = 0;
    WS_METHOD( ws_result  , GetInetAddress         )(wsiInetAddress ** ret) = 0;
    WS_METHOD( ws_result  , GetLocalAddress        )(wsiInetAddress ** ret) = 0;
    WS_METHOD( ws_int     , GetLocalPort           )(void) = 0;
    WS_METHOD( ws_result  , GetLocalSocketAddress  )(wsiSocketAddress ** ret) = 0;
    WS_METHOD( ws_int     , GetPort                )(void) = 0;
    WS_METHOD( ws_int     , GetReceiveBufferSize   )(void) = 0;
    WS_METHOD( ws_result  , GetRemoteSocketAddress )(wsiSocketAddress ** ret) = 0;
    WS_METHOD( ws_boolean , GetReuseAddress        )(void) = 0;
    WS_METHOD( ws_int     , GetSendBufferSize      )(void) = 0;
    WS_METHOD( ws_int     , GetSoTimeout           )(void) = 0;
    WS_METHOD( ws_int     , GetTrafficClass        )(void) = 0;
    WS_METHOD( ws_boolean , IsBound                )(void) = 0;
    WS_METHOD( ws_boolean , IsClosed               )(void) = 0;
    WS_METHOD( ws_boolean , IsConnected            )(void) = 0;
    WS_METHOD( ws_result  , Receive                )(wsiDatagramPacket * p) = 0;
    WS_METHOD( ws_result  , Send                   )(wsiDatagramPacket * p) = 0;
    WS_METHOD( ws_result  , SetBroadcast           )(ws_boolean on) = 0;
    WS_METHOD( ws_result  , SetReceiveBufferSize   )(ws_int size) = 0;
    WS_METHOD( ws_result  , SetReuseAddress        )(ws_boolean on) = 0;
    WS_METHOD( ws_result  , SetSendBufferSize      )(ws_int size) = 0;
    WS_METHOD( ws_result  , SetSoTimeout           )(ws_int timeout) = 0;
    WS_METHOD( ws_result  , SetTrafficClass        )(ws_int tc) = 0;

};

