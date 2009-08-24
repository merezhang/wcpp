#pragma once
#include <wcpp/net/wsiDatagramSocketImplFactory.h>
#include <wcpp/lang/wscObject.h>


#define WS_ClassName_OF_wscDatagramSocketImplFactory        "wcpp.net.impl.wscDatagramSocketImplFactory"


class wscDatagramSocketImplFactory : public wscObject , public wsiDatagramSocketImplFactory
{
    WS_IMPL_QUERY_INTERFACE_BEGIN( wscDatagramSocketImplFactory )
        WS_IMPL_QUERY_INTERFACE_BODY( wsiDatagramSocketImplFactory )
    WS_IMPL_QUERY_INTERFACE_END()
public:
    static const ws_char * const s_class_name;
public:
    wscDatagramSocketImplFactory(void);
    ~wscDatagramSocketImplFactory(void);

};

