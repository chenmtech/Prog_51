
#include "hal_led.h"


extern void LED_Init()
{
	LED_Pin = 1;
}

extern void LED_TurnOn()
{
	LED_Pin = 0;
}

extern void LED_TurnOff()
{
	LED_Pin = 1;
}

extern bool LED_GetState()
{
	return (LED_Pin == 0);
}

