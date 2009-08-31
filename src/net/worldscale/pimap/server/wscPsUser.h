#pragma once

#include "wsiPsUser.h"
#include <wcpp/lang/wscObject.h>


#define WS_ClassName_OF_wscPsUser     "net.worldscale.pimap.server.wscPsUser"


class wscPsUser : public wscObject , public wsiPsUser
{
    WS_IMPL_QUERY_INTERFACE_BEGIN( wscPsUser )
        WS_IMPL_QUERY_INTERFACE_BODY( wsiPsUser )
    WS_IMPL_QUERY_INTERFACE_END()
public:
    static const ws_char * const s_class_name;
private:
    ws_uint32 m_UserId;
    char m_padding[ 128 ];
public:
    wscPsUser(ws_uint32 uid);
    ~wscPsUser(void);
protected:
    WS_METHOD( ws_uint32 , GetUserId )(void);
};

