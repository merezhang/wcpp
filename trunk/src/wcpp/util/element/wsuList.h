#pragma once

#include <list>
#include "wsuKeyValue.h"
#include <wcpp/wspr/wsuMutex.h>


class wsuListCore
{
private:
    wsuListCore(const wsuListCore & src);
    const wsuListCore & operator = (const wsuListCore & src);
private:
    typedef std::list<wsuValue> t_list;
    wsuMutex m_mutex;
    t_list   m_list;
public:
    wsuListCore(void);
    ~wsuListCore(void);
    void AddItem(wsiObject * p);
};


template <typename T>
class wsuList
{
private:
    wsuListCore m_core;
public:
    void AddItem(T * p)
    {
        m_core.AddItem( p );
    }
};


