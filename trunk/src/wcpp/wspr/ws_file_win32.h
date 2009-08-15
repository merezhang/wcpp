#pragma once

#include "ws_file.h"
#if (WS_PLATFORM == WS_PLATFORM_WIN32)
#include <stdio.h>




class ws_file_win32 : public ws_file
{
public:
    ws_file_win32(void);
    ws_file_win32(const ws_char * const filename, const ws_uint32 flag);
    ~ws_file_win32(void);
public:
    WS_VFUNC( ws_int,     Read        )(void * const buf, const ws_int cb);
    WS_VFUNC( void,       Write       )(const void * const buf, const ws_int cb);
    WS_VFUNC( void,       Flush       )(void);
    WS_VFUNC( void,       Close       )(void);
    WS_VFUNC( ws_boolean, IsAvailable )(void);
public:
    WS_VFUNC( ws_uint32,  GetFileFlag )(const ws_char * const path , const ws_uint32 mask ) const;
    WS_VFUNC( ws_file_enumerator * , EnumerateFiles )(const ws_char * const path) const;

private:
    FILE * m_pfile;
};




#endif /* (WS_PLATFORM == WS_PLATFORM_WIN32) */
