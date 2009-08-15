#pragma once

#include <wcpp/lang/helper/ws_runtime.h>
#include <wcpp/wspr/wsuMutex.h>
#include <wcpp/lang/helper/ws_ptr.h>
#include <vector>
#include <wcpp/wscom/wscFactory.h>
#include "wsuGC.h"


class ws_runtime_main : public ws_runtime
{
private:
    
    wsuMutex m_mutexForRefcnt;
    wsuMutex m_mutexForSwap;

    ws_ptr<wsiServiceManager>       m_ServMgr;
    ws_ptr<wsiComponentManager>     m_CompMgr;
    ws_ptr<wsiComponentRegistrar>   m_CompReg;
    ws_ptr<wsiMemory>               m_Memory;

    wsuGC   m_gc;

    static ws_runtime_main * s_Instance;

private:

    ws_runtime_main(void);
    ~ws_runtime_main(void);

public:

    static void Init(void);
    static void DestroyGlobalManager(void);

public:     // debug

    WS_METHOD( ws_debug_probe * , debugNewProbe )(void);

public:     // ws_runtime

    WS_METHOD( ws_result , GetServiceManager     )(wsiServiceManager ** ret);
    WS_METHOD( ws_result , GetComponentManager   )(wsiComponentManager ** ret);
    WS_METHOD( ws_result , GetComponentRegistrar )(wsiComponentRegistrar ** ret);
    WS_METHOD( ws_result , GetMemoryManager      )(wsiMemory ** ret);

    WS_METHOD( ws_int , IncrementRefcnt      )(ws_int * pn);
    WS_METHOD( ws_int , DecrementRefcnt      )(ws_int * pn);

    WS_METHOD( void , SwapPtr         )(void ** pp1, void ** pp2);
    WS_METHOD( void , PreRelease      )(wsiObject * obj);
    WS_METHOD( void , Throw           )(wsiThrowable * aThrowable);


};

