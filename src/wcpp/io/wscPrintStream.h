#ifndef __wscPrintStream_h__
#define __wscPrintStream_h__

#include "wscOutputStream.h"
#include "wsiPrintStream.h"
#include <wcpp/lang/wscClass.h>


class wscPrintStream : public wscOutputStream, public wsiPrintStream
{

	WS_IMPL_QUERY_INTERFACE_BEGIN( wscPrintStream )
		WS_IMPL_QUERY_INTERFACE_BODY( wsiPrintStream )
	WS_IMPL_QUERY_INTERFACE_END()

public:
    typedef wscOutputStream super_class;
    static const ws_char * const s_class_name;
private:

	ws_safe_ptr<wsiOutputStream>   m_Out;
	ws_boolean                     m_Err;

public:

	wscPrintStream(void);
	~wscPrintStream(void);

    static void New(wsiPrintStream ** ret, wsiOutputStream * out);

private:

    void InternalInit(wsiOutputStream * out);

protected:

	// implements wsiPrintStream

	WS_METHOD( ws_boolean , CheckError )(void);
	WS_METHOD( ws_result  , Close      )(void);
	WS_METHOD( ws_result  , Flush      )(void);
	WS_METHOD( ws_result  , Write      )(const void * b, ws_int len);
	WS_METHOD( ws_result  , Write      )(ws_int b);

	WS_METHOD( ws_result  , Print )(ws_boolean b);
	WS_METHOD( ws_result  , Print )(ws_char c);
	WS_METHOD( ws_result  , Print )(const ws_char * const s);
	WS_METHOD( ws_result  , Print )(ws_double d);
	WS_METHOD( ws_result  , Print )(ws_float f);
	WS_METHOD( ws_result  , Print )(ws_int i);
	WS_METHOD( ws_result  , Print )(ws_long l);
	WS_METHOD( ws_result  , Print )(wsiObject * obj);
	WS_METHOD( ws_result  , Print )(wsiString * str);

	WS_METHOD( ws_result  , PrintLn )(void);
	WS_METHOD( ws_result  , PrintLn )(ws_boolean x);
	WS_METHOD( ws_result  , PrintLn )(ws_char x);
	WS_METHOD( ws_result  , PrintLn )(const ws_char * const x);
	WS_METHOD( ws_result  , PrintLn )(ws_double x);
	WS_METHOD( ws_result  , PrintLn )(ws_float x);
	WS_METHOD( ws_result  , PrintLn )(ws_int x);
	WS_METHOD( ws_result  , PrintLn )(ws_long x);
	WS_METHOD( ws_result  , PrintLn )(wsiObject * x);
	WS_METHOD( ws_result  , PrintLn )(wsiString * x);

protected:

	WS_METHOD( ws_result  , ClearError )(void);
	WS_METHOD( ws_result  , SetError   )(void);

};




#endif // __wsPrintStream_h__
