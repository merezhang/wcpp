#pragma once

#include "wsiInet4Address.h"
#include "wscInetAddress.h"


class wscInet4Address : public wscInetAddress , public wsiInet4Address
{
    WS_IMPL_QUERY_INTERFACE_BEGIN( wscInet4Address )
        WS_IMPL_QUERY_INTERFACE_BODY_BRANCH( wsiSerializable , wscInetAddress )
        WS_IMPL_QUERY_INTERFACE_BODY_BRANCH( wsiInetAddress  , wscInetAddress )
        WS_IMPL_QUERY_INTERFACE_BODY( wsiInet4Address )
    WS_IMPL_QUERY_INTERFACE_END()
public:
    wscInet4Address();
    ~wscInet4Address(void);
};

