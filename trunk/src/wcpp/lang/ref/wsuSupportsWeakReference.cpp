#include "wsuSupportsWeakReference.h"
#include <wcpp/lang/wscObject.h>


const ws_iid wsuSupportsWeakReference::wsi_wref_obj::sIID = 
    { 0xa9674d9e, 0x4272, 0x4387, { 0xb6, 0xcb, 0xf9, 0x22, 0xdc, 0xdf, 0x97, 0x71 } };
// {A9674D9E-4272-4387-B6CB-F922DCDF9771}


const ws_char * const wsuSupportsWeakReference::t_wref_obj::s_class_name = "wcpp.lang.ref.wsuSupportsWeakReference::t_wref_obj";


/*
******************************************************************************************************************
*   wsuSupportsWeakReference::t_wref_obj
******************************************************************************************************************
*/


void wsuSupportsWeakReference::t_wref_obj::New(wsuSupportsWeakReference::wsi_wref_obj ** ret , wsiSupportsWeakReference * target)
{
    wsuSupportsWeakReference::t_wref_obj * pnew = WS_NULL;
    wscObjectFinal<wsuSupportsWeakReference::t_wref_obj>::New( &pnew );
    ws_ptr<wsuSupportsWeakReference::wsi_wref_obj> keeper;
    keeper.Attach( pnew );
    pnew->m_target = target;
    keeper.CopyTo( ret );
}


wsuSupportsWeakReference::t_wref_obj::t_wref_obj(void) : m_target(WS_NULL)
{
}


wsuSupportsWeakReference::t_wref_obj::~t_wref_obj(void)
{
}


ws_result wsuSupportsWeakReference::t_wref_obj::GetTarget(const ws_iid & aIID, void ** ret)
{
    ws_ptr<wsiSupportsWeakReference> swr ( m_target );
    if (!swr) {
        return ws_result( WS_RLT_SUCCESS );
    }
    else {
        return swr->QueryInterface( aIID, ret );
    }
}


void wsuSupportsWeakReference::t_wref_obj::Clear(void)
{
    m_target = WS_NULL;
}


ws_boolean wsuSupportsWeakReference::t_wref_obj::Equals(wsiObject *obj)
{
    ws_ptr<wsiSupportsWeakReference> swr ( m_target );
    return swr->Equals( obj );
}


/*
******************************************************************************************************************
*   wsuSupportsWeakReference
******************************************************************************************************************
*/


wsuSupportsWeakReference::wsuSupportsWeakReference(void)
{
    ws_ptr<wsi_wref_obj> tmp;
    t_wref_obj::New( &tmp, this );
    m_WeakRef.Set( tmp );
}


wsuSupportsWeakReference::~wsuSupportsWeakReference(void)
{
    InternalReleaseWeakReferenceObject();
}


ws_result wsuSupportsWeakReference::GetWeakReference(wsiWeakReference ** ret)
{
    ws_ptr<wsi_wref_obj> tmp;
    m_WeakRef.Get( &tmp );
    ws_ptr<wsiWeakReference> wr;
    wr.Attach( tmp.Detach() );
    wr.CopyTo( ret );
    return ws_result( WS_RLT_SUCCESS );
}


void wsuSupportsWeakReference::InternalReleaseWeakReferenceObject(void)
{
    ws_ptr<wsi_wref_obj> p;
    m_WeakRef.Get( &p );
    m_WeakRef.Set( WS_NULL );
    p->Clear();
}

