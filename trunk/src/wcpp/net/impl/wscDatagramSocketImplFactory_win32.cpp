#include "wscDatagramSocketImplFactory_win32.h"
#include "wscDatagramSocketImpl_win32.h"
#include <wcpp/lang/wscThrowable.h>

#if (WS_PLATFORM == WS_PLATFORM_WIN32)


ws_result wscDatagramSocketImplFactory_win32::CreateDatagramSocketImpl(wsiDatagramSocketImpl ** ret)
{
    return NewObj<wscDatagramSocketImpl_win32>( ret );
}


#endif // (WS_PLATFORM == WS_PLATFORM_WIN32)
