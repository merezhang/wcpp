#pragma once

#include <wcpp/net/wscDatagramSocketImpl.h>
#if (WS_PLATFORM == WS_PLATFORM_LINUX)


class wscDatagramSocketImpl_linux : public wscDatagramSocketImpl
{
public:
    static const ws_char * const s_class_name;
public:
    wscDatagramSocketImpl_linux(void);
    ~wscDatagramSocketImpl_linux(void);
};


#endif // (WS_PLATFORM == WS_PLATFORM_LINUX)
