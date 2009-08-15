#pragma once

#include "wscObject.h"
#include "wsiRuntime.h"



class wscRuntime : public wsiRuntime
{
public:
	static void GetRuntime(wsiRuntime ** ret);
};

