#ifndef __wsiPrintStream_h__
#define __wsiPrintStream_h__

#include "wsiOutputStream.h"




class wsiCString;




#define WS_IID_OF_wsiPrintStream		\
	{ 0x5e26a9c, 0x3786, 0x4872, { 0x87, 0xd6, 0x1f, 0x24, 0xd7, 0x54, 0xc5, 0xcf } }
// {05E26A9C-3786-4872-87D6-1F24D754C5CF}




class wsiPrintStream : public wsiOutputStream
{
public:

	static const ws_iid sIID;

public:

	WS_METHOD( ws_boolean , CheckError )(void)                       = 0;
	WS_METHOD( ws_result  , Close      )(void)                       = 0;
	WS_METHOD( ws_result  , Flush      )(void)                       = 0;
	WS_METHOD( ws_result  , Write      )(const void * b, ws_int len) = 0;
	WS_METHOD( ws_result  , Write      )(ws_int b)                   = 0;

	WS_METHOD( ws_result  , Print )(ws_boolean b)            = 0;
	WS_METHOD( ws_result  , Print )(ws_char c)               = 0;
	WS_METHOD( ws_result  , Print )(const ws_char * const s) = 0;
	WS_METHOD( ws_result  , Print )(ws_double d)             = 0;
	WS_METHOD( ws_result  , Print )(ws_float f)              = 0;
	WS_METHOD( ws_result  , Print )(ws_int i)                = 0;
	WS_METHOD( ws_result  , Print )(ws_long l)               = 0;
	WS_METHOD( ws_result  , Print )(wsiObject * obj)         = 0;
	WS_METHOD( ws_result  , Print )(wsiString * str)         = 0;

	WS_METHOD( ws_result  , PrintLn )(void)                    = 0;
	WS_METHOD( ws_result  , PrintLn )(ws_boolean x)            = 0;
	WS_METHOD( ws_result  , PrintLn )(ws_char x)               = 0;
	WS_METHOD( ws_result  , PrintLn )(const ws_char * const x) = 0;
	WS_METHOD( ws_result  , PrintLn )(ws_double x)             = 0;
	WS_METHOD( ws_result  , PrintLn )(ws_float x)              = 0;
	WS_METHOD( ws_result  , PrintLn )(ws_int x)                = 0;
	WS_METHOD( ws_result  , PrintLn )(ws_long x)               = 0;
	WS_METHOD( ws_result  , PrintLn )(wsiObject * x)           = 0;
	WS_METHOD( ws_result  , PrintLn )(wsiString * x)           = 0;

};




#endif // __wsPrintStream_h__
