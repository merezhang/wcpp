#pragma once


class wsiClass;
class wsiThrowable;


template<typename T_super>
class wscObjectFinal : public T_super
{
public:
    typedef T_super          t_super_class;
    typedef wscObjectFinal   t_this_class;

public:

    template<typename T1>
    wscObjectFinal(T1 p1) : t_super_class(p1)
    {
        FinalConstruct();
    }

    template<typename T1,typename T2>
    wscObjectFinal(T1 p1, T2 p2) : t_super_class(p1,p2)
    {
        FinalConstruct();
    }

    template<typename T1, typename T2, typename T3>
    wscObjectFinal(T1 p1, T2 p2, T3 p3) : t_super_class(p1,p2,p3)
    {
        FinalConstruct();
    }

    template<typename T1, typename T2, typename T3, typename T4>
    wscObjectFinal(T1 p1, T2 p2, T3 p3, T4 p4) : t_super_class(p1,p2,p3,p4)
    {
        FinalConstruct();
    }


    wscObjectFinal(void)
    {
        FinalConstruct();
    }

    ~wscObjectFinal(void)
    {
        FinalRelease();
    }

private:    // implements wsiInterface

	WS_METHOD( ws_int , AddRef )(void)
    {
        return InternalAddRef();
    }

	WS_METHOD( ws_result , QueryInterface )( const ws_iid & iid, void ** ret)
    {
        return InternalQueryInterface( this , _GetEntries() , iid , ret );
    }

	WS_METHOD( ws_int , Release )(void)
    {
        return InternalRelease();
    }

private:

  	WS_METHOD( ws_boolean , Equals )    (wsiObject * obj)
    {
        return InternalEquals(obj);
    }

	WS_METHOD( ws_result ,  GetClass )  (wsiClass ** rClass)
    {
        return InternalGetClass( rClass , s_class_name );
    }

	WS_METHOD( ws_int ,     HashCode )  (void)
    {
        return InternalHashCode();
    }

	WS_METHOD( ws_result ,  Notify )    (void)
    {
        ThrowUnsupported( "", __FILE__ , __LINE__ );
        return ws_result( WS_RLT_UNSUPPORTED_OPERATION );
    }

	WS_METHOD( ws_result ,  NotifyAll ) (void)
    {
        ThrowUnsupported( "", __FILE__ , __LINE__ );
        return ws_result( WS_RLT_UNSUPPORTED_OPERATION );
    }

    WS_METHOD( ws_result ,  ToString )  (wsiString ** rString)
    {
        return InternalToString( rString );
    }

    WS_METHOD( ws_result ,  Wait )      (void)
    {
        ThrowUnsupported( "", __FILE__ , __LINE__ );
        return ws_result( WS_RLT_UNSUPPORTED_OPERATION );
    }

	WS_METHOD( ws_result ,  Wait )      (ws_long timeout)
    {
        ThrowUnsupported( "", __FILE__ , __LINE__ );
        return ws_result( WS_RLT_UNSUPPORTED_OPERATION );
    }

	WS_METHOD( ws_result ,  Wait )      (ws_long timeout, ws_int nanos)
    {
        ThrowUnsupported( "", __FILE__ , __LINE__ );
        return ws_result( WS_RLT_UNSUPPORTED_OPERATION );
    }

private:

    WS_METHOD( ws_result  , Clone     )(wsiObject ** ret)
    {
        ThrowUnsupported( "", __FILE__ , __LINE__ );
        return ws_result( WS_RLT_UNSUPPORTED_OPERATION );
    }

	WS_METHOD( ws_result  , Finalize  )(void)
    {
        ThrowUnsupported( "", __FILE__ , __LINE__ );
        return ws_result( WS_RLT_UNSUPPORTED_OPERATION );
    }

public:

    static ws_result New(T_super ** pp)
    {
        if (pp==WS_NULL) {  ThrowNullPointer( "", __FILE__ , __LINE__ );    }
        if (*pp) {          ThrowIllegalState( "", __FILE__ , __LINE__ );   }
        T_super * pnew = WS_NULL;
        pnew = new wscObjectFinal();
        if (pnew) ((wscObjectRootBase*)pnew)->AddRef();
        *pp = pnew;
        return WS_RLT_SUCCESS;
    }

