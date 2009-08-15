#include "ws_library.h"

#include "ws_library_win32.h"
#include "ws_library_linux.h"




ws_library * ws_library::Load(const ws_char * const aLibPath)
{

#if   (WS_PLATFORM == WS_PLATFORM_WIN32)
    ws_library * lib = new ws_library_win32( aLibPath );
#elif (WS_PLATFORM == WS_PLATFORM_LINUX)
    ws_library * lib = new ws_library_linux( aLibPath );
#else
    #error no platform.
#endif

    return lib;
}




ws_library::ws_library(void)
{
}


ws_library::~ws_library(void)
{
}



