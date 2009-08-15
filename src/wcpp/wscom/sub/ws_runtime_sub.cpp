#include "ws_runtime_sub.h"
#include <wcpp/wscom/wsiComponentManager.h>
#include <wcpp/wscom/wsiRuntimeProvider.h>


void ws_runtime_sub::Init(wsiComponentManager *aCompMgr)
{
    if (aCompMgr) {
        wsiRuntimeProvider * provider = WS_NULL;
        aCompMgr->QueryInterface( (*provider).sIID , (void**)(&provider) );
        if (provider) provider->Release();
        setRuntime( provider->GetRuntime() );
    }
}

