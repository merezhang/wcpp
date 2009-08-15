#include "ws_file.h"

#include "ws_file_win32.h"


ws_file * ws_file::Open(void)
{

#if   (WS_PLATFORM == WS_PLATFORM_WIN32)
    ws_file * file = new ws_file_win32();
#elif (WS_PLATFORM == WS_PLATFORM_LINUX)
    ws_file * file = new ws_file_linux();
#else
    #error no platform.
#endif

    return file;
}


ws_file * ws_file::Open(const ws_char * const filename, const ws_uint32 flag)
{

#if   (WS_PLATFORM == WS_PLATFORM_WIN32)
    ws_file * file = new ws_file_win32(filename,flag);
#elif (WS_PLATFORM == WS_PLATFORM_LINUX)
    ws_file * file = new ws_file_linux(filename,flag);
#else
    #error no platform.
#endif

    return file;
}


ws_file::ws_file(void)
{
}


ws_file::~ws_file(void)
{
}

