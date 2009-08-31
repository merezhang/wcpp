#include "wscMethodExecutor.h"
#include "TransactionContext.h"
#include <wcpp/lang/wscThrowable.h>


WS_IMPL_ClassName_OF( wscMethodExecutor )


wscMethodExecutor::wscMethodExecutor(void) : m_ptc(WS_NULL)
{
}


wscMethodExecutor::~wscMethodExecutor(void)
{
}


ws_result wscMethodExecutor::Execute(TransactionContext & tc)
{
    ws_result rlt = tc.m_decoder->Decode( tc.m_dgRequest , tc.m_pmRequest );
    if (rlt != WS_RLT_SUCCESS) return rlt;

    m_ptc = &tc;
    wsiPimapMethodsUp * pUpMethods = this;
    const ws_uint16 func = tc.m_pmRequest->GetFunction();
    switch (func) {
        case wsiPimapMethods::FUNC_LOGIN::FID:
            {
                ws_ptr<wsiString> username , psw;
                ws_uint8   type;
                ws_uint32  value;
                tc.m_pmRequest->GetParam( wsiPimapMethods::FUNC_LOGIN::PID_USER_NAME , type , value , &username );
                tc.m_pmRequest->GetParam( wsiPimapMethods::FUNC_LOGIN::PID_PASSWORD , type , value , &psw );
                pUpMethods->Login( username , psw );
            }
            break;
        case wsiPimapMethods::FUNC_LOGOUT::FID:
            pUpMethods->Logout();
            break;
        default:;
    }
    m_ptc = WS_NULL;

    return WS_RLT_SUCCESS;
}


ws_result wscMethodExecutor::Login(wsiString * username, wsiString * psw)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}


ws_result wscMethodExecutor::Logout(void)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}

