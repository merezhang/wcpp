#pragma once
#include "testcase.h"


class ThrowableTest : public TestCase
{
public:
    static const ws_char * const s_class_name;
public:
	ThrowableTest(void);
	~ThrowableTest(void);
    static void New(iTestCase ** ret);

	enum tid_x
	{
		tid_wsThrowable,
		tid_wsException,
		tid_wsError,

		tid_wsRuntimeException,
		tid_wsNullPointerException,
		tid_wsClassCastException,

		tid_wsIOException,
		tid_wsUTFDataFormatException,
		tid_wsUnsupportedEncodingException,
		tid_wsInterruptedIOException,
		tid_wsEOFException,

		tid_max,
	};

	WS_METHOD( ws_result , doTest )(void);
	void DoTryCatch(int tid);
	void DoTry(int tid);

};

