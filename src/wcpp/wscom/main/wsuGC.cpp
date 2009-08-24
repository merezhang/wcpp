#include "wsuGC.h"
#include <wcpp/wspr/wsuSingleLock.h>
#include <wcpp/lang/wsiObject.h>
#include <wcpp/wspr/wspr.h>


wsuGC::wsuGC(void)
:   m_pThread ( WS_NULL  ) ,
    m_stopped ( WS_FALSE ) ,
    m_doStop  ( WS_FALSE ) ,
    m_objbuf_in  ( & m_objbuf_1 ) ,
    m_objbuf_out ( & m_objbuf_2 )
{
    m_pThread = ws_thread::StartThread( this );
}


wsuGC::~wsuGC(void)
{
    Stop();
}


ws_result wsuGC::ThreadProc(void)
{
    while ( ! m_doStop ) {
        m_pThread->Sleep( 1000 );
        int cnt = DoRelease();
        SwapObjBuf();
    }

    /*
    int timeout = 0;
    while (timeout < 5) {
        int cnt = DoRelease();
        SwapObjBuf();
        if (cnt <= 0) {
            timeout ++ ;
        }
        else {
            timeout = 0;
        }
    }
    */

    m_stopped = WS_TRUE;
    return WS_RLT_SUCCESS;
}


void wsuGC::Stop(void)
{
    while (!m_stopped) {
        m_doStop = WS_TRUE;
        ws_thread::Sleep( 100 );
    }
    delete m_pThread;
    m_pThread = WS_NULL;
}


void wsuGC::PreRelease(wsiObject * obj)
{
//    if (m_stopped) {
        WS_ASSERT( m_stopped == WS_FALSE );
//    }
    wsuSingleLock lock( & m_mutex );
    m_objbuf_in->push_back( obj );
}


void wsuGC::SwapObjBuf(void)
{
    wsuSingleLock lock( & m_mutex );

    if (m_objbuf_in != (&m_objbuf_1)) {
        m_objbuf_in  = (&m_objbuf_1);
        m_objbuf_out = (&m_objbuf_2);
    }
    else {
        m_objbuf_in  = (&m_objbuf_2);
        m_objbuf_out = (&m_objbuf_1);
    }
}


int wsuGC::DoRelease(void)
{
    t_obj_buffer & buf(*m_objbuf_out);
    int cnt = 0;
    t_obj_buffer::iterator iEnd = buf.end();
    for (t_obj_buffer::iterator iter=buf.begin(); iter!=iEnd; iter++) {
        wsiObject * obj = (*iter);
        if (obj) {
            cnt ++ ;
            obj->Release();
        }
    }
    buf.clear();
    return cnt;
}

