// wscInputStream.h
#ifndef __wscInputStream_h__
#define __wscInputStream_h__

#include <wcpp/lang/wscObject.h>
#include "wsiInputStream.h"


class wscInputStream : public wscObject, public wsiInputStream
{
    WS_IMPL_QUERY_INTERFACE_BEGIN( wscInputStream )
        WS_IMPL_QUERY_INTERFACE_BODY( wsiInputStream )
    WS_IMPL_QUERY_INTERFACE_END()

public:
    static const ws_char * const s_class_name;
public:

	wscInputStream(void) {}

protected:

	WS_METHOD( ws_int     , Available     )(void)                              { return 0; }
	WS_METHOD( ws_result  , Close         )(void)                              { return WS_RLT_UNSUPPORTED_OPERATION; }
	WS_METHOD( ws_result  , Mark          )(ws_int readlimit)                  { return WS_RLT_UNSUPPORTED_OPERATION; }
	WS_METHOD( ws_boolean , MarkSupported )(void)                              { return WS_FALSE; }
	WS_METHOD( ws_int     , Read          )(void)                              { return -1; }
	WS_METHOD( ws_int     , Read          )(void * b, ws_int len)              { return 0; }
	WS_METHOD( ws_result  , Reset         )(void)                              { return WS_RLT_UNSUPPORTED_OPERATION; }
	WS_METHOD( ws_long    , Skip          )(ws_long n)                         { return 0; }

};




#endif // __wsInputStream_h__
