#pragma once


#include <wcpp/wspr/ws_id.h>
#include <wcpp/wspr/ws_type.h>
#include "wsiServiceManager.h"
#include "wsiComponentManager.h"
#include "wsiComponentRegistrar.h"
#include "wsiMemory.h"
#include <wcpp/lang/ref/ws_weakref.h>


class wsiDirectoryServiceProvider;


class WSCOM
{
private:
	WSCOM(void);
	~WSCOM(void);

public:

	static ws_result WS_InitRuntime   (void);
	static ws_result WS_InitWSCOM     (wsiServiceManager ** result, wsiFile * binDirectory, wsiDirectoryServiceProvider * appFileLocationProvider);
	static ws_result WS_ShutdownWSCOM (wsiServiceManager * servMgr);

	static ws_result WS_GetServiceManager     (wsiServiceManager     ** result);
	static ws_result WS_GetComponentManager   (wsiComponentManager   ** result);
	static ws_result WS_GetComponentRegistrar (wsiComponentRegistrar ** result);
	static ws_result WS_GetMemoryManager      (wsiMemory             ** result);

};

