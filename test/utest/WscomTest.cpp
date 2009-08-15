#include <windows.h>

#include "WscomTest.h"
#include <wcpp/wscom/wsiServiceManager.h>
#include <wcpp/wscom/WSCOM.h>
#include <wcpp/wscom/wscModule.h>


/*
void ThrowableTest::New(iTestCase ** ret)
{
    ThrowableTest * pnew = WS_NULL;
    wscObjectFinal<ThrowableTest>::New( &pnew );
    ws_ptr<iTestCase> keeper;
    keeper.Attach( pnew );
    keeper.CopyTo( ret );
}
*/

WscomTest::WscomTest(void)
{
}


WscomTest::~WscomTest(void)
{
}




ws_result WscomTest::doTest(void)
{
	trace( "========================================\n" );
	trace( "case:WscomTest - begin\n" );

	test_WSCOM_static_funcs();
	test_LoadLibrary();

	trace( "case:WscomTest - end\n" );
	trace( "========================================\n" );
    return ws_result( WS_RLT_SUCCESS );
}




void WscomTest::test_WSCOM_static_funcs(void)
{
	trace( "    --------------------------------    \n" );
	trace( "func:test_WSCOM_static_funcs - begin\n" );

	ws_ptr<wsiServiceManager> aServMgr;

	if (true) {
		ws_ptr<wsiServiceManager> sm;
		trace( "WSCOM::WS_InitWSCOM" );
//			WSCOM::WS_InitWSCOM( &sm, WS_NULL, WS_NULL );
		if (!sm) {
			trace( " - error : return null ServiceManager.\n" );
		} else {
			trace( " - ok\n" );
		}
		aServMgr = sm;
	}

	if (true) {
		ws_ptr<wsiComponentManager> cm;
		trace( "WSCOM::WS_GetComponentManager" );
		WSCOM::WS_GetComponentManager( &cm );
		if (!cm)
			trace( " - error : return null Component Manager.\n" );
		else
			trace( " - ok\n" );
	}

	if (true) {
		ws_ptr<wsiComponentRegistrar> cr;
		trace( "WSCOM::WS_GetComponentRegistrar" );
		WSCOM::WS_GetComponentRegistrar( &cr );
		if (!cr) {
			trace( " - error : return null wsiComponentRegistrar.\n" );
		} else {
			trace( " - ok\n" );
		}
	}

	if (true) {
		ws_ptr<wsiMemory> mm;
		trace( "WSCOM::WS_GetMemoryManager" );
		WSCOM::WS_GetMemoryManager( &mm );
		if (!mm) {
			trace( " - error : return null wsiMemory.\n" );
		} else {
			trace( " - ok\n" );
		}
	}

	if (true) {
		ws_ptr<wsiServiceManager> sm;
		trace( "WSCOM::WS_GetServiceManager" );
		WSCOM::WS_GetServiceManager( &sm );
		if (!sm) {
			trace( " - error : return null wsiServiceManager.\n" );
		} else {
			trace( " - ok\n" );
		}
	}

	if (true) {
		trace( "WSCOM::WS_ShutdownWSCOM" );
//			WSCOM::WS_ShutdownWSCOM( aServMgr );
		aServMgr.Release();
		trace( " - ok\n" );
	}

	trace( "func:test_WSCOM_static_funcs - end\n" );
	trace( "    --------------------------------    \n" );
}




void WscomTest::test_LoadLibrary(void)
{
	trace( "    --------------------------------    \n" );
	trace( "func:test_LoadLibrary - begin\n" );

	HINSTANCE hDLL = LoadLibraryA( "wcpp.net.win32.dll" );
    if (hDLL==NULL) {
        WS_THROW( wseNullPointerException , "" );
    }

	ws_proc_WSGetModule pEntry =(ws_proc_WSGetModule) GetProcAddress( hDLL, "WSGetModule" );
    if (pEntry==NULL) {
        WS_THROW( wseNullPointerException , "" );
    }

	ws_ptr<wsiComponentManager> aCompMgr;
	WSCOM::WS_GetComponentManager( &aCompMgr );

	ws_ptr<wsiModule> aModule;
	trace( "WSGetModule" );
	pEntry( aCompMgr, WS_NULL, &aModule );
	if (!aModule) {
		trace( " - error : return null wsiModule.\n" );
	} else {
		trace( " - ok.\n" );
	}

	ws_str str("");
	aModule->RegisterSelf( WS_NULL, WS_NULL, str, str );


	trace( "func:test_LoadLibrary - end\n" );
	trace( "    --------------------------------    \n" );
}



