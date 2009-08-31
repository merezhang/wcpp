#pragma once

#include <wcpp/lang/wsiObject.h>


class wsiPsUser;


#define WS_IID_OF_wsiPsUserTable      \
    { 0x7b001361, 0xe44d, 0x4eca, { 0xbd, 0x67, 0xc7, 0x60, 0xfe, 0x98, 0xb, 0xb5 } }
// {7B001361-E44D-4eca-BD67-C760FE980BB5}


class wsiPsUserTable : public wsiObject
{
public:
    static const ws_iid sIID;
public:
    WS_METHOD( ws_result , Put    )(wsiPsUser * user) = 0;
    WS_METHOD( ws_result , Get    )(wsiPsUser ** ret, ws_uint32 uid) = 0;
    WS_METHOD( ws_result , Remove )(ws_uint32 uid) = 0;
};

