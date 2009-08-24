#include "wscInetAddress.h"
#include "wscNetworkLibrary.h"
#include "wsiAddressImplFactory.h"


ws_result wscInetAddress::GetByAddress(wsiInetAddress ** ret, const ws_byte * buf, ws_int cb)
{
    ws_ptr<wsiNetworkLibrary> netlib;
    ws_result rlt = wscNetworkLibrary::GetNetworkLibrary( &netlib );
    if (rlt != WS_RLT_SUCCESS) return rlt;

    ws_ptr<wsiAddressImplFactory> implFac;
    rlt = netlib->GetAddressImplFactory( & implFac );
    if (rlt != WS_RLT_SUCCESS) return rlt;

    return implFac->GetByAddress( ret , buf , cb );
}


ws_result wscInetAddress::GetLocalHost(wsiInetAddress ** ret)
{
    ws_ptr<wsiNetworkLibrary> netlib;
    ws_result rlt = wscNetworkLibrary::GetNetworkLibrary( &netlib );
    if (rlt != WS_RLT_SUCCESS) return rlt;

    ws_ptr<wsiAddressImplFactory> implFac;
    rlt = netlib->GetAddressImplFactory( & implFac );
    if (rlt != WS_RLT_SUCCESS) return rlt;

    return implFac->GetLocalHost( ret );
}


wscInetAddress::wscInetAddress(void)
{
}


wscInetAddress::~wscInetAddress(void)
{
}

