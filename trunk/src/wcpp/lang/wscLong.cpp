// wscLong.cpp

#include "wscLong.h"
#include "wscString.h"
#include "wscThrowable.h"


void wscLong::ToString(const ws_long aValue, wsiString ** rString)
{
	const int bufsz = (sizeof(aValue) * 3) + 3;
	ws_char buf[bufsz];

	int i = bufsz - 1;
	buf[i] = 0;

	ws_long abs = aValue;
	if (abs < 0) abs=(-abs);
	ws_char sig = (aValue >= 0) ? '+' : '-';

	do {
		i--;
		buf[i] = static_cast<ws_char>('0' + (abs % 10));
		abs /= 10;
	} while ((i>1) && (abs>0));

	if (sig=='-') {
		i--;
		buf[i] = '-';
	}

    ws_str str( buf + i, bufsz-i-1 );
    ws_ptr<wsiString> tmp(str);
    tmp.CopyTo( rString );
}


ws_long wscLong::ParseLong(wsiString * aString)
{
    WS_THROW( wseUnsupportedOperationException , "" );
    return 0;
}


wscLong::wscLong(ws_long value) : m_value(value)
{
}


wscLong::wscLong(wsiString * s) : m_value(0)
{
    m_value = ParseLong(s);
}


wscLong::~wscLong(void)
{
}


ws_byte   wscLong::ByteValue(void)
{
    return static_cast<ws_byte>(m_value);
}


ws_double wscLong::DoubleValue(void)
{
    return static_cast<ws_double>(m_value);
}


ws_float  wscLong::FloatValue(void)
{
    return static_cast<ws_float>(m_value);
}


ws_int    wscLong::IntValue(void)
{
    return static_cast<ws_int>(m_value);
}


ws_long   wscLong::LongValue(void)
{
    return m_value;
}


ws_short  wscLong::ShortValue(void)
{
    return static_cast<ws_short>(m_value);
}

