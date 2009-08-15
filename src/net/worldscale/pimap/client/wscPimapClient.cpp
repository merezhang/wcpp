#include "wscPimapClient.h"
#include <wcpp/lang/wscThrowable.h>



wscPimapClient::wscPimapClient(void)
{
}


wscPimapClient::~wscPimapClient(void)
{
}


ws_result wscPimapClient::Login(wsiString *aUserName, wsiString *aPassword, wsiString *aServerAddr)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}


ws_result wscPimapClient::Logout(void)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}

