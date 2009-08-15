#include "TestCase.h"
#include <wcpp/lang/wscSystem.h>
#include <wcpp/io/wsiPrintStream.h>


TestCase::TestCase(void)
{
}


TestCase::~TestCase(void)
{
}


void TestCase::trace(const ws_char * const str)
{
//    printf(str);

    ws_ptr<wsiPrintStream> ps;
    wscSystem::GetOut( &ps );
    ps->Print( str );
}


void TestCase::trace(ws_long n)
{
//    printf( "%d", (int)n );

    ws_ptr<wsiPrintStream> ps;
    wscSystem::GetOut( &ps );
    ps->Print( n );
}

