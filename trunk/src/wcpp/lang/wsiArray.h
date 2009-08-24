#pragma once

#include "wsiObject.h"



template <typename T>
class wsiArray : public wsiObject
{
public:
    static const ws_iid sIID;
public:
    WS_METHOD( ws_int    , GetSize )(void) = 0;
    WS_METHOD( ws_result , GetItem )(ws_int index, T ** ret) = 0;
    WS_METHOD( ws_result , PutItem )(ws_int index, T * item) = 0;
};


template <typename T>
class wsiValueArray : public wsiObject
{
public:
    static const ws_iid sIID;
public:
    WS_METHOD( ws_int  , Length )(void) = 0;
    WS_METHOD( T*      , Data   )(void) = 0;
};


#define WS_IID_OF_wsiByteArray      \
    { 0x91fcf79a, 0x21c8, 0x4e1d, { 0xae, 0x7b, 0x24, 0xe2, 0xae, 0x5a, 0x59, 0x32 } }
// {91FCF79A-21C8-4e1d-AE7B-24E2AE5A5932}


typedef wsiValueArray<ws_byte> wsiByteArray;
typedef wsiValueArray<ws_char> wsiCharArray;

