#pragma once

#include "wsiPcEventDispatcher.h"
#include <wcpp/lang/wscThread.h>
#include <wcpp/lang/helper/ws_safe_ptr.h>


class wsiPcWorkingContext;
class wsiPcExchangeBuffer;


#define WS_ClassName_OF_wscPcEventDispatcher     "net.worldscale.pimap.client.wscPcEventDispatcher"


class wscPcEventDispatcher : public wscObject , public wsiPcEventDispatcher
{
    WS_IMPL_QUERY_INTERFACE_BEGIN( wscPcEventDispatcher )
        WS_IMPL_QUERY_INTERFACE_BODY( wsiPcEventDispatcher )
    WS_IMPL_QUERY_INTERFACE_END()
public:
    static const ws_char * const s_class_name;
private:
    ws_safe_ptr<wsiPcWorkingContext> m_wkContext;
public:
    wscPcEventDispatcher(wsiPcWorkingContext * wkContext);
    ~wscPcEventDispatcher(void);
public:
};

