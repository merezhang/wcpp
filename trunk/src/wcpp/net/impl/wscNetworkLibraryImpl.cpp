#include "wscNetworkLibraryImpl.h"

#include "wscDatagramSocketImplFactory_win32.h"
#include "wscAddressImplFactory_win32.h"


/*
****************************************************************************************************************
*   wscNetworkLibraryImpl::t_factory
****************************************************************************************************************
*/


const ws_char * const wscNetworkLibraryImpl::t_factory::s_class_name = "wcpp.net.impl.wscNetworkLibraryImpl::t_factory";


wscNetworkLibraryImpl::t_factory::t_factory(void)
: wscFactory( wscNetworkLibraryImpl::s_class_name , wscNetworkLibraryImpl::sCID , wscNetworkLibraryImpl::sContractID , 0, 0 )
{
}


wscNetworkLibraryImpl::t_factory::~t_factory(void)
{
}


ws_result wscNetworkLibraryImpl::t_factory::CreateInstance(wsiObject *aOuter, const ws_iid &aIID, void **ret)
{
    ws_ptr<wsiNetworkLibrary> netlib;
    ws_result rlt = NewObj<wscNetworkLibraryImpl>( & netlib );
    if (rlt != WS_RLT_SUCCESS) rlt;

    return netlib->QueryInterface( aIID , ret );
}


/*
****************************************************************************************************************
*   wscNetworkLibraryImpl
****************************************************************************************************************
*/


wscNetworkLibraryImpl::wscNetworkLibraryImpl(void)
{

    ws_ptr<wsiDatagramSocketImplFactory> aDSIF;
#if (WS_PLATFORM == WS_PLATFORM_WIN32)
    NewObj<wscDatagramSocketImplFactory_win32>( & aDSIF );
#elif(WS_PLATFORM == WS_PLATFORM_LINUX)
    NewObj<wscDatagramSocketImplFactory_linux>( & aDSIF );
#else
    #error no supported platform
#endif
    InternalSetDatagramSocketImplFactory( aDSIF );


    ws_ptr<wsiAddressImplFactory> aAIF;
#if (WS_PLATFORM == WS_PLATFORM_WIN32)
    NewObj<wscAddressImplFactory_win32>( & aAIF );
#elif(WS_PLATFORM == WS_PLATFORM_LINUX)
    NewObj<wscAddressImplFactory_linux>( & aAIF );
#else
    #error no supported platform
#endif
    InternalSetAddressImplFactory( aAIF );

}


wscNetworkLibraryImpl::~wscNetworkLibraryImpl(void)
{
}

