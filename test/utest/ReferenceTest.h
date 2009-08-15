#pragma once
#include "testcase.h"

class ReferenceTest : public TestCase
{
public:
    static const ws_char * const s_class_name;
public:

	ReferenceTest(void);
	~ReferenceTest(void);
    static void New(iTestCase ** ret);

private:

	WS_METHOD( ws_result , doTest )(void);


	void test_WeakReference(void);

};



