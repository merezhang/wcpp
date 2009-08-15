#pragma once

#include "ws_file.h"
#if (WS_PLATFORM == WS_PLATFORM_WIN32)
#include <windows.h>



class ws_file_enumerator_win32 : public ws_file_enumerator
{
private:
    HANDLE            m_handle;
    WIN32_FIND_DATA   m_ffd;
public:
    ws_file_enumerator_win32(const ws_char * const path);
    ~ws_file_enumerator_win32(void);
public:
    WS_VFUNC( ws_boolean , HasMore )(void);
    WS_VFUNC( void ,       Next    )(void);
    WS_VFUNC( ws_int ,     GetName )(ws_char * b, ws_int len);
};




#endif /* (WS_PLATFORM == WS_PLATFORM_WIN32) */
