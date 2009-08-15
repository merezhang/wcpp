#include "wscModuleManager.h"
#include <wcpp/lang/wscThrowable.h>
#include "wsiModuleHolder.h"
#include <wcpp/io/wsiFile.h>
#include <wcpp/lang/wscUUID.h>
#include "wsiClassRecord.h"
#include <wcpp/io/wsiDirectoryServiceProvider.h>
#include <wcpp/io/wscFileOutputStream.h>
#include <wcpp/calls/wscCallsParser.h>
#include <wcpp/calls/wscCallsSerializer.h>
#include <wcpp/io/wscFileInputStream.h>


const ws_char * const wscModuleManager::s_class_name = "wcpp.wscom.main.wscModuleManager";


wscModuleManager::wscModuleManager(void)
{
}


wscModuleManager::~wscModuleManager(void)
{
}


ws_result wscModuleManager::SaveModuleHolder(wsiModuleHolder * aModuleHolder)
{
    if (aModuleHolder == WS_NULL) {
        return WS_RLT_NULL_POINTER;
    }
    m_list_mh.AddItem( aModuleHolder );
    return WS_RLT_SUCCESS;
}


ws_result wscModuleManager::SaveClassRecord(wsiClassRecord *aClassRec)
{
    if (aClassRec==WS_NULL) {
        return WS_RLT_NULL_POINTER;
    }

    ws_cid cid;
    aClassRec->GetClassID( cid );
    ws_ptr<wsiUUID> puuid;
    NewObj<wscUUID>( &puuid , cid.uuid );
    m_map_cid_cr.put( puuid , aClassRec );

    ws_ptr<wsiString> ctid;
    aClassRec->GetContractID( &ctid );
    return m_map_ctid_cr.put( ctid , aClassRec );
}


ws_result wscModuleManager::GetClassRecord(wsiClassRecord **ret, const ws_cid &aClass)
{
    ws_ptr<wsiUUID> puuid;
    NewObj<wscUUID>( &puuid , aClass.uuid );
    return m_map_cid_cr.get( puuid , ret );
}


ws_result wscModuleManager::GetClassRecord(wsiClassRecord **ret, wsiString *aContractID)
{
    return m_map_ctid_cr.get( aContractID , ret );
}


ws_result wscModuleManager::OnMethod( wsiString * method, wsiCallsParamList * aParamList )
{
	WS_THROW( wseUnsupportedOperationException , "" );
}


ws_result wscModuleManager::SaveRegInfo(wsiDirectoryServiceProvider * appFileLocationProvider)
{
    if (appFileLocationProvider==WS_NULL)
        return WS_RLT_NULL_POINTER;

    ws_str prop( "WscomRegFile" );
    ws_ptr<wsiFile> regfile;
    appFileLocationProvider->GetFile( prop , &regfile );

    ws_ptr<wsiFileOutputStream> outs;
    ws_result rlt = NewObj<wscFileOutputStream>( & outs , regfile );
    if (rlt != WS_RLT_SUCCESS) return rlt;

    ws_ptr<wsiCallsSerializer> serializer;
    rlt = NewObj<wscCallsSerializer>( &serializer , outs );
    if (rlt != WS_RLT_SUCCESS) return rlt;

    WS_THROW( wseUnsupportedOperationException , "" );
}


ws_result wscModuleManager::LoadRegInfo(wsiDirectoryServiceProvider * appFileLocationProvider)
{
    if (appFileLocationProvider==WS_NULL)
        return WS_RLT_NULL_POINTER;

    ws_str prop( "WscomRegFile" );
    ws_ptr<wsiFile> regfile;
    appFileLocationProvider->GetFile( prop , &regfile );

    ws_ptr<wsiFileInputStream> is;
    ws_result rlt = NewObj<wscFileInputStream>( &is , regfile );
    if (rlt != WS_RLT_SUCCESS) return rlt;

    ws_ptr<wsiCallsParser> parser;
    rlt = NewObj<wscCallsParser>( &parser , static_cast<wsiCallsHandler*>(this) );
    if (rlt != WS_RLT_SUCCESS) return rlt;

    return parser->parse( is );
}

