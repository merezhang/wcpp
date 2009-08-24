#pragma once

#include <wcpp/wspr/ws_thread.h>
#include <wcpp/wspr/wsuMutex.h>
#include <list>


class wsiObject;


class wsuGC : private ws_runnable
{
private:

    typedef  std::list<wsiObject *>  t_obj_buffer;

    wsuMutex       m_mutex;
    t_obj_buffer   m_objbuf_1;
    t_obj_buffer   m_objbuf_2;

    ws_thread *    m_pThread;
    ws_boolean     m_stopped;
    ws_boolean     m_doStop;
    t_obj_buffer * m_objbuf_in;
    t_obj_buffer * m_objbuf_out;

public:
    wsuGC(void);
    ~wsuGC(void);
    void PreRelease(wsiObject * obj);
    void Stop(void);
private:
    ws_result ThreadProc(void);
    void SwapObjBuf(void);
    int  DoRelease(void);
};

