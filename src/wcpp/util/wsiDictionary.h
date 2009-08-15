#pragma once

#include <wcpp/lang/wsiObject.h>
#include <wcpp/util/wsiEnumeration.h>


template<typename K, typename V>
class wsiDictionary : public wsiObject
{
public:

    // all is abstract

    WS_METHOD( ws_result  , Elements )(wsiEnumeration<V> ** ret) = 0;
    WS_METHOD( ws_result  , Get      )(V ** ret , K * key) = 0;
    WS_METHOD( ws_boolean , IsEmpty  )(void) = 0;
    WS_METHOD( ws_result  , Keys     )(wsiEnumeration<K> ** ret) = 0;
    WS_METHOD( ws_result  , Put      )(V ** ret , K * key , V * value) = 0;
    WS_METHOD( ws_result  , Remove   )(V ** ret , wsiObject * key) = 0;
    WS_METHOD( ws_int     , Size     )(void) = 0;
};


