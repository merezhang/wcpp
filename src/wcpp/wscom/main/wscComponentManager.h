#pragma once
#include <wcpp/lang/wscObject.h>
#include <wcpp/wscom/wsiComponentManager.h>
#include <map>
#include <wcpp/wscom/wsiFactory.h>


class wsiModuleHolder;
class wsiComponentRegistrarEx;



class wscComponentManager : public wsiComponentManager
{
    WS_IMPL_QUERY_INTERFACE_BEGIN( wscComponentManager )
        WS_IMPL_QUERY_INTERFACE_BODY( wsiComponentManager )
    WS_IMPL_QUERY_INTERFACE_END()

public:

    static const ws_char * const s_class_name;

public:

	wscComponentManager(void);
	~wscComponentManager(void);

protected:

	WS_METHOD( ws_result, GetClassObject              )(const ws_cid & aCID, const ws_iid & aIID, void ** ret);
	WS_METHOD( ws_result, GetClassObjectByContractID  )(wsiString * aContractID, const ws_iid & aIID, void ** ret);
	WS_METHOD( ws_result, CreateInstance              )(const ws_cid & aCID, wsiObject * aDelegate, const ws_iid & aIID, void ** ret);
	WS_METHOD( ws_result, CreateInstanceByContractID  )(wsiString * aContractID, wsiObject * aDelegate, const ws_iid & aIID, void ** ret);

protected:

    void _StartComponentManager(void);
    void _StopComponentManager(void);

private:

    ws_boolean m_started;
    ws_boolean m_stopped;

};

