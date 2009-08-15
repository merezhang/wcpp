#pragma once

#include <wcpp/wspr/wsuMutex.h>


/*

typedef                     Single threading        Apartment threading     Free threading  
------------------------------------------------------------------------------------------------
wsuObjectThreadModel               S                       S                       M
wsuGlobalThreadModel               S                       M                       M
------------------------------------------------------------------------------------------------ 
S = wsuSingleThreadModel; M = wsuMultiThreadModel


*/


/*
*************************************************************************************************************
*   wsuXxxxCriticalSection
*************************************************************************************************************
*/


class wsuFakeCriticalSection
{
public:
    ws_result Init(void) throw();
    ws_result Lock(void) throw();
    ws_result Term(void) throw();
    ws_result Unlock(void) throw();
};


class wsuCriticalSection
{
public:
    wsuCriticalSection(void) throw();
    ws_result Init(void) throw();
    ws_result Lock(void) throw();
    ws_result Term(void) throw();
    ws_result Unlock(void) throw();
public:
    wsuMutex m_sec;
};


class wsuAutoCriticalSection : public wsuCriticalSection
{
public:
    wsuAutoCriticalSection(void);
    ~wsuAutoCriticalSection(void);
};


/*
*************************************************************************************************************
*   wsuXxxxThreadModel
*************************************************************************************************************
*/


class wsuMultiThreadModelNoCS
{
public:

    static ws_int Decrement(ws_int & n);
    static ws_int Increment(ws_int & n);

public:

    typedef wsuFakeCriticalSection    AutoCriticalSection;
    typedef wsuFakeCriticalSection    CriticalSection;
    typedef wsuMultiThreadModelNoCS   ThreadModelNoCS;

};


class wsuSingleThreadModel
{
public:

    static ws_int Decrement(ws_int & n);
    static ws_int Increment(ws_int & n);

public:

    typedef wsuFakeCriticalSection AutoCriticalSection;
    typedef wsuFakeCriticalSection CriticalSection;
    typedef wsuSingleThreadModel   ThreadModelNoCS;

};


class wsuMultiThreadModel
{
public:

    static ws_int Decrement(ws_int & n);
    static ws_int Increment(ws_int & n);

public:

    typedef wsuAutoCriticalSection    AutoCriticalSection;
    typedef wsuCriticalSection        CriticalSection;
    typedef wsuMultiThreadModelNoCS   ThreadModelNoCS;

};


/*
*************************************************************************************************************
*   typedefs
*************************************************************************************************************
*/


typedef wsuMultiThreadModel   wsuObjectThreadModel;
typedef wsuMultiThreadModel   wsuGlobalThreadModel;


/*
*************************************************************************************************************
*   eof
*************************************************************************************************************
*/

