#pragma once

#include "wsiInetSocketAddress.h"
#include "wscSocketAddress.h"


class wscInetSocketAddress : public wscSocketAddress , public wsiInetSocketAddress
{
public:
    wscInetSocketAddress(wsiInetAddress * addr, ws_int port);
    wscInetSocketAddress(ws_int port);
    wscInetSocketAddress(wsiString * hostname, ws_int port);
    ~wscInetSocketAddress(void);
public:
    static ws_result CreateUnresolved(wsiInetSocketAddress ** ret, wsiString * host, ws_int port);
};

