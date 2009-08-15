#include "stdafx.h"

#undef GetFreeSpace

#include "TestSession.h"
#include <wcpp/wscom/main/WSCOM_main.h>
#include <wcpp/io/wscFile.h>
#include "utOutputStream.h"




TestSession::TestSession(void)
{
    WSCOM::WS_InitRuntime();
    ws_ptr<wsiServiceManager> servMgr;
    ws_ptr<wsiFile> file;
    wscFile::New( &file , ws_str("D:\\temp\\wscom") );
    WSCOM::WS_InitWSCOM( &servMgr , file , WS_NULL );
    m_ServMgr.Set( servMgr );
    utOutputStream::Init();
}


TestSession::~TestSession(void)
{
    ws_ptr<wsiServiceManager> servMgr;
    m_ServMgr.Get( &servMgr );
    m_ServMgr.Set(WS_NULL);
    WSCOM::WS_ShutdownWSCOM( servMgr );
//    servMgr.Detach();
}

