#pragma once

#include "wsiPcExchangeBuffer.h"
#include <wcpp/lang/wscThread.h>


class wsiPimapPacket;


#define WS_ClassName_OF_wscPcExchangeBuffer     "net.wroldscale.pimap.client.wscPcExchangeBuffer"


class wscPcExchangeBuffer : public wscObject , public wsiPcExchangeBuffer
{
    WS_IMPL_QUERY_INTERFACE_BEGIN( wscPcExchangeBuffer )
        WS_IMPL_QUERY_INTERFACE_BODY( wsiPcExchangeBuffer )
    WS_IMPL_QUERY_INTERFACE_END()
public:
    static const ws_char * const s_class_name;
private:
    ws_safe_ptr<wsiPimapPacket>  m_forSend ;
    ws_safe_ptr<wsiPimapPacket>  m_waitResponse ;
    ws_safe_ptr<wsiPimapPacket>  m_event ;
public:
    wscPcExchangeBuffer(void);
    ~wscPcExchangeBuffer(void);
public:
    WS_METHOD( ws_result , OnSend       )(wsiPimapPacket * packet);
    WS_METHOD( ws_result , OnReceive    )(wsiPimapPacket **   ret);
};

