#pragma once

#include <wcpp/lang/wsiLangService.h>
#include <wcpp/lang/wscObject.h>
#include <wcpp/lang/wsiRuntime.h>
#include <wcpp/lang/wscString.h>


class wscRuntimeService : public wscObject , public wsiRuntimeService
{
    WS_IMPL_QUERY_INTERFACE_BEGIN(wscRuntimeService)
        WS_IMPL_QUERY_INTERFACE_BODY(wsiRuntimeService)
    WS_IMPL_QUERY_INTERFACE_END()
public:
    static const ws_char * const s_class_name;
public:
    wscRuntimeService(void);
    ~wscRuntimeService(void);
private:
    WS_METHOD( ws_result , GetRuntime )(wsiRuntime ** ret);
private:
    ws_ptr<wsiRuntime> m_runtime;
};

