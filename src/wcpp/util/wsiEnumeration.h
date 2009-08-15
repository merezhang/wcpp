#pragma once

#include <wcpp/lang/wsiObject.h>


template <typename E>
class wsiEnumeration : public wsiObject
{
public:
    static const ws_iid sIID;
public:
    WS_METHOD( ws_boolean , HasMoreElements )(void) = 0;
    WS_METHOD( ws_result  , NextElement     )(E ** ret) = 0;
};

