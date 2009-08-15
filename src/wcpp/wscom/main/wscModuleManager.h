#pragma once

#include "wsiModuleManager.h"
#include <wcpp/lang/wscObject.h>
#include <wcpp/lang/wsiUUID.h>
#include <wcpp/util/element/wsuHashtable.h>
#include <wcpp/util/element/wsuList.h>
#include <wcpp/calls/wsiCallsHandler.h>


class wscModuleManager : public wsiModuleManager , public wsiCallsHandler
{
    WS_IMPL_QUERY_INTERFACE_BEGIN( wscModuleManager )
        WS_IMPL_QUERY_INTERFACE_BODY( wsiModuleManager )
    WS_IMPL_QUERY_INTERFACE_END()
public:
    static const ws_char * const s_class_name;
private:
    wsuHashtable< wsiUUID   , wsiClassRecord > m_map_cid_cr;
    wsuHashtable< wsiString , wsiClassRecord > m_map_ctid_cr;
    wsuList<wsiModuleHolder>                   m_list_mh;
protected:
    wscModuleManager(void);
    ~wscModuleManager(void);
protected:
    WS_METHOD( ws_result , GetClassRecord   )(wsiClassRecord ** ret , const ws_cid & aClass);
    WS_METHOD( ws_result , GetClassRecord   )(wsiClassRecord ** ret , wsiString * aContractID);
    WS_METHOD( ws_result , SaveClassRecord  )(wsiClassRecord * aClassRec);
    WS_METHOD( ws_result , SaveModuleHolder )(wsiModuleHolder * aModuleHolder);

    WS_METHOD( ws_result , SaveRegInfo      )(wsiDirectoryServiceProvider * appFileLocationProvider);
    WS_METHOD( ws_result , LoadRegInfo      )(wsiDirectoryServiceProvider * appFileLocationProvider);

    WS_METHOD( ws_result, OnMethod)( wsiString * method, wsiCallsParamList * aParamList );
};

