#include "wscThread.h"
#include "wsoLangService.h"
#include "wscThrowable.h"


/*
 ********************************************************************************************************
 *  wscRunnableProxy
 ********************************************************************************************************
 */


class wscRunnableProxy : public wscObject , public wsiRunnableProxy
{
public:
    static void New(wsiRunnableProxy ** ret, wsiRunnable * target);

    wscRunnableProxy(void);
    ~wscRunnableProxy(void);

protected:

	// implements wsiRunnable
	WS_METHOD( ws_result , Run )(void);

	// implements wsiRunnableProxy
    WS_METHOD( ws_result  , Clear     )(void);
    WS_METHOD( ws_boolean , IsStarted )(void);
    WS_METHOD( ws_boolean , IsStopped )(void);

private:
    wsiRunnable * m_pTarget;
    ws_boolean m_started;
    ws_boolean m_stopped;
};


wscRunnableProxy::wscRunnableProxy(void)
:   m_pTarget( WS_NULL ),
    m_started( WS_FALSE ),
    m_stopped( WS_FALSE )
{
}


wscRunnableProxy::~wscRunnableProxy(void)
{
    m_pTarget = WS_NULL;
}


ws_result wscRunnableProxy::Run(void)
{
    ws_ptr<wsiRunnable> target( m_pTarget );
    m_pTarget = WS_NULL;
    m_started = WS_TRUE;

    ws_result ret = target->Run();
    m_stopped = WS_TRUE;
    return ret;
}


ws_result wscRunnableProxy::Clear(void)
{
    m_pTarget = WS_NULL;
    return ws_result( WS_RLT_SUCCESS );
}


ws_boolean wscRunnableProxy::IsStarted(void)
{
    return m_started;
}


ws_boolean wscRunnableProxy::IsStopped(void)
{
    return m_stopped;
}


/*
 ********************************************************************************************************
 *  wscThread
 ********************************************************************************************************
 */


void wscThread::GetThreadService(wsiThreadService ** ret)
{
    ws_ptr<wsiLangService> pls;
    wsoLangService::GetLangService( &pls );
    pls->GetThreadService( ret );
}


wscThread::wscThread(void) : 
    m_thread  (WS_NULL) , 
    m_started (WS_FALSE) , 
    m_stopped (WS_FALSE) ,
    m_id (-1)
{
}


void wscThread::New(wsiThread ** ret)
{
    New( ret , WS_NULL , WS_NULL );
}


void wscThread::New( wsiThread ** ret , wsiRunnable * target )
{
    New( ret , target , WS_NULL );
}


void wscThread::New(wsiThread ** ret , wsiRunnable * target, wsiString * name)
{
    wscThread * pnew = WS_NULL;
    NewObj<wscThread>(&pnew);
    pnew->m_name = name;
    pnew->m_target = target;
    ws_ptr<wsiThread> kp;
    kp.Attach( pnew );
    kp.CopyTo( ret );
}


void wscThread::New(wsiThread ** ret , wsiString * name)
{
    New( ret , WS_NULL , name );
}


wscThread::~wscThread(void)
{
    ws_thread * thd = m_thread;
    m_thread = WS_NULL;
    if (thd) {
        delete thd;
    }
}


ws_int wscThread::ActiveCount(void)
{
    WS_THROW( wseUnsupportedOperationException, "" );
	return 0;
}


void wscThread::CurrentThread(wsiThread ** rThread)
{
    WS_THROW( wseUnsupportedOperationException, "" );
}


void wscThread::Sleep(ws_long millis)
{
    ws_ptr<wsiThreadService> ts;
    GetThreadService( &ts );
    ts->Sleep( millis );
}


void wscThread::Yield(void)
{
    WS_THROW( wseUnsupportedOperationException, "" );
}


ws_result wscThread::GetName(wsiString ** rName)
{
	m_name.CopyTo( rName );
    return ws_result( WS_RLT_SUCCESS );
}


ws_int wscThread::GetPriority(void)
{
	WS_THROW( wseUnsupportedOperationException , "" );
    return 0;
}


ws_result wscThread::Interrupt(void)
{
	WS_THROW( wseUnsupportedOperationException , "" );
    return ws_result( WS_RLT_SUCCESS );
}


ws_boolean wscThread::IsAlive(void)
{
	WS_THROW( wseUnsupportedOperationException , "" );
    return WS_FALSE;
}


ws_result wscThread::Join(void)
{
    if ( m_started ) {
        while (true) {
            if (m_stopped) break;
            Sleep(10);
        }
    }
    else {
        WS_THROW( wseIllegalThreadStateException , "Join a thread which is not started." );
    }
    return ws_result( WS_RLT_SUCCESS );
}


ws_result wscThread::SetPriority(ws_int newPriority)
{
	WS_THROW( wseUnsupportedOperationException , "" );
    return ws_result( WS_RLT_SUCCESS );
}


ws_result wscThread::Start(void)
{
    if (m_thread) {
        WS_THROW( wseIllegalThreadStateException , "" );
    }
    m_thread = ws_thread::StartThread( this );
    if (m_thread==WS_NULL) {
        WS_THROW( wseIllegalThreadStateException , "" );
    }

    int cs = 0;
    int lp = 0;
    while (cs < 1000) {
        lp++;
        if (m_started) return ws_result( WS_RLT_SUCCESS );
        if (lp > 500) {
            Sleep(1);
            cs++;
        }
        else {
            Sleep(0);
        }
    }

    WS_THROW( wseIllegalThreadStateException , "" );
    return ws_result( WS_RLT_SUCCESS );
}


ws_result wscThread::Run(void)
{
    ws_ptr<wsiRunnable> tar( m_target );
    wsiRunnable * ptar = tar;
    if (ptar) ptar->Run();
    return ws_result( WS_RLT_SUCCESS );
}


ws_result wscThread::ThreadProc(void)
{
    ws_ptr<wsiThread> keeper(this);
    _ThreadProc2();
    return ws_result( WS_RLT_SUCCESS );
}


void wscThread::_ThreadProc2(void)
{
    class t_auto_state_man
    {
    public:
        t_auto_state_man(ws_boolean * p1 , ws_boolean * p2) : m_p1(p1) , m_p2(p2)
        {
            *m_p1 = WS_TRUE;
        }
        ~t_auto_state_man(void)
        {
            *m_p2 = WS_TRUE;
        }
    private:
        ws_boolean * m_p1;
        ws_boolean * m_p2;
    };

    m_id = ws_thread::GetCurrentThreadId();
    t_auto_state_man( &m_started , &m_stopped );
    
    wsiRunnable * pRun = this;
    pRun->Run();
}

