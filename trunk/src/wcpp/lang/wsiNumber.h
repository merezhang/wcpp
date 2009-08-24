#pragma once

#include <wcpp/io/wsiSerializable.h>


#define WS_IID_OF_wsiNumber     \
    { 0x9c4de63b, 0x7dc0, 0x455b, { 0x9b, 0xdc, 0xb6, 0xb1, 0x67, 0x17, 0xc6, 0x1a } }
// {9C4DE63B-7DC0-455b-9BDC-B6B16717C61A}


class wsiNumber : public wsiSerializable
{
public:
	static const ws_iid sIID;
public:
    WS_METHOD( ws_byte   , ByteValue   )(void) = 0;
    WS_METHOD( ws_double , DoubleValue )(void) = 0;
    WS_METHOD( ws_float  , FloatValue  )(void) = 0;
    WS_METHOD( ws_int    , IntValue    )(void) = 0;
    WS_METHOD( ws_long   , LongValue   )(void) = 0;
    WS_METHOD( ws_short  , ShortValue  )(void) = 0;
};

