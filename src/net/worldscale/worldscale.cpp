#include "worldscale.h"

#include <wcpp/lang/ws_ptr.h>
#include <wcpp/lang/wscThread.h>
#include <wcpp/wscom/WSCOM.h>
#include <wcpp/io/wscFile.h>


void worldscale::Main(void)
{
    ws_str str( "" );
    ws_ptr<wsiFile> binDir( new wscFile(str) );

    ws_ptr<wsiServiceManager> servMgr;
    WSCOM::WS_InitWSCOM( servMgr.GetPtr2(), binDir, WS_NULL );

    ws_ptr<wsiComponentManager> compMgr;
    WSCOM::WS_GetComponentManager( compMgr.GetPtr2() );

    ws_cid aCID;
    ws_ptr<wsiRunnable> target;
    compMgr->CreateInstance( aCID, WS_NULL, target.GetIID(), (void**)target.GetPtr2() );

    ws_ptr<wsiThread> thd( new wscThread( target.GetPtr() ) );
    thd->Start();
    thd->Join();

    WSCOM::WS_ShutdownWSCOM( servMgr.GetPtr() );
}

