#pragma once

#include <wcpp/wscom/wsiRuntimeProvider.h>


class wscRuntimeProvider : public wsiRuntimeProvider
{
protected:

    WS_METHOD( ws_runtime * , GetRuntime )(void);

};

