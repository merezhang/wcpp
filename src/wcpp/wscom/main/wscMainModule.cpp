#include "wscMainModule.h"

#include <wcpp/lang/wsoLangService.h>
#include <wcpp/lang/service/wscLangService.h>


/*
 *************************************************************************************************
 *  wscModule
 *************************************************************************************************
 */


void wscModule::NewCurrentModule(wsiModule ** ret)
{
    NewObj<wscMainModule>( ret );
}


/*
 *************************************************************************************************
 *  wscMainModule
 *************************************************************************************************
 */


const ws_char * const wscMainModule::s_class_name = "wcpp.wscom.main.wscMainModule";


wscMainModule::wscMainModule(void)
{
}


wscMainModule::~wscMainModule(void)
{
}


ws_result wscMainModule::IndexToClassId(ws_cid & rCid , ws_int index)
{
    ws_result ret( WS_RLT_SUCCESS );
    switch (index) {
        case 0:     rCid = wsoLangService::sCID;    break;
        default:    ret = WS_RLT_CLASS_NOT_FOUND;
    }
    return ret;
}


ws_result wscMainModule::NewClassFactory(wsiFactory ** ret , const ws_cid & aClass)
{
    if (aClass == wsoLangService::sCID) {
        return NewObj<wscLangService::t_factory>( ret );
    }
    else {
        return WS_RLT_CLASS_NOT_FOUND;
    }
}

