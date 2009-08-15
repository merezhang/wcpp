#pragma once

#include <wcpp/lang/wsiIterable.h>
#include "wsiCollection.h"


template <typename E>
class wsiSet : public wsiCollection<E> /* , public wsiIterable<E> */
{
public:
    static const ws_iid sIID;
};

