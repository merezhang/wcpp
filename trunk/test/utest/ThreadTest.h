#pragma once
#include "testcase.h"




class ThreadTest : public TestCase
{
    WS_IMPL_QUERY_INTERFACE_BEGIN( TestCase )
    WS_IMPL_QUERY_INTERFACE_END()
public:
    static const ws_char * const s_class_name;
public:
	ThreadTest(void);
	~ThreadTest(void);
    static void New(iTestCase ** ret);

	WS_METHOD( ws_result , doTest )(void);

private:

	void test_CreateThread(void);

};



