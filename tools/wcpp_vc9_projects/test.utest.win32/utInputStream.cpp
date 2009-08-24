#include "utInputStream.h"
#include <wcpp/lang/wscSystem.h>
#include <iostream>


void utInputStream::Init(void)
{
    ws_ptr<wsiInputStream> is;
    NewObj<utInputStream>( &is );
    wscSystem::SetIn( is );
}


const ws_char * const utInputStream::s_class_name = "utInputStream";


utInputStream::utInputStream(void)
{
}


utInputStream::~utInputStream(void)
{
}


ws_int utInputStream::Read(void)
{
    char chr;
    std::cin >> chr;
    return chr;
}

