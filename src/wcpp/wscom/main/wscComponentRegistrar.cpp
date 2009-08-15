#include "wscComponentRegistrar.h"
#include <wcpp/lang/wscThrowable.h>
#include "wsiComponentRegistrarEx.h"
#include <wcpp/io/wsiFile.h>
#include "wscSubModuleHolder.h"
#include <wcpp/wscom/wsiComponentManager.h>
#include <wcpp/wscom/WSCOM.h>
#include <wcpp/wscom/wsiModule.h>
#include "wsiModuleManager.h"
#include <wcpp/io/wsiFilenameFilter.h>
#include "wscClassRecord.h"


wscComponentRegistrar::wscComponentRegistrar(void)
:   m_started(WS_FALSE),
    m_stopped(WS_FALSE)
{
}


wscComponentRegistrar::~wscComponentRegistrar(void)
{
}


void wscComponentRegistrar::_StartComponentRegistrar(void)
{
    m_started = WS_TRUE;
}


void wscComponentRegistrar::_StopComponentRegistrar(void)
{
    m_stopped = WS_TRUE;
}


class wscComponentRegistrar_AutoRegisterDir_filter : public wscObject , public wsiFilenameFilter
{
    WS_IMPL_QUERY_INTERFACE_BEGIN( wscComponentRegistrar_AutoRegisterDir_filter )
        WS_IMPL_QUERY_INTERFACE_BODY( wsiFilenameFilter )
    WS_IMPL_QUERY_INTERFACE_END()
public:
    static const ws_char * const s_class_name;
public:
    WS_METHOD( ws_boolean , Accept )(wsiFile * dir , wsiString * name);
};

const ws_char * const wscComponentRegistrar_AutoRegisterDir_filter::s_class_name = "";

ws_boolean wscComponentRegistrar_AutoRegisterDir_filter::Accept(wsiFile *dir, wsiString *name)
{
    if (name) {
        ws_ptr<wsiString> lcstr;
        name->ToLowerCase( &lcstr );
        if (!(!lcstr)) {
            ws_str suffix( ".so" );
            return lcstr->EndsWith( suffix );
        }
    }
    return WS_FALSE;
}


ws_result wscComponentRegistrar::AutoRegisterDir( wsiFile * aSpec )
{
    ws_ptr<wsiFilenameFilter> filter;
    NewObj<wscComponentRegistrar_AutoRegisterDir_filter>( & filter );


    if (aSpec == WS_NULL) {
        return WS_RLT_NULL_POINTER;
    }

    if (aSpec->IsDirectory()) {
        // is a directory

        ws_ptr<wsiFileArray> fileArray;
        ws_result rlt = aSpec->ListFiles( & fileArray , filter );
        if (rlt != WS_RLT_SUCCESS) return rlt;

        const ws_int cntFile = fileArray->GetSize();
        for (ws_int i=0; i<cntFile; i++) {
            ws_ptr<wsiFile> rFile;
            rlt = fileArray->GetItem( i, &rFile );
            if (rlt == WS_RLT_SUCCESS) {
                AutoRegisterFile( rFile );
            }
        }

        return WS_RLT_SUCCESS;
    }
    else {
        // is a normal file (not a directory)
        return WS_RLT_FAILED;
    }
}


ws_result wscComponentRegistrar::AutoRegisterFile( wsiFile * aSpec )
{
    if (aSpec == WS_NULL) {
        return WS_RLT_NULL_POINTER;
    }

    ws_ptr<wsiString> tracestr;
    aSpec->GetCanonicalPath( & tracestr );
    tracestr.Release();

    if (aSpec->IsDirectory()) {
        // is a directory
        return WS_RLT_FAILED;
    }
    else {
        // is a normal file (not a directory)
        ws_result rlt( WS_RLT_SUCCESS );

        ws_ptr<wsiModuleManager> modMgr;
        rlt = (this)->QueryInterface( modMgr.GetIID() , (void**)(&modMgr) );
        if (rlt != WS_RLT_SUCCESS) return rlt;

        ws_ptr<wsiModuleHolder> subModuleHolder;
        rlt = wscSubModuleHolder::New( &subModuleHolder , aSpec );
        if (rlt != WS_RLT_SUCCESS) return rlt;

        modMgr->SaveModuleHolder( subModuleHolder );

        ws_ptr<wsiModule> subModule;
        rlt = subModuleHolder->GetModule( &subModule );
        if (rlt != WS_RLT_SUCCESS) return rlt;

        ws_str aLoaderStr, aType;
        ws_ptr<wsiComponentManager> compMgr;
        WSCOM::WS_GetComponentManager( &compMgr );
        return subModule->RegisterSelf( compMgr, aSpec, aLoaderStr, aType );
    }
}


