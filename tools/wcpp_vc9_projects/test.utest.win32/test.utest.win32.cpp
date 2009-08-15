// test.utest.win32.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
//  #include <utest/win32/TestSession.h>
#include "TestSession.h"
#include <wcpp/wscom/WSCOM.h>
#include <net/worldscale/pimap/wscPimapLibrary.h>
#include <wcpp/lang/wscThread.h>


int _tmain(int argc, _TCHAR* argv[])
{
    TestSession ts;
    
    if (true) {
        ws_ptr<wsiComponentManager> compMgr;
        ws_result rlt = WSCOM::WS_GetComponentManager( & compMgr );
        if ((rlt==WS_RLT_SUCCESS) && (!(!compMgr))) {
            ws_ptr<wsiPimapLibrary> pimap;
            rlt = compMgr->CreateInstance( wscPimapLibrary::sCID , WS_NULL , pimap.GetIID() , (void**)(&pimap) );
            if ((rlt==WS_RLT_SUCCESS) && (!(!pimap))) {
                ws_ptr<wsiPimapServer> ps;
                rlt = pimap->CreateServer( &ps );
                if ((rlt==WS_RLT_SUCCESS) && (!(!ps))) {
                    ps->Start( 10217 );

                    wscThread::Sleep( 10000 );

                    ps->Stop();
                }
            }
        }
    }

	return 0;
}

