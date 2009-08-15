#include "ws_file_enumerator_win32.h"
#include "ws_string_convertor.h"
#include <string>
#include "wspr.h"
#if (WS_PLATFORM == WS_PLATFORM_WIN32)


ws_file_enumerator_win32::ws_file_enumerator_win32(const ws_char *const path) : m_handle( INVALID_HANDLE_VALUE )
{
    ws_string_convertor::t_cis  cis( path );
    ws_string_convertor::t_wos  wos;
    ws_string_convertor::utf8_to_ucs2( cis , wos );

    wos.m_buf += ( L"/*" );

    m_handle = FindFirstFile( wos.m_buf.data() , & m_ffd );
}


ws_file_enumerator_win32::~ws_file_enumerator_win32(void)
{
    if (m_handle != INVALID_HANDLE_VALUE) {
        FindClose( m_handle );
        m_handle = INVALID_HANDLE_VALUE;
    }
}


ws_int ws_file_enumerator_win32::GetName(ws_char * b , ws_int len)
{
    ws_string_convertor::t_wis  wis( (ws_uint16*)(m_ffd.cFileName) );
    ws_string_convertor::t_cos  cos;
    ws_string_convertor::ucs2_to_utf8( wis , cos );

    ws_int rlen =(ws_int) cos.m_buf.length();
    if (rlen < len) {
        wspr::ws_memcpy( b , cos.m_buf.data() , rlen+1 );
    }

    return rlen;
}


ws_boolean ws_file_enumerator_win32::HasMore(void)
{
    return ( m_handle != INVALID_HANDLE_VALUE );
}


void ws_file_enumerator_win32::Next(void)
{
    BOOL rlt = FindNextFile( m_handle , & m_ffd );
    if (rlt==0) {
        FindClose( m_handle );
        m_handle = INVALID_HANDLE_VALUE;
    }
}



#endif /* (WS_PLATFORM == WS_PLATFORM_WIN32) */
