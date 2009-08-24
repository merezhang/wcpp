#include "wsuConsoleAppCore.h"
#include <wcpp/io/wscInputStream.h>
#include <wcpp/io/wscOutputStream.h>
#if (WS_PLATFORM == WS_PLATFORM_WIN32) // (win32 platform begin)
#include <iostream>


/*
****************************************************************************************************************
*   wscConsoleInputStream_win32
****************************************************************************************************************
*/


class wscConsoleInputStream_win32 : public wscInputStream
{
protected:
	WS_METHOD( ws_int     , Read          )(void);
	WS_METHOD( ws_int     , Read          )(void * b, ws_int len);
};


ws_int wscConsoleInputStream_win32::Read(void *b, ws_int len)
{
    ws_byte * buf =(ws_byte *) b;
    ws_int ret = 0;
    for (; ret<len; ret++) {
        const ws_int chr = Read();
        if ((0<=chr) && (chr<=255)) {
            buf[ret] = (ws_byte)chr;
        }
        else {
            return ret;
        }
    }
    return ret;
}


ws_int wscConsoleInputStream_win32::Read(void)
{
    ws_char chr;
    std::cin.read( &chr , 1 );
    return chr;
}


/*
****************************************************************************************************************
*   wscConsoleOutputStream_win32
****************************************************************************************************************
*/


class wscConsoleOutputStream_win32 : public wscOutputStream
{
protected:
    WS_METHOD( ws_result , Write )(ws_int b);
};


ws_result wscConsoleOutputStream_win32::Write(ws_int b)
{
    ws_char chr = (ws_char) b;
    std::cout<<chr;
    return WS_RLT_SUCCESS;
}


/*
****************************************************************************************************************
*   ConsoleIOStreamProvider_win32
****************************************************************************************************************
*/


class ConsoleIOStreamProvider_win32 : public iConsoleIOStreamProvider
{
protected:
    WS_METHOD( ws_result , CreateInputStream  )(wsiInputStream  ** ret);
    WS_METHOD( ws_result , CreateOutputStream )(wsiOutputStream ** ret);
};


ws_result ConsoleIOStreamProvider_win32::CreateInputStream(wsiInputStream ** ret)
{
    return NewObj<wscConsoleInputStream_win32>(ret);
}


ws_result ConsoleIOStreamProvider_win32::CreateOutputStream(wsiOutputStream ** ret)
{
    return NewObj<wscConsoleOutputStream_win32>(ret);
}


/*
****************************************************************************************************************
*   main
****************************************************************************************************************
*/


int main(void)
{
    ConsoleIOStreamProvider_win32 ciosp;
    wsuConsoleAppCore cac( &ciosp );
    cac.Main();
    return 0;
}


#endif // (WS_PLATFORM == WS_PLATFORM_WIN32) // (win32 platform end)
