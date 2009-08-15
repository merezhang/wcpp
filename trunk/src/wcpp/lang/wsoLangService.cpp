/* 
 * File:   wsolangservice.cpp
 * Author: Xukun
 * 
 * Created on 2009��7��17��, ����2:09
 */

#include "wsoLangService.h"
#include "wsiLangService.h"
#include <wcpp/wscom/wsiServiceManager.h>
#include <wcpp/wscom/WSCOM.h>
#include <wcpp/lang/helper/ws_ptr.h>


void wsoLangService::GetLangService(wsiLangService ** ret)
{
    static ws_ptr<wsiLangService> sLS;
    if (!sLS) {

        ws_ptr<wsiServiceManager> sm;
        WSCOM::WS_GetServiceManager( &sm );

        ws_ptr<wsiLangService> ls;
        sm->GetService( wsoLangService::sCID, ls.GetIID(), (void**) (&ls) );

        sLS = ls;
    }
    sLS.CopyTo( ret );
}

