
#include "hal_timer.h"
#include "sys_core.h"

static uint16 Timeout0 = 0;
static uint16 cnt0 = 0;
static uint8  event0 = 0;

#define THMS	0xFC
#define TLMS	0x66


extern void Timer_Init()
{
	TMOD = 0x21;
	TH0 = THMS;
	TL0 = TLMS;
	ET0 = 1;
	
	EA = 1;
}

extern void Timer_Start(uint16 timeout, uint8 event)
{
	TR0 = 0;
	
	Timeout0 = timeout;
	event0 = event;
	cnt0 = 0;

	TR0 = 1;
}

extern void Timer_Stop()
{
	TR0 = 0;
}


void timer0_int() interrupt 1
{
	cnt0++;
	if(event0 != 0x00 && cnt0 == Timeout0) {
		Sys_SetEvent(event0);
		TR0 = 0;
	} else {
		TH0 = THMS;
		TL0 = TLMS;
		TR0 = 1;
	}
}
