#pragma once
#include "wsiPsWorkingContext.h"
#include <wcpp/lang/wscObject.h>


class wsiPsExchangeBuffer;
class wsiDatagramSocket;
class wsiPsUserTable;


#define WS_ClassName_OF_wscPsWorkingContext         "net.worldscale.pimap.server.wscPsWorkingContext"


class wscPsWorkingContext : public wscObject , public wsiPsWorkingContext
{
    WS_IMPL_QUERY_INTERFACE_BEGIN( wscPsWorkingContext )
        WS_IMPL_QUERY_INTERFACE_BODY( wsiPsWorkingContext )
    WS_IMPL_QUERY_INTERFACE_END()
public:
    static const ws_char * const s_class_name;
private:
    ws_boolean    m_StopFlag;
    ws_int        m_nListeningPort;
    ws_safe_ptr<wsiPsExchangeBuffer>   m_ExchangeBuffer;
    ws_safe_ptr<wsiDatagramSocket>     m_DatagramSocket;
    ws_safe_ptr<wsiPsUserTable>        m_UserTable;
protected:
    wscPsWorkingContext(ws_int nPort);
    ~wscPsWorkingContext(void);

    WS_METHOD( ws_result  , SetStopFlag )(void);
    WS_METHOD( ws_boolean , GetStopFlag )(void);
    WS_METHOD( ws_int     , GetListeningPort )(void);
    WS_METHOD( ws_result  , GetExchangeBuffer )(wsiPsExchangeBuffer ** ret);
    WS_METHOD( ws_result  , GetDatagramSocket )(wsiDatagramSocket ** ret);
    WS_METHOD( ws_result  , SetDatagramSocket )(wsiDatagramSocket * aDatagramSocket);
    WS_METHOD( ws_result  , GetUserTable      )(wsiPsUserTable ** ret);

};

