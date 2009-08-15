#pragma once
#include "wsiModuleHolder.h"
#include <wcpp/lang/wscObject.h>
#include <wcpp/lang/wscClass.h>
#include <wcpp/wscom/wsiModule.h>


class ws_library;
class wsiFile;


class wscSubModuleHolder : public wscObject , public wsiModuleHolder , public wsiModule
{
    WS_IMPL_QUERY_INTERFACE_BEGIN( wscSubModuleHolder )
        WS_IMPL_QUERY_INTERFACE_BODY( wsiModuleHolder )
        WS_IMPL_QUERY_INTERFACE_BODY( wsiModule )
    WS_IMPL_QUERY_INTERFACE_END()
public:
    static const ws_char * const s_class_name;
public:
    static ws_result New(wsiModuleHolder ** ret , wsiFile * aFile);
protected:
    wscSubModuleHolder(void);
    ~wscSubModuleHolder(void);

    WS_METHOD( ws_result,   GetModule      )(wsiModule ** ret);
	WS_METHOD( ws_result,   GetBinFile     )(wsiFile ** ret);
	WS_METHOD( ws_result,   Unload         )(void);

    WS_METHOD( ws_result,   GetClassObject )(wsiComponentManager * aCompMgr, const ws_cid & aCID, const ws_iid & aIID, void ** ret);
	WS_METHOD( ws_result,   RegisterSelf   )(wsiComponentManager * aCompMgr, wsiFile * aLocation, wsiString * aLoaderStr, wsiString * aType);
	WS_METHOD( ws_result,   UnregisterSelf )(wsiComponentManager * aCompMgr, wsiFile * aLocation, wsiString * aLoaderStr);
	WS_METHOD( ws_boolean,  CanUnload      )(wsiComponentManager * aCompMgr);

private:
    ws_result  InternalInit(wsiFile * aFile);
    ws_result  InternalUnload(void);
    ws_boolean InternalCanUnload(wsiComponentManager * aCompMgr);

private:
    ws_library * m_lib;
    ws_safe_ptr<wsiModule>  m_module;
    ws_safe_ptr<wsiFile>    m_file;
};

