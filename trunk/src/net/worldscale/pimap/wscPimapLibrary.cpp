#include "wscPimapLibrary.h"
#include <net/worldscale/pimap/server/wscPimapServer.h>
#include <net/worldscale/pimap/client/wscPimapClient.h>


/*
*****************************************************************************************************************
*   wscPimapLibrary
*****************************************************************************************************************
*/


wscPimapLibrary::t_factory::t_factory(void)
:   wscFactory(
               wscPimapLibrary::s_class_name ,
               wscPimapLibrary::sCID ,
               wscPimapLibrary::sContractID , 
               0 , 
               0 )
{
}


wscPimapLibrary::t_factory::~t_factory(void)
{
}


ws_result wscPimapLibrary::t_factory::CreateInstance(wsiObject *aOuter, const ws_iid &aIID, void **ret)
{
    ws_ptr<wsiPimapLibrary> inst;
    ws_result rlt = NewObj<wscPimapLibrary>( &inst );
    if (rlt!=WS_RLT_SUCCESS) return rlt;

    return inst->QueryInterface( aIID , ret );
}


/*
*****************************************************************************************************************
*   wscPimapLibrary
*****************************************************************************************************************
*/


wscPimapLibrary::wscPimapLibrary(void)
{
}


wscPimapLibrary::~wscPimapLibrary(void)
{
}


ws_result wscPimapLibrary::CreateServer(wsiPimapServer ** ret)
{
    return NewObj<wscPimapServer>(ret);
}


ws_result wscPimapLibrary::CreateClient(wsiPimapClient ** ret)
{
    return NewObj<wscPimapClient>(ret);
}

