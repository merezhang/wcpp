#pragma once

#include "ws_library.h"
#if (WS_PLATFORM == WS_PLATFORM_WIN32)
#include <windows.h>


class ws_library_win32 : public ws_library
{
public:
    ws_library_win32(const ws_char* const aLibPath);
    WS_VIRTUAL_DESTRUCTOR( ws_library_win32 );
    WS_VFUNC(void*,      GetProc    )(const ws_char* const aProcName);
    WS_VFUNC(ws_boolean, IsAvailable)(void);
private:
    HMODULE m_hModule;
};


#endif /* (WS_PLATFORM == WS_PLATFORM_WIN32) */
