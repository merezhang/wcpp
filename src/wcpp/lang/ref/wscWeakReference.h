#pragma once
#include <wcpp/lang/wscObject.h>
#include "wsiWeakReference.h"
#include "wsiSupportsWeakReference.h"
#include <wcpp/lang/wscString.h>


class wsiWeakReferenceCtrl : public wsiWeakReference
{
public:
    static const ws_iid sIID;
public:
	WS_METHOD( ws_result , Clear     )(void) = 0;
};


class wscWeakReference : public wscObject, public wsiWeakReferenceCtrl
{
public:
    typedef wscWeakReference       t_this_class;
    static const ws_char * const   s_class_name;
private:

	wscWeakReference(const wscWeakReference & init);
	const wscWeakReference & operator=(const wscWeakReference & init);

	WS_METHOD( ws_result , Clear     )(void);
	WS_METHOD( ws_result , GetTarget )(const ws_iid & aIID, void ** ret);

public:

	wscWeakReference(wsiSupportsWeakReference * obj);
	~wscWeakReference(void);

private:

	wsiSupportsWeakReference * m_ptr;

};



