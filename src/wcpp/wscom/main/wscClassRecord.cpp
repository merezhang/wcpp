#include "wscClassRecord.h"
#include <wcpp/lang/wscThrowable.h>
#include <wcpp/wscom/wsiFactory.h>
#include <wcpp/io/wsiFile.h>


wscClassRecord::wscClassRecord(const ws_cid & cid) : m_cid(cid)
{
}


wscClassRecord::~wscClassRecord(void)
{
}


ws_result wscClassRecord::GetBinFile(wsiFile ** ret)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}


ws_result wscClassRecord::GetClassID(ws_cid & ret)
{
    ret = m_cid;
    return WS_RLT_SUCCESS;
}


ws_result wscClassRecord::GetContractID(wsiString ** ret)
{
    m_contractId.Get( ret );
    return WS_RLT_SUCCESS;
}


ws_result wscClassRecord::GetFactory(wsiFactory ** ret)
{
    m_factory.Get( ret );
    return WS_RLT_SUCCESS;
}


ws_result wscClassRecord::GetClassName(wsiString ** ret)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}


ws_result wscClassRecord::SetBinFile(wsiFile * aBinFile)
{
    m_file.Set( aBinFile );
    return WS_RLT_SUCCESS;
}


ws_result wscClassRecord::SetClassName(wsiString *aClassName)
{
    const ws_char * buf = "";
    if (aClassName) {
        buf = aClassName->GetBuffer();
    }
    ws_str str( buf );
    ws_ptr<wsiString> ptr;
    str.CopyTo( &ptr );
    m_className.Set( ptr );
    return WS_RLT_SUCCESS;
}


ws_result wscClassRecord::SetContractID(wsiString * aContractID)
{
    const ws_char * buf = "";
    if (aContractID) {
        buf = aContractID->GetBuffer();
    }
    ws_str str( buf );
    ws_ptr<wsiString> ptr;
    str.CopyTo( &ptr );
    m_contractId.Set( ptr );
    return WS_RLT_SUCCESS;
}


ws_result wscClassRecord::SetFactory(wsiFactory *aFactory)
{
    m_factory.Set( aFactory );
    return WS_RLT_SUCCESS;
}

