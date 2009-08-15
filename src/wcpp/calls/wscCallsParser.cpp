#include "wscCallsParser.h"
#include "wsiCallsHandler.h"
#include <wcpp/lang/wscThrowable.h>
#include <wcpp/io/wsiInputStream.h>
#include <wcpp/lang/helper/ws_str_buffer.h>

#include <boost/regex.hpp>
#include <string>


const ws_char * const wscCallsParser::s_class_name = "wcpp.calls.wscCallsParser";


wscCallsParser::wscCallsParser(wsiCallsHandler * ch)
{
}


wscCallsParser::~wscCallsParser(void)
{
}


ws_result wscCallsParser::parse(wsiInputStream * is)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}


ws_int wscCallsParser::SkipSpaces(wsiInputStream * is)
{
    if (is==WS_NULL) return -1;
    for (;;) {
        const ws_int c = is->Read();
        switch (c) {
            case ' ':
            case '\t':
            case 0x0a:
            case 0x0d:
                break;
            default:
                return c;
        }
    }
}


ws_int wscCallsParser::ReadString(wsiInputStream * is, ws_str_buffer & buf)
{
    if (is==WS_NULL) return -1;
    for (;;) {
        const ws_int c = is->Read();
        if ((0<=c) && (c<=255)) {
            if (c=='"') {
                return c;
            }
            else {
                buf += ((ws_char)c);
            }
        }
        else {
            return -1;
        }
    }
}


ws_int wscCallsParser::ReadSymbol(wsiInputStream * is, ws_str_buffer & buf)
{
    if (is==WS_NULL) return -1;
    for (;;) {
        const ws_int c = is->Read();
        if (
            (('a'<=c) && (c<='z')) ||
            (('A'<=c) && (c<='Z')) ||
            (('0'<=c) && (c<='9')) ||
            (c=='_')
            )
        {
            buf += static_cast<ws_char>(c);
        }
        else
        {
            return c;
        }
    }
}

