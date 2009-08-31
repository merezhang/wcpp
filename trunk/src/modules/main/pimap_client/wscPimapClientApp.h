#pragma once

#include <wcpp/caf/wscConsoleApp.h>


class wsiPimapClient;


#define WS_ClassName_OF_wscPimapClientApp       "modules.main.pimap_client.wscPimapClientApp"


class wscPimapClientApp : public wscConsoleApp
{
public:
    static const ws_char * const s_class_name;
    typedef wscConsoleApp  t_super_class;
public:
    enum commands
    {
        cmdExit ,
        cmdHelp ,
        cmdInfo ,
        cmdLogin ,
        cmdLogout ,
    };
private:
    ws_safe_ptr<wsiPimapClient> m_client;
public:
    wscPimapClientApp(void);
    ~wscPimapClientApp(void);
protected:
    WS_METHOD( ws_result  , OnInit      )( void );
    WS_METHOD( ws_result  , OnExit      )( void );
    WS_METHOD( ws_result  , WaitForCmd  )(wsiConsoleCommand ** ret);
    WS_METHOD( ws_result  , OnCmdMapped )(ws_int id, wsiConsoleCommand * cmd);
private:
    void OnCmdExit(wsiConsoleCommand * cmd);
    void OnCmdHelp(wsiConsoleCommand * cmd);
    void OnCmdInfo(wsiConsoleCommand * cmd);
    void OnCmdLogin(wsiConsoleCommand * cmd);
    void OnCmdLogout(wsiConsoleCommand * cmd);
};

