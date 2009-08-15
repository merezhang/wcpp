#include "WSCOM_sub.h"
#include <wcpp/lang/wscThrowable.h>
#include <wcpp/wspr/wsuSingleLock.h>
#include <wcpp/wscom/wscModule.h>
#include "ws_runtime_sub.h"


/*
***********************************************************************************************************************
	WSGetModule - the sub module entry
***********************************************************************************************************************
*/


ws_result WSGetModule( wsiComponentManager *aCompMgr, wsiFile* location, wsiModule** return_cobj )
{
    return WSCOM_sub::_real_WSGetModule( aCompMgr, location, return_cobj );
}


/*
***********************************************************************************************************************
	WSCOM
***********************************************************************************************************************
*/


ws_result WSCOM::WS_InitRuntime()
{
    WS_THROW( wseUnsupportedOperationException , "" );
}


ws_result WSCOM::WS_InitWSCOM(wsiServiceManager **result, wsiFile *binDirectory, wsiDirectoryServiceProvider *appFileLocationProvider)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}


ws_result WSCOM::WS_ShutdownWSCOM(wsiServiceManager *servMgr)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}



/*
***********************************************************************************************************************
	WSCOM_sub
***********************************************************************************************************************
*/


ws_result WSCOM_sub::_real_WSGetModule(wsiComponentManager *aCompMgr, wsiFile* location, wsiModule** return_cobj)
{
    static ws_boolean sFirstTime = WS_TRUE;
    if (sFirstTime) {
        sFirstTime = WS_FALSE;
        ws_runtime_sub::Init( aCompMgr );
    }
	wscModule::GetCurrentModule( return_cobj );
    return ws_result( WS_RLT_SUCCESS );
}

