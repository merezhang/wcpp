#pragma once

#include <wcpp/wspr/wspr.h>


class ws_debug_probe;
class wsiServiceManager;
class wsiComponentManager;
class wsiComponentRegistrar;
class wsiMemory;
class wsiObject;
class wsiThrowable;
class wsiLangService;


class ws_runtime
{
private:
    static ws_runtime * s_pRuntime;
protected:
    static void setRuntime(ws_runtime * pRT) { s_pRuntime = pRT; }
public:
    static ws_runtime * getRuntime(void) { return s_pRuntime; }

public:

    virtual ~ws_runtime(void) {}

    WS_METHOD( ws_result , GetServiceManager     )(wsiServiceManager ** ret) = 0;
    WS_METHOD( ws_result , GetComponentManager   )(wsiComponentManager ** ret) = 0;
    WS_METHOD( ws_result , GetComponentRegistrar )(wsiComponentRegistrar ** ret) = 0;
    WS_METHOD( ws_result , GetMemoryManager      )(wsiMemory ** ret) = 0;
    WS_METHOD( ws_result , GetLangService        )(wsiLangService ** ret) = 0;

    WS_METHOD( ws_int , IncrementRefcnt      )(ws_int * pn) = 0;
    WS_METHOD( ws_int , DecrementRefcnt      )(ws_int * pn) = 0;

    WS_METHOD( void , SwapPtr         )(void ** pp1 , void ** pp2) = 0;
    WS_METHOD( void , PreRelease      )(wsiObject * obj) = 0;
    WS_METHOD( void , Throw           )(wsiThrowable * aThrowable) = 0;

#ifdef WS_DEBUG

    WS_METHOD( ws_debug_probe * , debugNewProbe )(void) = 0;

#endif

};

