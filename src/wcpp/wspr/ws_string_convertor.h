#pragma once

#include "ws_type.h"
#include <string>


class ws_string_convertor
{
public:

    typedef ws_uint16  t_wchar;
    typedef ws_uint8   t_char;

    class t_char_is
    {
    public:
        WS_VFUNC( t_char , Read )(void) = 0;
    };

    class t_char_os
    {
    public:
        WS_VFUNC( void , Write )(t_char chr) = 0;
    };

    class t_wchar_is
    {
    public:
        WS_VFUNC( t_wchar , Read )(void) = 0;
    };

    class t_wchar_os
    {
    public:
        WS_VFUNC( void , Write )(t_wchar wchr) = 0;
    };


    static void utf8_to_ucs2( t_char_is  & src , t_wchar_os & dst );
    static void ucs2_to_utf8( t_wchar_is & src , t_char_os  & dst );


    class t_wis : public t_wchar_is
    {
    private:
        const ws_uint16 * m_src;
    public:
        t_wis(const ws_uint16 * const src);
        ~t_wis(void);
        WS_VFUNC( t_wchar , Read )(void);
    };


    class t_wos : public t_wchar_os
    {
    public:
        std::wstring m_buf;
    public:
        t_wos(void);
        ~t_wos(void);
        WS_VFUNC( void , Write )(t_wchar wchr);
    };


    class t_cis : public t_char_is
    {
    private:
        const ws_char * m_src;
    public:
        t_cis(const ws_char * const src);
        ~t_cis(void);
        WS_VFUNC( t_char , Read )(void);
    };


    class t_cos : public t_char_os
    {
    public:
        std::string m_buf;
    public:
        t_cos(void);
        ~t_cos(void);
        WS_VFUNC( void , Write )(t_char chr);
    };

};



