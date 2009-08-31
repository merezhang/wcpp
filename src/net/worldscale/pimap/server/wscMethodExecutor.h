#pragma once

#include "wsiMethodExecutor.h"
#include <wcpp/lang/wscObject.h>
#include <net/worldscale/pimap/wsiPimapMethodsUp.h>


#define WS_ClassName_OF_wscMethodExecutor       "net.worldscale.pimap.server.wscMethodExecutor"


class wscMethodExecutor : public wscObject , public wsiMethodExecutor , public wsiPimapMethodsUp
{
    WS_IMPL_QUERY_INTERFACE_BEGIN( wscMethodExecutor )
        WS_IMPL_QUERY_INTERFACE_BODY( wsiMethodExecutor )
    WS_IMPL_QUERY_INTERFACE_END()
public:
    static const ws_char * const s_class_name;
private:
    TransactionContext * m_ptc;
public:
    wscMethodExecutor(void);
    ~wscMethodExecutor(void);
protected:
    WS_METHOD( ws_result , Execute )( TransactionContext & tc );
protected:
    WS_METHOD( ws_result , Login  )(wsiString * username, wsiString * psw);
    WS_METHOD( ws_result , Logout )(void);
};

