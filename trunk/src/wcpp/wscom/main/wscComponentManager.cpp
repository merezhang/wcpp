#include "wscComponentManager.h"
#include <wcpp/wscom/wsiComponentRegistrar.h>
#include <wcpp/wscom/WSCOM.h>
#include <wcpp/wspr/wsuSingleLock.h>
#include <wcpp/io/wsiFile.h>
#include <wcpp/lang/wscString.h>
#include <wcpp/lang/wscThrowable.h>
#include <wcpp/lang/service/wscLangService.h>
#include <wcpp/lang/wsoLangService.h>
#include "wsiModuleHolder.h"
#include "wscMainModule.h"
#include "wsiComponentRegistrarEx.h"
#include "wscSubModuleHolder.h"
#include "wsiGlobalManager.h"
#include "ws_runtime_main.h"
#include "wscGlobalManager.h"
#include "wsiClassRecord.h"


/*
**************************************************************************************************************
*   wscMainModuleHolder
**************************************************************************************************************
*/


class wscMainModuleHolder : public wscObject , public wsiModuleHolder
{
    WS_IMPL_QUERY_INTERFACE_BEGIN( wscMainModuleHolder )
        WS_IMPL_QUERY_INTERFACE_BODY( wsiModuleHolder )
    WS_IMPL_QUERY_INTERFACE_END()
public:
    static const ws_char * const s_class_name;
public:
    wscMainModuleHolder(void);
    ~wscMainModuleHolder(void);
protected:
	WS_METHOD(ws_result,GetModule)  (wsiModule ** ret);
	WS_METHOD(ws_result,GetBinFile) (wsiFile ** ret);
	WS_METHOD(ws_result,Unload)     (void);
};
const ws_char * const wscMainModuleHolder::s_class_name = "wcpp.wscom.main.wscMainModuleHolder";


wscMainModuleHolder::wscMainModuleHolder(void)
{
}


wscMainModuleHolder::~wscMainModuleHolder(void)
{
}


ws_result wscMainModuleHolder::GetModule(wsiModule ** ret)
{
    wscMainModule::GetCurrentModule( ret );
    return ws_result( WS_RLT_SUCCESS );
}


ws_result wscMainModuleHolder::Unload(void)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}

	
ws_result wscMainModuleHolder::GetBinFile(wsiFile ** ret)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}


/*
**************************************************************************************************************
*   wscComponentManager
**************************************************************************************************************
*/


wscComponentManager::wscComponentManager(void)
:   m_started(WS_FALSE),
    m_stopped(WS_FALSE)
{
}


wscComponentManager::~wscComponentManager(void)
{
}


void wscComponentManager::_StartComponentManager(void)
{
    m_started = WS_TRUE;
}


void wscComponentManager::_StopComponentManager(void)
{
    m_stopped = WS_TRUE;
}


ws_result wscComponentManager::GetClassObject(const ws_cid & aClass, const ws_iid & aIID, void ** ret)
{
    ws_ptr<wsiModuleManager> modMgr;
    ws_result rlt = QueryInterface( modMgr.GetIID() , (void**)(&modMgr) );
    if (rlt!=WS_RLT_SUCCESS) return rlt;

    ws_ptr<wsiClassRecord> clsRec;
    rlt = modMgr->GetClassRecord( &clsRec , aClass );
    if (rlt!=WS_RLT_SUCCESS) return rlt;

    ws_ptr<wsiFactory> fac;
    rlt = clsRec->GetFactory( & fac );
    if (rlt!=WS_RLT_SUCCESS) return rlt;

    return fac->QueryInterface( aIID , ret );
}


ws_result wscComponentManager::GetClassObjectByContractID(wsiString * aContractID, const ws_iid & aIID, void ** ret)
{
    ws_ptr<wsiModuleManager> modMgr;
    ws_result rlt = QueryInterface( modMgr.GetIID() , (void**)(&modMgr) );
    if (rlt!=WS_RLT_SUCCESS) return rlt;

    ws_ptr<wsiClassRecord> clsRec;
    rlt = modMgr->GetClassRecord( &clsRec , aContractID );
    if (rlt!=WS_RLT_SUCCESS) return rlt;

    ws_ptr<wsiFactory> fac;
    rlt = clsRec->GetFactory( & fac );
    if (rlt!=WS_RLT_SUCCESS) return rlt;

    return fac->QueryInterface( aIID , ret );
}


ws_result wscComponentManager::CreateInstance(const ws_cid & aClass, wsiObject * aDelegate, const ws_iid & aIID, void ** ret)
{
	ws_ptr<wsiFactory> factory;
	ws_result rlt = GetClassObject( aClass, factory.GetIID(), (void**) (&factory) );
    if (rlt!=WS_RLT_SUCCESS) return rlt;

	return factory->CreateInstance( aDelegate, aIID, ret );
}


ws_result wscComponentManager::CreateInstanceByContractID(wsiString * aContractID, wsiObject * aDelegate, const ws_iid & aIID, void ** ret)
{
	ws_ptr<wsiFactory> factory;
	ws_result rlt = GetClassObjectByContractID( aContractID, factory.GetIID(), (void**) (&factory) );
    if (rlt!=WS_RLT_SUCCESS) return rlt;

    return factory->CreateInstance( aDelegate, aIID, ret );
}



