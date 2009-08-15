#include "wscRuntimeService.h"


const ws_char * const wscRuntimeService::s_class_name = "wcpp.lang.service.wscRuntimeService";


wscRuntimeService::wscRuntimeService(void)
{
}


wscRuntimeService::~wscRuntimeService(void)
{
}


ws_result wscRuntimeService::GetRuntime(wsiRuntime ** ret)
{
    m_runtime.CopyTo( ret );
    return ws_result( WS_RLT_SUCCESS );
}

