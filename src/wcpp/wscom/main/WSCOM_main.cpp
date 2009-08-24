#include "WSCOM_main.h"
#include "wscGlobalManager.h"
#include <wcpp/wscom/wscModule.h>
#include <wcpp/io/wsiFile.h>
#include "ws_runtime_main.h"


/*
***********************************************************************************************************************
	WSCOM
***********************************************************************************************************************
*/


ws_result WSCOM::WS_InitRuntime(void)
{
    ws_runtime_main::Init();
    return WS_RLT_SUCCESS;
}


ws_result WSCOM::WS_ShutdownRuntime(void)
{
    ws_runtime_main::Shutdown();
    return WS_RLT_SUCCESS;
}


ws_result WSCOM::WS_InitWSCOM(wsiServiceManager **result, wsiFile *binDirectory, wsiDirectoryServiceProvider *appFileLocationProvider)
{
    return WSCOM_main::Init( result , binDirectory , appFileLocationProvider );
}


ws_result WSCOM::WS_ShutdownWSCOM(wsiServiceManager *servMgr)
{
    return WSCOM_main::Shutdown( servMgr );
}


/*
***********************************************************************************************************************
	WSCOM_main
***********************************************************************************************************************
*/


ws_result WSCOM_main::Init(wsiServiceManager ** result, wsiFile * binDirectory, wsiDirectoryServiceProvider * appFileLocationProvider)
{
    // GetServiceManager
    ws_ptr<wsiServiceManager> servMgr;
    ws_result rlt = WSCOM::WS_GetServiceManager( & servMgr );
    if (rlt != WS_RLT_SUCCESS) return rlt;
    if (result) servMgr.CopyTo( result );

    // StartGM
    ws_ptr<wsiGlobalManager> globMgr;
    servMgr.QueryInterface2( &globMgr );
    rlt = globMgr->StartGM( binDirectory, appFileLocationProvider );
    return rlt;
}


ws_result WSCOM_main::Shutdown(wsiServiceManager * aServMgr)
{
    ws_ptr<wsiServiceManager> servMgr;
    WS_GetServiceManager( & servMgr );
    ws_ptr<wsiGlobalManager> globMgr;
    servMgr.QueryInterface2( &globMgr );
    globMgr->StopGM();

    ws_runtime_main::DestroyGlobalManager();
    return ws_result( WS_RLT_SUCCESS );
}


