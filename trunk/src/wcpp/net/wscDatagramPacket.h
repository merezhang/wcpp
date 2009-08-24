#pragma once

#include "wsiDatagramPacket.h"
#include <wcpp/lang/wscObject.h>


#define WS_ClassName_OF_wscDatagramPacket       "wcpp.net.wscDatagramPacket"


class wscDatagramPacket : public wscObject , public wsiDatagramPacket
{
    WS_IMPL_QUERY_INTERFACE_BEGIN( wscDatagramPacket )
        WS_IMPL_QUERY_INTERFACE_BODY( wsiDatagramPacket )
    WS_IMPL_QUERY_INTERFACE_END()
public:
    static const ws_char * const s_class_name;
private:
    ws_safe_ptr<wsiByteArray>  m_buffer;
    ws_int                     m_length;
protected:

    wscDatagramPacket(wsiByteArray * buf , ws_int length);
    wscDatagramPacket(wsiByteArray * buf , ws_int length , wsiInetAddress * address , ws_int port);
    wscDatagramPacket(wsiByteArray * buf , ws_int length , wsiSocketAddress * address);
    wscDatagramPacket(wsiByteArray * buf , ws_int offset , ws_int length);
    wscDatagramPacket(wsiByteArray * buf , ws_int offset , ws_int length , wsiInetAddress * address , ws_int port);
    wscDatagramPacket(wsiByteArray * buf , ws_int offset , ws_int length , wsiSocketAddress * address);

    ~wscDatagramPacket(void);

    WS_METHOD( ws_result , GetAddress       )(wsiInetAddress ** ret);
    WS_METHOD( ws_result , GetData          )(wsiByteArray ** ret);
    WS_METHOD( ws_int    , GetLength        )(void);
    WS_METHOD( ws_int    , GetOffset        )(void);
    WS_METHOD( ws_int    , GetPort          )(void);
    WS_METHOD( ws_result , GetSocketAddress )(wsiSocketAddress ** ret);
    WS_METHOD( ws_result , SetAddress       )(wsiInetAddress * iaddr);
    WS_METHOD( ws_result , SetData          )(wsiByteArray * buf);
    WS_METHOD( ws_result , SetData          )(wsiByteArray * buf , ws_int offset , ws_int length);
    WS_METHOD( ws_result , SetLength        )(ws_int length);
    WS_METHOD( ws_result , SetPort          )(ws_int iport);
    WS_METHOD( ws_result , SetSocketAddress )(wsiSocketAddress * address);

};

