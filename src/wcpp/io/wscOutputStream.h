// wscOutputStream.h
#ifndef __wscOutputStream_h__
#define __wscOutputStream_h__

#include <wcpp/lang/wscObject.h>
#include "wsiOutputStream.h"



class wscOutputStream : public wscObject, public wsiOutputStream
{

	WS_IMPL_QUERY_INTERFACE_BEGIN( t_this_class )
		WS_IMPL_QUERY_INTERFACE_BODY( wsiOutputStream )
	WS_IMPL_QUERY_INTERFACE_END()

public:
    typedef wscObject        t_super_class;
    typedef wscOutputStream  t_this_class;
    static const ws_char * const s_class_name;
public:
	wscOutputStream(void);
	~wscOutputStream(void);
protected:
	// implements wsiOutputStream
    WS_METHOD( ws_result , Close )(void);
    WS_METHOD( ws_result , Flush )(void);
    WS_METHOD( ws_result , Write )(const void * b, ws_int len);
    WS_METHOD( ws_result , Write )(ws_int b) = 0;
};


#endif // __wsOutputStream_h__
