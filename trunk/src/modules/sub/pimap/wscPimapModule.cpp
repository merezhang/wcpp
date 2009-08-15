#include "wscPimapModule.h"
#include <wcpp/lang/wscObject.h>
#include <wcpp/lang/wscThrowable.h>
#include <net/worldscale/pimap/wscPimapLibrary.h>


/*
**************************************************************************************************************
*   wscModule
**************************************************************************************************************
*/


void wscModule::NewCurrentModule(wsiModule ** ret)
{
    NewObj<wscPimapModule>( ret );
}




/*
**************************************************************************************************************
*   wscPimapModule
**************************************************************************************************************
*/


wscPimapModule::wscPimapModule(void)
{
}


wscPimapModule::~wscPimapModule(void)
{
}


ws_result wscPimapModule::IndexToClassId(ws_cid & rClass , ws_int index)
{
    ws_result ret( WS_RLT_SUCCESS );
    switch (index) {
        case 0:     rClass = wscPimapLibrary::sCID;     break;
        default:    ret = WS_RLT_CLASS_NOT_FOUND;
    }
    return ret;
}


ws_result wscPimapModule::NewClassFactory(wsiFactory ** ret , const ws_cid & aClass)
{
    if (aClass == wscPimapLibrary::sCID) {
        return NewObj<wscPimapLibrary::t_factory>( ret );
    }
    else {
        return WS_RLT_CLASS_NOT_FOUND;
    }
}

