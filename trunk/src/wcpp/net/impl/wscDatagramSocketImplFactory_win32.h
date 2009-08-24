#pragma once

#include "wscDatagramSocketImplFactory.h"
#if (WS_PLATFORM == WS_PLATFORM_WIN32)


class wscDatagramSocketImplFactory_win32 : public wscDatagramSocketImplFactory
{
public:
    WS_METHOD( ws_result , CreateDatagramSocketImpl )(wsiDatagramSocketImpl ** ret);
};


#endif // (WS_PLATFORM == WS_PLATFORM_WIN32)
