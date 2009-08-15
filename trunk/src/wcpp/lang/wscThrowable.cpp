// wscThrowable.cpp

#include "wscThrowable.h"
#include <wcpp/lang/helper/ws_runtime.h>


const ws_char* const wseThrowable::s_class_name = "wcpp.lang.wscThrowable";
const ws_char* const wseError::s_class_name     = "wcpp.lang.wseError";
const ws_char* const wseException::s_class_name = "wcpp.lang.wseException";

const ws_char* const wseRuntimeException::s_class_name                = "wcpp.lang.wseRuntimeException";
const ws_char* const wseNullPointerException::s_class_name            = "wcpp.lang.wseNullPointerException";
const ws_char* const wseClassCastException::s_class_name              = "wcpp.lang.wseClassCastException";
const ws_char* const wseUnsupportedOperationException::s_class_name   = "wcpp.lang.wseUnsupportedOperationException";
const ws_char* const wseIllegalThreadStateException::s_class_name     = "wcpp.lang.wseIllegalThreadStateException";
const ws_char* const wseClassNotFoundException::s_class_name          = "wcpp.lang.wseClassNotFoundException";
const ws_char* const wseNumberFormatException::s_class_name           = "wcpp.lang.wseNumberFormatException";
const ws_char* const wseIllegalArgumentException::s_class_name        = "wcpp.lang.wseIllegalArgumentException";
const ws_char* const wseIllegalStateException::s_class_name           = "wcpp.lang.wseIllegalStateException";
const ws_char* const wseStringIndexOutOfBoundsException::s_class_name = "wcpp.lang.wseStringIndexOutOfBoundsException";
const ws_char* const wseIndexOutOfBoundsException::s_class_name       = "wcpp.lang.wseIndexOutOfBoundsException";
const ws_char* const wseArrayIndexOutOfBoundsException::s_class_name  = "wcpp.lang.wseArrayIndexOutOfBoundsException";
const ws_char* const wseIllegalAccessException::s_class_name          = "wcpp.lang.wseIllegalAccessException";
const ws_char* const wseNegativeArraySizeException::s_class_name      = "wcpp.lang.wseNegativeArraySizeException";

const ws_char* const wseOutOfMemoryError::s_class_name                = "wcpp.lang.wseOutOfMemoryError";



    
ws_result wscThrowableBase::ThrowThrowable( wsiThrowable * pobj )
{
    ws_ptr<wsiThrowable> obj(pobj);

    ws_runtime::getRuntime()->Throw( pobj );

    return ws_result( WS_RLT_EXCEPTION );
}




wscThrowableBase::wscThrowableBase(const ws_char * const aMsg, const ws_char* const aFileName, ws_int aLine)
:   m_msg    (aMsg),
    m_file   (aFileName),
    m_line   (aLine)
{
}


wscThrowableBase::~wscThrowableBase(void)
{
}


ws_result wscThrowableBase::GetMessage(wsiString ** rString)
{
    ws_str str( m_msg );
    str.CopyTo( rString );
    return ws_result( WS_RLT_SUCCESS );
}


ws_result wscThrowableBase::PrintStackTrace(void)
{
    return ws_result( WS_RLT_SUCCESS );
}


ws_result wscThrowableBase::ToString(wsiString ** rString)
{
    ws_str str( "" );
    str.CopyTo( rString );
    return ws_result( WS_RLT_SUCCESS );
}

