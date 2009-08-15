#include "wscStringService.h"
#include <wcpp/lang/wscThrowable.h>
#include <wcpp/lang/wscString.h>


const ws_char * const wscStringService::s_class_name = "wcpp.lang.service.wscStringService";


wscStringService::wscStringService(void)
{
}


wscStringService::~wscStringService(void)
{
}


ws_int wscStringService::AllocateString( wsiStringRW ** ret, ws_int size, const ws_char * const buf, ws_int len )
{
    if ((size < len) || (size < 0) || (len < 0)) {
        WS_THROW( wseStringIndexOutOfBoundsException , "string length larger than buffer size." );
    }

    ws_ptr<wsiStringRW> pnew;
    wscString::New( &pnew, size, buf, len );
    pnew.CopyTo( ret );
    return pnew->GetBufferSize();
}


ws_result wscStringService::RecycleString( wsiStringRW * obj )
{
    wsiInterface * i = obj;
    delete i;
    return ws_result( WS_RLT_SUCCESS );
}

