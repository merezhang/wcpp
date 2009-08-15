#include "WSCOM.h"
#include "wsiComponentManager.h"
#include "wsiComponentRegistrar.h"
#include "wsiMemory.h"
#include "wsiServiceManager.h"
#include <wcpp/lang/wscObject.h>
#include <wcpp/lang/wscThrowable.h>
#include <wcpp/lang/helper/ws_runtime.h>


ws_result WSCOM::WS_GetServiceManager(wsiServiceManager ** ret)
{
    return ws_runtime::getRuntime()->GetServiceManager( ret );
}


ws_result WSCOM::WS_GetComponentManager(wsiComponentManager ** ret)
{
    return ws_runtime::getRuntime()->GetComponentManager( ret );
}


ws_result WSCOM::WS_GetComponentRegistrar(wsiComponentRegistrar ** ret)
{
    return ws_runtime::getRuntime()->GetComponentRegistrar( ret );
}


ws_result WSCOM::WS_GetMemoryManager(wsiMemory ** ret)
{
    return ws_runtime::getRuntime()->GetMemoryManager( ret );
}

