#pragma once

#include "wscObject.h"
#include "wsiArray.h"


#define WS_ClassName_OF_wscArrayBase        "wcpp.lang.wscArrayBase"


class wscArrayBase : public wscObject
{
public:
    static const ws_char * const s_class_name;
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


#define WS_ClassName_OF_wscValueArrayBase       "wcpp.lang.wscValueArrayBase"


class wscValueArrayBase : public wscObject
{
public:
    static const ws_char * const s_class_name;
protected:
    static void * InternalAlloca(ws_int size);
    static void   InternalFree(void * p);
};


template<typename T>
class wscValueArray : public wscValueArrayBase , public wsiValueArray<T>
{
    WS_IMPL_QUERY_INTERFACE_BEGIN( t_this_class )
        WS_IMPL_QUERY_INTERFACE_BODY( t_this_interface )
    WS_IMPL_QUERY_INTERFACE_END()

public:
    typedef wscValueArray      t_this_class;
    typedef wsiValueArray<T>   t_this_interface;
    typedef T                  t_data_type;

private:

    T *      m_data;
    ws_int   m_length;

protected:

    WS_METHOD( ws_int  , Length )(void)
    {
        return m_length;
    }

    WS_METHOD( T*      , Data   )(void)
    {
        return m_data;
    }

public:

    wscValueArray(ws_int length) : m_data(WS_NULL) , m_length(length)
    {
        m_data = (t_data_type*) InternalAlloca( sizeof(t_data_type) * length );
        if (m_data==WS_NULL) m_length = 0;
    }

    ~wscValueArray(void)
    {
        InternalFree( m_data );
    }
};


typedef wscValueArray<ws_byte>         wscByteArray;

