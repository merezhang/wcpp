#include "wsuConsoleAppCore.h"
#include <wcpp/io/wscInputStream.h>
#include <wcpp/io/wscOutputStream.h>
#if (WS_PLATFORM == WS_PLATFORM_LINUX) // (linux platform begin)


class wscConsoleInputStream_linux : public wscInputStream
{
};


class wscConsoleOutputStream_linux : public wscOutputStream
{
};


class ConsoleIOStreamProvider_linux : public iConsoleIOStreamProvider
{
};



int main(void)
{
    ConsoleIOStreamProvider_linux ciosp;
    wsuConsoleAppCore cac( &ciosp );
    cac.Main();
    return 0;
}


#endif // (WS_PLATFORM == WS_PLATFORM_LINUX) // (linux platform end)
