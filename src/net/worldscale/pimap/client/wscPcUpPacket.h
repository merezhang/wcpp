#pragma once

#include <net/worldscale/pimap/wscPimapPacket.h>
#include <net/worldscale/pimap/wsiPimapMethodsUp.h>


class wscPcUpPacket : public wscPimapPacket , public wsiPimapMethodsUp
{
public:
    wscPcUpPacket(void);
    ~wscPcUpPacket(void);
public:
    WS_METHOD( ws_result , Login  )(wsiString * username, wsiString * psw);
    WS_METHOD( ws_result , Logout )(void);
};

