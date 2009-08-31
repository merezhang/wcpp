#pragma once

#include "wsiPsUserTable.h"
#include <wcpp/lang/wscObject.h>
#include <unordered_map>
#include <wcpp/util/element/wsuKeyValue.h>


#define WS_ClassName_OF_wscPsUserTable      "net.worldscale.pimap.server.wscPsUserTable"


class wscPsUserTable : public wscObject , public wsiPsUserTable
{
    WS_IMPL_QUERY_INTERFACE_BEGIN( wscPsUserTable )
        WS_IMPL_QUERY_INTERFACE_BODY( wsiPsUserTable )
    WS_IMPL_QUERY_INTERFACE_END()
public:
    static const ws_char * const s_class_name;
private:
    typedef ws_uint32                                                       t_user_table_key;
    typedef wsuValue                                                        t_user_table_value;
    typedef std::tr1::unordered_map<t_user_table_key,t_user_table_value>    t_user_table;

    t_user_table   m_UserTab;
    wsuMutex       m_mutex;
public:
    wscPsUserTable(void);
    ~wscPsUserTable(void);
protected:
    WS_METHOD( ws_result , Put    )(wsiPsUser * user);
    WS_METHOD( ws_result , Get    )(wsiPsUser ** ret, ws_uint32 uid);
    WS_METHOD( ws_result , Remove )(ws_uint32 uid);
};

