#pragma once
#include <wcpp/lang/wsiObject.h>
#include "wsiSocketOptions.h"


class wsiInetAddress;
class wsiFileDescriptor;
class wsiSocketAddress;
class wsiNetworkInterface;
class wsiDatagramPacket;


#define WS_IID_OF_wsiDatagramSocketImpl     \
    { 0x23afcb44, 0x2093, 0x4a94, { 0xad, 0x9d, 0x33, 0x7a, 0x7b, 0xe0, 0xab, 0x9b } }
// {23AFCB44-2093-4a94-AD9D-337A7BE0AB9B}


class wsiDatagramSocketImpl : /* public wsiObject , */ public wsiSocketOptions
{
public:
    static const ws_iid sIID;

public:

    WS_METHOD( ws_result , Bind              )(ws_int lport , wsiInetAddress * laddr) = 0;
    WS_METHOD( ws_result , Close             )(void) = 0;
    WS_METHOD( ws_result , Connect           )(wsiInetAddress * address , ws_int port) = 0;
    WS_METHOD( ws_result , Create            )(void) = 0;
    WS_METHOD( ws_result , Disconnect        )(void) = 0;
    WS_METHOD( ws_result , GetFileDescriptor )(wsiFileDescriptor ** ret) = 0;
    WS_METHOD( ws_int    , GetLocalPort      )(void) = 0;
    WS_METHOD( ws_int    , GetTimeToLive     )(void) = 0;
    WS_METHOD( ws_result , Join              )(wsiInetAddress * inetaddr) = 0;
    WS_METHOD( ws_result , JoinGroup         )(wsiSocketAddress * mcastaddr , wsiNetworkInterface * netIf) = 0;
    WS_METHOD( ws_result , Leave             )(wsiInetAddress * inetaddr) = 0;
    WS_METHOD( ws_result , LeaveGroup        )(wsiSocketAddress * mcastaddr , wsiNetworkInterface * netIf) = 0;
    WS_METHOD( ws_int    , Peek              )(wsiInetAddress * i) = 0;
    WS_METHOD( ws_int    , PeekData          )(wsiDatagramPacket * p) = 0;
    WS_METHOD( ws_result , Receive           )(wsiDatagramPacket * p) = 0;
    WS_METHOD( ws_result , Send              )(wsiDatagramPacket * p) = 0;
    WS_METHOD( ws_result , SetTimeToLive     )(ws_int ttl) = 0;

};

