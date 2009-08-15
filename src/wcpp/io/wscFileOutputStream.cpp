#include "wscFileOutputStream.h"
#include <wcpp/wspr/ws_file.h>
#include <wcpp/lang/wscThrowable.h>
#include <wcpp/io/wsiFile.h>


const ws_char * const wscFileOutputStream::s_class_name = "wcpp.io.wscFileOutputStream";


wscFileOutputStream::wscFileOutputStream(wsiFile * file) : m_file(WS_NULL)
{
    if (file==WS_NULL) {
        WS_THROW( wseNullPointerException , "" );
    }
    ws_ptr<wsiString> str;
    file->GetCanonicalPath( &str );
    realOpen( str->GetBuffer() );
}


wscFileOutputStream::wscFileOutputStream(wsiFile * file, ws_boolean append) : m_file(WS_NULL)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}


wscFileOutputStream::wscFileOutputStream(wsiFileDescriptor * fdObj) : m_file(WS_NULL)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}


wscFileOutputStream::wscFileOutputStream(wsiString * name) : m_file(WS_NULL)
{
    if (name==WS_NULL) {
        WS_THROW( wseNullPointerException , "" );
    }
    realOpen( name->GetBuffer() );
}


wscFileOutputStream::wscFileOutputStream(wsiString * name, ws_boolean append) : m_file(WS_NULL)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}


wscFileOutputStream::~wscFileOutputStream(void)
{
    realClose();
}


ws_result wscFileOutputStream::Close(void)
{
    return realClose();
}


ws_result wscFileOutputStream::GetChannel(wsiFileChannel ** ret)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}


ws_result wscFileOutputStream::GetFD(wsiFileDescriptor ** ret)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}


ws_result wscFileOutputStream::Write(const void * b, ws_int cb)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}


ws_result wscFileOutputStream::Write(ws_int b)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}


ws_result wscFileOutputStream::Flush(void)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}


ws_result wscFileOutputStream::realClose(void)
{
    ws_file * file = m_file;
    m_file = WS_NULL;
    delete file;
    return WS_RLT_SUCCESS;
}


ws_result wscFileOutputStream::realOpen(const ws_char * const filename)
{
    WS_ASSERT( m_file==WS_NULL );
    m_file = ws_file::Open( filename , ws_file::ff_Create | ws_file::ff_ExclusiveReadWrite );
    if (m_file) {
        if (m_file->IsAvailable()) {
            return WS_RLT_SUCCESS;
        }
    }
    return WS_RLT_FAILED;
}


ws_result wscFileOutputStream::Finalize(void)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}

