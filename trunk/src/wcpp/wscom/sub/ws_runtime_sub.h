#pragma once

#include <wcpp/lang/helper/ws_runtime.h>


class wsiComponentManager;


class ws_runtime_sub : public ws_runtime
{
public:
    static void Init(wsiComponentManager * aCompMgr);
};

