#include "wscOutputStream.h"
#include <wcpp/lang/wscThrowable.h>


wscOutputStream::wscOutputStream(void)
{
}


wscOutputStream::~wscOutputStream(void)
{
}


ws_result wscOutputStream::Close(void)
{
    WS_THROW( wseUnsupportedOperationException , "" );
    return ws_result( WS_RLT_UNSUPPORTED_OPERATION );
}


ws_result wscOutputStream::Write(const void * const buf, const ws_int len)
{
    const ws_byte * bin =(const ws_byte *) buf;
    for (ws_int i=0; i<len; i++) {
        Write( bin[i] );
    }
    return ws_result( WS_RLT_SUCCESS );
}


ws_result wscOutputStream::Flush(void)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}

