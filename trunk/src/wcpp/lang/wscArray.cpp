#include "wscArray.h"
#include <wcpp/lang/helper/ws_runtime.h>


wscArrayBase::wscArrayBase(ws_int size) : m_size(size) , m_array( WS_NULL )
{
    m_array = new t_pobj[ size ];
    for (ws_int i=m_size-1; i>=0; i--) {
        m_array[i] = WS_NULL;
    }
}


wscArrayBase::~wscArrayBase(void)
{
    for (ws_int i=m_size-1; i>=0; i--) {
        t_pobj pobj = m_array[i];
        m_array[i] = WS_NULL;
        if (pobj) pobj->Release();
    }

    delete []m_array;
    m_array = WS_NULL;
}


ws_result wscArrayBase::InternalGetItem(ws_int index, wsiObject **ret)
{
    WS_ASSERT( ret != WS_NULL );
    WS_ASSERT( (*ret) == WS_NULL );
    WS_ASSERT( m_array != WS_NULL );
    if ((0<=index) && (index<m_size)) {
        t_pobj pobj = m_array[index];
        if (pobj) {
            if ( pobj->AddRef() > 0 ) {
                *ret = pobj;
            }
        }
        return WS_RLT_SUCCESS;
    }
    else {
        return WS_RLT_ARRAY_INDEX_OUT_OF_BOUNDS;
    }
}


ws_result wscArrayBase::InternalPutItem(ws_int index, wsiObject * pobj)
{
    WS_ASSERT( m_array != WS_NULL );
    if ((index<0) || (m_size<=index)) {
        return WS_RLT_ARRAY_INDEX_OUT_OF_BOUNDS;
    }
    if (pobj) pobj->AddRef();
    ws_runtime::getRuntime()->SwapPtr( (void**)(&pobj) , (void**)(m_array+index) );
    if (pobj) pobj->Release();
    return WS_RLT_SUCCESS;
}


ws_int wscArrayBase::InternalGetSize(void)
{
    return m_size;
}


/*
******************************************************************************************************************************
*       wscValueArrayBase
******************************************************************************************************************************
*/


void * wscValueArrayBase::InternalAlloca(ws_int size)
{
    return ( new ws_byte [ size ] );
}


void wscValueArrayBase::InternalFree(void *p)
{
    ws_byte * pdel =(ws_byte *) p;
    if (pdel) delete [] pdel;
}

