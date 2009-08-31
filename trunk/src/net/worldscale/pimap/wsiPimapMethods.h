#pragma once

#include <wcpp/lang/wsiObject.h>


class wsiPimapMethods : public wsiObject
{
public:
    static const ws_iid sIID;
public:
    
    class FUNC_LOGIN
    {
    public:
        enum func_id {
            FID = 1001 ,
        };
        enum param_id {
            PID_USER_NAME = 1 ,
            PID_PASSWORD  = 2 ,
            PID_USER_ID   = 3 ,
            PID_DOWN_KEY  = 4 ,
        };
    };

    class FUNC_LOGOUT
    {
    public:
        enum func_id {
            FID = 1002 ,
        };
        enum param_id {
        };
    };

};

