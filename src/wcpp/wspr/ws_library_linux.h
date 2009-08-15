#pragma once

#include "ws_library.h"
#if (WS_PLATFORM == WS_PLATFORM_LINUX)


class ws_library_linux : public ws_library
{
public:
    ws_library_linux(const ws_char * const aPath);
    ~ws_library_linux(void);
    WS_VFUNC(void *, GetProc)(const ws_char* const aProcName);
private:
    void * m_handle;
};


#endif /* (WS_PLATFORM == WS_PLATFORM_LINUX) */
