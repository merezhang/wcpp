// wscThrowable.h
#ifndef __wscThrowable_h__
#define __wscThrowable_h__

#include "wscObject.h"
#include "wsiThrowable.h"
#include "wsiString.h"
#include "wscClass.h"
#include <wcpp/lang/helper/wscThrowableExTempl.h>


class wscThrowableBase : public wscObject , public wsiThrowable
{
    WS_IMPL_QUERY_INTERFACE_BEGIN( wscThrowableBase )
        WS_IMPL_QUERY_INTERFACE_BODY( wsiThrowable )
    WS_IMPL_QUERY_INTERFACE_END(  )
public:

    static const ws_char * const s_class_name;

protected:

    static ws_result ThrowThrowable( wsiThrowable * pobj );

protected:

	const ws_char* const m_msg;
	const ws_char* const m_file;
	const ws_int         m_line;

private:

	wscThrowableBase(const wscThrowableBase & src);
	const wscThrowableBase & operator = (const wscThrowableBase & src);

protected:

	wscThrowableBase(const ws_char * const msg, const ws_char * const file, ws_int line);
	~wscThrowableBase(void);

    static void InternalThrow(wsiThrowable * pThrowable);

protected:      // implements wsiThrowable

	WS_METHOD( ws_result , GetMessage      )(wsiString ** rString);
	WS_METHOD( ws_result , PrintStackTrace )(void);
	WS_METHOD( ws_result , ToString        )(wsiString ** rString);

};



#define WS_THROW( __class__ , __msg__ )                 \
    throw ws_result( __class__::Throw( __msg__ , __FILE__ , __LINE__ ) );



#define WS_THROW_EX_DECLARE( __class__ , __super__ )                                    \
    struct _indicator_of_##__class__ {};                                                \
    typedef wscThrowableExTempl< _indicator_of_##__class__ , __super__ > __class__ ;     \




// layer 0
WS_THROW_EX_DECLARE( wseThrowable , wscThrowableBase )


// layer 1
WS_THROW_EX_DECLARE( wseError ,     wseThrowable )
WS_THROW_EX_DECLARE( wseException , wseThrowable )


// layer 2
WS_THROW_EX_DECLARE( wseRuntimeException ,       wseException )
WS_THROW_EX_DECLARE( wseClassNotFoundException , wseException )
WS_THROW_EX_DECLARE( wseIllegalAccessException , wseException )
WS_THROW_EX_DECLARE( wseInstantiationException , wseException )
WS_THROW_EX_DECLARE( wseInterruptedException ,   wseException )

WS_THROW_EX_DECLARE( wseNoClassDefFoundError ,  wseError )
WS_THROW_EX_DECLARE( wseVirtualMachineError ,   wseError )


// layer 3
WS_THROW_EX_DECLARE( wseArithmeticException ,            wseRuntimeException )
WS_THROW_EX_DECLARE( wseArrayStoreException ,            wseRuntimeException )
WS_THROW_EX_DECLARE( wseClassCastException ,             wseRuntimeException )
WS_THROW_EX_DECLARE( wseIllegalArgumentException ,       wseRuntimeException )
WS_THROW_EX_DECLARE( wseIllegalMonitorStateException ,   wseRuntimeException )
WS_THROW_EX_DECLARE( wseIllegalStateException ,          wseRuntimeException )
WS_THROW_EX_DECLARE( wseIndexOutOfBoundsException ,      wseRuntimeException )
WS_THROW_EX_DECLARE( wseNegativeArraySizeException ,     wseRuntimeException )
WS_THROW_EX_DECLARE( wseNullPointerException ,           wseRuntimeException )
WS_THROW_EX_DECLARE( wseSecurityException ,              wseRuntimeException )
WS_THROW_EX_DECLARE( wseUnsupportedOperationException ,  wseRuntimeException )

WS_THROW_EX_DECLARE( wseOutOfMemoryError , wseVirtualMachineError )


// layer 4
WS_THROW_EX_DECLARE( wseArrayIndexOutOfBoundsException ,    wseIndexOutOfBoundsException    )
WS_THROW_EX_DECLARE( wseIllegalThreadStateException ,       wseIllegalArgumentException     )
WS_THROW_EX_DECLARE( wseNumberFormatException ,             wseIllegalArgumentException     )
WS_THROW_EX_DECLARE( wseStringIndexOutOfBoundsException ,   wseIndexOutOfBoundsException    )




#endif // __wsThrowable_h__
