#include "wsuKeyValue.h"
#include <wcpp/lang/helper/ws_runtime.h>
#include <wcpp/lang/wsiObject.h>


wsuValue::wsuValue(const wsuValue &src) : m_object(WS_NULL)
{
    wsiObject * obj = src.m_object;
    if (obj) {
        obj->AddRef();
        m_object = obj;
    }
}


wsuValue::wsuValue(wsiObject * obj) : m_object(WS_NULL)
{
    if (obj) {
        obj->AddRef();
        m_object = obj;
    }
}


wsuValue::~wsuValue(void)
{
    wsiObject * obj = m_object;
    m_object = WS_NULL;
    if (obj) ws_runtime::getRuntime()->PreRelease( obj );
}


ws_result wsuValue::CopyTo(wsiObject ** ret)
{
    if (ret==WS_NULL) {
        return WS_RLT_NULL_POINTER;
    }
    if (*ret) {
        return WS_RLT_NULL_POINTER;
    }
    *ret = m_object;
    if (*ret) {
        (*ret)->AddRef();
    }
    return WS_RLT_SUCCESS;
}

