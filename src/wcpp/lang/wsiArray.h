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



