#pragma once

#include <wcpp/wspr/wspr.h>
#include <wcpp/lang/helper/ws_safe_ptr.h>


class wsiInputStream;
class wsiOutputStream;
class wsiServiceManager;


class iConsoleIOStreamProvider
{
public:
    WS_METHOD( ws_result , CreateInputStream  )(wsiInputStream  ** ret) = 0;
    WS_METHOD( ws_result , CreateOutputStream )(wsiOutputStream ** ret) = 0;
};


class wsuConsoleAppCore
{
private:
    ws_safe_ptr<wsiInputStream>    m_consoleInputStream;
    ws_safe_ptr<wsiOutputStream>   m_consoleOutputStream;
    ws_safe_ptr<wsiServiceManager> m_ServMgr;
public:
    wsuConsoleAppCore( iConsoleIOStreamProvider * aConsoleIOStreamProvider );
    ~wsuConsoleAppCore(void);
    void Main(void);
};

