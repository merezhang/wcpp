// wscLong.h
#ifndef __wscLong_h__
#define __wscLong_h__

#include "wscObject.h"
#include "wsiLong.h"
#include "wsiString.h"




class wscLong : public wscObject , public wsiLong
{
public:

	ws_long m_value;

public:

//	static const ws_long MAX_VALUE = 9223372036854775807;
//	static const ws_long MIN_VALUE = -9223372036854775807;

    static const ws_long MAX_VALUE = 2147483647;
    static const ws_long MIN_VALUE = -2147483647;

public:

	static void     ToString(const ws_long aValue, wsiString ** rString);
	static ws_long  ParseLong(wsiString * aString);
};




#endif // __wsxLong_h__
