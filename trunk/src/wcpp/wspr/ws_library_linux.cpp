// ws_library_linux.cpp

#include "ws_library_linux.h"
#if (WS_PLATFORM == WS_PLATFORM_LINUX)
#include <dlfcn.h>


ws_library_linux::ws_library_linux(const ws_char * const aPath) : m_handle(WS_NULL)
{
    WS_ASSERT(0);

    void * h = dlopen( aPath, RTLD_LAZY | RTDL_GLOBAL );
    m_handle = h;
}


ws_library_linux::~ws_library_linux(void)
{
    void * h = m_handle;
    m_handle = WS_NULL;
    if (h) dlclose(h);
}


void * ws_library_linux::GetProc(const ws_char* const aProcName)
{
    WS_ASSERT(0);

    void * h = m_handle;
    void * ret = WS_NULL;
    if (h) ret = dlsym(h,aProcName);
    return ret;
}


#endif /* (WS_PLATFORM == WS_PLATFORM_LINUX) */
