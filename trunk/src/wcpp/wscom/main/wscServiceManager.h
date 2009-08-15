#pragma once
#include <wcpp/lang/wscObject.h>
#include <wcpp/wscom/wsiServiceManager.h>
#include <map>


#define WS_CID_OF_wscServiceManager		\
	{ 0xa0ee5cd2, 0x5cf5, 0x4f1b, { 0x8f, 0xe7, 0x44, 0x7, 0x5f, 0xfc, 0xda, 0x5f } }
// {A0EE5CD2-5CF5-4f1b-8FE7-44075FFCDA5F}




class wscServiceManager : public wsiServiceManager
{
    WS_IMPL_QUERY_INTERFACE_BEGIN( wscServiceManager )
        WS_IMPL_QUERY_INTERFACE_BODY( wsiServiceManager )
    WS_IMPL_QUERY_INTERFACE_END()
public:

    static const ws_char * const  s_class_name;
	static const ws_cid sCID;

public:

	wscServiceManager(void);
	~wscServiceManager(void);

protected:

	// implements wsiServiceManager

	WS_METHOD( ws_result  , GetService                        )(const ws_cid & aClass,    const ws_iid & aIID, void ** ret);
	WS_METHOD( ws_result  , GetServiceByContractID            )(wsiString * aContractID, const ws_iid & aIID, void ** ret);
	WS_METHOD( ws_boolean , IsServiceInstantiated             )(const ws_cid & aClass,    const ws_iid & aIID);
	WS_METHOD( ws_boolean , IsServiceInstantiatedByContractID )(wsiString * aContractID, const ws_iid & aIID);

protected:

    void _StartServiceManager(void);
    void _StopServiceManager(void);

private:

	ws_result FindService(const ws_cid & aClass, wsiObject ** ret);
	ws_result AddService (const ws_cid & aClass, wsiObject * obj);

private:
	typedef ws_cid             service_key;
	typedef ws_ptr<wsiObject>  service_value;
	typedef std::map< service_key , service_value > service_list;
	service_list m_services;
	wsuMutex m_mutexForServiceList;

private:
    ws_boolean m_started;
    ws_boolean m_stopped;

};

