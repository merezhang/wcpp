#pragma once
#include "wsiDatagramSocketImpl.h"
#include <wcpp/lang/wscObject.h>


class wscDatagramSocketImpl : public wscObject , public wsiDatagramSocketImpl
{
    WS_IMPL_QUERY_INTERFACE_BEGIN( wscDatagramSocketImpl )
        WS_IMPL_QUERY_INTERFACE_BODY( wsiDatagramSocketImpl )
    WS_IMPL_QUERY_INTERFACE_END()
public:
    wscDatagramSocketImpl(void);
    ~wscDatagramSocketImpl(void);
};

