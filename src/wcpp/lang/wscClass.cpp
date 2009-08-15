// wscClass.cpp
#include "wscClass.h"


wscClass::wscClass(const ws_char * const aName) : m_name(aName)
{
}


wscClass::~wscClass(void)
{
}


const ws_char * const wscClass::GetName(void)
{
    return m_name;
}


ws_result wscClass::GetName(wsiString ** rString)
{
    ws_str str( m_name );
    ws_ptr<wsiString> tmp( str );
    tmp.CopyTo( rString );
    return WS_RLT_SUCCESS;
}

