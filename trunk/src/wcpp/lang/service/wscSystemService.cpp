#include "wscSystemService.h"
#include <wcpp/io/wscPrintStream.h>
#include <wcpp/io/wscInputStream.h>
#include <wcpp/lang/wscThrowable.h>


const ws_char * const wscSystemService::s_class_name = "wcpp.lang.service.wscSystemService";


wscSystemService::wscSystemService(void)
{
    ws_ptr<wsiInputStream>   is  ;
    NewObj<wscInputStream>( &is );
    m_in.Set( is );

    ws_ptr<wsiPrintStream> ps;
    wscPrintStream::New( &ps , WS_NULL );
    m_err.Set( ps );
    m_out.Set( ps );
}


wscSystemService::~wscSystemService(void)
{
}


ws_result wscSystemService::GetErr(wsiPrintStream ** ret)
{
    m_err.Get( ret );
    return ws_result( WS_RLT_SUCCESS );
}


ws_result wscSystemService::GetIn(wsiInputStream ** ret)
{
    m_in.Get( ret );
    return ws_result( WS_RLT_SUCCESS );
}


ws_result wscSystemService::GetOut(wsiPrintStream ** ret)
{
    m_out.Get( ret );
    return ws_result( WS_RLT_SUCCESS );
}


ws_result wscSystemService::SetErr(wsiPrintStream * aPS)
{
    if (aPS==WS_NULL) {
        WS_THROW( wseNullPointerException , "wscSystemService::SetErr must set a non-null wsiPrintStream." );
    }
    m_err.Set( aPS );
    return ws_result( WS_RLT_SUCCESS );
}


ws_result wscSystemService::SetIn(wsiInputStream * aIS)
{
    if (aIS==WS_NULL) {
        WS_THROW( wseNullPointerException , "wscSystemService::SetIn must set a non-null wsiInputStream." );
    }
    m_in.Set( aIS );
    return ws_result( WS_RLT_SUCCESS );
}


ws_result wscSystemService::SetOut(wsiPrintStream * aPS)
{
    if (aPS==WS_NULL) {
        WS_THROW( wseNullPointerException , "wscSystemService::SetOut must set a non-null wsiPrintStream." );
    }
    m_out.Set( aPS );
    return ws_result( WS_RLT_SUCCESS );
}

