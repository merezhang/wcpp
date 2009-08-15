#include "wsuHashtable.h"
#include <wcpp/wspr/wsuSingleLock.h>


wsuHashtableCore::wsuHashtableCore(void)
{
}


wsuHashtableCore::~wsuHashtableCore(void)
{
}


ws_result wsuHashtableCore::Get(wsiObject *key, wsiObject **ret)
{
    wsuSingleLock lock( & m_mutex );

    t_table::iterator iter = m_table.find( key );
    if (iter == m_table.end()) {
        return WS_RLT_FAILED;
    }
    (*iter).second.CopyTo( ret );
    return WS_RLT_SUCCESS;
}


ws_result wsuHashtableCore::Put(wsiObject *key, wsiObject *value)
{
    if (key==WS_NULL) {
        return WS_RLT_NULL_POINTER;
    }

    wsuSingleLock lock( & m_mutex );

    m_table.insert( t_table::value_type( key , value ) );

    return WS_RLT_SUCCESS;
}

