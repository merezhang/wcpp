#pragma once

#include "wsiPimapLibrary.h"
#include <wcpp/wscom/wscFactory.h>
#include <wcpp/lang/wscObject.h>


#define WS_ClassName_OF_wscPimapLibrary         "net.worldscale.pimap.wscPimapLibrary"
#define WS_ContractID_OF_wscPimapLibrary        "@worldscale.net/pimap;1"
#define WS_CID_OF_wscPimapLibrary       \
    { 0x2355b8b4, 0xd671, 0x44ec, { 0x8a, 0xd1, 0xc7, 0xf9, 0x2d, 0xbc, 0x40, 0x57 } }
// {2355B8B4-D671-44ec-8AD1-C7F92DBC4057}


class wscPimapLibrary : public wscObject , public wsiPimapLibrary
{
    WS_IMPL_QUERY_INTERFACE_BEGIN( wscPimapLibrary )
        WS_IMPL_QUERY_INTERFACE_BODY( wsiPimapLibrary )
    WS_IMPL_QUERY_INTERFACE_END(  )
public:

    class t_factory : public wscFactory
    {
    public:
        static const ws_char * const s_class_name;
    public:
        t_factory(void);
        ~t_factory(void);
    	WS_METHOD( ws_result , CreateInstance )(wsiObject * aOuter, const ws_iid & aIID, void ** ret);
    };

    static const ws_cid          sCID;
    static const ws_char * const sContractID;
    static const ws_char * const s_class_name;

protected:

    wscPimapLibrary(void);
    ~wscPimapLibrary(void);

    WS_METHOD( ws_result , CreateServer )(wsiPimapServer ** ret);
    WS_METHOD( ws_result , CreateClient )(wsiPimapClient ** ret);

public:
};

