#pragma once

#include <wcpp/lang/wscObject.h>
#include <wcpp/lang/wsiThread.h>
#include <wcpp/lang/ref/ws_weakref.h>
#include <wcpp/lang/wscString.h>
#include <wcpp/wspr/ws_thread.h>


class wscThreadImpl : public wscObject , public wsiThread, public ws_runnable
{
public:
    wscThreadImpl(wsiRunnable * target, wsiString * name);
    ~wscThreadImpl(void);
private:
    WS_METHOD( ws_result,  GetName     )(wsiString ** rName);
	WS_METHOD( ws_int,     GetPriority )(void);
	WS_METHOD( ws_result,  Interrupt   )(void);
	WS_METHOD( ws_boolean, IsAlive     )(void);
	WS_METHOD( ws_result,  Join        )(void);
	WS_METHOD( ws_result,  Run         )(void);
	WS_METHOD( ws_result,  SetPriority )(ws_int newPriority);
	WS_METHOD( ws_result,  Start       )(void);
	WS_METHOD( ws_result,  ToString    )(wsiString ** rString);

    WS_VFUNC( ws_result, ThreadProc )(void);

private:
    ws_ptr<wsiRunnable> m_target;
    ws_str m_name;
    ws_thread * m_thread;
};

