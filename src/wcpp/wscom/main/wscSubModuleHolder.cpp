#include "wscSubModuleHolder.h"
#include <wcpp/lang/wscThrowable.h>
#include <wcpp/wspr/ws_library.h>
#include <wcpp/wscom/wscModule.h>
#include <wcpp/io/wsiFile.h>
#include <wcpp/lang/wscString.h>
#include <wcpp/wscom/wseWSCOMException.h>
#include <wcpp/wscom/WSCOM.h>


/*
*********************************************************************************************************************
*   wscSubModuleHolder
*********************************************************************************************************************
*/


const ws_char * const wscSubModuleHolder::s_class_name = "wcpp.wscom.main.wscSubModuleHolder";


ws_result wscSubModuleHolder::New(wsiModuleHolder ** ret , wsiFile * aFile)
{
    ws_ptr<wsiModuleHolder> pnew;
    ws_result rlt = NewObj<wscSubModuleHolder>( &pnew );
    if (rlt != WS_RLT_SUCCESS) return rlt;

    wsiModuleHolder * p = pnew;
    rlt = dynamic_cast<wscSubModuleHolder*>(p)->InternalInit( aFile );
    if (rlt != WS_RLT_SUCCESS) return rlt;

    pnew.CopyTo( ret );
    return WS_RLT_SUCCESS;
}


wscSubModuleHolder::wscSubModuleHolder(void)
:   m_lib(WS_NULL)
{
}


ws_result wscSubModuleHolder::GetBinFile(wsiFile ** ret)
{
    if (ret==WS_NULL) return WS_RLT_NULL_POINTER;
    if (*ret) return WS_RLT_ILLEGAL_STATE;
    m_file.Get( ret );
    if ((*ret)==WS_NULL) return WS_RLT_FAILED;
    return WS_RLT_SUCCESS;
}


ws_result wscSubModuleHolder::InternalInit(wsiFile * aFile)
{
    if (m_lib) {
        WS_THROW( wseIllegalStateException , "Re-Initial the wscSubModuleHolder object." );
    }
    if (aFile==WS_NULL) {
        return WS_RLT_NULL_POINTER;
    }

    // save file
    m_file.Set( aFile );

    // load library
    ws_ptr<wsiString> path;
    ws_result rlt = aFile->GetCanonicalPath( &path );
    if (rlt != WS_RLT_SUCCESS) return rlt;
    m_lib = ws_library::Load( path->GetBuffer() );
    if ((m_lib==WS_NULL) || (!(m_lib->IsAvailable()))) {
        return WS_RLT_FAILED;
    }

    /*
    extern "C" WS_EXPORT void WS_CALLBACK 
    WSGetModule(
			    wsiComponentManager *aCompMgr,
                wsiFile* location,
                wsiModule** return_cobj
			    );
    */
    // get symbol
    ws_proc_WSGetModule proc = (ws_proc_WSGetModule) m_lib->GetProc( WS_GET_MODULE_SYMBOL );
    if (proc==WS_NULL) {
        return WS_RLT_FAILED;
    }

    // get module
    ws_ptr<wsiComponentManager> aCompMgr;
    ws_ptr<wsiModule> aModule;
    rlt = WSCOM::WS_GetComponentManager( &aCompMgr );
    if (rlt != WS_RLT_SUCCESS)  return rlt;
    rlt = proc( aCompMgr , aFile , &aModule );
    if (rlt != WS_RLT_SUCCESS)  return rlt;
    m_module.Set( aModule );

    return WS_RLT_SUCCESS;
}


wscSubModuleHolder::~wscSubModuleHolder(void)
{
//    InternalUnload();
}


ws_result wscSubModuleHolder::GetModule(wsiModule ** ret)
{
    if (ret==WS_NULL) {
        WS_THROW( wseNullPointerException ,  "" );
    }
    if (*ret) {
        WS_THROW( wseNullPointerException ,  "" );
    }
    *ret = this;
    return ws_result( WS_RLT_SUCCESS );
}


ws_result wscSubModuleHolder::GetClassObject(wsiComponentManager * aCompMgr, const ws_cid & aCID, const ws_iid & aIID, void ** ret)
{
    ws_ptr<wsiModule> module;
    m_module.Get( &module );
    return module->GetClassObject( aCompMgr , aCID , aIID , ret );
}


ws_result wscSubModuleHolder::RegisterSelf(wsiComponentManager * aCompMgr, wsiFile * aLocation, wsiString * aLoaderStr, wsiString * aType)
{
    ws_ptr<wsiModule> module;
    m_module.Get( &module );
    return module->RegisterSelf( aCompMgr , aLocation , aLoaderStr , aType );
}


ws_result wscSubModuleHolder::UnregisterSelf(wsiComponentManager * aCompMgr, wsiFile * aLocation, wsiString * aLoaderStr)
{
    ws_ptr<wsiModule> module;
    m_module.Get( &module );
    return module->UnregisterSelf( aCompMgr , aLocation , aLoaderStr );
}


ws_boolean wscSubModuleHolder::CanUnload(wsiComponentManager * aCompMgr)
{
    return InternalCanUnload( aCompMgr );
}


ws_result wscSubModuleHolder::Unload(void)
{
    InternalUnload();
    return ws_result( WS_RLT_SUCCESS );
}


ws_result wscSubModuleHolder::InternalUnload(void)
{
    ws_ptr<wsiComponentManager> compMgr;
    WSCOM::WS_GetComponentManager( & compMgr );

    ws_ptr<wsiModule> mo;
    m_module.Get( & mo );
    m_module.Set( WS_NULL );
    if (!(!mo)) {
        ws_boolean isCanUnload = mo->CanUnload( compMgr );
        WS_ASSERT ( isCanUnload == WS_TRUE );
        mo.Release();
    }

    ws_library * lib = m_lib;
    m_lib = WS_NULL;
    delete lib;

    return WS_RLT_SUCCESS;
}


ws_boolean wscSubModuleHolder::InternalCanUnload(wsiComponentManager * aCompMgr)
{
    ws_ptr<wsiModule> module;
    m_module.Get( &module );
    m_module.Set( WS_NULL );
    ws_boolean ret = module->CanUnload( aCompMgr );
    m_module.Set( module );
    return ret;
}

