#include "ws_runtime_main.h"
#include <wcpp/wspr/wsuSingleLock.h>
#include <wcpp/lang/helper/wscObjectFinal.h>
#include "wscGlobalManager.h"

#include <wcpp/wscom/wsiServiceManager.h>
#include <wcpp/wscom/wsiComponentManager.h>
#include <wcpp/wscom/wsiComponentRegistrar.h>
#include <wcpp/wscom/wsiMemory.h>
#include <wcpp/lang/wsiThrowable.h>


/*
*************************************************************************************************************************
*   ws_runtime_main
*************************************************************************************************************************
*/


ws_runtime_main * ws_runtime_main::s_Instance = WS_NULL;


ws_runtime_main::ws_runtime_main(void)
{
    s_Instance = this;
    setRuntime( this );
}


ws_runtime_main::~ws_runtime_main(void)
{
    setRuntime( WS_NULL );
    s_Instance = WS_NULL;
}


void ws_runtime_main::DestroyGlobalManager(void)
{
    ws_runtime_main::s_Instance->m_CompMgr.Release();
    ws_runtime_main::s_Instance->m_CompReg.Release();
    ws_runtime_main::s_Instance->m_ServMgr.Release();
    ws_runtime_main::s_Instance->m_Memory.Release();
}


void ws_runtime_main::Init(void)
{
    static ws_runtime_main sInst;

    if ( !(sInst.m_CompMgr) ) {
        ws_ptr<wsiGlobalManager> gm;
        ws_result rlt = NewObj<wscGlobalManager>( &gm );
        if (rlt != WS_RLT_SUCCESS) return;

        gm.QueryInterface2( & sInst.m_CompMgr );
        gm.QueryInterface2( & sInst.m_CompReg );
        gm.QueryInterface2( & sInst.m_ServMgr );
        gm.QueryInterface2( & sInst.m_Memory );
    }
}


ws_result ws_runtime_main::GetServiceManager(wsiServiceManager ** ret)
{
    m_ServMgr.CopyTo( ret );
    if ((*ret) == WS_NULL) {
        throw WS_RLT_ILLEGAL_STATE;
    }
    return WS_RLT_SUCCESS;
}


ws_result ws_runtime_main::GetComponentManager(wsiComponentManager ** ret)
{
    m_CompMgr.CopyTo( ret );
    if ((*ret) == WS_NULL) {
        throw WS_RLT_ILLEGAL_STATE;
    }
    return WS_RLT_SUCCESS;
}


ws_result ws_runtime_main::GetComponentRegistrar(wsiComponentRegistrar ** ret)
{
    m_CompReg.CopyTo( ret );
    if ((*ret) == WS_NULL) {
        throw WS_RLT_ILLEGAL_STATE;
    }
    return WS_RLT_SUCCESS;
}


ws_result ws_runtime_main::GetMemoryManager(wsiMemory ** ret)
{
    m_Memory.CopyTo( ret );
    if ((*ret) == WS_NULL) {
        throw WS_RLT_ILLEGAL_STATE;
    }
    return WS_RLT_SUCCESS;
}


ws_int ws_runtime_main::IncrementRefcnt(ws_int * pn)
{
    if (pn==WS_NULL) {
        throw WS_RLT_NULL_POINTER;
    }

    wsuSingleLock lock( & m_mutexForRefcnt );
    const ws_int ret = (*pn) + 1;
    (*pn) = ret;

    return ret;
}


ws_int ws_runtime_main::DecrementRefcnt(ws_int * pn)
{
    if (pn==WS_NULL) {
        throw WS_RLT_NULL_POINTER;
    }

    wsuSingleLock lock( & m_mutexForRefcnt );
    const ws_int ret = (*pn) - 1;
    if (ret==0) {
        (*pn) = -65530;
    }
    else {
        (*pn) = ret;
    }

    return ret;
}


void ws_runtime_main::PreRelease(wsiObject * obj)
{
    m_gc.PreRelease( obj );
}


void ws_runtime_main::SwapPtr(void ** pp1 , void ** pp2)
{
    if ((pp1==WS_NULL) || (pp2==WS_NULL)) {
        throw WS_RLT_NULL_POINTER;
    }

    wsuSingleLock lock( & m_mutexForSwap );

    void * old_1 = (*pp1);
    void * old_2 = (*pp2);

    (*pp1) = old_2;
    (*pp2) = old_1;
}


ws_debug_probe * ws_runtime_main::debugNewProbe(void)
{
    return WS_NULL;
}


void ws_runtime_main::Throw(wsiThrowable * aThrowable)
{
    if (aThrowable) {
        aThrowable->PrintStackTrace();
    }
    throw ws_result( WS_RLT_EXCEPTION );
}

