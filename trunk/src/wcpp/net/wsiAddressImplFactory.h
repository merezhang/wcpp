#pragma once

#include <wcpp/lang/wsiObject.h>


class wsiInetAddress;


#define WS_IID_OF_wsiAddressImplFactory     \
    { 0x8fd56ab5, 0xeb5, 0x436c, { 0xb6, 0xea, 0xf4, 0xf4, 0x16, 0x86, 0xfc, 0xd7 } }
// {8FD56AB5-0EB5-436c-B6EA-F4F41686FCD7}


class wsiAddressImplFactory : public wsiObject
{
public:
    static const ws_iid sIID;
public:
    WS_METHOD( ws_result , GetByAddress )(wsiInetAddress ** ret, const ws_byte * buf, ws_int cb) = 0;
    WS_METHOD( ws_result , GetLocalHost )(wsiInetAddress ** ret) = 0;
    WS_METHOD( ws_result , GetByName    )(wsiInetAddress ** ret, wsiString * host) = 0;
};

