// wscSystem.cpp
#include "wscSystem.h"
#include "wsoLangService.h"
#include "wsiLangService.h"


void wscSystem::GetSystemService(wsiSystemService ** ret)
{
    ws_ptr<wsiLangService> pls;
    wsoLangService::GetLangService( &pls );
    pls->GetSystemService(ret);
}


void wscSystem::GetErr(wsiPrintStream ** ret)
{
    ws_ptr<wsiSystemService> pss;
    GetSystemService( &pss );
    pss->GetErr(ret);
}


void wscSystem::GetOut(wsiPrintStream ** ret)
{
    ws_ptr<wsiSystemService> pss;
    GetSystemService( &pss );
    pss->GetOut(ret);
}


void wscSystem::GetIn(wsiInputStream ** ret)
{
    ws_ptr<wsiSystemService> pss;
    GetSystemService( &pss );
    pss->GetIn(ret);
}


void wscSystem::SetErr(wsiPrintStream *aPrintStream)
{
    ws_ptr<wsiSystemService> pss;
    GetSystemService( &pss );
    pss->SetErr( aPrintStream );
}


void wscSystem::SetIn(wsiInputStream *aInputStream)
{
    ws_ptr<wsiSystemService> pss;
    GetSystemService( &pss );
    pss->SetIn( aInputStream );
}


void wscSystem::SetOut(wsiPrintStream *aPrintStream)
{
    ws_ptr<wsiSystemService> pss;
    GetSystemService( &pss );
    pss->SetOut( aPrintStream );
}

