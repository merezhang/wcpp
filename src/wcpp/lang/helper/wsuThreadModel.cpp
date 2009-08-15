#include "wsuThreadModel.h"
#include <wcpp/wspr/wsuSingleLock.h>
#include <wcpp/lang/wscThrowable.h>
#include "ws_runtime.h"


ws_int wsuMultiThreadModel::Decrement(ws_int &n)
{
    return ws_runtime::getRuntime()->DecrementRefcnt( & n );
}


ws_int wsuMultiThreadModel::Increment(ws_int &n)
{
    return ws_runtime::getRuntime()->IncrementRefcnt( & n );
}

