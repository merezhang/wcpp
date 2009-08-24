#pragma once

#include <wcpp/lang/wscObject.h>
#include "wsiConsoleCommand.h"


class wsiInputStream;


#define WS_ClassName_OF_wscConsoleCommand       "wcpp.caf.wscConsoleCommand"


class wscConsoleCommand : public wscObject , public wsiConsoleCommand
{
    WS_IMPL_QUERY_INTERFACE_BEGIN( wscConsoleCommand )
        WS_IMPL_QUERY_INTERFACE_BODY( wsiConsoleCommand )
    WS_IMPL_QUERY_INTERFACE_END()
public:
    static const ws_char * const s_class_name;
public:
    static ws_result ParseCommand(wsiConsoleCommand ** ret , wsiInputStream * is);
private:
    ws_safe_ptr<wsiString> m_cmdString;
protected:
    wscConsoleCommand(const ws_char * const cmdStr);
    ~wscConsoleCommand(void);
protected:
    WS_METHOD( ws_result , GetName          )(wsiString ** ret);
    WS_METHOD( ws_result , GetCommandString )(wsiString ** ret);
};

