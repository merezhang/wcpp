#include "ws_string_convertor.h"





void ws_string_convertor::utf8_to_ucs2( t_char_is  & src , t_wchar_os & dst )
{
    t_wchar buf = 0;
    for (;;) {
        const t_char c = src.Read();

        if (c & 0x80) {
            if (c & 0x40) {
                if (buf) {
                    dst.Write( buf );
                    buf = 0;
                }
                buf = c;
                t_char mask = 0x80;
                while (mask & c) {
                    buf &= (~mask);
                    mask>>=1;
                }
            }
            else {
                buf <<= 6;
                buf |= (c & 0x3f);
            }
        }
        else {
            if (buf) {
                dst.Write( buf );
                buf = 0;
            }
            if (c) dst.Write( c );
        }

        if (c==0) return;
    }
}


void ws_string_convertor::ucs2_to_utf8( t_wchar_is & src , t_char_os  & dst )
{
    for (;;) {
        const t_wchar wc = src.Read();
        if (wc==0) return;

        if      ((0x0000 <= wc) && (wc <= 0x007f)) {
            dst.Write( wc & 0x7f );
        }
        else if ((0x0080 <= wc) && (wc <= 0x07ff)) {
            dst.Write( (0xC0) | (0x1f & (wc>>6)) );
            dst.Write( (0x80) | (0x3f & wc) );
        }
        else if ((0x0800 <= wc) && (wc <= 0xffff)) {
            dst.Write( (0xE0) | (0x0f & (wc>>12)) );
            dst.Write( (0x80) | (0x3f & (wc>>6)) );
            dst.Write( (0x80) | (0x3f & wc) );
        }
    }
}


ws_string_convertor::t_cis::t_cis(const ws_char *const src) : m_src(src)
{
}


ws_string_convertor::t_cis::~t_cis(void)
{
}


ws_string_convertor::t_char ws_string_convertor::t_cis::Read(void)
{
    if (m_src) {
        t_char ret = (*m_src);
        if (ret) {
            m_src ++ ;
        }
        else {
            m_src = WS_NULL;
        }
        return ret;
    }
    else {
        return 0;
    }
}


ws_string_convertor::t_wos::t_wos(void)
{
}


ws_string_convertor::t_wos::~t_wos(void)
{
}


void ws_string_convertor::t_wos::Write(ws_string_convertor::t_wchar wchr)
{
    m_buf += wchr;
}


ws_string_convertor::t_wis::t_wis(const ws_uint16 *const src) : m_src(src)
{
}


ws_string_convertor::t_wchar ws_string_convertor::t_wis::Read(void)
{
    if (m_src) {
        t_wchar ret = (*m_src);
        if (ret) {
            m_src ++ ;
        }
        else {
            m_src = WS_NULL;
        }
        return ret;
    }
    else {
        return 0;
    }
}


ws_string_convertor::t_wis::~t_wis(void)
{
}


ws_string_convertor::t_cos::t_cos(void)
{
}


ws_string_convertor::t_cos::~t_cos(void)
{
}


void ws_string_convertor::t_cos::Write(ws_string_convertor::t_char chr)
{
    m_buf += chr;
}



