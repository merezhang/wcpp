#pragma once

#include <net/worldscale/pimap/wscPimapConfig.h>


class wscPimapServerConfig : public wscPimapConfig
{
public:
    static const ws_int MAX_USER_NUMBER     = 120000;
    static const ws_int MAX_THREAD_NUMBER   = 250;
};

