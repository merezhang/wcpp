#pragma once
#include "ws_type.h"


class ws_library
{
public:
    static ws_library * Load(const ws_char* const aPath);
protected:
    ws_library(void);
public:
    WS_VIRTUAL_DESTRUCTOR( ws_library );
    WS_VFUNC(void*,     GetProc    )(const ws_char* const aProcName) = 0;
    WS_VFUNC(ws_boolean,IsAvailable)(void) = 0;
};

