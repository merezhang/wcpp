#pragma once

#include <wcpp/lang/wscObject.h>
#include <wcpp/lang/wscClass.h>


#define WS_IID_OF_iTestCase     \
    { 0x71e20b6, 0x9b91, 0x4474, { 0xb8, 0x6e, 0x44, 0xbe, 0x96, 0x3a, 0xf2, 0x6f } }
// {071E20B6-9B91-4474-B86E-44BE963AF26F}


class iTestCase : public wsiObject
{
public:
	static const ws_iid sIID;
public:
	WS_METHOD( ws_result , doTest )(void) = 0;
};




class TestCase : public wscObject , public iTestCase
{
    WS_IMPL_QUERY_INTERFACE_BEGIN( TestCase )
        WS_IMPL_QUERY_INTERFACE_BODY( iTestCase )
    WS_IMPL_QUERY_INTERFACE_END()
public:

	TestCase(void);
	WS_VIRTUAL_DESTRUCTOR( TestCase );

protected:

	static void trace(const char* const str);
	static void trace(ws_long n);

};



