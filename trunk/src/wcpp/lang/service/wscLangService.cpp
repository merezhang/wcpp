#include "wscLangService.h"

#include "wscRuntimeService.h"
#include "wscSystemService.h"
#include "wscThreadService.h"
#include "wscStringService.h"

#include <wcpp/lang/wsoLangService.h>


/*
 **************************************************************************************************************
 *  wscLangService::t_factory
 **************************************************************************************************************
 */


const ws_char * const wscLangService::t_factory::s_class_name = "wcpp.lang.service.wscLangServiceFactory";


wscLangService::t_factory::t_factory(void)
:   wscFactory( wscLangService::s_class_name , wsoLangService::sCID , wsoLangService::sContractID , 0 , 0 )
{
}


wscLangService::t_factory::~t_factory(void)
{
}


ws_result wscLangService::t_factory::CreateInstance(wsiObject * aOuter, const ws_iid & aIID, void ** ret)
{
    ws_ptr<wsiLangService> nls;
    NewObj<wscLangService>(&nls);
    return nls->QueryInterface( aIID, ret );
}


/*
 **************************************************************************************************************
 *  wscLangService
 **************************************************************************************************************
 */


const ws_char * const wscLangService::s_class_name = "wcpp.lang.service.wscLangService";


wscLangService::wscLangService(void)
{
    ws_ptr<wsiRuntimeService>   rs  ;
    NewObj<wscRuntimeService>( &rs );
    m_runtimes.Set( rs );

    ws_ptr<wsiSystemService>   ss  ;
    NewObj<wscSystemService>( &ss );
    m_systems.Set( ss );

    ws_ptr<wsiThreadService>   ts  ;
    NewObj<wscThreadService>( &ts );
    m_threads.Set( ts );

    ws_ptr<wsiStringService>   strs  ;
    NewObj<wscStringService>( &strs );
    m_strings.Set( strs );
}


wscLangService::~wscLangService(void)
{
}


ws_result wscLangService::GetRuntimeService(wsiRuntimeService ** ret)
{
    m_runtimes.Get( ret );
    return ws_result( WS_RLT_SUCCESS );
}


ws_result wscLangService::GetSystemService(wsiSystemService ** ret)
{
    m_systems.Get( ret );
    return ws_result( WS_RLT_SUCCESS );
}


ws_result wscLangService::GetThreadService(wsiThreadService ** ret)
{
    m_threads.Get( ret );
    return ws_result( WS_RLT_SUCCESS );
}


ws_result wscLangService::GetStringService(wsiStringService ** ret)
{
    m_strings.Get( ret );
    return ws_result( WS_RLT_SUCCESS );
}

