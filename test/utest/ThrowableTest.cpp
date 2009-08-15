#include "ThrowableTest.h"

#include <wcpp/lang/wscThrowable.h>
#include <wcpp/io/wseIOException.h>


void ThrowableTest::New(iTestCase ** ret)
{
    ThrowableTest * pnew = WS_NULL;
    wscObjectFinal<ThrowableTest>::New( &pnew );
    ws_ptr<iTestCase> keeper;
    keeper.Attach( pnew );
    keeper.CopyTo( ret );
}


ThrowableTest::ThrowableTest(void)
{
}


ThrowableTest::~ThrowableTest(void)
{
}


void ThrowableTest::DoTry(int tid)
{
	switch (tid) {
		case tid_wsThrowable:						WS_THROW( wseThrowable,"msg in DoTry(tid_wsThrowable)");		break;
		case tid_wsException:						WS_THROW( wseException,"msg in DoTry(tid_wsException)");		break;
		case tid_wsError:							WS_THROW( wseError    ,"msg in DoTry(tid_wsError)"    );		break;

		case tid_wsRuntimeException:				WS_THROW( wseRuntimeException,"msg");							break;
		case tid_wsNullPointerException:			WS_THROW( wseNullPointerException,"msg");						break;
		case tid_wsClassCastException:				WS_THROW( wseClassCastException,"msg");							break;

		case tid_wsIOException:						WS_THROW( wseIOException,"msg");								break;
		case tid_wsUTFDataFormatException:			WS_THROW( wseUTFDataFormatException,"msg");						break;
		case tid_wsUnsupportedEncodingException:	WS_THROW( wseUnsupportedEncodingException,"msg");				break;
		case tid_wsInterruptedIOException:			WS_THROW( wseInterruptedIOException,"msg");						break;
		case tid_wsEOFException:					WS_THROW( wseEOFException,"msg");								break;
	}
}


void ThrowableTest::DoTryCatch(int tid)
{
	DoTry(tid);
}


ws_result ThrowableTest::doTest(void)
{
	trace( "========================================\n" );
	trace( "case:ThrowableTest - begin\n" );

	for (int i=0; i<tid_max; i++)
	{
		trace( "    --------------------------------    \n" );
		trace( "    " );
		trace( i );
		trace( "." );
		switch (i) {

			case tid_wsThrowable:	trace( "tid_wsThrowable" );	break;
			case tid_wsError:		trace( "tid_wsError" );		break;
			case tid_wsException:	trace( "tid_wsException" );	break;

			case tid_wsRuntimeException:		trace( "tid_wsRuntimeException" );		break;
			case tid_wsNullPointerException:	trace( "tid_wsNullPointerException" );	break;
			case tid_wsClassCastException:		trace( "tid_wsClassCastException" );	break;

			case tid_wsIOException:						trace( "tid_wsIOException" );					break;
			case tid_wsUTFDataFormatException:			trace( "tid_wsUTFDataFormatException" );		break;
			case tid_wsUnsupportedEncodingException:	trace( "tid_wsUnsupportedEncodingException" );	break;
			case tid_wsInterruptedIOException:			trace( "tid_wsInterruptedIOException" );		break;
			case tid_wsEOFException:					trace( "tid_wsEOFException" );					break;

		}
		trace( "\n" );
		DoTryCatch( i );
	}

	trace( "case:ThrowableTest - end\n" );
	trace( "========================================\n" );
    return ws_result( WS_RLT_SUCCESS );
}

