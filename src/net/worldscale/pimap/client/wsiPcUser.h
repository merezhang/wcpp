#pragma once

#include <wcpp/lang/wsiObject.h>


class wsiInetSocketAddress;


#define WS_IID_OF_wsiPcUser     \
    { 0x179026a8, 0xd8e4, 0x423e, { 0xb4, 0x18, 0xc9, 0x1b, 0x54, 0xa8, 0xdc, 0x57 } }
// {179026A8-D8E4-423e-B418-C91B54A8DC57}


class wsiPcUser : public wsiObject
{
public:
    static const ws_iid sIID;
public:
    WS_METHOD( ws_result , GetServerAddress )(wsiInetSocketAddress ** ret) = 0;
    WS_METHOD( ws_result , SetServerAddress )(wsiInetSocketAddress * addr) = 0;
};

