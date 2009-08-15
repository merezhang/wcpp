#pragma once

#include <wcpp/lang/wscObject.h>
#include <wcpp/lang/wscClass.h>
#include "wscComponentManager.h"
#include "wscComponentRegistrar.h"
#include "wscMemory.h"
#include "wscServiceManager.h"
#include <wcpp/lang/ref/wsuSupportsWeakReference.h>
#include "wsiGlobalManager.h"
#include "wsiModuleManager.h"
#include "wscModuleManager.h"
#include "wscRuntimeProvider.h"


#define WS_ClassName_OF_wscGlobalManager        "wcpp.wscom.main.wscGlobalManager"


class wscGlobalManager :
                        public wscObject ,
                        public wscComponentManager , 
                        public wscComponentRegistrar , 
                        public wscServiceManager , 
                        public wscMemory , 
                        public wscModuleManager ,
                        public wscRuntimeProvider ,
                        public wsiGlobalManager
{
	WS_IMPL_QUERY_INTERFACE_BEGIN( wscGlobalManager )
		WS_IMPL_QUERY_INTERFACE_BODY( wsiComponentManager )
		WS_IMPL_QUERY_INTERFACE_BODY( wsiComponentRegistrar )
		WS_IMPL_QUERY_INTERFACE_BODY( wsiServiceManager )
		WS_IMPL_QUERY_INTERFACE_BODY( wsiMemory )
		WS_IMPL_QUERY_INTERFACE_BODY( wsiModuleManager )
		WS_IMPL_QUERY_INTERFACE_BODY( wsiRuntimeProvider )
		WS_IMPL_QUERY_INTERFACE_BODY( wsiGlobalManager )
	WS_IMPL_QUERY_INTERFACE_END()

public:

    typedef wscObject t_super_class;
    static const ws_char * const s_class_name;

public:

    static ws_result GetGlobalManager(wsiGlobalManager ** ret);

protected:

    wscGlobalManager(void);
	~wscGlobalManager(void);

    void FinalConstruct(void);

protected:

    WS_METHOD( ws_result , GetServiceManager     )(wsiServiceManager     ** ret);
    WS_METHOD( ws_result , GetComponentManager   )(wsiComponentManager   ** ret);
    WS_METHOD( ws_result , GetComponentRegistrar )(wsiComponentRegistrar ** ret);
    WS_METHOD( ws_result , GetMemoryManager      )(wsiMemory             ** ret);
    WS_METHOD( ws_result , GetModuleManager      )(wsiModuleManager      ** ret);

    WS_METHOD( ws_result , StartGM )(wsiFile * binDirectory, wsiDirectoryServiceProvider * appFileLocationProvider);
    WS_METHOD( ws_result , StopGM  )(void);

private:

    static wsiGlobalManager * s_Instance;

};

