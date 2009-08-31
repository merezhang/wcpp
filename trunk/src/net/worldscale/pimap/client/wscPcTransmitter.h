#pragma once

#include <wcpp/lang/helper/ws_safe_ptr.h>
#include "wsiPcTransmitter.h"
#include <wcpp/lang/wscObject.h>


class wsiPcWorkingContext;
class wsiPcExchangeBuffer;


#define WS_ClassName_OF_wscPcTransmitter        "net.worldscale.pimap.client.wscPcTransmitter"


class wscPcTransmitter : public wscObject , public wsiPcTransmitter
{
    WS_IMPL_QUERY_INTERFACE_BEGIN( wscPcTransmitter )
        WS_IMPL_QUERY_INTERFACE_BODY( wsiPcTransmitter )
    WS_IMPL_QUERY_INTERFACE_END()
public:
    static const ws_char * const s_class_name;
private:
    ws_safe_ptr<wsiPcWorkingContext> m_wkContext;
public:
    wscPcTransmitter(wsiPcWorkingContext * wkContext);
    ~wscPcTransmitter(void);
public:
    WS_METHOD( ws_result , SendRequest )(wsiPimapPacket * packet , wsiInetSocketAddress * sockAddr);
};

