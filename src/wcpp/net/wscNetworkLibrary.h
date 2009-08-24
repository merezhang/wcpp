#pragma once

#include <wcpp/wspr/ws_id.h>
#include <wcpp/wscom/wscFactory.h>
#include "wsiNetworkLibrary.h"
#include "wsiDatagramSocketImplFactory.h"
#include "wsiAddressImplFactory.h"


#define WS_ClassName_OF_wscNetworkLibrary		"wcpp.net.wscNetworkLibrary"
#define WS_ContractID_OF_wscNetworkLibrary		"@worldscale.net/network;1"
#define WS_CID_OF_wscNetworkLibrary		\
	{ 0x379c9069, 0x554a, 0x41bb, { 0x97, 0xad, 0x7f, 0x92, 0x9a, 0x19, 0xaf, 0x3a } }
// {379C9069-554A-41bb-97AD-7F929A19AF3A}


class wscNetworkLibrary : public wscObject , public wsiNetworkLibrary
{
    WS_IMPL_QUERY_INTERFACE_BEGIN( wscNetworkLibrary )
        WS_IMPL_QUERY_INTERFACE_BODY( wsiNetworkLibrary )
    WS_IMPL_QUERY_INTERFACE_END()
public:

public:
    static const ws_cid sCID;
    static const ws_char * const sContractID;
    static const ws_char * const s_class_name;
private:
    ws_safe_ptr<wsiDatagramSocketImplFactory> m_DatagramSocketImplFactory;
    ws_safe_ptr<wsiAddressImplFactory>        m_AddressImplFactory;

public:
    static ws_result GetNetworkLibrary(wsiNetworkLibrary ** ret);

protected:

    ws_result InternalSetDatagramSocketImplFactory(wsiDatagramSocketImplFactory * aImplFactory);
    ws_result InternalSetAddressImplFactory(wsiAddressImplFactory * aImplFactory);

protected:

    WS_METHOD( ws_result , GetAddressImplFactory )(wsiAddressImplFactory ** ret);

    WS_METHOD( ws_result , GetDatagramSocketImplFactory )(wsiDatagramSocketImplFactory ** ret);
    WS_METHOD( ws_result , SetDatagramSocketImplFactory )(wsiDatagramSocketImplFactory * aImplFactory);

};

