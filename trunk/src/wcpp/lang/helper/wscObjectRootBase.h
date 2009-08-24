#pragma once

#include <wcpp/lang/wsiObject.h>
#include "ws_debug_endpoint.h"



/********************************************************************************************************************
	WS_IMPL_QUERY_INTERFACE_
*/


typedef struct tWS_INTMAP_ENTRY
{
    const ws_iid * const   piid;
    ws_long                offset;
    ws_int                 type;
}
WS_INTMAP_ENTRY;




#define WS_IID_INST_OF( _interface_ )                   \
    (&(_interface_::sIID))


#define _WS_PACKING 8
#define WS_OFFSET_BETWEEN( derived , base )      \
    ((ws_long)(static_cast<base*>((derived*)_WS_PACKING))-_WS_PACKING)




#define WS_IMPL_QUERY_INTERFACE_BEGIN(_this_class_)     \
protected:                                              \
    static const WS_INTMAP_ENTRY * const _GetEntries(void)     \
    {                                                   \
        typedef _this_class_   _t_this_class;           \
        static const WS_INTMAP_ENTRY sEntries[] = {     \


#define WS_IMPL_QUERY_INTERFACE_BODY(_interface_)       \
            { WS_IID_INST_OF(_interface_) , WS_OFFSET_BETWEEN(_t_this_class , _interface_) , 1 },  \


#define WS_IMPL_QUERY_INTERFACE_END()                   \
            { 0 , 0 , 0 },                              \
        };                                              \
        return sEntries;                                \
    }                                                   \


#define WS_IMPL_QUERY_INTERFACE_BODY_BRANCH( _interface_ , _branch_ )                                               \
            { WS_IID_INST_OF(_interface_) ,                                                                         \
            (WS_OFFSET_BETWEEN( _t_this_class , _branch_ ))+(WS_OFFSET_BETWEEN( _branch_ , _interface_ )) , \
            1 },                                                                                                    \




/*******************************************************************************************************************
	wscObjectRootBase
*/


class wscObjectRootBase : public wsiObject
{
protected:

	wscObjectRootBase(void);
	wscObjectRootBase(wsiInterface * aOuter);
	~wscObjectRootBase(void);

protected:  // methods

    void FinalConstruct();
    void FinalRelease();

public:     // static functions

    static ws_result InternalQueryInterface(
        void * pThis,
        const WS_INTMAP_ENTRY * pEntries,
        const ws_iid & iid,
        void ** pp
        );

    static void ObjectMain(
        ws_boolean bStarting 
        );

    static ws_result InternalGetClass(wsiClass ** ret, const ws_char * const name);

protected:  // implements wsiObject

	ws_boolean  InternalEquals     (wsiObject * obj);
//	ws_result   InternalGetClass   (wsiClass ** rClass);
	ws_int      InternalHashCode   (void);

	ws_result   InternalNotify     (void);
	ws_result   InternalNotifyAll  (void);
    ws_result   InternalToString   (wsiString ** rString);
	ws_result   InternalWait       (void);
	ws_result   InternalWait       (ws_long timeout);
	ws_result   InternalWait       (ws_long timeout, ws_int nanos);

public:

    static void ThrowUnsupported(const ws_char * const msg, const ws_char * const file, ws_int line);
    static void ThrowNullPointer(const ws_char * const msg, const ws_char * const file, ws_int line);
    static void ThrowIllegalState(const ws_char * const msg, const ws_char * const file, ws_int line);

private:

	ws_debug_endpoint m_dbg_ep;

    static ws_int s_objcnt;

};

