#include "wscNetworkModule.h"
#include <wcpp/lang/wscObject.h>
#include <wcpp/net/impl/wscNetworkLibraryImpl.h>


/*
*************************************************************************************************************
*   wscModule
*************************************************************************************************************
*/


void wscModule::NewCurrentModule(wsiModule ** ret)
{
    NewObj<wscNetworkModule>( ret );
}


/*
*************************************************************************************************************
*   wscNetworkModule
*************************************************************************************************************
*/


wscNetworkModule::wscNetworkModule(void)
{
}


wscNetworkModule::~wscNetworkModule(void)
{
}


ws_result wscNetworkModule::IndexToClassId(ws_cid & rClass , ws_int index)
{
    ws_result ret( WS_RLT_SUCCESS );
    switch (index) {
        case 0:     rClass = wscNetworkLibrary::sCID;      break;
        default:    ret = WS_RLT_CLASS_NOT_FOUND;
    }
    return ret;
}


ws_result wscNetworkModule::NewClassFactory(wsiFactory ** ret , const ws_cid & aClass)
{
    if (aClass == wscNetworkLibrary::sCID) {
        return NewObj<wscNetworkLibraryImpl::t_factory>( ret );
    }
    else {
        return WS_RLT_CLASS_NOT_FOUND;
    }
}

