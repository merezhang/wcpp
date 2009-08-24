#include "wscInteger.h"
#include "wscLong.h"


ws_int wscInteger::ParseInt(wsiString *s)
{
    ws_long lo = wscLong::ParseLong(s);
    return static_cast<ws_int>(lo);
}


WS_IMPL_ClassName_OF( wscInteger )


wscInteger::wscInteger(wsiString * s) : m_value(0)
{
    m_value = ParseInt(s);
}


wscInteger::wscInteger(ws_int n) : m_value(n)
{
}


wscInteger::~wscInteger(void)
{
}


ws_byte   wscInteger::ByteValue(void)
{
    return static_cast<ws_byte>(m_value);
}


ws_double wscInteger::DoubleValue(void)
{
    return m_value;
}


ws_float  wscInteger::FloatValue(void)
{
    return static_cast<ws_float>(m_value);
}


ws_int    wscInteger::IntValue(void)
{
    return m_value;
}


ws_long   wscInteger::LongValue(void)
{
    return m_value;
}


ws_short  wscInteger::ShortValue(void)
{
    return static_cast<ws_short>(m_value);
}

