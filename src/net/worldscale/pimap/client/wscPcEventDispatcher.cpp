#include "wscPcEventDispatcher.h"
#include "wsiPcWorkingContext.h"


WS_IMPL_ClassName_OF( wscPcEventDispatcher )


wscPcEventDispatcher::wscPcEventDispatcher(wsiPcWorkingContext * wc)
{
    m_wkContext.Set( wc );
}


wscPcEventDispatcher::~wscPcEventDispatcher(void)
{
}

