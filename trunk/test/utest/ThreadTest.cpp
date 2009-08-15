#include "ThreadTest.h"
#include <wcpp/lang/wscThread.h>
#include <wcpp/lang/wscSystem.h>


ThreadTest::ThreadTest(void)
{
}

ThreadTest::~ThreadTest(void)
{
}


ws_result ThreadTest::doTest(void)
{
	trace( "========================================\n" );
	trace( "case:ThreadTest - begin\n" );

	test_CreateThread();

	trace( "case:ThreadTest - end\n" );
	trace( "========================================\n" );
    return ws_result( WS_RLT_SUCCESS );
}


	class myRunnable : public wscObject , public wsiRunnable
	{
        WS_IMPL_QUERY_INTERFACE_BEGIN( myRunnable )
            WS_IMPL_QUERY_INTERFACE_BODY( wsiRunnable )
        WS_IMPL_QUERY_INTERFACE_END()
    public:
        static const ws_char * const  s_class_name;
	public:
		WS_METHOD( ws_result , Run )(void)
		{
//          trace( "myRunnable::Run - begin\n" );
//			wscThread::Sleep( 1000 * 10 );
//          trace( "myRunnable::Run - end\n" );
            return ws_result(0);
		}
	};
    const ws_char * const  myRunnable::s_class_name = "myRunnable";



void ThreadTest::test_CreateThread(void)
{
	class myThread : public wscThread
	{
	public:
		WS_METHOD( ws_result , Run )(void)
		{
            trace( "myThread::Run - begin\n" );
//			wscThread::Sleep( 1000 * 5 );
            trace( "myThread::Run - end\n" );
            return ws_result(0);
		}
	};


	trace( "    --------------------------------    \n" );
	trace( "func:test_CreateThread - begin\n" );

    myRunnable * prun3 = WS_NULL;
    wscObjectFinal<myRunnable>::New(&prun3);
    ws_ptr<wsiRunnable> run3;
    run3.Attach( prun3 );

    ws_ptr<wsiThread> thd1;     wscThread::New(&thd1);
    ws_ptr<wsiThread> thd2;     myThread::New(&thd2);
    ws_ptr<wsiThread> thd3;     wscThread::New( &thd3 , run3 );

	thd1->Start();
	thd2->Start();
	thd3->Start();

	thd1->Join();
	thd2->Join();
	thd3->Join();

	trace( "func:test_CreateThread - end\n" );
	trace( "    --------------------------------    \n" );
}

