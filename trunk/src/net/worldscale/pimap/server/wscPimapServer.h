#pragma once

#include <net/worldscale/pimap/wsiPimapLibrary.h>
#include <wcpp/lang/wscObject.h>


#define WS_ClassName_OF_wscPimapServer      "net.worldscale.pimap.server.wscPimapServer"


class wscPimapServer : public wscObject , public wsiPimapServer
{
    WS_IMPL_QUERY_INTERFACE_BEGIN( wscPimapServer )
        WS_IMPL_QUERY_INTERFACE_BODY( wsiPimapServer )
    WS_IMPL_QUERY_INTERFACE_END()
public:
    static const ws_char * const s_class_name;
protected:
    wscPimapServer(void);
    ~wscPimapServer(void);

    WS_METHOD( ws_result , Start )(ws_int nPort);
    WS_METHOD( ws_result , Stop  )(void);
};



