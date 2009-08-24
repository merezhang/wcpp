#pragma once
#include <wcpp/lang/wsiObject.h>


class wsiSocketOptions : public wsiObject
{
public:
    static const ws_iid sIID;
public:
    enum fields
    {
        IP_MULTICAST_IF,
        IP_MULTICAST_IF2,
        IP_MULTICAST_LOOP,
        IP_TOS,
        SO_BINDADDR,
        SO_BROADCAST,
        SO_KEEPALIVE,
        SO_LINGER,
        SO_OOBINLINE,
        SO_RCVBUF,
        SO_REUSEADDR,
        SO_SNDBUF,
        SO_TIMEOUT,
        TCP_NODELAY,
    };
public:
    WS_METHOD( ws_result , GetOption )(wsiObject ** ret , ws_int optID) = 0;
    WS_METHOD( ws_result , SetOption )(ws_int optID , wsiObject * value) = 0;
};

