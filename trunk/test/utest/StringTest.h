#pragma once
#include "testcase.h"


class StringTest : public TestCase
{
public:
    static const ws_char * const s_class_name;
public:

    StringTest(void);
	~StringTest(void);

	WS_METHOD( ws_result , doTest )(void);


    static void New(iTestCase ** ret);


	void test_wsString(void);
	void test_wsLong_ToString(void);
	void test_wscUUID_ToString(void);



};

