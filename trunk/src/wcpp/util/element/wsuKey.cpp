#include "wsuKeyValue.h"
#include <wcpp/lang/helper/ws_runtime.h>
#include <wcpp/lang/wsiObject.h>


wsuKey::wsuKey(wsiObject * src) : m_object(WS_NULL)
{
    if (src) {
        src->AddRef();
        m_object = src;
    }
}


wsuKey::wsuKey(const wsuKey &src) : m_object(WS_NULL)
{
    wsiObject * obj = src.m_object;
    if (obj) {
        obj->AddRef();
        m_object = obj;
    }
}


wsuKey::~wsuKey(void)
{
    wsiObject * obj = m_object;
    m_object = WS_NULL;
    if (obj) ws_runtime::getRuntime()->PreRelease( obj );
}


wsuKey::operator long(void) const
{
    wsiObject * obj = m_object;
    if (obj) {
        return obj->HashCode();
    }
    else {
        return 0;
    }
}


bool wsuKey::operator ==(const wsuKey &other) const
{
    wsiObject * o1 = m_object;
    wsiObject * o2 = other.m_object;

    if ((o1==WS_NULL) || (o2==WS_NULL)) {
        return (o1==o2);
    }
    else {
        return o1->Equals( o2 );
    }
}

