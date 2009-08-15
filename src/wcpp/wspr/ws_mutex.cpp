/* 
 * File:   ws_mutex.cpp
 * Author: Xu Kun <xukun17@sina.com>
 * 
 * Created on 2009年7月17日, 上午11:42
 */

#include "ws_mutex.h"
#include "ws_mutex_win32.h"



ws_mutex * ws_mutex::New(void)
{

#if (WS_PLATFORM == WS_PLATFORM_WIN32)
    ws_mutex * ret = new ws_mutex_win32();
#else
    #error no platform.
#endif

    return ret;
}


ws_mutex::ws_mutex()
{
}

ws_mutex::ws_mutex(const ws_mutex& orig)
{
}

ws_mutex::~ws_mutex()
{
}

