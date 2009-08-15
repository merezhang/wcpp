#include "ws_debug_endpoint.h"
#include "ws_debug_probe.h"
#include "ws_runtime.h"
#include "ws_debug_probe.h"


ws_debug_endpoint::ws_debug_endpoint(void) : m_probe(WS_NULL)
{
    m_probe = ws_runtime::getRuntime()->debugNewProbe();
}


ws_debug_endpoint::~ws_debug_endpoint(void)
{
    if (m_probe) m_probe->SelectTarget( WS_NULL );
}


wsiObject * ws_debug_endpoint::SelectTarget(wsiObject * obj)
{
    if (m_probe) {
        return m_probe->SelectTarget( obj );
    }
    else {
        return WS_NULL;
    }
}

