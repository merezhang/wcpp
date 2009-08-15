#pragma once

#include "wsiDictionary.h"
#include "wsiMap.h"
#include "wsiSet.h"
#include "wsiEnumeration.h"
#include <wcpp/io/wsiSerializable.h>
#include <wcpp/lang/wsiCloneable.h>


template <typename K , typename V>
class wsiHashtable : public wsiDictionary<K,V> , public wsiSerializable , public wsiCloneable , public wsiMap<K,V>
{
public:

    WS_METHOD( ws_result  , Clear         )(void) = 0;
    WS_METHOD( ws_result  , Clone         )(wsiObject ** ret) = 0;
    WS_METHOD( ws_boolean , Contains      )(wsiObject * value) = 0;
    WS_METHOD( ws_boolean , ContainsKey   )(wsiObject * key) = 0;
    WS_METHOD( ws_boolean , ContainsValue )(wsiObject * value) = 0;
    WS_METHOD( ws_result  , Elements      )(wsiEnumeration<V> ** ret) = 0;
//    WS_METHOD( ws_result  , EntrySet      )(wsiSet<> ** ret) = 0;
    WS_METHOD( ws_boolean , Equals        )(wsiObject * obj) = 0;
    WS_METHOD( ws_result  , Get           )(V ** ret , wsiObject * key) = 0;
    WS_METHOD( ws_int     , HashCode      )(void) = 0;
    WS_METHOD( ws_boolean , IsEmpty       )(void) = 0;
    WS_METHOD( ws_result  , Keys          )(wsiEnumeration<K> ** ret) = 0;
    WS_METHOD( ws_result  , KeySet        )(wsiSet<K> ** ret) = 0;
    WS_METHOD( ws_result  , Put           )(V ** ret , K * key , V * value) = 0;
//    WS_METHOD(  , PutAll        )() = 0;
    WS_METHOD( ws_result  , Remove        )(V ** ret, wsiObject * key) = 0;
    WS_METHOD( ws_int     , Size          )(void) = 0;
    WS_METHOD( ws_result  , ToString      )(wsiString ** ret) = 0;
    WS_METHOD( ws_result  , Values        )(wsiCollection<V> ** ret) = 0;

protected:

    WS_METHOD( ws_result  , Rehash        )(void) = 0;

};


