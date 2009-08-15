#include "wscFileInputStream.h"
#include <wcpp/lang/wscThrowable.h>
#include <wcpp/wspr/ws_file.h>
#include "wsiFile.h"


const ws_char * const wscFileInputStream::s_class_name = "wcpp.io.wscFileInputStream";


wscFileInputStream::wscFileInputStream(wsiFile *file) : m_file(WS_NULL)
{
    if (file==WS_NULL) return;

    ws_ptr<wsiString> str;
    ws_result rlt = file->GetCanonicalPath( &str );
    if (rlt != WS_RLT_SUCCESS) return;

    m_file = ws_file::Open( str->GetBuffer() , 0 );
}


wscFileInputStream::wscFileInputStream(wsiFileDescriptor *fdObj) : m_file(WS_NULL)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}


wscFileInputStream::wscFileInputStream(wsiString *name) : m_file(WS_NULL)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}


wscFileInputStream::~wscFileInputStream(void)
{
    ws_file * file = m_file;
    m_file = WS_NULL;
    delete file;
}




ws_int wscFileInputStream::Available(void)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}


ws_result wscFileInputStream::Close(void)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}


ws_result wscFileInputStream::GetChannel(wsiFileChannel ** ret)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}


ws_result wscFileInputStream::GetFD(wsiFileDescriptor ** ret)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}


ws_int wscFileInputStream::Read(void)
{
    for (;;) {
        ws_byte b[1];
        ws_int rlt = _realRead( b , 1 );
        if (rlt==1) return b[0];
        if (rlt<0) return rlt;
        WS_ASSERT(rlt != 0);
    }
}


ws_int wscFileInputStream::Read(void * b, ws_int len)
{
    return _realRead(b,len);
}


ws_int wscFileInputStream::_realRead(void * b, ws_int len)
{
    if (m_file==WS_NULL) {
        return -1;
    }
    ws_int rlt = m_file->Read( b , len );
    if (rlt > 0) {
        return rlt;
    }
    else {
        return -1;
    }
}


ws_long wscFileInputStream::Skip(ws_long n)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}


ws_result wscFileInputStream::Finalize(void)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}



