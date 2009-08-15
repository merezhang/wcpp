#pragma once
#include "testcase.h"




class WscomTest : public TestCase
{
public:
    static const ws_char * const s_class_name;
public:

	WscomTest(void);
	~WscomTest(void);
    static void New(iTestCase ** ret);

	WS_METHOD( ws_result , doTest )(void);

	void test_LoadLibrary(void);
	void test_WSCOM_static_funcs(void);

};


