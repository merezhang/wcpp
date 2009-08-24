// wscLong.h
#ifndef __wscLong_h__
#define __wscLong_h__

#include "wscNumber.h"
#include "wsiLong.h"
#include "wsiString.h"




class wscLong : public wscNumber , public wsiLong
{
public:

	ws_long m_value;

public:

//	static const ws_long MAX_VALUE = 9223372036854775807;
//	static const ws_long MIN_VALUE = -9223372036854775807;

    static const ws_long MAX_VALUE = 2147483647;
    static const ws_long MIN_VALUE = -2147483647;

protected:

    WS_METHOD( ws_byte   , ByteValue   )(void);
    WS_METHOD( ws_double , DoubleValue )(void);
    WS_METHOD( ws_float  , FloatValue  )(void);
    WS_METHOD( ws_int    , IntValue    )(void);
    WS_METHOD( ws_long   , LongValue   )(void);
    WS_METHOD( ws_short  , ShortValue  )(void);

protected:

    wscLong(ws_long value);
    wscLong(wsiString * s);
    ~wscLong(void);

public:

	static void     ToString(const ws_long aValue, wsiString ** rString);
	static ws_long  ParseLong(wsiString * aString);
};




#endif // __wsxLong_h__
