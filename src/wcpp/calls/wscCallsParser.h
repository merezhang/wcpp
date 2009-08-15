#pragma once
#include "wsiCallsParser.h"
#include <wcpp/lang/wscObject.h>


class wsiCallsHandler;
class ws_str_buffer;


class wscCallsParser : public wscObject, public wsiCallsParser
{
    WS_IMPL_QUERY_INTERFACE_BEGIN( wscCallsParser )
        WS_IMPL_QUERY_INTERFACE_BODY( wsiCallsParser )
    WS_IMPL_QUERY_INTERFACE_END()
public:
    static const ws_char * const s_class_name;
public:
    wscCallsParser(wsiCallsHandler * ch);
    ~wscCallsParser(void);
protected:
    WS_METHOD( ws_result , parse)(wsiInputStream * is);
private:
    static ws_int SkipSpaces(wsiInputStream * is);
    static ws_int ReadString(wsiInputStream * is, ws_str_buffer & buf);
    static ws_int ReadSymbol(wsiInputStream * is, ws_str_buffer & buf);
private:
    ws_safe_ptr<wsiCallsHandler> m_ch;
};

