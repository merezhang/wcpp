#pragma once

#include <net/worldscale/pimap/wsiPimapLibrary.h>
#include <wcpp/lang/wscObject.h>


#define WS_ClassName_OF_wscPimapClient      "net.worldscale.pimap.client.wscPimapClient"


class wscPimapClient : public wscObject , public wsiPimapClient
{
    WS_IMPL_QUERY_INTERFACE_BEGIN( wscPimapClient )
        WS_IMPL_QUERY_INTERFACE_BODY( wsiPimapClient )
    WS_IMPL_QUERY_INTERFACE_END()
public:
    static const ws_char * const s_class_name;
protected:
    wscPimapClient(void);
    ~wscPimapClient(void);

    WS_METHOD( ws_result , Login  )(wsiString * aUserName, wsiString * aPassword, wsiString * aServerAddr);
    WS_METHOD( ws_result , Logout )(void);
};



