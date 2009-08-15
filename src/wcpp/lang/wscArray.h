#pragma once

#include "wscObject.h"
#include "wsiArray.h"


class wscArrayBase : public wscObject
{
private:
    typedef wsiObject *  t_pobj;
    const ws_int m_size;
    t_pobj *     m_array;
protected:
    wscArrayBase(ws_int size);
    ~wscArrayBase(void);
protected:
    ws_result InternalGetItem(ws_int index , wsiObject ** ret);
    ws_result InternalPutItem(ws_int index , wsiObject *  obj);
    ws_int    InternalGetSize(void);
};


template <typename T>
class wscArray : public wscArrayBase , public wsiArray<T>
{
    WS_IMPL_QUERY_INTERFACE_BEGIN( t_this_class )
        WS_IMPL_QUERY_INTERFACE_BODY( t_this_interface )
    WS_IMPL_QUERY_INTERFACE_END()

public:
    static const ws_char * const s_class_name;
    typedef wscArray      t_this_class;
    typedef wsiArray<T>   t_this_interface;

public:

    wscArray(ws_int size) : wscArrayBase(size)
    {
    }

    ~wscArray(void)
    {
    }

    WS_METHOD( ws_int    , GetSize )(void)
    {
        return InternalGetSize();
    }

    WS_METHOD( ws_result , GetItem )(ws_int index, T ** ret)
    {
        return InternalGetItem( index , (wsiObject**) ret );
    }

    WS_METHOD( ws_result , PutItem )(ws_int index, T * item)
    {
        return InternalPutItem( index , item );
    }
};


