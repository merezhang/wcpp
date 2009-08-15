#pragma once

#include "ws_type.h"


class ws_runnable
{
public:
    WS_VFUNC( ws_result, ThreadProc )(void) = 0;
};


class ws_thread
{
protected:
    ws_thread(void);
public:
    static ws_thread *   StartThread(ws_runnable * pRun);
    static void          Sleep(ws_long millis);
    static ws_int        GetCurrentThreadId(void);
public:
    WS_VIRTUAL_DESTRUCTOR( ws_thread );
	WS_VFUNC(ws_int,GetPriority)(void) = 0;
};

