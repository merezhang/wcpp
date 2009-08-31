#pragma once

#include "wsiPimapDecoder.h"
#include <wcpp/lang/wscObject.h>


#define WS_ClassName_OF_wscPimapDecoder     "net.worldscale.pimap.wscPimapDecoder"


class wscPimapDecoder : public wscObject , public wsiPimapDecoder
{
    WS_IMPL_QUERY_INTERFACE_BEGIN( wscPimapDecoder )
        WS_IMPL_QUERY_INTERFACE_BODY( wsiPimapDecoder )
    WS_IMPL_QUERY_INTERFACE_END()
public:
    static const ws_char * const s_class_name;
public:
    wscPimapDecoder(void);
    ~wscPimapDecoder(void);
public:
    WS_METHOD( ws_result , Decode )( wsiDatagramPacket * src , wsiPimapPacket * dest );
};

