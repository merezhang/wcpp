#pragma once

#include "wsiInetAddress.h"
#include "wsiInetSocketAddress.h"
#include "wscSocketAddress.h"


#define WS_ClassName_OF_wscInetSocketAddress        "wcpp.net.wscInetSocketAddress"


class wscInetSocketAddress : public wscSocketAddress , public wsiInetSocketAddress
{
    WS_IMPL_QUERY_INTERFACE_BEGIN( wscInetSocketAddress )
        WS_IMPL_QUERY_INTERFACE_BODY( wsiInetSocketAddress )
        WS_IMPL_QUERY_INTERFACE_BODY_BRANCH( wsiSocketAddress , wsiInetSocketAddress )
        WS_IMPL_QUERY_INTERFACE_BODY_BRANCH( wsiSerializable  , wsiInetSocketAddress )
    WS_IMPL_QUERY_INTERFACE_END()
public:
    static const ws_char * const s_class_name;
private:
    ws_safe_ptr<wsiString>       m_hostName;
    ws_safe_ptr<wsiInetAddress>  m_address;
    ws_int                       m_port;
public:
    wscInetSocketAddress(wsiInetAddress * addr, ws_int port);
    wscInetSocketAddress(ws_int port);
    wscInetSocketAddress(wsiString * hostname, ws_int port);
    ~wscInetSocketAddress(void);
public:
    static ws_result CreateUnresolved(wsiInetSocketAddress ** ret, wsiString * host, ws_int port);

protected:

    ws_boolean  InternalEquals       (wsiObject * obj);
    ws_int      InternalHashCode     (void);
    ws_result   InternalToString     (wsiString ** ret);

    WS_METHOD( ws_result  , GetAddress   )(wsiInetAddress ** ret);
    WS_METHOD( ws_result  , GetHostName  )(wsiString ** ret);
    WS_METHOD( ws_int     , GetPort      )(void);
    WS_METHOD( ws_boolean , IsUnresolved )(void);

};

