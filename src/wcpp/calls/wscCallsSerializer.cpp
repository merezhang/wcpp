#include "wscCallsSerializer.h"
#include <wcpp/io/wsiOutputStream.h>
#include <wcpp/lang/wscThrowable.h>


const ws_char * const wscCallsSerializer::s_class_name = "wcpp.calls.wscCallsSerializer";


wscCallsSerializer::wscCallsSerializer(wsiOutputStream * os)
{
    m_os.Set( os );
}


wscCallsSerializer::~wscCallsSerializer(void)
{
}


ws_result wscCallsSerializer::OnMethod(wsiString * method , wsiCallsParamList * aParamList)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}

