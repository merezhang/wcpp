#include "ReferenceTest.h"
#include <wcpp/lang/ref/wsiWeakReference.h>
#include <wcpp/lang/ref/wsuSupportsWeakReference.h>
#include <wcpp/lang/wscClass.h>



/*
 *******************************************************************************
 * private classes
 *******************************************************************************
 */


class iClassB : public wsiObject
{
public:
        WS_METHOD( ws_result , SetPtr )(wsiWeakReference * ptr) = 0;
};


class iClassA : public wsiSupportsWeakReference
{
public:
        WS_METHOD( ws_result , SetPtr )(iClassB * ptr) = 0;

};


class ClassA : public wscObject , public iClassA, public wsuSupportsWeakReference
{
 
    WS_IMPL_QUERY_INTERFACE_BEGIN( ClassA )
        WS_IMPL_QUERY_INTERFACE_BODY( iClassA )
        WS_IMPL_QUERY_INTERFACE_BODY_BRANCH( wsiSupportsWeakReference , iClassA )
    WS_IMPL_QUERY_INTERFACE_END()

public:
    static const ws_char * const s_class_name;
public:
    ClassA(void);
    ~ClassA(void);
    WS_METHOD( ws_result , SetPtr )(iClassB * ptr) { m_b = ptr; return ws_result(0); }

    WS_METHOD( ws_result , GetWeakReference )(wsiWeakReference ** ret) { return wsuSupportsWeakReference::GetWeakReference(ret); }

private:
    ws_ptr<iClassB> m_b;
};
const ws_char * const ClassA::s_class_name = "ClassA";


ClassA::ClassA(void)
{
}

ClassA::~ClassA(void)
{
}



class ClassB : public wscObject , public iClassB
{
    WS_IMPL_QUERY_INTERFACE_BEGIN( ClassB )
        WS_IMPL_QUERY_INTERFACE_BODY( iClassB )
    WS_IMPL_QUERY_INTERFACE_END()
public:
    static const ws_char * const s_class_name;
public:
    ClassB(void){}
    ~ClassB(void){}
    WS_METHOD( ws_result , SetPtr )(wsiWeakReference * ptr) { m_a = ptr; return ws_result(0); }
private:
    ws_ptr<wsiWeakReference> m_a;
};
const ws_char * const ClassB::s_class_name = "ClassB";



/*
 *******************************************************************************
 * ReferenceTest class
 *******************************************************************************
 */


// WS_DEFINE_STATIC_NEW( ReferenceTest ,  )


ReferenceTest::ReferenceTest(void)
{
}


ReferenceTest::~ReferenceTest(void)
{
}


ws_result ReferenceTest::doTest(void)
{
	trace( "========================================\n" );
	trace( "case:ReferenceTest - begin\n" );

	test_WeakReference();

	trace( "case:ReferenceTest - end\n" );
	trace( "========================================\n" );
    return ws_result( WS_RLT_SUCCESS );
}




void ReferenceTest::test_WeakReference(void)
{

    ClassA * pa = WS_NULL;
    wscObjectFinal<ClassA>::New( &pa );
	ws_ptr<iClassA> a;
    a.Attach( pa );

    ClassB * pb = WS_NULL;
    wscObjectFinal<ClassB>::New( &pb );
	ws_ptr<iClassB> b;
    b.Attach( pb );

	//
	ws_ptr<wsiWeakReference> wRef;
	a->GetWeakReference( &wRef );
	//
	b->SetPtr( wRef );
	a->SetPtr( b );
	//
//	wRef.Release();
	a.Release();
	b.Release();

	ws_ptr<wsiObject> obj;
    wRef->GetTarget( obj.GetIID(), (void**) (&obj) );

}


