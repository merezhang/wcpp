#pragma once

#include "wscAddressImplFactory.h"
#if (WS_PLATFORM == WS_PLATFORM_WIN32)


class wscAddressImplFactory_win32 : public wscAddressImplFactory
{
public:
    WS_METHOD( ws_result , GetByAddress )(wsiInetAddress ** ret, const ws_byte * buf, ws_int cb);
    WS_METHOD( ws_result , GetLocalHost )(wsiInetAddress ** ret);
};


#endif // (WS_PLATFORM == WS_PLATFORM_WIN32)
