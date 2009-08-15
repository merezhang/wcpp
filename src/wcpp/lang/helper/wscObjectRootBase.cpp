// wscObjectRootBase.cpp
#include "wscObjectRootEx.h"

#include <wcpp/wspr/wspr.h>
#include <wcpp/lang/wscClass.h>
#include <wcpp/lang/wscThrowable.h>
#include "ws_ptr.h"
#include "ws_runtime.h"



ws_result wscObjectRootBase::InternalGetClass(wsiClass ** ret, const ws_char * const name)
{
    return NewObj<wscClass>(ret,name);
}


void wscObjectRootBase::ThrowUnsupported(const ws_char * const msg, const ws_char * const file, ws_int line)
{
    throw wseUnsupportedOperationException::Throw( msg , file , line );
}


void wscObjectRootBase::ThrowNullPointer(const ws_char * const msg, const ws_char * const file, ws_int line)
{
    throw wseNullPointerException::Throw( msg , file , line );
}


void wscObjectRootBase::ThrowIllegalState(const ws_char * const msg, const ws_char * const file, ws_int line)
{
    throw wseIllegalStateException::Throw( msg , file , line );
}


#define OBJCNT_BASE_VALUE     1000000
ws_int wscObjectRootBase::s_objcnt = OBJCNT_BASE_VALUE;


wscObjectRootBase::wscObjectRootBase(void)
{
    ws_runtime::getRuntime()->IncrementRefcnt( & s_objcnt );
}


wscObjectRootBase::~wscObjectRootBase(void)
{
    ws_int rlt = ws_runtime::getRuntime()->DecrementRefcnt( & s_objcnt );

    /*
    if (rlt == OBJCNT_BASE_VALUE) {
        WS_ASSERT( 0 );     // 发生这个断言表示所有的对象已在退出程序之前析构
    }
    */
}


void wscObjectRootBase::FinalConstruct()
{
    m_dbg_ep.SelectTarget( this );
}


void wscObjectRootBase::FinalRelease()
{
}


// static functions


ws_result wscObjectRootBase::InternalQueryInterface(void * pThis, const WS_INTMAP_ENTRY * pEntries, const ws_iid & iid, void ** pp)
{
    if (pEntries==WS_NULL) {
        WS_THROW( wseNullPointerException , "QueryInterface with a null entries table ." );
    }

    if (pp==WS_NULL) {
        WS_THROW( wseNullPointerException , "QueryInterface with a null ptr-to-ptr ." );
    }
    if (*pp) {
        WS_THROW( wseNullPointerException , "QueryInterface with a ptr-to-ptr which is holding something ." );
    }

    while ( pEntries->type ) {
        if (pEntries->piid[0]==iid) {
            ((wsiInterface*)pThis)->AddRef();
            *pp =(void*) (((ws_long)pThis) + pEntries->offset);
            return ws_result( WS_RLT_SUCCESS );
        }
        pEntries++;
    }

    if (wsiObject::sIID == iid) {
        ((wsiInterface*)pThis)->AddRef();
        *pp = pThis;
        return ws_result( WS_RLT_SUCCESS );
    }

    WS_THROW( wseClassCastException , "QueryInterface on the object which unsupport the required interface . " );
    return ws_result( WS_RLT_CLASS_CAST );
}


void wscObjectRootBase::ObjectMain(ws_boolean bStarting)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}




ws_boolean wscObjectRootBase::InternalEquals(wsiObject * obj)   // method
{
    if (obj==WS_NULL) {
        return WS_FALSE;
    }
    else {
        ws_ptr<wsiObject> p1,p2;
        obj->QueryInterface( wsiObject::sIID , (void**)(&p2) );
        this->QueryInterface( wsiObject::sIID , (void**)(&p1) );
        return (p1==p2);
    }
}


/*
ws_result wscObjectRootBase::InternalGetClass(wsiClass ** rClass)   // method
{
    WS_TRY {
        return InternalGetClass(rClass);
    } WS_CATCH();
}
*/


ws_int wscObjectRootBase::InternalHashCode(void)   // method
{
    return ((ws_int)((((ws_long)this) ^ 0x12345678) & 0xffffffff));
}


ws_result wscObjectRootBase::InternalNotify(void)   // method
{
    return ws_result( WS_RLT_UNSUPPORTED_OPERATION );
}


ws_result wscObjectRootBase::InternalNotifyAll(void)   // method
{
    return WS_RLT_UNSUPPORTED_OPERATION;
}


ws_result wscObjectRootBase::InternalToString(wsiString ** rString)   // method
{
    ws_ptr<wsiClass> cls;
    this->GetClass( &cls );
    return cls->GetName( rString );
}


ws_result wscObjectRootBase::InternalWait(void)   // method
{
    return WS_RLT_UNSUPPORTED_OPERATION;
}


ws_result wscObjectRootBase::InternalWait(ws_long timeout)   // method
{
    return WS_RLT_UNSUPPORTED_OPERATION;
}


ws_result wscObjectRootBase::InternalWait(ws_long timeout, ws_int nanos)   // method
{
    return WS_RLT_UNSUPPORTED_OPERATION;
}

