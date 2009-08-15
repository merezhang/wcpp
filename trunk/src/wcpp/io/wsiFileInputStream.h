#pragma once

#include "wsiInputStream.h"


class wsiFileChannel;
class wsiFileDescriptor;


class wsiFileInputStream : public wsiInputStream
{
public:
    WS_METHOD( ws_int    , Available  )(void) = 0;
    WS_METHOD( ws_result , Close      )(void) = 0;
    WS_METHOD( ws_result , GetChannel )(wsiFileChannel ** ret) = 0;
    WS_METHOD( ws_result , GetFD      )(wsiFileDescriptor ** ret) = 0;
    WS_METHOD( ws_int    , Read       )(void) = 0;
    WS_METHOD( ws_int    , Read       )(void * b, ws_int len) = 0;
    WS_METHOD( ws_long   , Skip       )(ws_long n) = 0;
protected:
    WS_METHOD( ws_result , Finalize   )(void) = 0;
};

