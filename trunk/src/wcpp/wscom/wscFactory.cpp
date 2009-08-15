#include "wscFactory.h"
#include <wcpp/lang/wscThrowable.h>


wscFactory::wscFactory( const ws_char * aClassName , const ws_cid & aClass , const ws_char * aContractId , ws_uint32 aFlags , ws_uint32 aImplLang )
:   m_ClassName(aClassName) , m_Class(aClass) , m_ContractId(aContractId) , m_Flags(aFlags) , m_ImplLang(aImplLang)
{
}


wscFactory::~wscFactory(void)
{
}




ws_result wscFactory::CreateInstance(wsiObject * aOuter, const ws_iid & aIID, void ** ret)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}


ws_result wscFactory::LockFactory(ws_boolean aLock)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}




ws_result wscFactory::GetHelperForLanguage(wsiObject ** ret , ws_uint32 aLanguage)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}


ws_result wscFactory::GetInterfaces(wsiIIDsArray ** ret)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}


ws_result wscFactory::GetClassDescription(wsiString ** ret)
{
    ws_str str( m_ClassName );
    str.CopyTo( ret );
    return WS_RLT_SUCCESS;
}


ws_result wscFactory::GetClassID(ws_cid & rClassID)
{
    rClassID = m_Class;
    return WS_RLT_SUCCESS;
}


ws_result wscFactory::GetContractID(wsiString ** rContractID)
{
    ws_str str(m_ContractId);
    str.CopyTo( rContractID );
    return WS_RLT_SUCCESS;
}


ws_uint32 wscFactory::GetFlags(void)
{
    return m_Flags;
}


ws_uint32 wscFactory::GetImplementationLanguage(void)
{
    return m_ImplLang;
}