ws_result wscComponentRegistrar::AutoRegister( wsiFile * aSpec )
{
    if (aSpec == WS_NULL) {
        return WS_RLT_NULL_POINTER;
    }

    if (aSpec->IsDirectory()) {
        // is a directory
        return AutoRegisterDir( aSpec );
    }
    else {
        // is a normal file (not a directory)
        return AutoRegisterFile( aSpec );
    }
}


ws_result wscComponentRegistrar::AutoUnregister( wsiFile * aSpec )
{
	WS_THROW( wseUnsupportedOperationException , "" );
}


ws_result wscComponentRegistrar::RegisterFactory(	const ws_cid & aClass, wsiString * aClassName, wsiString * aContractID, wsiFactory * aFactory )
{
	ws_ptr<wsiModuleManager> modMgr;
    ws_result rlt = QueryInterface( modMgr.GetIID() , (void**)(&modMgr) );
    if (rlt != WS_RLT_SUCCESS) return rlt;

    ws_ptr<wsiClassRecord> clsRec;
    rlt = modMgr->GetClassRecord( &clsRec , aClass );
    if ((rlt != WS_RLT_SUCCESS) || (!clsRec)) {
        rlt = NewObj<wscClassRecord>( & clsRec , aClass );
        if (rlt != WS_RLT_SUCCESS) return rlt;
    }

    clsRec->SetClassName( aClassName );
    clsRec->SetContractID( aContractID );
    clsRec->SetFactory( aFactory );

    return modMgr->SaveClassRecord( clsRec );
}


ws_result wscComponentRegistrar::UnregisterFactory(	const ws_cid & aClass, wsiFactory * aFactory )
{
	WS_THROW( wseUnsupportedOperationException , "" );
}


ws_result wscComponentRegistrar::RegisterFactoryLocation(	const ws_cid & aClass, wsiString * aClassName, wsiString * aContractID, wsiFile * aFile, wsiString * aLoaderStr, wsiString * aType )
{
	ws_ptr<wsiModuleManager> modMgr;
    ws_result rlt = QueryInterface( modMgr.GetIID() , (void**)(&modMgr) );
    if (rlt != WS_RLT_SUCCESS) return rlt;

    ws_ptr<wsiClassRecord> clsRec;
    rlt = modMgr->GetClassRecord( &clsRec , aClass );
    if ((rlt != WS_RLT_SUCCESS) || (!clsRec)) {
        rlt = NewObj<wscClassRecord>( & clsRec , aClass );
        if (rlt != WS_RLT_SUCCESS) return rlt;
    }

    clsRec->SetClassName( aClassName );
    clsRec->SetContractID( aContractID );
    clsRec->SetBinFile( aFile );

    return modMgr->SaveClassRecord( clsRec );
}


ws_result wscComponentRegistrar::UnregisterFactoryLocation(	const ws_cid & aClass, wsiFile * aFile )
{
	WS_THROW( wseUnsupportedOperationException , "" );
}


ws_boolean wscComponentRegistrar::IsCIDRegistered( const ws_cid & aClass )
{
	WS_THROW( wseUnsupportedOperationException , "" );
}


ws_boolean wscComponentRegistrar::IsContractIDRegistered( wsiString * aContractID )
{
	WS_THROW( wseUnsupportedOperationException , "" );
}


ws_result wscComponentRegistrar::EnumerateCIDs( wsiSimpleEnumerator ** rEnum )
{
	WS_THROW( wseUnsupportedOperationException , "" );
}


ws_result wscComponentRegistrar::EnumerateContractIDs( wsiSimpleEnumerator ** rEnum )
{
	WS_THROW( wseUnsupportedOperationException , "" );
}


ws_result wscComponentRegistrar::CIDToContractID( const ws_cid & aClass, wsiString ** rContractID )
{
	WS_THROW( wseUnsupportedOperationException , "" );
}


ws_result wscComponentRegistrar::ContractIDToCID( wsiString * aContractID, ws_cid & rClass )
{
	WS_THROW( wseUnsupportedOperationException , "" );
}

