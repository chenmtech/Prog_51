
#include "hal_serial.h"
#include "sys_core.h"
#include "hal_lcd1602.h"

static uint8*	pRevData = NULL;
static uint8	revEvent = 0x00;
static uint8	sndEvent = 0x00;

static void T1_Init(uint8 t1);

static void T1_Init(uint8 t1)
{
	TMOD &= 0x2F;
	TL1 = t1;
	TH1 = t1;
	TR1 = 0;
}

extern void Serial_Init(uint16 baud)
{
	uint8 t1 = 0;
	switch(baud) {
		case 9600:
			t1 = 0xFA;
			break;
		case 14400:
			t1 = 0xFC;
			break;
		case 19200:
			t1 = 0xFD;
			break;
		case 28800:
			t1 = 0xFE;
			break;
		default:
			return;
	}
	
	T1_Init(t1);
	
	PCON = 0x80;
	SCON = 0x50;
	ES = 1;
	EA = 1;
}

extern void Serial_SetReceiveInfo(uint8 * pData, uint8 evt)
{
	pRevData = pData;
	revEvent = evt;
}

extern void Serial_SetSendFinishEvent(uint8 evt)
{
	sndEvent = evt;
}

extern void Serial_SendByte(uint8 d)
{
	SBUF = d;
}

extern void Serial_Start()
{
	TR1 = 1;
}

extern void Serial_Stop() 
{
	TR1 = 0;
}

void serial_inter() interrupt 4
{
	if(RI == 1) {
		RI = 0;
		if(pRevData != NULL) *pRevData = SBUF;
		if(revEvent != 0x00) Sys_SetEvent(revEvent);
	} else {
		TI = 0;
		if(sndEvent != 0x00) Sys_SetEvent(sndEvent);
	}
	
}