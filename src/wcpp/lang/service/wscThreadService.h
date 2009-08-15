#pragma once

#include <wcpp/lang/wsiLangService.h>
#include <wcpp/lang/wscObject.h>
#include <wcpp/lang/wscString.h>


class wscThreadService : public wscObject , public wsiThreadService
{
    WS_IMPL_QUERY_INTERFACE_BEGIN(wscThreadService)
        WS_IMPL_QUERY_INTERFACE_BODY(wsiThreadService)
    WS_IMPL_QUERY_INTERFACE_END()
public:
    static const ws_char * const s_class_name;
public:
    wscThreadService(void);
    ~wscThreadService(void);
private:
    WS_METHOD( ws_result , NewThread )(wsiRunnable * target, wsiString * name, wsiThread ** ret);
    WS_METHOD( ws_result , Sleep     )(ws_long millis);
};

