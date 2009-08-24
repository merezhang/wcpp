#pragma once

#include <net/worldscale/pimap/wsiPimapLibrary.h>
#include <wcpp/lang/wscObject.h>
#include <wcpp/lang/helper/ws_safe_ptr.h>


class wsiThread;
class wsiPsWorkingContext;


#define WS_ClassName_OF_wscPimapServer      "net.worldscale.pimap.server.wscPimapServer"


class wscPimapServer : public wscObject , public wsiPimapServer
{
    WS_IMPL_QUERY_INTERFACE_BEGIN( wscPimapServer )
        WS_IMPL_QUERY_INTERFACE_BODY( wsiPimapServer )
    WS_IMPL_QUERY_INTERFACE_END()
public:
    static const ws_char * const s_class_name;
private:
    ws_safe_ptr<wsiThread> m_ServerThread;
    ws_safe_ptr<wsiPsWorkingContext> m_WorkingContext;
protected:
    wscPimapServer(void);
    ~wscPimapServer(void);

    WS_METHOD( ws_result , Start )(ws_int nPort);
    WS_METHOD( ws_result , Stop  )(void);
};

