#include "StdAfx.h"
#include "utOutputStream.h"
#include <wcpp/lang/wscString.h>

#include <utest/WcppUnitTest.h>
#include <wcpp/wscom/WSCOM.h>
#include <wcpp/lang/wscSystem.h>
#include <wcpp/lang/wsoLangService.h>
#include <wcpp/io/wscPrintStream.h>
#include <wcpp/wspr/ws_file.h>
#include "utOutputStream.h"


    
const ws_char * const utOutputStream::s_class_name = "utOutputStream";


void utOutputStream::Init(void)
{
    ws_ptr<wsiOutputStream> os;
    NewObj<utOutputStream>( &os );

    ws_ptr<wsiPrintStream> ps;
    wscPrintStream::New( &ps , os );
    wscSystem::SetOut( ps );
}


utOutputStream::utOutputStream(void)
{
}


utOutputStream::~utOutputStream(void)
{
}


ws_result utOutputStream::Write(ws_int b)
{
    return 0;
}

