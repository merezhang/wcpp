#include "wscRuntime.h"
#include "wsoLangService.h"
#include "wsiLangService.h"


void wscRuntime::GetRuntime(wsiRuntime ** ret)
{
    wsiLangService * pls = WS_NULL;
    wsoLangService::GetLangService( &pls );
    ws_ptr<wsiLangService> ls(pls);

    wsiRuntimeService * prs = WS_NULL;
    ls->GetRuntimeService( &prs );
    ws_ptr<wsiRuntimeService> rs(prs);

    rs->GetRuntime(ret);
}

