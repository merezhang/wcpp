#pragma once
#include <wcpp/lang/helper/ws_ptr.h>
#include <wcpp/lang/wscObject.h>
#include "wsiCallsSerializer.h"


class wsiOutputStream;


class wscCallsSerializer : public wscObject , public wsiCallsSerializer
{
    WS_IMPL_QUERY_INTERFACE_BEGIN( wscCallsSerializer )
        WS_IMPL_QUERY_INTERFACE_BODY( wsiCallsSerializer )
    WS_IMPL_QUERY_INTERFACE_END()
public:
    static const ws_char * const s_class_name;
public:
    wscCallsSerializer(wsiOutputStream * os);
    ~wscCallsSerializer(void);
protected:
    WS_METHOD( ws_result, OnMethod)( wsiString * method, wsiCallsParamList * aParamList );
private:
    ws_safe_ptr<wsiOutputStream> m_os;
};

