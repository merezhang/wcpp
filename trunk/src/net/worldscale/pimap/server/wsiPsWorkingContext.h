#pragma once
#include <wcpp/lang/wsiObject.h>


class wsiPsExchangeBuffer;
class wsiDatagramSocket;
class wsiPsUserTable;


#define WS_IID_OF_wsiPsWorkingContext       \
    { 0xa53d2293, 0x5056, 0x4c66, { 0xaa, 0xe, 0xc8, 0xe6, 0x80, 0x4e, 0xe3, 0xec } }
// {A53D2293-5056-4c66-AA0E-C8E6804EE3EC}


class wsiPsWorkingContext : public wsiObject
{
public:
    static const ws_iid sIID;
public:
    WS_METHOD( ws_result  , SetStopFlag       )(void) = 0;
    WS_METHOD( ws_boolean , GetStopFlag       )(void) = 0;
    WS_METHOD( ws_int     , GetListeningPort  )(void) = 0;
    WS_METHOD( ws_result  , GetExchangeBuffer )(wsiPsExchangeBuffer ** ret) = 0;
    WS_METHOD( ws_result  , GetDatagramSocket )(wsiDatagramSocket ** ret) = 0;
    WS_METHOD( ws_result  , GetUserTable      )(wsiPsUserTable ** ret) = 0;
    WS_METHOD( ws_result  , SetDatagramSocket )(wsiDatagramSocket * aDatagramSocket) = 0;
};

