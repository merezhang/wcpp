#pragma once

#include <wcpp/lang/wsiLangService.h>
#include <wcpp/lang/wscObject.h>
#include <wcpp/lang/wscClass.h>
#include <wcpp/lang/wscString.h>
#include <wcpp/lang/ref/wsuSupportsWeakReference.h>
#include <vector>



class wscStringService : public wscObject , public wsuSupportsWeakReference, public wsiStringService
{
    WS_IMPL_QUERY_INTERFACE_BEGIN(wscStringService)
        WS_IMPL_QUERY_INTERFACE_BODY(wsiStringService)
        WS_IMPL_QUERY_INTERFACE_BODY(wsiSupportsWeakReference)
    WS_IMPL_QUERY_INTERFACE_END()
public:
    static const ws_char * const s_class_name;
public:
    wscStringService(void);
    ~wscStringService(void);
public:
    WS_METHOD(ws_int,   AllocateString)  (wsiStringRW ** ret, ws_int size, const ws_char * const buf, ws_int len);
    WS_METHOD(ws_result,RecycleString)   (wsiStringRW * obj);
private:
    
//    typedef ws_ptr<wsiStringRW> t_strlist_item;
    typedef wsiStringRW* t_strlist_item;

    typedef std::vector<t_strlist_item> t_strlist;

    t_strlist m_strlist;

};

