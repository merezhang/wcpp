// WcppUnitTest.cpp : ����Ӧ�ó��������Ϊ��?
//

#include "WcppUnitTest.h"

#include "StringTest.h"
#include "ThrowableTest.h"
#include "ThreadTest.h"
#include "wscomTest.h"
#include "ServiceManagerTest.h"
#include "ReferenceTest.h"

#include <wcpp/wscom/WSCOM.h>
#include <wcpp/io/wscFile.h>


void test_main(void)
{
    ws_ptr<wsiServiceManager> servMgr;
    WSCOM::WS_GetServiceManager( & servMgr ); 
    const ws_boolean needInit = (!servMgr) ;

    if (needInit) {
//        WSCOM::WS_InitWSCOM( & servMgr, WS_NULL , WS_NULL );
    }

	for (int i=0; i<10; i++) {
		ws_ptr<iTestCase> tc;
		tc.Release();
		switch (i) {
            case 0:     NewObj<StringTest>         (&tc);	    break;
            case 1:		NewObj<ThrowableTest>      (&tc);		break;
            case 2:		NewObj<ThreadTest>         (&tc);		break;
            case 3:		NewObj<WscomTest>          (&tc);		break;
            case 4:		NewObj<ServiceManagerTest> (&tc);       break;
            case 5:		NewObj<ReferenceTest>      (&tc);		break;
		}
		if (!(!tc)) tc->doTest();
	}

    if (needInit) {
//        WSCOM::WS_ShutdownWSCOM( servMgr );
    }
}

