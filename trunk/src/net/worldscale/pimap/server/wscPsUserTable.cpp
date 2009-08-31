#include "wscPsUserTable.h"
#include "wsiPsUser.h"
#include <wcpp/wspr/wsuSingleLock.h>
#include "wscPimapServerConfig.h"
#include "wscPsUser.h"


wscPsUserTable::wscPsUserTable(void)
{
    /*
    for (ws_uint32 i=wscPimapServerConfig::MAX_USER_NUMBER+3; i>0; i--) {
        ws_ptr<wsiPsUser> user;
        NewObj<wscPsUser>( &user , i );
        Put( user );
    }
    */
}


wscPsUserTable::~wscPsUserTable(void)
{
}


ws_result wscPsUserTable::Get(wsiPsUser ** ret, ws_uint32 uid)
{
    ws_ptr<wsiObject> obj;
    if (true)
    {
        wsuSingleLock lock( &m_mutex );
        t_user_table::iterator iter = m_UserTab.find(uid);
        if (iter == m_UserTab.end()) return WS_RLT_FAILED;
        (*iter).second.CopyTo( &obj );
    }
    if (!obj) return WS_RLT_FAILED;
    return obj->QueryInterface( wsiPsUser::sIID , (void**)ret );
}


ws_result wscPsUserTable::Put(wsiPsUser *user)
{
    if (user==WS_NULL) return WS_RLT_NULL_POINTER;
    ws_uint32 uid = user->GetUserId();
    wsuSingleLock lock( &m_mutex );
    if (wscPimapServerConfig::MAX_USER_NUMBER < m_UserTab.size()) return WS_RLT_ARRAY_INDEX_OUT_OF_BOUNDS;
    m_UserTab.insert( t_user_table::value_type(uid,user) );
    return WS_RLT_SUCCESS;
}


ws_result wscPsUserTable::Remove(ws_uint32 uid)
{
    wsuSingleLock lock( &m_mutex );
    m_UserTab.erase( uid );
    return WS_RLT_SUCCESS;
}

