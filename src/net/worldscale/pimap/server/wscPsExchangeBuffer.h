#pragma once
#include "wsiPsExchangeBuffer.h"
#include <wcpp/lang/wscObject.h>
#include <list>


#define WS_ClassName_OF_wscPsExchangeBuffer         "net.worldscale.pimap.server.wscPsExchangeBuffer"


class wscPsExchangeBuffer : public wscObject , public wsiPsExchangeBuffer
{
    WS_IMPL_QUERY_INTERFACE_BEGIN( wscPsExchangeBuffer )
        WS_IMPL_QUERY_INTERFACE_BODY( wsiPsExchangeBuffer )
    WS_IMPL_QUERY_INTERFACE_END()
public:
    static const ws_char * const s_class_name;
private:
    
    typedef std::list<wsiDatagramPacket*> t_list;

    wsuMutex m_mutex;
    t_list m_ready_list;
    t_list m_free_list;

    ws_int m_count_packet_limit;
    ws_int m_packet_buffer_length;

private:

    ws_int    InternalCountReadyPacket(void);
    ws_result InternalAllocatePacket(wsiDatagramPacket ** ret);

protected:
    wscPsExchangeBuffer(void);
    ~wscPsExchangeBuffer(void);

    WS_METHOD( ws_result , AllocatePacket )(wsiDatagramPacket ** ret   );
    WS_METHOD( ws_result , PushPacket     )(wsiDatagramPacket *  packet);
    WS_METHOD( ws_result , PopPacket      )(wsiDatagramPacket ** ret   );
    WS_METHOD( ws_result , RecyclePacket  )(wsiDatagramPacket *  packet);

};

