#pragma once

#include "ws_safe_ptr_RootBase.h"


template <typename T>
class ws_safe_ptr_RootEx : public ws_safe_ptr_RootBase
{
private:

    typedef ws_safe_ptr_RootBase   t_super_class;

    T * m_ptr;

    ws_safe_ptr_RootEx(const ws_safe_ptr_RootEx &);
    const ws_safe_ptr_RootEx & operator=(const ws_safe_ptr_RootEx &);

protected:

    ws_safe_ptr_RootEx(void) : m_ptr(WS_NULL)
    {
    }

    ~ws_safe_ptr_RootEx(void)
    {
        T * tmp = m_ptr;
        m_ptr = WS_NULL;
        if (tmp) tmp->Release();
    }

public:

    void Get(T ** pp)
    {
        if (pp==WS_NULL) {
            t_super_class::ThrowNullPointerException( "" , __FILE__ , __LINE__ );
        }
        if (*pp) {
            t_super_class::ThrowNullPointerException( "" , __FILE__ , __LINE__ );
        }
        T * tmp = m_ptr;
        if (tmp) {
            if (tmp->AddRef() > 0) {
                (*pp) = tmp;
            }
        }
    }

    void Set(T * p)
    {
        if (p) p->AddRef();
        SwapPtr( (void**)(&p) , (void**)(&m_ptr) );
        if (p) p->Release();
    }

    ws_boolean IsNull() const
    {
        return (m_ptr==WS_NULL);
    }

};


