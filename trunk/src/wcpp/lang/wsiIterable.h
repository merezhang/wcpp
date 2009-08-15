#pragma once

#include "wsiObject.h"
#include <wcpp/util/wsiIterator.h>


template <typename T>
class wsiIterable : public wsiObject
{
public:
    static const ws_iid sIID;
public:
    WS_METHOD( ws_result , Iterator )(wsiIterator<T> ** ret) = 0;
};


