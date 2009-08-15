// wscLong.cpp

#include "wscLong.h"
#include "wscString.h"
#include "wscThrowable.h"


void wscLong::ToString(const ws_long aValue, wsiString ** rString)
{
	const int bufsz = (sizeof(aValue) * 3) + 3;
	ws_char buf[bufsz];

	int i = bufsz - 1;
	buf[i] = 0;

	ws_long abs = aValue;
	if (abs < 0) abs=(-abs);
	ws_char sig = (aValue >= 0) ? '+' : '-';

	do {
		i--;
		buf[i] = static_cast<ws_char>('0' + (abs % 10));
		abs /= 10;
	} while ((i>1) && (abs>0));

	if (sig=='-') {
		i--;
		buf[i] = '-';
	}

    ws_str str( buf + i, bufsz-i-1 );
    ws_ptr<wsiString> tmp(str);
    tmp.CopyTo( rString );
}


ws_long wscLong::ParseLong(wsiString * aString)
{
    WS_THROW( wseUnsupportedOperationException , "" );
    return 0;
}

