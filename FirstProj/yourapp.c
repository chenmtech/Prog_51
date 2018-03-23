
#include "yourapp.h"
#include "hal_lcd1602.h"
#include "sys_core.h"
#include "hal_delay.h"
#include "hal_timer.h"
#include "hal_led.h"
#include "hal_key.h"
#include "hal_serial.h"

static bool isStart = FALSE;

static uint8 revData = 0;

static uint8 num = 0;

extern void YourApp_Init()
{
	Lcd1602_init();
	Key_Init(KEY_EVT);
	Serial_Init(28800);
	Serial_SetReceiveInfo(&revData, RECEIVE_DATA_EVT);
	Serial_SetSendFinishEvent(SEND_FINISH_EVT);
	Sys_SetEvent(START_DEVICE_EVT);	
}

extern uint8 YourApp_ProcessEvent(uint8 events)
{
	if(events & START_DEVICE_EVT) {
		Lcd1602_SetPosition(0, 0);   
		Lcd1602_ShowString("This is CM51SYS.", 15);
		
		Lcd1602_SetPosition(1, 0);
		Lcd1602_ShowString("You are Welcome.", 15);
		
		Serial_Start();
				
		return (events ^ START_DEVICE_EVT);
	}
	
	if(events & KEY_EVT) {

		Sys_SetEvent(SEND_DATA_EVT);
		
		return (events ^ KEY_EVT);
	}
	
	if(events & RECEIVE_DATA_EVT) {
		Lcd1602_Clear();
		Lcd1602_SetPosition(0,0);
		Lcd1602_ShowString("receive:", 8);
		Lcd1602_ShowInt(revData);
		
		if(revData == 0) Timer_Stop();
		else if(revData == 1) Timer_Start(1000, SEND_DATA_EVT);
		
		return (events ^ RECEIVE_DATA_EVT);
	}
	
	if(events & SEND_DATA_EVT) {
		
		Serial_SendByte(0x12);
		
		//LED_TurnOn();
		
		Timer_Start(1000, SEND_DATA_EVT);
		
		return (events ^ SEND_DATA_EVT);
	}
	
	if(events & SEND_FINISH_EVT) {
		
		
		return (events ^ SEND_FINISH_EVT);
	}
	
	return 0x00;	
}