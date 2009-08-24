/* 
 * File:   ws_mutex_win32.cpp
 * Author: Xukun
 * 
 * Created on 2009��7��17��, ����10:36
 */

#include "ws_mutex_win32.h"
#if (WS_PLATFORM == WS_PLATFORM_WIN32)
#include <windows.h>


/*
 *******************************************************************************
 *  ws_mutex_win32
 *******************************************************************************
 */


ws_mutex_win32::ws_mutex_win32() : m_hMutex(NULL)
{
	m_hMutex = CreateMutex( NULL, FALSE, NULL );
}


ws_mutex_win32::ws_mutex_win32(const ws_mutex_win32& orig) : m_hMutex(NULL)
{
	m_hMutex = CreateMutex( NULL, FALSE, NULL );
}


ws_mutex_win32::~ws_mutex_win32(void)
{
	CloseHandle( m_hMutex );
}


void ws_mutex_win32::Lock(void)
{
	DWORD rlt = WaitForSingleObject( m_hMutex, INFINITE );
}


void ws_mutex_win32::Unlock(void)
{
	BOOL rlt = ReleaseMutex( m_hMutex );
}


#endif /* (WS_PLATFORM == WS_PLATFORM_WIN32) */
