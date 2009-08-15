#include "wscRuntimeProvider.h"
#include <wcpp/lang/helper/ws_runtime.h>


ws_runtime * wscRuntimeProvider::GetRuntime(void)
{
    return ws_runtime::getRuntime();
}

