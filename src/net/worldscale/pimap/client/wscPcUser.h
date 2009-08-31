#pragma once

#include "wsiPcUser.h"
#include <wcpp/lang/wscObject.h>


#define WS_ClassName_OF_wscPcUser       "net.worldscale.pimap.client.wscPcUser"


class wscPcUser : public wscObject , public wsiPcUser
{
    WS_IMPL_QUERY_INTERFACE_BEGIN( wscPcUser )
        WS_IMPL_QUERY_INTERFACE_BODY( wsiPcUser )
    WS_IMPL_QUERY_INTERFACE_END()
public:
    static const ws_char * const s_class_name;
private:
    ws_safe_ptr<wsiInetSocketAddress> m_ServerAddress;
public:
    wscPcUser(void);
    ~wscPcUser(void);
public:
    WS_METHOD( ws_result , GetServerAddress )(wsiInetSocketAddress ** ret);
    WS_METHOD( ws_result , SetServerAddress )(wsiInetSocketAddress * addr);
};