    template <typename T1>
    static ws_result New(T_super ** pp, T1 p1)
    {
        if (pp==WS_NULL) {  ThrowNullPointer( "", __FILE__ , __LINE__ );    }
        if (*pp) {          ThrowIllegalState( "", __FILE__ , __LINE__ );   }
        T_super * pnew = WS_NULL;
        pnew = new wscObjectFinal(p1);
        if (pnew) ((wscObjectRootBase*)pnew)->AddRef();
        *pp = pnew;
        return WS_RLT_SUCCESS;
    }

    template <typename T1, typename T2>
    static ws_result New(T_super ** pp, T1 p1, T2 p2)
    {
        if (pp==WS_NULL) {  ThrowNullPointer( "", __FILE__ , __LINE__ );    }
        if (*pp) {          ThrowIllegalState( "", __FILE__ , __LINE__ );   }
        T_super * pnew = WS_NULL;
        pnew = new wscObjectFinal(p1,p2);
        if (pnew) ((wscObjectRootBase*)pnew)->AddRef();
        *pp = pnew;
        return WS_RLT_SUCCESS;
    }

    template <typename T1, typename T2, typename T3>
    static ws_result New(T_super ** pp, T1 p1, T2 p2, T3 p3)
    {
        if (pp==WS_NULL) {  ThrowNullPointer( "", __FILE__ , __LINE__ );    }
        if (*pp) {          ThrowIllegalState( "", __FILE__ , __LINE__ );   }
        T_super * pnew = WS_NULL;
        pnew = new wscObjectFinal(p1,p2,p3);
        if (pnew) ((wscObjectRootBase*)pnew)->AddRef();
        *pp = pnew;
        return WS_RLT_SUCCESS;
    }

    template <typename T1, typename T2, typename T3, typename T4>
    static ws_result New(T_super ** pp, T1 p1, T2 p2, T3 p3, T4 p4)
    {
        if (pp==WS_NULL) {  ThrowNullPointer( "", __FILE__ , __LINE__ );    }
        if (*pp) {          ThrowIllegalState( "", __FILE__ , __LINE__ );   }
        T_super * pnew = WS_NULL;
        pnew = new wscObjectFinal(p1,p2,p3,p4);
        if (pnew) ((wscObjectRootBase*)pnew)->AddRef();
        *pp = pnew;
        return WS_RLT_SUCCESS;
    }
};


template< typename T , typename Q >
ws_result NewObj(Q ** pp)
{
    if (pp==WS_NULL) {  T::ThrowNullPointer( "", __FILE__ , __LINE__ );     }
    if (*pp) {          T::ThrowIllegalState( "", __FILE__ , __LINE__ );    }
    T * pnew = WS_NULL;
    ws_result ret = wscObjectFinal<T>::New( &pnew );
    (*pp) = pnew;
    return ret;
}


template< typename T , typename Q , typename T1 >
ws_result NewObj(Q ** pp, T1 p1)
{
    if (pp==WS_NULL) {  T::ThrowNullPointer( "", __FILE__ , __LINE__ );     }
    if (*pp) {          T::ThrowIllegalState( "", __FILE__ , __LINE__ );    }
    T * pnew = WS_NULL;
    ws_result ret = wscObjectFinal<T>::New( &pnew , p1 );
    (*pp) = pnew;
    return ret;
}


template< typename T , typename Q , typename T1 , typename T2>
ws_result NewObj(Q ** pp, T1 p1, T2 p2)
{
    if (pp==WS_NULL) {  T::ThrowNullPointer( "", __FILE__ , __LINE__ );     }
    if (*pp) {          T::ThrowIllegalState( "", __FILE__ , __LINE__ );    }
    T * pnew = WS_NULL;
    ws_result ret = wscObjectFinal<T>::New( &pnew , p1 , p2 );
    (*pp) = pnew;
    return ret;
}


template< typename T , typename Q , typename T1 , typename T2 , typename T3>
ws_result NewObj(Q ** pp, T1 p1, T2 p2, T3 p3)
{
    if (pp==WS_NULL) {  T::ThrowNullPointer( "", __FILE__ , __LINE__ );     }
    if (*pp) {          T::ThrowIllegalState( "", __FILE__ , __LINE__ );    }
    T * pnew = WS_NULL;
    ws_result ret = wscObjectFinal<T>::New( &pnew , p1 , p2 , p3 );
    (*pp) = pnew;
    return ret;
}

