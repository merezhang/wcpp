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
#include <wcpp/lang/helper/ws_runtime.h>


void wsoLangService::GetLangService(wsiLangService ** ret)
{
    ws_runtime::getRuntime()->GetLangService( ret );
}

