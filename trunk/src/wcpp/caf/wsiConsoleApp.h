#pragma once

#include <wcpp/lang/wsiObject.h>


class wsiInputStream;
class wsiPrintStream;
class wsiOutputStream;
class wsiConsoleCommand;


#define WS_IID_OF_wsiConsoleApp     \
    { 0xd3176e42, 0xe290, 0x43d0, { 0x8a, 0x5d, 0x14, 0x4d, 0x83, 0xb8, 0xc1, 0x78 } }
// {D3176E42-E290-43d0-8A5D-144D83B8C178}


class wsiConsoleApp : public wsiObject
{
public:
    static const ws_iid sIID;
public:
    WS_METHOD( ws_result  , OnInit      )( void ) = 0;
    WS_METHOD( ws_result  , OnExit      )( void ) = 0;
    WS_METHOD( ws_result  , OnCmd       )( wsiConsoleCommand * cmd ) = 0;
    WS_METHOD( ws_result  , OnCmdMapped )(ws_int cmdId , wsiConsoleCommand * cmd) = 0;
    WS_METHOD( ws_result  , OnCmdUnsupported )(wsiConsoleCommand * cmd) = 0;

    WS_METHOD( ws_result  , WaitForCmd  )(wsiConsoleCommand ** ret) = 0;
    WS_METHOD( ws_result  , AddCmdMap   )(ws_int cmdId , const ws_char * const cmdStr) = 0;
    WS_METHOD( ws_boolean , IsDoExit    )( void ) = 0;
    WS_METHOD( ws_result  , Exit        )( void ) = 0;
    WS_METHOD( ws_result  , GetInput    )( wsiInputStream  ** ret ) = 0;
    WS_METHOD( ws_result  , SetInput    )( wsiInputStream  *  aIS ) = 0;
    WS_METHOD( ws_result  , GetOutput   )( wsiPrintStream  ** ret ) = 0;
    WS_METHOD( ws_result  , SetOutput   )( wsiOutputStream *  aOS ) = 0;
};

