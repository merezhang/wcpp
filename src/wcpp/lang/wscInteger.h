#pragma once

#include "wsiInteger.h"
#include "wscNumber.h"


#define WS_ClassName_OF_wscInteger      "wcpp.lang.wscInteger"


class wscInteger : public wscNumber , public wsiInteger
{
    WS_IMPL_QUERY_INTERFACE_BEGIN( wscInteger )
        WS_IMPL_QUERY_INTERFACE_BODY( wsiInteger )
        WS_IMPL_QUERY_INTERFACE_BODY_BRANCH( wsiNumber , wscNumber )
    WS_IMPL_QUERY_INTERFACE_END()
public:
    static const ws_char * const s_class_name;

public:

    static ws_int ParseInt(wsiString * s);

private:

    ws_int  m_value;

protected:

    wscInteger(ws_int value);
    wscInteger(wsiString * s);
    ~wscInteger(void);

protected:

    WS_METHOD( ws_byte   , ByteValue   )(void);
    WS_METHOD( ws_double , DoubleValue )(void);
    WS_METHOD( ws_float  , FloatValue  )(void);
    WS_METHOD( ws_int    , IntValue    )(void);
    WS_METHOD( ws_long   , LongValue   )(void);
    WS_METHOD( ws_short  , ShortValue  )(void);

};

