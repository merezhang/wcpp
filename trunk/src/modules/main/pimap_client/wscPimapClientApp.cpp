#include "wscPimapClientApp.h"
#include <wcpp/wscom/WSCOM.h>
#include <net/worldscale/pimap/wscPimapLibrary.h>


ws_result wscConsoleApp::CreateApp(wsiConsoleApp ** ret)
{
    return NewObj<wscPimapClientApp>(ret);
}


WS_IMPL_ClassName_OF( wscPimapClientApp )


wscPimapClientApp::wscPimapClientApp(void)
{
}


wscPimapClientApp::~wscPimapClientApp(void)
{
}


ws_result wscPimapClientApp::OnExit(void)
{
    ws_ptr<wsiPimapClient> pimapClient;
    m_client.Get( &pimapClient );
    m_client.Set( WS_NULL );

    if (!(!pimapClient)) pimapClient->Close();

    return WS_RLT_SUCCESS;
}


ws_result wscPimapClientApp::WaitForCmd(wsiConsoleCommand **ret)
{
    ws_ptr<wsiPrintStream> out;
    GetOutput(&out);
    out->PrintLn();
    out->Print( "$ " );
    return t_super_class::WaitForCmd(ret);
}


ws_result wscPimapClientApp::OnCmdMapped(ws_int id, wsiConsoleCommand *cmd)
{
    switch (id) {
        case cmdExit:   OnCmdExit(cmd);     break;
        case cmdHelp:   OnCmdHelp(cmd);     break;
        case cmdInfo:   OnCmdInfo(cmd);     break;
        case cmdLogin:  OnCmdLogin(cmd);    break;
        case cmdLogout: OnCmdLogout(cmd);   break;
        default:        t_super_class::OnCmdMapped(id,cmd);
    }
    return WS_RLT_SUCCESS;
}


ws_result wscPimapClientApp::OnInit(void)
{
    ws_ptr<wsiPrintStream> out;
    ws_result rlt = GetOutput(&out);
    if (rlt != WS_RLT_SUCCESS) return rlt;

    out->PrintLn( "Worldscale PIMAP Testing Client [v0.1]" );
    out->PrintLn();

    AddCmdMap( cmdExit   , "exit"   );
    AddCmdMap( cmdHelp   , "help"   );
    AddCmdMap( cmdInfo   , "info"   );
    AddCmdMap( cmdLogin  , "login"  );
    AddCmdMap( cmdLogout , "logout" );

    ws_ptr<wsiServiceManager> servMgr;
    rlt = WSCOM::WS_GetServiceManager( &servMgr );
    if (rlt != WS_RLT_SUCCESS) return rlt;

    ws_ptr<wsiPimapLibrary> pimapLib;
    rlt = servMgr->GetService( wscPimapLibrary::sCID , pimapLib.GetIID() , (void**)(&pimapLib) );
    if (rlt != WS_RLT_SUCCESS) return rlt;

    ws_ptr<wsiPimapClient> pimapClient;
    rlt = pimapLib->CreateClient( &pimapClient );
    if (rlt != WS_RLT_SUCCESS) return rlt;

    m_client.Set( pimapClient );

    out->PrintLn( "The client is ready." );

    return WS_RLT_SUCCESS;
}


void wscPimapClientApp::OnCmdHelp(wsiConsoleCommand *cmd)
{
    ws_ptr<wsiPrintStream> out;
    GetOutput(&out);
    out->PrintLn( "help ... [no implements]" );
}


void wscPimapClientApp::OnCmdInfo(wsiConsoleCommand *cmd)
{
    ws_ptr<wsiPrintStream> out;
    GetOutput(&out);
    out->PrintLn( "info ... [no implements]" );
}


void wscPimapClientApp::OnCmdLogin(wsiConsoleCommand *cmd)
{
    ws_ptr<wsiPrintStream> out;
    GetOutput(&out);
    out->PrintLn( "login ... " );

    ws_ptr<wsiPimapClient> client;
    m_client.Get( &client );
    ws_str user( "xukun17" );
    ws_str pswd( "12345678" );
    ws_str serv( "localhost" );
    client->Login( user , pswd , serv , 10217 );
}


void wscPimapClientApp::OnCmdLogout(wsiConsoleCommand *cmd)
{
    ws_ptr<wsiPrintStream> out;
    GetOutput(&out);
    out->PrintLn( "logout ... [no implements]" );
}


void wscPimapClientApp::OnCmdExit(wsiConsoleCommand *cmd)
{
    Exit();
    ws_ptr<wsiPrintStream> out;
    GetOutput(&out);
    out->PrintLn( "exit ... " );
    ws_ptr<wsiPimapClient> pimapClient;
    m_client.Get( &pimapClient );
    if (!pimapClient) return;
    pimapClient->Close();
}

