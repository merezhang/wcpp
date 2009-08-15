#include "wscPrintStream.h"
#include <wcpp/lang/wscLong.h>
#include <wcpp/lang/wscObject.h>
#include <wcpp/lang/wscThrowable.h>


#define WS_CHAR_LN '\n'


void wscPrintStream::InternalInit(wsiOutputStream * out)
{
    m_Out.Set( out );
}


wscPrintStream::wscPrintStream(void) : m_Err(WS_FALSE)
{
}


wscPrintStream::~wscPrintStream(void)
{
}



	
ws_result wscPrintStream::ClearError(void)
{
    m_Err = WS_FALSE;
    return ws_result( WS_RLT_SUCCESS );
}

	
ws_result wscPrintStream::SetError(void)
{
    m_Err = WS_TRUE;
    return ws_result( WS_RLT_SUCCESS );
}




void wscPrintStream::New(wsiPrintStream ** ret , wsiOutputStream * out)
{
    wscPrintStream * pnew = WS_NULL;
    wscObjectFinal<wscPrintStream>::New( &pnew );

    ws_ptr<wsiPrintStream> keeper;
    keeper.Attach( pnew );

    pnew->InternalInit( out );
    keeper.CopyTo(ret);
}


ws_boolean wscPrintStream::CheckError(void)
{
	return m_Err;
}


ws_result wscPrintStream::Close(void)
{
	ws_ptr<wsiOutputStream> p;
    m_Out.Get(&p);
    if (!p) return ws_result( WS_RLT_SUCCESS );
    return p->Close();
}


ws_result wscPrintStream::Flush(void)
{
	ws_ptr<wsiOutputStream> p;
    m_Out.Get(&p);
    if (!p) return ws_result( WS_RLT_SUCCESS );
    return p->Flush();
}


ws_result wscPrintStream::Write(const void * const buf, const ws_int len)
{
	ws_ptr<wsiOutputStream> p;
    m_Out.Get(&p);
    if (!p) return ws_result( WS_RLT_SUCCESS );
    return p->Write(buf,len);
}


ws_result wscPrintStream::Write(ws_int b)
{
	ws_ptr<wsiOutputStream> p;
    m_Out.Get(&p);
    if (!p) return ws_result( WS_RLT_SUCCESS );
	return p->Write(b);
}




ws_result wscPrintStream::Print(ws_boolean b)
{
	if (b) {
		return Write("true",4);
	} else {
		return Write("false",5);
	}
}


ws_result wscPrintStream::Print(ws_char c)
{
	return Write( c );
}


ws_result wscPrintStream::Print(const ws_char * const s)
{
	const ws_char * p = s;
	ws_int len = 0;
	while (*p) { len++; p++; }
	return Write( s, len );
}


ws_result wscPrintStream::Print(ws_double d)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}


ws_result wscPrintStream::Print(ws_float f)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}


ws_result wscPrintStream::Print(ws_int i)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}


ws_result wscPrintStream::Print(ws_long l)
{
	ws_ptr<wsiString> str;
	wscLong::ToString( l, &str );
	return Print( static_cast<wsiString*>(str) );
}


ws_result wscPrintStream::Print(wsiObject * obj)
{
	if (obj) {
		ws_ptr<wsiString> str;
		obj->ToString( &str );
		return Print( static_cast<wsiString*>(str) );
	}
    else {
        return ws_result( WS_RLT_NULL_POINTER );
    }
}


ws_result wscPrintStream::Print(wsiString * str)
{
    ws_ptr<wsiString> p(str);
	const ws_char * buf = p->GetBuffer();
	const ws_int    len = p->GetLength();
	return Write( buf, len );
}


ws_result wscPrintStream::PrintLn(void)
{
	return Write( WS_CHAR_LN );
}


ws_result wscPrintStream::PrintLn(ws_boolean x)
{
	Print(x);
	return Write( WS_CHAR_LN );
}


ws_result wscPrintStream::PrintLn(ws_char x)
{
	Print(x);
	return Write( WS_CHAR_LN );
}


ws_result wscPrintStream::PrintLn(const ws_char * const x)
{
	Print(x);
	return Write( WS_CHAR_LN );
}


ws_result wscPrintStream::PrintLn(ws_double x)
{
	Print(x);
	return Write( WS_CHAR_LN );
}


ws_result wscPrintStream::PrintLn(ws_float x)
{
	Print(x);
	return Write( WS_CHAR_LN );
}


ws_result wscPrintStream::PrintLn(ws_int x)
{
	Print(x);
	return Write( WS_CHAR_LN );
}


ws_result wscPrintStream::PrintLn(ws_long x)
{
	Print(x);
	return Write( WS_CHAR_LN );
}


ws_result wscPrintStream::PrintLn(wsiObject * x)
{
	Print(x);
	return Write( WS_CHAR_LN );
}


ws_result wscPrintStream::PrintLn(wsiString * x)
{
	Print(x);
	return Write( WS_CHAR_LN );
}



