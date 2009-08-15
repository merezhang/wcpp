#pragma once

#include "ws_ptr_RootBase.h"


template <typename T>
class NoAddReleaseT_for_ws_ptr : public T
{
private:
	WS_METHOD( ws_int , AddRef  )(void) = 0;
	WS_METHOD( ws_int , Release )(void) = 0;
};


template<typename T>
class ws_ptr_RootEx : public ws_ptr_RootBase
{
private:
    T * m_ptr;

public:

    enum WS_CLSCTX_x {
        WS_CLSCTX_ALL ,
    };

protected:

    ws_ptr_RootEx(void) : m_ptr(WS_NULL)
    {
    }

    ~ws_ptr_RootEx(void)
    {
        T * p = m_ptr;
        m_ptr = WS_NULL;
        if (p) p->Release();
    }

private:

    ws_ptr_RootEx(const ws_ptr_RootEx & src);
    const ws_ptr_RootEx & operator = (const ws_ptr_RootEx & src);

public:             // operators

    operator T* (void) const
    {
        return m_ptr;
    }

    ws_boolean operator < (T * pT) const
    {
        return ( m_ptr < pT );
    }

    ws_boolean operator ! (void) const
    {
        return (m_ptr==WS_NULL);
    }

    T ** operator & (void)
    {
        Release();
        return (&m_ptr);
    }

    T & operator * (void) const
    {
        return (*m_ptr);
    }

    NoAddReleaseT_for_ws_ptr<T> * operator -> (void) const
    {
        if (m_ptr==WS_NULL) {
            ThrowNullPointerException( "" , __FILE__ , __LINE__ );
            return WS_NULL;
        }
        else {
            return ((NoAddReleaseT_for_ws_ptr<T> *)m_ptr);
        }
    }

    ws_boolean operator == (T * pT) const
    {
        return (m_ptr == pT);
    }

public:

    void Advise(wsiObject * pObj, const ws_iid & iid, ws_uint32 & dw)
    {
        InternalThrowUnsupported();
    }

    void Attach(T * p2)
    {
        T * pold = m_ptr;
        m_ptr = p2;
        if (pold) pold->Release();
    }

    void CoCreateInstance(wsiString * aContractID, wsiObject * aOuter = WS_NULL, ws_uint32 dwClsContext = WS_CLSCTX_ALL)
    {
        InternalThrowUnsupported();
    }

    void CoCreateInstance(const ws_cid & aClass, wsiObject * aOuter = WS_NULL, ws_uint32 dwClsContext = WS_CLSCTX_ALL)
    {
        InternalThrowUnsupported();
    }

    void CopyTo(T ** ret)
    {
        if (ret==WS_NULL) {
            ThrowNullPointerException( "" , __FILE__ , __LINE__ );
        }
        else {
            WS_ASSERT((*ret)==WS_NULL);
            (*ret) = m_ptr;
            if (m_ptr) m_ptr->AddRef();
        }
    }

    T * Detach(void)
    {
        T * ret = m_ptr;
        m_ptr = WS_NULL;
        return ret;
    }

    ws_boolean IsEqualObject(wsiObject * other)
    {
        if (m_ptr==WS_NULL) {
            return (other==WS_NULL);
        }
        else {
            return m_ptr->Equals();
        }
    }

    template<typename Q>
    ws_result QueryInterface2(Q ** pp) const
    {
        if (pp==WS_NULL) {
            ThrowNullPointerException( "" , __FILE__ , __LINE__ );
        }
        else {
            WS_ASSERT((*pp)==WS_NULL);
            if (m_ptr) {
                return m_ptr->QueryInterface( Q::sIID , (void**)pp );
            }
        }
        return WS_RLT_FAILED;
    }

    void Release(void) 
    {
        if (m_ptr) m_ptr->Release();
        m_ptr = WS_NULL;
    }

    void SetSite(wsiObject * parent)
    {
        InternalThrowUnsupported();
    }

public:

    static const ws_iid & GetIID(void)
    {
        return T::sIID;
    }

};

