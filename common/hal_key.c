
#include "hal_key.h"
#include "sys_core.h"
#include "hal_delay.h"

static uint8 event = 0x00;
sbit KEY = P3^3;

extern void Key_Init(uint8 evt)
{
	IT1 = 1;
	EX1 = 1;
	EA = 1;
	
	event = evt;
}

void int1_inter() interrupt 2
{
	if(event == 0x00) return;
	
	delay_ms(10);
	if(KEY == 0) {
		Sys_SetEvent(event);
	}
}