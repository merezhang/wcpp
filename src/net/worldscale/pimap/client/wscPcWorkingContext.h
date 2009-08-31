#pragma once

#include "wsiPcWorkingContext.h"
#include <wcpp/lang/wscObject.h>


#define WS_ClassName_OF_wscPcWorkingContext     "net.worldscale.pimap.client.wscPcWorkingContext"


class wscPcWorkingContext : public wscObject , public wsiPcWorkingContext
{
    WS_IMPL_QUERY_INTERFACE_BEGIN( wscPcWorkingContext )
        WS_IMPL_QUERY_INTERFACE_BODY( wsiPcWorkingContext )
    WS_IMPL_QUERY_INTERFACE_END()
public:
    static const ws_char * const s_class_name;
private:
    ws_boolean                        m_StopFlag;
    ws_safe_ptr<wsiDatagramSocket>    m_DatagramSocket;
    ws_safe_ptr<wsiPcExchangeBuffer>  m_ExchangeBuffer;
    ws_safe_ptr<wsiPcTransmitter>     m_Transmitter;
    ws_safe_ptr<wsiPcEventDispatcher> m_EventDispatcher;
    ws_safe_ptr<wsiPcUser>            m_User;
public:
    wscPcWorkingContext(void);
    ~wscPcWorkingContext(void);
protected:
    WS_METHOD( ws_result  , SetStopFlag       )(void);
    WS_METHOD( ws_boolean , GetStopFlag       )(void);

    WS_METHOD( ws_result , GetUser )(wsiPcUser ** ret);
    WS_METHOD( ws_result , SetUser )(wsiPcUser * user);

    WS_METHOD( ws_result  , GetDatagramSocket  )(wsiDatagramSocket    ** ret);
    WS_METHOD( ws_result  , GetExchangeBuffer  )(wsiPcExchangeBuffer  ** ret);
    WS_METHOD( ws_result  , GetTransmitter     )(wsiPcTransmitter     ** ret);
    WS_METHOD( ws_result  , GetEventDispatcher )(wsiPcEventDispatcher ** ret);

    WS_METHOD( ws_result  , SetDatagramSocket  )(wsiDatagramSocket    * p);
    WS_METHOD( ws_result  , SetExchangeBuffer  )(wsiPcExchangeBuffer  * p);
    WS_METHOD( ws_result  , SetTransmitter     )(wsiPcTransmitter     * p);
    WS_METHOD( ws_result  , SetEventDispatcher )(wsiPcEventDispatcher * p);

};

