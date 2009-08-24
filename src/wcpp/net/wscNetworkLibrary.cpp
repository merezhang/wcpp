#include "wscNetworkLibrary.h"

#include <wcpp/lang/wscThrowable.h>
#include <wcpp/lang/helper/ws_runtime.h>
#include <wcpp/wscom/wsiServiceManager.h>


/*
***********************************************************************************************************
*   wscNetworkLibrary
***********************************************************************************************************
*/


ws_result wscNetworkLibrary::GetNetworkLibrary(wsiNetworkLibrary ** ret)
{
    ws_result rlt(0);

    ws_ptr<wsiServiceManager> servMgr;
    rlt = ws_runtime::getRuntime()->GetServiceManager( & servMgr );
    if (rlt != WS_RLT_SUCCESS) return rlt;

    return servMgr->GetService( wscNetworkLibrary::sCID , wsiNetworkLibrary::sIID , (void**) ret );
}


ws_result wscNetworkLibrary::GetDatagramSocketImplFactory(wsiDatagramSocketImplFactory ** ret)
{
    if (ret==WS_NULL) return WS_RLT_NULL_POINTER;
    if (*ret) return WS_RLT_NULL_POINTER;
    m_DatagramSocketImplFactory.Get( ret );
    if (*ret) return WS_RLT_SUCCESS;
    return WS_RLT_FAILED;
}


ws_result wscNetworkLibrary::SetDatagramSocketImplFactory(wsiDatagramSocketImplFactory * aImplFactory)
{
    return InternalSetDatagramSocketImplFactory( aImplFactory );
}


ws_result wscNetworkLibrary::InternalSetDatagramSocketImplFactory(wsiDatagramSocketImplFactory * aImplFactory)
{
    if (aImplFactory==WS_NULL) return WS_RLT_NULL_POINTER;
    m_DatagramSocketImplFactory.Set( aImplFactory );
    return WS_RLT_SUCCESS;
}


ws_result wscNetworkLibrary::InternalSetAddressImplFactory(wsiAddressImplFactory * aImplFactory)
{
    if (aImplFactory==WS_NULL) return WS_RLT_NULL_POINTER;
    m_AddressImplFactory.Set( aImplFactory );
    return WS_RLT_SUCCESS;
}


ws_result wscNetworkLibrary::GetAddressImplFactory(wsiAddressImplFactory ** ret)
{
    if (ret==WS_NULL) return WS_RLT_NULL_POINTER;
    if (*ret) return WS_RLT_NULL_POINTER;
    m_AddressImplFactory.Get( ret );
    if (*ret) return WS_RLT_SUCCESS;
    return WS_RLT_FAILED;
}

