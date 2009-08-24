#pragma once
#include <wcpp/lang/wscObject.h>
#include "wsiDatagramSocket.h"
#include "wsiDatagramSocketImpl.h"


class wsiDatagramSocketImplFactory;
class wsiDatagramSocketImpl;


#define WS_ClassName_OF_wscDatagramSocket           "wcpp.net.wscDatagramSocket"


class wscDatagramSocket : public wscObject , public wsiDatagramSocket
{
    WS_IMPL_QUERY_INTERFACE_BEGIN( wscDatagramSocket )
        WS_IMPL_QUERY_INTERFACE_BODY( wsiDatagramSocket )
    WS_IMPL_QUERY_INTERFACE_END()

public:

    static const ws_char * const s_class_name;

public:

    static ws_result SetDatagramSocketImplFactory(wsiDatagramSocketImplFactory * fac);

private:

    ws_safe_ptr<wsiDatagramSocketImpl> m_impl;

private:
    
    void InternalInit(void);

protected:

    wscDatagramSocket(void);
    wscDatagramSocket(wsiDatagramSocketImpl * impl);
    wscDatagramSocket(ws_int port);
    wscDatagramSocket(ws_int port, wsiInetAddress * laddr);
    wscDatagramSocket(wsiSocketAddress * bindaddr);

    ~wscDatagramSocket(void);

protected:

    WS_METHOD( ws_result  , Bind                   )(wsiSocketAddress * addr);
    WS_METHOD( ws_result  , Close                  )(void);
    WS_METHOD( ws_result  , Connect                )(wsiInetAddress * address, ws_int port);
    WS_METHOD( ws_result  , Connect                )(wsiSocketAddress * addr);
    WS_METHOD( ws_result  , Disconnect             )(void);
    WS_METHOD( ws_boolean , GetBroadcast           )(void);
    WS_METHOD( ws_result  , GetChannel             )(wsiDatagramChannel ** ret);
    WS_METHOD( ws_result  , GetInetAddress         )(wsiInetAddress ** ret);
    WS_METHOD( ws_result  , GetLocalAddress        )(wsiInetAddress ** ret);
    WS_METHOD( ws_int     , GetLocalPort           )(void);
    WS_METHOD( ws_result  , GetLocalSocketAddress  )(wsiSocketAddress ** ret);
    WS_METHOD( ws_int     , GetPort                )(void);
    WS_METHOD( ws_int     , GetReceiveBufferSize   )(void);
    WS_METHOD( ws_result  , GetRemoteSocketAddress )(wsiSocketAddress ** ret);
    WS_METHOD( ws_boolean , GetReuseAddress        )(void);
    WS_METHOD( ws_int     , GetSendBufferSize      )(void);
    WS_METHOD( ws_int     , GetSoTimeout           )(void);
    WS_METHOD( ws_int     , GetTrafficClass        )(void);
    WS_METHOD( ws_boolean , IsBound                )(void);
    WS_METHOD( ws_boolean , IsClosed               )(void);
    WS_METHOD( ws_boolean , IsConnected            )(void);
    WS_METHOD( ws_result  , Receive                )(wsiDatagramPacket * p);
    WS_METHOD( ws_result  , Send                   )(wsiDatagramPacket * p);
    WS_METHOD( ws_result  , SetBroadcast           )(ws_boolean on);
    WS_METHOD( ws_result  , SetReceiveBufferSize   )(ws_int size);
    WS_METHOD( ws_result  , SetReuseAddress        )(ws_boolean on);
    WS_METHOD( ws_result  , SetSendBufferSize      )(ws_int size);
    WS_METHOD( ws_result  , SetSoTimeout           )(ws_int timeout);
    WS_METHOD( ws_result  , SetTrafficClass        )(ws_int tc);

};

