#include "ws_thread_win32.h"
#include <windows.h>


/*
***********************************************************************************************************
*   ws_thread
***********************************************************************************************************
*/


DWORD WINAPI ws_thread_proc(LPVOID lpParameter)
{
    ws_runnable * pRun =(ws_runnable *) lpParameter;
    if (pRun) pRun->ThreadProc();
    return 0;
}


ws_thread * ws_thread::StartThread(ws_runnable * pRun)
{
    DWORD tid;
    HANDLE hThread = CreateThread( NULL, 0, ws_thread_proc, pRun, 0, &tid );
    ws_thread_win32 * ret = new ws_thread_win32( hThread, tid );
    return ret;
}


void ws_thread::Sleep(ws_long millis)
{
    ::Sleep( (DWORD) millis );
}


ws_int ws_thread::GetCurrentThreadId(void)
{
    return ::GetCurrentThreadId();
}


/*
***********************************************************************************************************
*   ws_thread_win32
***********************************************************************************************************
*/


ws_thread_win32::ws_thread_win32(HANDLE hThread, DWORD dwThreadId)
:   m_hThread( hThread ),
    m_dwThreadId( dwThreadId )
{
}


ws_thread_win32::~ws_thread_win32(void)
{
}


ws_int ws_thread_win32::GetPriority(void)
{
    return 0;
}

