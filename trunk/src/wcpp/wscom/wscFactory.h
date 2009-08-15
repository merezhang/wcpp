#ifndef __wscFactory_h__
#define __wscFactory_h__

#include "wsiClassInfo.h"
#include "wsiFactory.h"
#include <wcpp/lang/wscObject.h>



class wscFactory : public wscObject , public wsiFactory , public wsiClassInfo
{
    WS_IMPL_QUERY_INTERFACE_BEGIN( wscFactory )
        WS_IMPL_QUERY_INTERFACE_BODY( wsiClassInfo )
        WS_IMPL_QUERY_INTERFACE_BODY( wsiFactory )
    WS_IMPL_QUERY_INTERFACE_END()

public:
    typedef wscObject t_super_class;

private:

    const ws_char * const   m_ClassName;
    const ws_cid            m_Class;
    const ws_char * const   m_ContractId;
    const ws_uint32         m_Flags;
    const ws_uint32         m_ImplLang;

protected:
    wscFactory( const ws_char * aClassName , const ws_cid & aClass , const ws_char * aContractId , ws_uint32 aFlags , ws_uint32 aImplLang );
    ~wscFactory(void);

protected:  // implements wsiFactory

	WS_METHOD( ws_result , CreateInstance )(wsiObject * aOuter, const ws_iid & aIID, void ** ret);
	WS_METHOD( ws_result , LockFactory    )(ws_boolean aLock);

protected:  // implements wsiClassInfo

    WS_METHOD( ws_result , GetHelperForLanguage      )(wsiObject ** ret , ws_uint32 aLanguage);
    WS_METHOD( ws_result , GetInterfaces             )(wsiIIDsArray ** ret);
    WS_METHOD( ws_result , GetClassDescription       )(wsiString ** ret);
    WS_METHOD( ws_result , GetClassID                )(ws_cid & rClassID);
    WS_METHOD( ws_result , GetContractID             )(wsiString ** rContractID);
    WS_METHOD( ws_uint32 , GetFlags                  )(void);
    WS_METHOD( ws_uint32 , GetImplementationLanguage )(void);

};


#endif // __wscFactory_h__
