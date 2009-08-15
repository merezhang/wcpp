#pragma once

#include <unordered_map>
#include <wcpp/wspr/wsuMutex.h>
#include "wsuKeyValue.h"


class wsuHashtableCore
{
private:
    wsuHashtableCore(const wsuHashtableCore & src);
    const wsuHashtableCore & operator = (const wsuHashtableCore & src);
private:
    typedef std::tr1::unordered_map<wsuKey,wsuValue> t_table;
    wsuMutex m_mutex;
    t_table  m_table;
public:
    wsuHashtableCore(void);
    ~wsuHashtableCore(void);
    ws_result Put(wsiObject * key, wsiObject * value);
    ws_result Get(wsiObject * key, wsiObject ** ret);
};


template <typename K, typename V>
class wsuHashtable
{
private:
    wsuHashtableCore m_core;
public:

    ws_result put(K * key, V * value)
    {
        return m_core.Put( key , value );
    }

    ws_result get(K * key, V ** ret)
    {
        return m_core.Get( key , (wsiObject**) ret );
    }

};

