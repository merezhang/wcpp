#pragma once

#include <wcpp/lang/wsiLangService.h>
#include <wcpp/lang/wscObject.h>
#include <wcpp/io/wsiPrintStream.h>
#include <wcpp/lang/wscString.h>


class wscSystemService : public wscObject , public wsiSystemService
{
    WS_IMPL_QUERY_INTERFACE_BEGIN(wscSystemService)
        WS_IMPL_QUERY_INTERFACE_BODY(wsiSystemService)
    WS_IMPL_QUERY_INTERFACE_END()
public:
    static const ws_char * const s_class_name;
public:
    wscSystemService(void);
    ~wscSystemService(void);
private:
    WS_METHOD(ws_result,  GetErr) (wsiPrintStream ** ret);
    WS_METHOD(ws_result,  GetIn ) (wsiInputStream ** ret);
    WS_METHOD(ws_result,  GetOut) (wsiPrintStream ** ret);
    WS_METHOD(ws_result,  SetErr) (wsiPrintStream * aPrintStream);
    WS_METHOD(ws_result,  SetIn ) (wsiInputStream * aInputStream);
    WS_METHOD(ws_result,  SetOut) (wsiPrintStream * aPrintStream);
private:
    ws_safe_ptr<wsiPrintStream> m_err;
    ws_safe_ptr<wsiInputStream> m_in;
    ws_safe_ptr<wsiPrintStream> m_out;
};

