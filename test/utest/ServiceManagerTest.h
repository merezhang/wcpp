#pragma once
#include "testcase.h"


class wsiServiceManager;


class ServiceManagerTest : public TestCase
{
public:
    static const ws_char * const s_class_name;
public:
	ServiceManagerTest(void);
	~ServiceManagerTest(void);
    static void New(iTestCase ** ret);

	WS_METHOD( ws_result , doTest )(void);

private:

	void test_GetService(wsiServiceManager * aServMgr);
	void test_GetServiceByContractID(wsiServiceManager * aServMgr);
	void test_IsServiceInstantiated(wsiServiceManager * aServMgr);
	void test_IsServiceInstantiatedByContractID(wsiServiceManager * aServMgr);

};



