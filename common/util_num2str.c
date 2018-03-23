
#include "util_num2str.h"

#include "stdio.h"

extern uint8 NST_IntLength(int16 num)
{
	uint8 len = 0;
	if(num < 0) {num = -num; len++;}
	if(num >= 10000) return len+5;
	else if(num >= 1000) return len+4;
	else if(num >= 100) return len+3;
	else if(num >= 10) return len+2;
	else return len+1;
}

extern uint8 NST_FloatLength(float num)
{
	uint16 len = NST_IntLength((int16)num);
	return len+4;
}

extern uint8 NST_Int2Str(int16 num, uint8 * pStr)
{
	return sprintf(pStr, "%d", num);
}

extern uint8 NST_Float2Str(float num, uint8 * pStr)
{
	return sprintf(pStr, "%.3f", num);
}