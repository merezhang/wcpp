#include "StringTest.h"
#include <wcpp/lang/wscUUID.h>
#include <wcpp/lang/wscSystem.h>
#include <wcpp/lang/wscLong.h>
#include <wcpp/lang/wscThrowable.h>


StringTest::StringTest(void)
{
}


StringTest::~StringTest(void)
{
}

	
ws_result StringTest::doTest(void)
{
	trace( "========================================\n" );
	trace( "case:StringTest - begin\n" );

	test_wsString();
	test_wsLong_ToString();
	test_wscUUID_ToString();

	trace( "case:StringTest - end\n" );
	trace( "========================================\n" );
    return ws_result( WS_RLT_SUCCESS );
}


void StringTest::test_wscUUID_ToString(void)
{
	trace( "    --------------------------------    \n" );
	trace( "func:test_wscUUID_ToString - begin\n" );



	{

        ws_ptr<wsiString> str1, str2;
		wscUUID::ToString( wsiObject::sIID.uuid, &str1 );

		ws_uuid uuid;
		wscUUID::ParseUUID( str1, uuid );
		wscUUID::ToString( uuid, &str2 );
		trace( "wsiObject::sIID           : " );		trace( "{3F45A92B-A7D5-4d93-946C-373E56A8C17B}" );		trace( "\n" );
		trace( "wsiObject::sIID ToString  : " );		trace( str1->GetBuffer() );		trace( "\n" );
        trace( "wsiObject::sIID ParseUUID : " );		trace( str2->GetBuffer() );		trace( "\n" );
	}


    ws_ptr<wsiString> str1,str2;
	wscUUID::ToString( wsiSystem::sIID.uuid, &str1 );
	ws_uuid uuid;
	wscUUID::ParseUUID( str2, uuid );
	wscUUID::ToString( uuid, &str2 );
	trace( "wsiSystem::sIID           : " );		trace( "{FAC4AD98-7554-4561-AF17-9A5ADB66AD30}" );		trace( "\n" );
	trace( "wsiSystem::sIID ToString  : " );		trace( str1->GetBuffer() );		trace( "\n" );
    trace( "wsiSystem::sIID ParseUUID : " );		trace( str2->GetBuffer() );		trace( "\n" );


	trace( "func:test_wscUUID_ToString - end\n" );
	trace( "    --------------------------------    \n" );
}


void StringTest::test_wsLong_ToString(void)
{
	trace( "    --------------------------------    \n" );
	trace( "func:test_wsLong_ToString - begin\n" );


	const int len = 8;
	ws_long values[len] = 
	{
		-1,
		0,
		1,

		2147483647,
		-2147483647,
		2147483647,
	//	-2147483648,
	};

	ws_ptr<wsiString> str;
	trace( "ws_long        [wsString]\n" );

	for (int i=0; i<len; i++) {
		wscLong::ToString( values[i], &str );
		trace( values[i] );
		trace( "        [" );
		trace( str->GetBuffer() );
		trace( "]\n" );
	}


	trace( "func:test_wsLong_ToString - end\n" );
	trace( "    --------------------------------    \n" );
}


void StringTest::test_wsString(void)
{
	trace( "    --------------------------------    \n" );
	trace( "func:test_wsString - begin\n" );



	ws_str str1;
	ws_str str2( static_cast<wsiString*>(WS_NULL) );
	ws_str str3( "" );
	ws_str str4( "hello" );

	str1 = str4;
	str2 = str4;
	str3 = str4;

	str4 = "";
	str3 = str4;

	str4.SetString( 0, 0 );
	str3 = "abcdefg hijk lmn opq rst uvw xyz";

	str4 = "hp";

	trace( "func:test_wsString - end\n" );
	trace( "    --------------------------------    \n" );
}

