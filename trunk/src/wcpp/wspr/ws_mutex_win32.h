/* 
 * File:   ws_mutex_win32.h
 * Author: Xukun
 *
 * Created on 2009��7��17��, ����10:36
 */

#ifndef _WS_MUTEX_WIN32_H
#define	_WS_MUTEX_WIN32_H

#include "ws_mutex.h"
#if (WS_PLATFORM == WS_PLATFORM_WIN32)
#include <windows.h>


class ws_mutex_win32 : public ws_mutex
{
public:
    ws_mutex_win32(void);
private:
    ws_mutex_win32(const ws_mutex_win32& orig);
    WS_VIRTUAL_DESTRUCTOR( ws_mutex_win32 );
    WS_VFUNC(void,Lock)(void);
    WS_VFUNC(void,Unlock)(void);
private:
    HANDLE m_hMutex;
};


#endif /* (WS_PLATFORM == WS_PLATFORM_WIN32) */

#endif	/* _WS_MUTEX_WIN32_H */
