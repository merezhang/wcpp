#ifndef __wscLangService_h__
#define __wscLangService_h__

#include <wcpp/lang/wsiLangService.h>
#include <wcpp/wscom/wscFactory.h>
#include <wcpp/lang/wscClass.h>


class wscLangService : public wscObject , public wsiLangService
{
    WS_IMPL_QUERY_INTERFACE_BEGIN( wscLangService )
        WS_IMPL_QUERY_INTERFACE_BODY( wsiLangService )
    WS_IMPL_QUERY_INTERFACE_END()
public:
    typedef wscObject super_class;
    static const ws_char * const  s_class_name;
public:
    class t_factory : public wscFactory
    {
    public:
        t_factory(void);
        ~t_factory(void);
        static const ws_char * const s_class_name;
    	WS_METHOD( ws_result , CreateInstance )(wsiObject * aOuter, const ws_iid & aIID, void ** ret);
    };
public:
    wscLangService(void);
    ~wscLangService(void);
public:
    WS_METHOD(ws_result,GetRuntimeService) (wsiRuntimeService ** ret);
    WS_METHOD(ws_result,GetSystemService)  (wsiSystemService ** ret);
    WS_METHOD(ws_result,GetThreadService)  (wsiThreadService ** ret);
    WS_METHOD(ws_result,GetStringService)  (wsiStringService ** ret);
private:
    ws_safe_ptr<wsiRuntimeService> m_runtimes;
    ws_safe_ptr<wsiSystemService>  m_systems;
    ws_safe_ptr<wsiThreadService>  m_threads;
    ws_safe_ptr<wsiStringService>  m_strings;
};


#endif // __wscLangService_h__
