#pragma once

#include "wscDictionary.h"
#include "wsiHashtable.h"


template <typename K , typename V>
class wscHashtable : public wscDictionary<K,V> , public wsiHashtable<K,V>
{
protected:
    wscHashtable(void);
    ~wscHashtable(void);
};


