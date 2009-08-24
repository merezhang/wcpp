#include "wscServiceManager.h"
#include <wcpp/wspr/wsuSingleLock.h>
#include <wcpp/lang/wscThrowable.h>
#include <wcpp/wscom/wsiComponentManager.h>
#include <wcpp/wscom/WSCOM.h>
#include <wcpp/wscom/wsiComponentRegistrar.h>


wscServiceManager::wscServiceManager(void)
:   m_started(WS_FALSE),
    m_stopped(WS_FALSE)
{
}


wscServiceManager::~wscServiceManager(void)
{
}


ws_result wscServiceManager::AddService(const ws_cid & aClass, wsiObject * obj)
{
	service_list::value_type val( aClass, obj );
	wsuSingleLock lock( & m_mutexForServiceList );
	m_services.insert( val );
    return WS_RLT_SUCCESS;
}


ws_result wscServiceManager::FindService(const ws_cid & aClass, wsiObject ** ret)
{
	wsuSingleLock lock( & m_mutexForServiceList );

	service_list::iterator iter = m_services.find( aClass );
	service_list::iterator end  = m_services.end();
    if (iter == end) {
		return WS_RLT_CLASS_NOT_FOUND;
    }
    (*iter).second.CopyTo( ret );
    return WS_RLT_SUCCESS;
}




ws_result wscServiceManager::GetService(const ws_cid & aClass, const ws_iid & aIID, void ** ret)
{
	ws_ptr<wsiObject> obj;
    FindService( aClass, &obj );
    if (!obj) {
        ws_ptr<wsiComponentManager> compMgr;
        WSCOM::WS_GetComponentManager( &compMgr );
        ws_result rlt = compMgr->CreateInstance( aClass, WS_NULL, obj.GetIID(), (void**) (&obj) );
        if (rlt!=WS_RLT_SUCCESS) return rlt;
    	AddService( aClass, obj );
    }
    return obj->QueryInterface( aIID , ret );
}


ws_result wscServiceManager::GetServiceByContractID(wsiString * aContractID, const ws_iid & aIID, void ** ret)
{
	ws_ptr<wsiComponentRegistrar> cr;
	WSCOM::WS_GetComponentRegistrar( &cr );
	ws_cid cid;
	cr->ContractIDToCID( aContractID, cid );
	GetService( cid, aIID, ret );
    return ws_result( WS_RLT_SUCCESS );
}


ws_boolean wscServiceManager::IsServiceInstantiated(const ws_cid & aClass, const ws_iid & aIID)
{
	ws_ptr<wsiObject> obj;
	FindService( aClass, &obj );
	ws_ptr<wsiInterface> ret;
	ws_result rlt = obj->QueryInterface( aIID, (void**) (&ret) );
    return ( (rlt==WS_RLT_SUCCESS) ? WS_TRUE : WS_FALSE );
}


ws_boolean wscServiceManager::IsServiceInstantiatedByContractID(wsiString * aContractID, const ws_iid & aIID)
{
	ws_ptr<wsiComponentRegistrar> cr;
	WSCOM::WS_GetComponentRegistrar( &cr );
	ws_cid cid;
	cr->ContractIDToCID( aContractID, cid );
	return IsServiceInstantiated( cid, aIID );
}


void wscServiceManager::_StartServiceManager(void)
{
    m_started = WS_TRUE;
}


void wscServiceManager::_StopServiceManager(void)
{
    m_stopped = WS_TRUE;

    m_services.clear();
}

