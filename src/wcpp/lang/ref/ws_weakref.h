#pragma once

#include "wsiWeakReference.h"
#include "wsiSupportsWeakReference.h"
#include <wcpp/lang/helper/ws_safe_ptr.h>


template<typename T>
class ws_weakref
{
private:

    ws_safe_ptr<wsiWeakReference> m_wrobj;

public:
    
    ws_weakref(void)
    {
    }

    ws_weakref(const ws_weakref & src)
    {
        m_wrobj = src.m_wrobj;
    }

    ~ws_weakref(void)
    {
    }

    const ws_weakref & operator = (const ws_weakref & src)
    {
        m_wrobj = src.m_wrobj;
        return (*this);
    }

    void SetTarget(T * p)
    {
        m_wrobj.Release();
        if (p==WS_NULL) return;
        ws_ptr<wsiInterface> obj( p );
        ws_ptr<wsiSupportsWeakReference> pswr;
        obj.QueryInterface2( &pswr );
        pswr->GetWeakReference( &m_wrobj );
    }

    void GetTarget(T ** tar)
    {
        m_wrobj->GetTarget( T::sIID , (void**) tar );
    }

    void Release(void)
    {
        m_wrobj.Release();
    }

};

