#pragma once

#include <wcpp/wspr/wspr.h>


class ws_debug_probe
{
public:
    WS_VIRTUAL ~ws_debug_probe(void){}

    WS_VFUNC( wsiObject * , SelectTarget )(wsiObject *) = 0;
};

