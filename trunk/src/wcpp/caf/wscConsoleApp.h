#pragma once

#include "wsiConsoleApp.h"
#include <wcpp/lang/wscObject.h>
#include <wcpp/lang/wsiInteger.h>
#include <wcpp/io/wsiInputStream.h>
#include <wcpp/io/wsiPrintStream.h>
#include <wcpp/io/wsiOutputStream.h>
#include <wcpp/util/element/wsuHashtable.h>


class wscConsoleApp : public wscObject , public wsiConsoleApp
{
    WS_IMPL_QUERY_INTERFACE_BEGIN( wscConsoleApp )
        WS_IMPL_QUERY_INTERFACE_BODY( wsiConsoleApp )
    WS_IMPL_QUERY_INTERFACE_END()
private:
    ws_safe_ptr<wsiInputStream>   m_is;
    ws_safe_ptr<wsiPrintStream>   m_ps;
    ws_boolean                    m_doExit;
private:
    typedef wsiString   t_ht_cmdmap_k;
    typedef wsiInteger  t_ht_cmdmap_v;
    typedef wsuHashtable< t_ht_cmdmap_k , t_ht_cmdmap_v > t_ht_cmdmap;
    t_ht_cmdmap    m_htCmdMap;
public:
    static ws_result CreateApp(wsiConsoleApp ** ret);
public:
    wscConsoleApp(void);
    ~wscConsoleApp(void);
public:
    WS_METHOD( ws_result  , OnInit      )( void );
    WS_METHOD( ws_result  , OnExit      )( void );
    WS_METHOD( ws_result  , OnCmd       )( wsiConsoleCommand * cmd );
    WS_METHOD( ws_result  , OnCmdMapped )(ws_int cmdId , wsiConsoleCommand * cmd);
    WS_METHOD( ws_result  , OnCmdUnsupported )(wsiConsoleCommand * cmd);

    WS_METHOD( ws_result  , WaitForCmd  )(wsiConsoleCommand ** ret);
    WS_METHOD( ws_result  , AddCmdMap   )(ws_int cmdId , const ws_char * const cmdStr);
    WS_METHOD( ws_boolean , IsDoExit    )( void );
    WS_METHOD( ws_result  , Exit        )( void );
    WS_METHOD( ws_result  , GetInput    )( wsiInputStream  ** ret );
    WS_METHOD( ws_result  , SetInput    )( wsiInputStream  *  aIS );
    WS_METHOD( ws_result  , GetOutput   )( wsiPrintStream  ** ret );
    WS_METHOD( ws_result  , SetOutput   )( wsiOutputStream *  aOS );
};

