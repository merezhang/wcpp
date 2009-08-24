#include "wsuConsoleAppCore.h"
#include <wcpp/lang/helper/ws_ptr.h>
#include <wcpp/io/wsiInputStream.h>
#include <wcpp/io/wsiOutputStream.h>
#include <wcpp/io/wscFile.h>
#include <wcpp/wscom/WSCOM.h>
#include "wscConsoleApp.h"
#include "wscConsoleCommand.h"


wsuConsoleAppCore::wsuConsoleAppCore(iConsoleIOStreamProvider * aConsoleIOStreamProvider)
{
    WSCOM::WS_InitRuntime();
    ws_ptr<wsiServiceManager> servMgr;
    ws_ptr<wsiFile> file;
    wscFile::New( &file , ws_str( "D:\\temp\\wscom" ) );
    WSCOM::WS_InitWSCOM( &servMgr , file , WS_NULL );
    m_ServMgr.Set( servMgr );

    ws_ptr<wsiInputStream> is;
    aConsoleIOStreamProvider->CreateInputStream( &is );
    m_consoleInputStream.Set( is );

    ws_ptr<wsiOutputStream> os;
    aConsoleIOStreamProvider->CreateOutputStream( &os );
    m_consoleOutputStream.Set( os );
}


wsuConsoleAppCore::~wsuConsoleAppCore(void)
{
    m_consoleInputStream.Set( WS_NULL );
    m_consoleOutputStream.Set( WS_NULL );

    ws_ptr<wsiServiceManager> servMgr;
    m_ServMgr.Get( &servMgr );
    m_ServMgr.Set(WS_NULL);
    WSCOM::WS_ShutdownWSCOM( servMgr );
    servMgr.Release();

    WSCOM::WS_ShutdownRuntime();
}


void wsuConsoleAppCore::Main(void)
{
    ws_ptr<wsiConsoleApp> app;
    ws_result rlt = wscConsoleApp::CreateApp( & app );
    if (rlt != WS_RLT_SUCCESS) return;

    ws_ptr<wsiInputStream> is;
    ws_ptr<wsiOutputStream> os;
    m_consoleInputStream.Get( &is );
    m_consoleOutputStream.Get( &os );

    app->SetInput(is);
    app->SetOutput(os);
    app->OnInit();
    while ( ! app->IsDoExit() ) {
        ws_ptr<wsiConsoleCommand> cmd;
        app->WaitForCmd( &cmd );
        app->OnCmd( cmd );
    }
    app->OnExit();
}

