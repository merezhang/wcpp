#include "wscConsoleApp.h"
#include <wcpp/io/wscPrintStream.h>
#include <wcpp/io/wscInputStream.h>
#include <wcpp/lang/wscString.h>
#include <wcpp/lang/wscInteger.h>
#include "wscConsoleCommand.h"


wscConsoleApp::wscConsoleApp(void) : m_doExit( WS_FALSE )
{
}


wscConsoleApp::~wscConsoleApp(void)
{
}


ws_result wscConsoleApp::OnInit( void )
{
    return WS_RLT_SUCCESS;
}


ws_result wscConsoleApp::OnExit( void )
{
    return WS_RLT_SUCCESS;
}


ws_result wscConsoleApp::GetInput(wsiInputStream **ret)
{
    if (ret==WS_NULL) return WS_RLT_NULL_POINTER;
    if (*ret) return WS_RLT_NULL_POINTER;
    m_is.Get(ret);
    if ((*ret)==WS_NULL) return WS_RLT_FAILED;
    return WS_RLT_SUCCESS;
}


ws_result wscConsoleApp::GetOutput(wsiPrintStream **ret)
{
    if (ret==WS_NULL) return WS_RLT_NULL_POINTER;
    if (*ret) return WS_RLT_NULL_POINTER;
    m_ps.Get(ret);
    if ((*ret)==WS_NULL) return WS_RLT_FAILED;
    return WS_RLT_SUCCESS;
}


ws_result wscConsoleApp::SetInput(wsiInputStream *aIS)
{
    m_is.Set(aIS);
    return WS_RLT_SUCCESS;
}


ws_result wscConsoleApp::SetOutput(wsiOutputStream *aOS)
{
    ws_ptr<wsiPrintStream> ps;
    NewObj<wscPrintStream>( &ps , aOS );
    m_ps.Set(ps);
    return WS_RLT_SUCCESS;
}


ws_result wscConsoleApp::Exit(void)
{
    m_doExit = WS_TRUE;
    return WS_RLT_SUCCESS;
}


ws_boolean wscConsoleApp::IsDoExit(void)
{
    return m_doExit;
}


ws_result wscConsoleApp::OnCmdMapped(ws_int cmdId, wsiConsoleCommand * cmd)
{
    ws_ptr<wsiPrintStream> ps;
    GetOutput(&ps);
    if (!(!ps)) ps->PrintLn( "Exception: No Implements for OnCmdMapped(...)." );
    return WS_RLT_SUCCESS;
}


ws_result wscConsoleApp::OnCmdUnsupported(wsiConsoleCommand * cmd)
{
    ws_ptr<wsiPrintStream> ps;
    GetOutput(&ps);
    if (!(!ps)) {
        ws_ptr<wsiString> name;
        if (cmd) cmd->GetName(&name);
        ps->Print( "The command is unsupported: \'" );
        ps->Print( name );
        ps->PrintLn( "\'" );
    }
    return WS_RLT_SUCCESS;
}


ws_result wscConsoleApp::AddCmdMap(ws_int cmdId, const ws_char *const cmdStr)
{
    if (cmdStr == WS_NULL) return WS_RLT_NULL_POINTER;

    ws_ptr<wsiString> name;
    wscString::Allocate( &name , cmdStr );
    if (!name) return WS_RLT_FAILED;

    ws_ptr<wsiInteger> id;
    NewObj<wscInteger>( &id , cmdId );
    if (!name) return WS_RLT_FAILED;

    return m_htCmdMap.put( name , id );
}


ws_result wscConsoleApp::WaitForCmd(wsiConsoleCommand **ret)
{
    ws_ptr<wsiInputStream> in;
    GetInput(&in);
    return wscConsoleCommand::ParseCommand(ret,in);
}


ws_result wscConsoleApp::OnCmd(wsiConsoleCommand * cmd)
{
    if (cmd == WS_NULL) return WS_RLT_NULL_POINTER;

    ws_ptr<wsiString> name;
    cmd->GetName( &name );
    if (!name) {
        return OnCmdUnsupported(cmd);
    }

    ws_ptr<wsiInteger> id;
    m_htCmdMap.get( name , &id );
    if (!id) {
        return OnCmdUnsupported(cmd);
    }

    return OnCmdMapped( id->IntValue() , cmd );
}

