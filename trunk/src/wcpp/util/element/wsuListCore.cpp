#include "wsuList.h"
#include <wcpp/wspr/wsuSingleLock.h>


wsuListCore::wsuListCore(void)
{
}


wsuListCore::~wsuListCore(void)
{
}


void wsuListCore::AddItem(wsiObject * p)
{
    if (p==WS_NULL) return;
    wsuValue val( p );
    wsuSingleLock lock( & m_mutex );
    m_list.push_back( val );
}

