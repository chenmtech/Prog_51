
#include "hal_delay.h"

static void delay1ms();

static void delay1ms(void)
{
	uint8 a,b;
	for(b=4;b>0;b--)
			for(a=113;a>0;a--);
}

extern void delay_ms(uint8 timer)
{
	uint8 i = timer;
	for(; i > 0; i--)
			delay1ms();
}


