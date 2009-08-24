#pragma once

#include "wsiInet6Address.h"
#include "wscInetAddress.h"


class wscInet6Address : public wscInetAddress , public wsiInet6Address
{
public:
    wscInet6Address(void);
    ~wscInet6Address(void);
public:
    static ws_result GetByAddress(wsiInet6Address ** ret, wsiString * host, wsiByteArray * addr, ws_int scope_id);
    static ws_result GetByAddress(wsiInet6Address ** ret, wsiString * host, wsiByteArray * addr, wsiNetworkInterface * nif);
};

