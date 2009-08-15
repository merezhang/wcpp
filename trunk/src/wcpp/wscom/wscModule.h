#pragma once
#include <wcpp/lang/wscObject.h>
#include <wcpp/lang/wscThrowable.h>
#include "wsiModule.h"
#include <wcpp/wspr/ws_type.h>


class wsiFactory;


class wscModule : public wscObject , public wsiModule
{
    /*
    WS_IMPL_QUERY_INTERFACE_BEGIN( wscModule )
        WS_IMPL_QUERY_INTERFACE_BODY( wsiModule )
    WS_IMPL_QUERY_INTERFACE_END()
    */
protected:
    const WS_INTMAP_ENTRY * const _GetEntries(void)
    {
        return 0;
    }


public:
	wscModule(void);
	~wscModule(void);

private:

	static void NewCurrentModule(wsiModule ** ret);

public:

	static void GetCurrentModule(wsiModule ** ret);

	WS_METHOD( ws_result,  GetClassObject )(wsiComponentManager * aCompMgr, const ws_cid & aCID, const ws_iid & aIID, void ** ret);
	WS_METHOD( ws_result,  RegisterSelf   )(wsiComponentManager * aCompMgr, wsiFile * aLocation, wsiString * aLoaderStr, wsiString * aType);
	WS_METHOD( ws_result,  UnregisterSelf )(wsiComponentManager * aCompMgr, wsiFile * aLocation, wsiString * aLoaderStr);
	WS_METHOD( ws_boolean, CanUnload      )(wsiComponentManager * aCompMgr);

protected:

    WS_VFUNC( ws_result , IndexToClassId  )(ws_cid & ret , ws_int index) = 0;
    WS_VFUNC( ws_result , NewClassFactory )(wsiFactory ** ret , const ws_cid & aClass) = 0;

};


// Exported Function from module dll to Create the nsIModule
#define WS_GET_MODULE_SYMBOL "WSGetModule"


ws_result WSGetModule(
			wsiComponentManager *aCompMgr,
            wsiFile* location,
            wsiModule** return_cobj
			);


typedef ws_result ( * ws_proc_WSGetModule)(
			wsiComponentManager *,
            wsiFile* ,
            wsiModule** 
			);



