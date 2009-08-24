#pragma once

#include "wsiNumber.h"
#include "wscObject.h"


class wscNumber : public wscObject , public wsiNumber
{
public:
    wscNumber(void);
    ~wscNumber(void);
};

