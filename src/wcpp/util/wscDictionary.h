#pragma once

#include <wcpp/lang/wscObject.h>
#include "wsiDictionary.h"


template <typename K , typename V>
class wscDictionary : public wscObject , public wsiDictionary<K,V>
{
protected:
    wscDictionary(void);
    ~wscDictionary(void);
};


