#pragma once

#include <wcpp/net/wsiAddressImplFactory.h>
#include <wcpp/lang/wscObject.h>


#define WS_ClassName_OF_wscAddressImplFactory     "wcpp.net.impl.wscAddressImplFactory"


class wscAddressImplFactory : public wscObject , public wsiAddressImplFactory
{
    WS_IMPL_QUERY_INTERFACE_BEGIN( wscAddressImplFactory )
        WS_IMPL_QUERY_INTERFACE_BODY( wsiAddressImplFactory )
    WS_IMPL_QUERY_INTERFACE_END()
public:
    static const ws_char * const s_class_name;
public:
    wscAddressImplFactory(void);
    ~wscAddressImplFactory(void);
};

