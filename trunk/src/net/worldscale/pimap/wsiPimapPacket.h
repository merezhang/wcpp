#pragma once

#include <wcpp/lang/wsiObject.h>


#define WS_IID_OF_wsiPimapPacket        \
    { 0x3ec7f045, 0xd46, 0x4f63, { 0x9c, 0xf8, 0x9, 0x14, 0xd5, 0xf8, 0x7, 0x33 } }
// {3EC7F045-0D46-4f63-9CF8-0914D5F80733}


class wsiPimapPacket : public wsiObject
{
public:
    static const ws_iid sIID;
public:

    enum flag
    {
        FLAG_SERVER_PUSH = 0x04 ,
        FLAG_NO_SIGN     = 0x02 ,
        FLAG_DOWNWARD    = 0x01 ,
    };

    enum param_type
    {
        TYPE_NULL   = 0,
        TYPE_UINT8  = 1,
        TYPE_UINT16 = 2,
        TYPE_UINT32 = 3,
        TYPE_STRING = 4,
    };

public:
    WS_METHOD( ws_uint8  , GetVersion  )(void) = 0;
    WS_METHOD( ws_uint8  , GetFlag     )(void) = 0;
    WS_METHOD( ws_uint8  , GetXOR      )(void) = 0;
    WS_METHOD( ws_uint8  , GetTransID  )(void) = 0;
    WS_METHOD( ws_uint32 , GetUserID   )(void) = 0;
    WS_METHOD( ws_uint32 , GetKey      )(void) = 0;
    WS_METHOD( ws_uint16 , GetFunction )(void) = 0;
    WS_METHOD( ws_uint16 , GetAddLen   )(void) = 0;

    WS_METHOD( void  , SetVersion  )(ws_uint8  value) = 0;
    WS_METHOD( void  , SetFlag     )(ws_uint8  value) = 0;
    WS_METHOD( void  , SetXOR      )(ws_uint8  value) = 0;
    WS_METHOD( void  , SetTransID  )(ws_uint8  value) = 0;
    WS_METHOD( void  , SetUserID   )(ws_uint32 value) = 0;
    WS_METHOD( void  , SetKey      )(ws_uint32 value) = 0;
    WS_METHOD( void  , SetFunction )(ws_uint16 value) = 0;
    WS_METHOD( void  , SetAddLen   )(ws_uint16 value) = 0;

    WS_METHOD( void  , PutParam    )(ws_uint8 id, ws_uint8 type, ws_uint32 value) = 0;
    WS_METHOD( void  , PutParam    )(ws_uint8 id, ws_uint8 type, wsiString * str) = 0;
    WS_METHOD( ws_result, GetParam )(ws_uint8 id, ws_uint8 & type, ws_uint32 & value, wsiString ** str) = 0;

};

