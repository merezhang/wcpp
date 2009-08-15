#ifndef __wseIOException_h__
#define __wseIOException_h__

#include <wcpp/lang/wscThrowable.h>




WS_THROW_EX_DECLARE( wseIOException , wseException )

WS_THROW_EX_DECLARE( wseEOFException ,                 wseIOException )
WS_THROW_EX_DECLARE( wseUTFDataFormatException ,       wseIOException )
WS_THROW_EX_DECLARE( wseUnsupportedEncodingException , wseIOException )
WS_THROW_EX_DECLARE( wseInterruptedIOException ,       wseIOException )




#endif // __wseIOException_h__
