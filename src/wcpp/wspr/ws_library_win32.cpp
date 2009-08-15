// ws_library_win32.cpp

#include "ws_library_win32.h"
#if (WS_PLATFORM == WS_PLATFORM_WIN32)


ws_library_win32::ws_library_win32(const ws_char * const aLibPath) : m_hModule(WS_NULL)
{
    HMODULE h = LoadLibraryA( aLibPath );
    m_hModule = h;
}


ws_library_win32::~ws_library_win32(void)
{
    HMODULE h = m_hModule;
    m_hModule = WS_NULL;
    if (h) FreeLibrary(h);
}


ws_boolean ws_library_win32::IsAvailable(void)
{
    return ((m_hModule==WS_NULL) ? WS_FALSE : WS_TRUE );
}


void * ws_library_win32::GetProc(const ws_char* const aProcName)
{
    HMODULE h = m_hModule;
    if (h) {
        return GetProcAddress( h, aProcName );
    }
    else {
        return WS_NULL;
    }
}


#endif /* (WS_PLATFORM == WS_PLATFORM_WIN32) */
