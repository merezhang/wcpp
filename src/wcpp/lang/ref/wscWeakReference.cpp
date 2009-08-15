#include "wscWeakReference.h"



wscWeakReference::wscWeakReference(wsiSupportsWeakReference * obj) : m_ptr(obj)
{
}


wscWeakReference::~wscWeakReference(void)
{
	m_ptr = WS_NULL;
}



	
ws_result wscWeakReference::Clear(void)
{
	m_ptr = WS_NULL;
    return ws_result( WS_RLT_SUCCESS );
}


ws_result wscWeakReference::GetTarget(const ws_iid & aIID, void ** ret)
{
    ws_ptr<wsiSupportsWeakReference> ptr(m_ptr);
	if (!ptr) {
        return ws_result( WS_RLT_NULL_POINTER );
    }
    else {
		return ptr->QueryInterface(aIID,ret);
	}
}



