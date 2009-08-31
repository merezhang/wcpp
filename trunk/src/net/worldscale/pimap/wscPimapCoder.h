#pragma once

#include "wsiPimapCoder.h"
#include <wcpp/lang/wscObject.h>


#define WS_ClassName_OF_wscPimapCoder     "net.worldscale.pimap.wscPimapCoder"


class wscPimapCoder : public wscObject , public wsiPimapCoder
{
    WS_IMPL_QUERY_INTERFACE_BEGIN( wscPimapCoder )
        WS_IMPL_QUERY_INTERFACE_BODY( wsiPimapCoder )
    WS_IMPL_QUERY_INTERFACE_END()
public:
    static const ws_char * const s_class_name;
public:
    wscPimapCoder(void);
    ~wscPimapCoder(void);
public:
    WS_METHOD( ws_result , Code )( wsiPimapPacket * src , wsiDatagramPacket * dest );
};

