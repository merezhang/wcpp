#pragma once

#include <net/worldscale/pimap/wsiPimapLibrary.h>
#include <wcpp/lang/wscObject.h>


class wsiPcWorkingContext;
class wsiThread;
class wsiPimapMethodsUp;
class wsiPcExchangeBuffer;


#define WS_ClassName_OF_wscPimapClient      "net.worldscale.pimap.client.wscPimapClient"


class wscPimapClient : public wscObject , public wsiPimapClient
{
    WS_IMPL_QUERY_INTERFACE_BEGIN( wscPimapClient )
        WS_IMPL_QUERY_INTERFACE_BODY( wsiPimapClient )
    WS_IMPL_QUERY_INTERFACE_END()
public:
    static const ws_char * const s_class_name;
private:
    ws_safe_ptr<wsiPcWorkingContext>  m_WorkingContext;
    ws_safe_ptr<wsiThread>            m_WorkingThread;
private:
    ws_result InternalClose(void);
    ws_result InternalPost( wsiPimapMethodsUp * methods );
protected:
    wscPimapClient(void);
    ~wscPimapClient(void);

    WS_METHOD( ws_result , Login  )(wsiString * aUserName, wsiString * aPassword, wsiString * aServerAddr, ws_int aPort);
    WS_METHOD( ws_result , Logout )(void);
    WS_METHOD( ws_result , Close  )(void);
};

