#pragma once

#include "wsiPimapMethods.h"


class wsiPimapMethodsUp : public wsiPimapMethods
{
public:
    static const ws_iid sIID;
public:
    WS_METHOD( ws_result , Login  )(wsiString * username, wsiString * psw) = 0;
    WS_METHOD( ws_result , Logout )(void) = 0;
};

