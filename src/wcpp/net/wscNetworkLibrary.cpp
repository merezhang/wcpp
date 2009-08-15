#include "wscNetworkLibrary.h"

#include <wcpp/lang/wscThrowable.h>


/*
***********************************************************************************************************
*   wscNetworkLibrary::t_factory
***********************************************************************************************************
*/


wscNetworkLibrary::t_factory::t_factory(void)
:   wscFactory( 
               wscNetworkLibrary::s_class_name , 
               wscNetworkLibrary::sCID , 
               wscNetworkLibrary::sContractID , 
               0 , 
               0 )
{
}


wscNetworkLibrary::t_factory::~t_factory(void)
{
}


/*
***********************************************************************************************************
*   wscNetworkLibrary
***********************************************************************************************************
*/


void wscNetworkLibrary::GetNetwork(wsiNetwork ** ret)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}



