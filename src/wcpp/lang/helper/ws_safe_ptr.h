#pragma once

#include "ws_safe_ptr_RootEx.h"


template <typename T>
class ws_safe_ptr : public ws_safe_ptr_RootEx<T>
{
public:

    ws_safe_ptr(void)
    {
    }

    ~ws_safe_ptr(void)
    {
    }

private:

    ws_safe_ptr(const ws_safe_ptr &);
    const ws_safe_ptr & operator=(const ws_safe_ptr &);
};

