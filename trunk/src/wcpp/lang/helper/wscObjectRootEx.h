#pragma once

#include <wcpp/wspr/ws_type.h>
#include "wsuThreadModel.h"
#include "wscObjectRootBase.h"


template<typename T_ThreadModel>
class wscObjectRootEx : public wscObjectRootBase
{
public:

    typedef wscObjectRootBase  t_super_class;

    typedef T_ThreadModel                                     ThreadModel;
    /*
    typedef typename ThreadModel::AutoCriticalSection         CritSec;
    typedef typename ThreadModel::AutoDeleteCriticalSection   AutoDelCritSec;
    typedef typename wsuObjectLockT<ThreadModel>              ObjectLock;
    */

protected:

    wscObjectRootEx(void) : m_nRef(0)
    {
    }

//  methods

    ws_int InternalAddRef()
    {
        return ThreadModel::Increment( m_nRef );
    }

    ws_int InternalRelease()
    {
        ws_int ret = ThreadModel::Decrement( m_nRef );
        if (ret==0) {
            delete ((wsiInterface*)this);
        }
        return ret;
    }

    void Lock(void)
    {
        InternalThrowUnsupported();
    //    m_lock.Lock();
    }

    void Unlock(void)
    {
        InternalThrowUnsupported();
    //    m_lock.Unlock();
    }

protected:

    void FinalConstruct()
    {
        t_super_class::FinalConstruct();
    }

    void FinalRelease()
    {
        t_super_class::FinalRelease();
    }

    ws_int OuterAddRef(void)
    {
        return m_pOuter->AddRef();
    }

    ws_result OuterQueryInterface(const ws_iid & iid , void** pp)
    {
        return m_pOuter->QueryInterface(iid,pp);
    }

    ws_int OuterRelease(void)
    {
        return m_pOuter->Release();
    }

public:

    /*
    static void InternalQueryInterface(void* pThis, const WS_INTMAP_ENTRY * pEntries, const ws_iid & iid, void** pp)
    {
        t_super_class::InternalQueryInterface( pThis , pEntries , iid , pp );
    }
    */

    static void ObjectMain(ws_boolean bStarting)
    {
        t_super_class::ObjectMain( bStarting );
    }

private:    // data member

    union
    {
       ws_int         m_nRef;
       wsiInterface * m_pOuter;
    };

//    ObjectLock m_lock;

};

