
#include "Main.h"
#ifdef __PIC32MX__
    #include <plib.h>
#endif

XCHAR *    xItoA(XCHAR buf[8],int val,int base){

    short i = 0;
    int valCopy = 0;

    if(!val) {
        buf[0] = '0';
        buf[1] = 0;
	return &buf[0];
    }
    valCopy = val;
    for(i = 0; (i<8 && valCopy >0); i++){

        valCopy = valCopy/10;

    }
    buf[i] = 0x0000;
    for(; (i>=0 && val >0);){

        buf[--i] = 0x30 + (val%10);
        val = val/10;

    }

    return &buf[0];
    
}