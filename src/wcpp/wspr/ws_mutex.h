/* 
 * File:   ws_mutex.h
 * Author: Xukun
 *
 * Created on 2009��7��17��, ����11:42
 */

#ifndef _WS_MUTEX_H
#define	_WS_MUTEX_H

#include "ws_def.h"


class ws_mutex
{
protected:
    ws_mutex(void);
    ws_mutex(const ws_mutex& orig);
public:
    static ws_mutex * New(void);
public:
    WS_VIRTUAL_DESTRUCTOR( ws_mutex );
    WS_VFUNC(void,Lock)(void) = 0;
    WS_VFUNC(void,Unlock)(void) = 0;
};


#endif	/* _WS_MUTEX_H */
