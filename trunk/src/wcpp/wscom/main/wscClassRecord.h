#pragma once

#include "wsiClassRecord.h"
#include <wcpp/lang/wscObject.h>


#define WS_ClassName_OF_wscClassRecord      "wcpp.wscom.main.wscClassRecord"


class wscClassRecord : public wscObject , public wsiClassRecord
{
    WS_IMPL_QUERY_INTERFACE_BEGIN( wscClassRecord )
        WS_IMPL_QUERY_INTERFACE_BODY( wsiClassRecord )
    WS_IMPL_QUERY_INTERFACE_END()
public:
    static const ws_char * const s_class_name;
private:
    const ws_cid             m_cid;
    ws_safe_ptr<wsiString>   m_className;
    ws_safe_ptr<wsiString>   m_contractId;
    ws_safe_ptr<wsiFactory>  m_factory;
    ws_safe_ptr<wsiFile>     m_file;
protected:
    wscClassRecord( const ws_cid & cid );
    ~wscClassRecord(void);
protected:

    WS_METHOD( ws_result , GetClassID    )(ws_cid &      ret);
    WS_METHOD( ws_result , GetContractID )(wsiString  ** ret);
    WS_METHOD( ws_result , GetBinFile    )(wsiFile    ** ret);
    WS_METHOD( ws_result , GetFactory    )(wsiFactory ** ret);
    WS_METHOD( ws_result , GetClassName  )(wsiString  ** ret);

    WS_METHOD( ws_result , SetBinFile    )(wsiFile    * aBinFile    );
    WS_METHOD( ws_result , SetClassName  )(wsiString  * aClassName  );
    WS_METHOD( ws_result , SetContractID )(wsiString  * aContractID );
    WS_METHOD( ws_result , SetFactory    )(wsiFactory * aFactory    );

};

