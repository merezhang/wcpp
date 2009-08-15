#pragma once
#include "wscObject.h"
#include "wscRunnable.h"
#include "wsiThread.h"
#include "wscString.h"

#include <wcpp/wspr/ws_thread.h>
#include <wcpp/lang/ref/wsuSupportsWeakReference.h>




class wsiRunnableProxy : public wsiRunnable
{
public:
    static const ws_iid sIID;
public:
    WS_METHOD( ws_result  , Clear     )(void) = 0;
    WS_METHOD( ws_boolean , IsStarted )(void) = 0;
    WS_METHOD( ws_boolean , IsStopped )(void) = 0;
};


class wsiThreadService;


#define WS_ClassName_OF_wscThread       "wcpp.lang.wscThread"


class wscThread : public wscObject , public wsiThread , private ws_runnable
{
    WS_IMPL_QUERY_INTERFACE_BEGIN( wscThread )
        WS_IMPL_QUERY_INTERFACE_BODY( wsiThread )
        WS_IMPL_QUERY_INTERFACE_BODY( wsiRunnable )
    WS_IMPL_QUERY_INTERFACE_END()

public:
    typedef wscThread     t_this_class;
    typedef wscObject     t_super_class;
    static const ws_char * const s_class_name;

public:

	static void New(wsiThread ** ret);
	static void New(wsiThread ** ret, wsiRunnable * target);
	static void New(wsiThread ** ret, wsiRunnable * target, wsiString * name);
	static void New(wsiThread ** ret, wsiString * name);

	wscThread(void);
	~wscThread(void);

	static ws_int ActiveCount(void);
	static void   CurrentThread(wsiThread ** rThread);
	static void   Sleep(ws_long millis);
	static void   Yield(void);

protected:

	WS_METHOD( ws_result  , GetName     )(wsiString ** rName);
	WS_METHOD( ws_int     , GetPriority )(void);
	WS_METHOD( ws_result  , Interrupt   )(void);
	WS_METHOD( ws_boolean , IsAlive     )(void);
	WS_METHOD( ws_result  , Join        )(void);
	WS_METHOD( ws_result  , SetPriority )(ws_int newPriority);
	WS_METHOD( ws_result  , Start       )(void);

	WS_METHOD( ws_result  , Run         )(void);

    WS_VFUNC ( ws_result  , ThreadProc  )(void);

private:
    void       _ThreadProc2(void);
    void _Init( wsiRunnable * target , wsiString * name );
    static void GetThreadService(wsiThreadService ** ret);
private:
    ws_str                    m_name;
    ws_ptr<wsiRunnable>       m_target;

    ws_thread *               m_thread;
    ws_boolean                m_started;
    ws_boolean                m_stopped;
    ws_int                    m_id;
};

