#pragma once
#include <wcpp/lang/wsiObject.h>


class wsiDatagramSocketImpl;


#define WS_IID_OF_wsiDatagramSocketImplFactory      \
    { 0xa1d61240, 0xa0b9, 0x4415, { 0x96, 0x3e, 0x59, 0x32, 0xb5, 0x4b, 0xee, 0x84 } }
// {A1D61240-A0B9-4415-963E-5932B54BEE84}


class wsiDatagramSocketImplFactory : public wsiObject
{
public:
    static const ws_iid sIID;
public:
    WS_METHOD( ws_result , CreateDatagramSocketImpl )(wsiDatagramSocketImpl ** ret) = 0;
};

