#include "wscConsoleCommand.h"
#include <wcpp/io/wsiInputStream.h>
#include <wcpp/lang/wscString.h>


ws_result wscConsoleCommand::ParseCommand(wsiConsoleCommand ** ret , wsiInputStream * is)
{
    if (is==WS_NULL) return WS_RLT_NULL_POINTER;
    if (ret==WS_NULL) return WS_RLT_NULL_POINTER;
    if (*ret) return WS_RLT_NULL_POINTER;
    
    ws_char buf[256];
    ws_int  i = 0;
    while (true) {
        const ws_int chr = is->Read();
        if ((0<chr) && (chr<128)) {
            if ((chr==0x0a) || (chr==0x0d)) {
                if (i < sizeof(buf)) {
                    buf[i] = 0;
                }
                else {
                    buf[sizeof(buf)-1] = 0;
                }
                break;
            }
            else {
                if (i<sizeof(buf)) buf[i++] = static_cast<ws_char>(chr);
            }
        }
    }

    return NewObj<wscConsoleCommand>(ret, buf );
}


WS_IMPL_ClassName_OF( wscConsoleCommand )


wscConsoleCommand::wscConsoleCommand(const ws_char * const cmdStr)
{
    ws_ptr<wsiString> str;
    wscString::Allocate( &str , cmdStr );
    m_cmdString.Set( str );
}


wscConsoleCommand::~wscConsoleCommand(void)
{
}


ws_result wscConsoleCommand::GetName(wsiString ** ret)
{
    if (ret==WS_NULL) return WS_RLT_NULL_POINTER;
    if (*ret) return WS_RLT_NULL_POINTER;
    m_cmdString.Get( ret );
    if ((*ret)==WS_NULL) return WS_RLT_FAILED;
    return WS_RLT_SUCCESS;
}


ws_result wscConsoleCommand::GetCommandString(wsiString ** ret)
{
    if (ret==WS_NULL) return WS_RLT_NULL_POINTER;
    if (*ret) return WS_RLT_NULL_POINTER;
    m_cmdString.Get( ret );
    if ((*ret)==WS_NULL) return WS_RLT_FAILED;
    return WS_RLT_SUCCESS;
}

