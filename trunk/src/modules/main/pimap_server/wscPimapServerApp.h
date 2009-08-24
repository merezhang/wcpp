#pragma once

#include <wcpp/caf/wscConsoleApp.h>
#include <net/worldscale/pimap/wsiPimapLibrary.h>


#define WS_ClassName_OF_wscPimapServerApp       "modules.main.pimap_server.wscPimapServerApp"


class wscPimapServerApp : public wscConsoleApp
{
public:
    static const ws_char * const s_class_name;
    typedef wscConsoleApp  t_super_class;
public:
    enum cmds
    {
        cmdExit,
        cmdHelp,
        cmdInfo,
    };
private:
    ws_safe_ptr<wsiPimapServer> m_server;
protected:
    wscPimapServerApp(void);
    ~wscPimapServerApp(void);
protected:
    WS_METHOD( ws_result , OnInit )( void );
    WS_METHOD( ws_result , OnExit )( void );
    WS_METHOD( ws_result , OnCmd  )( wsiConsoleCommand * cmd );
    WS_METHOD( ws_result  , OnCmdMapped )(ws_int cmdId , wsiConsoleCommand * cmd);
    WS_METHOD( ws_result  , WaitForCmd  )(wsiConsoleCommand ** ret);
private:
    void OnCmdHelp(wsiConsoleCommand * cmd);
    void OnCmdInfo(wsiConsoleCommand * cmd);
};

