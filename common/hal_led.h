
#ifndef HAL_LED_H
#define HAL_LED_H

#include "sys_core.h"

#if (CFG_LED == LED_ON)

extern void LED_Init();

extern void LED_TurnOn();

extern void LED_TurnOff();

extern bool LED_GetState();

#endif

#endif