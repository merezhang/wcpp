// ws_file_win32.cpp

#include "ws_file_win32.h"
#include "wspr.h"
#include "ws_file_enumerator_win32.h"
#if (WS_PLATFORM == WS_PLATFORM_WIN32)
#include <windows.h>


ws_file_win32::ws_file_win32(void) : m_pfile(WS_NULL)
{
}


ws_file_win32::ws_file_win32(const ws_char *const filename, const ws_uint32 flag) : m_pfile(WS_NULL)
{
    errno_t err = fopen_s( &m_pfile, filename , "r+" );

    if (m_pfile==WS_NULL) {
        err = fopen_s( &m_pfile, filename , "w+" );
    }
}


ws_file_win32::~ws_file_win32(void)
{
    FILE * pf = m_pfile;
    m_pfile = WS_NULL;
    if (pf) fclose(pf);
}


ws_boolean ws_file_win32::IsAvailable(void)
{
    return (m_pfile != WS_NULL);
}


ws_int ws_file_win32::Read (void * const buf, const ws_int cb)
{
    if (m_pfile==WS_NULL) {
        return -1;
    }
    ws_int rlt =(ws_int) fread( buf , 1 , cb , m_pfile );
    if (rlt > 0) {
        return rlt;
    }
    else {
        return -1;
    }
}


void   ws_file_win32::Write(const void * const buf, const ws_int cb)
{
    WS_ASSERT(0);
}


void   ws_file_win32::Flush(void)
{
    WS_ASSERT(0);
}


void   ws_file_win32::Close(void)
{
    FILE * pf = m_pfile;
    m_pfile = WS_NULL;
    if (pf) fclose(pf);
}


ws_uint32 ws_file_win32::GetFileFlag(const ws_char * const path , const ws_uint32 mask ) const
{
    DWORD dwRlt = GetFileAttributesA( path );
    if (dwRlt == INVALID_FILE_ATTRIBUTES)
        return ff_ReturnFalse;

    ws_uint32 ret = 0;
    for (ws_uint32 b=1; b!=0; b<<=1) {
        if (b & mask) {
            switch (b) {
                case ff_IsDirectory:
                    ret |= ((dwRlt & FILE_ATTRIBUTE_DIRECTORY) ? (b) : (0) );
                    break;
                case ff_IsFile:
                    ret |= ((dwRlt & FILE_ATTRIBUTE_DIRECTORY) ? (0) : (b) );
                    break;
                case ff_IsHidden:
                    ret |= ((dwRlt & FILE_ATTRIBUTE_HIDDEN)    ? (b) : (0) );
                    break;
                default:;
            }
        }
    }
    return ret;
}


ws_file_enumerator * ws_file_win32::EnumerateFiles(const ws_char *const path) const
{
    return new ws_file_enumerator_win32( path );
}


#endif /* (WS_PLATFORM == WS_PLATFORM_WIN32) */
