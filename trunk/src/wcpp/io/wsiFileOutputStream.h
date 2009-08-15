#pragma once

#include "wsiOutputStream.h"


class wsiFileChannel;
class wsiFileDescriptor;


class wsiFileOutputStream : public wsiOutputStream
{
public:
    WS_METHOD( ws_result , Close      )(void) = 0;
    WS_METHOD( ws_result , GetChannel )(wsiFileChannel ** ret) = 0;
    WS_METHOD( ws_result , GetFD      )(wsiFileDescriptor ** ret) = 0;
    WS_METHOD( ws_result , Write      )(const void * b, ws_int cb) = 0;
    WS_METHOD( ws_result , Write      )(ws_int b) = 0;
protected:
    WS_METHOD( ws_result , Finalize )(void) = 0;
};


