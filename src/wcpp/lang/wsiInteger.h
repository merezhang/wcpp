#pragma once
#include "wsinumber.h"


#define WS_IID_OF_wsiInteger        \
    { 0x5dfd79a5, 0x2093, 0x4b6d, { 0x97, 0x9a, 0x31, 0x40, 0x10, 0xec, 0xed, 0x5f } }
// {5DFD79A5-2093-4b6d-979A-314010ECED5F}


class wsiInteger : public wsiNumber
{
public:
    static const ws_iid sIID;
};

