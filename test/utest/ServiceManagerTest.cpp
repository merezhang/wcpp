#include "ServiceManagerTest.h"
#include <wcpp/wscom/WSCOM.h>


ServiceManagerTest::ServiceManagerTest(void)
{
}


ServiceManagerTest::~ServiceManagerTest(void)
{
}




ws_result ServiceManagerTest::doTest(void)
{
	trace( "========================================\n" );
	trace( "case:ServiceManagerTest - begin\n" );


	ws_ptr<wsiServiceManager> sm;
	WSCOM::WS_GetServiceManager( &sm );

	test_GetService(sm);
	test_GetServiceByContractID(sm);
	test_IsServiceInstantiated(sm);
	test_IsServiceInstantiatedByContractID(sm);


	trace( "case:ServiceManagerTest - end\n" );
	trace( "========================================\n" );
    return ws_result( WS_RLT_SUCCESS );
}




void ServiceManagerTest::test_GetService(wsiServiceManager * aServMgr)
{
	trace( "    --------------------------------    \n" );
	trace( "func:test_GetService - begin\n" );

	trace( "func:test_GetService - end\n" );
	trace( "    --------------------------------    \n" );
}


void ServiceManagerTest::test_GetServiceByContractID(wsiServiceManager * aServMgr)
{
	trace( "    --------------------------------    \n" );
	trace( "func:test_GetServiceByContractID - begin\n" );

	trace( "func:test_GetServiceByContractID - end\n" );
	trace( "    --------------------------------    \n" );
}


void ServiceManagerTest::test_IsServiceInstantiated(wsiServiceManager * aServMgr)
{
	trace( "    --------------------------------    \n" );
	trace( "func:test_IsServiceInstantiated - begin\n" );

	trace( "func:test_IsServiceInstantiated - end\n" );
	trace( "    --------------------------------    \n" );
}


void ServiceManagerTest::test_IsServiceInstantiatedByContractID(wsiServiceManager * aServMgr)
{
	trace( "    --------------------------------    \n" );
	trace( "func:test_IsServiceInstantiatedByContractID - begin\n" );

	trace( "func:test_IsServiceInstantiatedByContractID - end\n" );
	trace( "    --------------------------------    \n" );
}



