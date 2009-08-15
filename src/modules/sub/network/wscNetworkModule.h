#pragma once

#include <wcpp/wscom/wscModule.h>


class wscNetworkModule : public wscModule
{
public:
    static const ws_char * const s_class_name;
public:
    wscNetworkModule(void);
    ~wscNetworkModule(void);
protected:
    WS_VFUNC( ws_result , IndexToClassId  )(ws_cid & ret , ws_int index);
    WS_VFUNC( ws_result , NewClassFactory )(wsiFactory ** ret , const ws_cid & aClass);
};

