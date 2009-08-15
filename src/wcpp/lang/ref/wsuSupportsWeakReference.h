#pragma once
#include "wsiSupportsWeakReference.h"
#include "wsiWeakReference.h"
#include <wcpp/lang/wscClass.h>
#include <wcpp/lang/wscObject.h>


class wsuSupportsWeakReference : public wsiSupportsWeakReference
{
protected:

	wsuSupportsWeakReference(void);
	~wsuSupportsWeakReference(void);

	WS_METHOD(ws_result,GetWeakReference)(wsiWeakReference ** ret);

    void InternalReleaseWeakReferenceObject(void);

private:        // data member

    class wsi_wref_obj : public wsiWeakReference 
    {
    public:
        static const ws_iid sIID;
    public:
        WS_METHOD(void,Clear)(void) = 0;
    };

    class t_wref_obj : public wscObject , public wsi_wref_obj
    {
        WS_IMPL_QUERY_INTERFACE_BEGIN( wsuSupportsWeakReference::t_wref_obj )
            WS_IMPL_QUERY_INTERFACE_BODY( wsuSupportsWeakReference::wsi_wref_obj )
        WS_IMPL_QUERY_INTERFACE_END()
    public:     // profile
        static const ws_char * const s_class_name;
    public:     // static New
        static void New( wsi_wref_obj ** ret , wsiSupportsWeakReference * target );
    public:
        typedef t_wref_obj       t_this_class;
        typedef wscObject        t_super_class;
    public:
        t_wref_obj(void);
        ~t_wref_obj(void);
        WS_METHOD(ws_result, GetTarget)(const ws_iid & aIID, void ** ret);
        WS_METHOD(void,      Clear)    (void);
        WS_METHOD(ws_boolean,Equals)   (wsiObject *obj);
    private:
        wsiSupportsWeakReference * m_target;
    };

	ws_safe_ptr<wsi_wref_obj> m_WeakRef;

};



