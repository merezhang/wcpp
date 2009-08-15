#pragma once

#include "ws_ptr_RootEx.h"


template <typename T>
class ws_ptr : public ws_ptr_RootEx<T>
{
public:

    ws_ptr(void)
    {
    }

    ws_ptr(T * lp)
    {
        if (lp) lp->AddRef();
        Attach( lp );
    }

    ws_ptr(const ws_ptr & src)
    {
        T * p = src;
        if (p) p->AddRef();
        Attach( p );
    }

public:

    T* operator =(T* lp)
    {
        if (lp) lp->AddRef();
        Attach( lp );
        return lp;
    }

    T* operator =(const ws_ptr & src)
    {
        T * p = src;
        if (p) p->AddRef();
        Attach( p );
        return p;
    }



};

