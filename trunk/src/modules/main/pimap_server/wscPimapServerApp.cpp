#include "wscPimapServerApp.h"
#include <wcpp/caf/wsiConsoleCommand.h>
#include <wcpp/wscom/WSCOM.h>
#include <net/worldscale/pimap/wscPimapLibrary.h>


ws_result wscConsoleApp::CreateApp(wsiConsoleApp ** ret)
{
    return NewObj<wscPimapServerApp>(ret);
}


WS_IMPL_ClassName_OF( wscPimapServerApp )


wscPimapServerApp::wscPimapServerApp(void)
{
}


wscPimapServerApp::~wscPimapServerApp(void)
{
}


ws_result wscPimapServerApp::OnInit(void)
{
    ws_result rlt = wscConsoleApp::OnInit();
    if (rlt != WS_RLT_SUCCESS) return rlt;

    ws_ptr<wsiPrintStream> out;
    GetOutput( &out );
    if (!(!out)) {
        out->PrintLn( "Worldscale PIMAP Server [v0.1]" );
        out->PrintLn();
    }

    AddCmdMap( cmdExit , "exit" );
    AddCmdMap( cmdHelp , "help" );
    AddCmdMap( cmdInfo , "info" );

    ws_ptr<wsiServiceManager> servMgr;
    rlt = WSCOM::WS_GetServiceManager( &servMgr );
    if (rlt != WS_RLT_SUCCESS) return rlt;

    ws_ptr<wsiPimapLibrary> pimapLib;
    rlt = servMgr->GetService( wscPimapLibrary::sCID , pimapLib.GetIID() , (void**)(&pimapLib) );
    if (rlt != WS_RLT_SUCCESS) return rlt;

    ws_ptr<wsiPimapServer> pimapServer;
    rlt = pimapLib->CreateServer( &pimapServer );
    if (rlt != WS_RLT_SUCCESS) return rlt;

    rlt = pimapServer->Start( 10217 );
    if (rlt != WS_RLT_SUCCESS) return rlt;
    m_server.Set( pimapServer );

    out->PrintLn( "The server is started." );

    return WS_RLT_SUCCESS;
}


ws_result wscPimapServerApp::OnExit(void)
{
    ws_ptr<wsiPrintStream> out;
    GetOutput( &out );

    ws_ptr<wsiPimapServer> pimapServer;
    m_server.Get( &pimapServer );
    m_server.Set( WS_NULL );
    ws_result rlt = pimapServer->Stop();
    if (rlt == WS_RLT_SUCCESS) {
        if (!(!out)) out->PrintLn( "The server is stopped." );
    }

    return wscConsoleApp::OnExit();
}


ws_result wscPimapServerApp::OnCmd(wsiConsoleCommand * cmd)
{
    return t_super_class::OnCmd(cmd);
}


ws_result wscPimapServerApp::WaitForCmd(wsiConsoleCommand ** ret)
{
    ws_ptr<wsiPrintStream> out;
    GetOutput(&out);
    out->PrintLn();
    out->Print( "$ " );
    return t_super_class::WaitForCmd(ret);
}


ws_result wscPimapServerApp::OnCmdMapped(ws_int cmdId, wsiConsoleCommand *cmd)
{
    switch (cmdId) {
        case cmdExit:   Exit();             break;
        case cmdHelp:   OnCmdHelp(cmd);     break;
        case cmdInfo:   OnCmdInfo(cmd);     break;
        default:        t_super_class::OnCmdMapped(cmdId,cmd);
    }
    return WS_RLT_SUCCESS;
}


void wscPimapServerApp::OnCmdHelp(wsiConsoleCommand *cmd)
{
    ws_ptr<wsiPrintStream> out;
    GetOutput(&out);
    out->PrintLn( "Help ... [no implements]" );
}


void wscPimapServerApp::OnCmdInfo(wsiConsoleCommand *cmd)
{
    ws_ptr<wsiPrintStream> out;
    GetOutput(&out);
    out->PrintLn( "Info ... [no implements]" );
}

