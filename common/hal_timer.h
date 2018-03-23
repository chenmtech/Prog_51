
#ifndef HAL_TIMER_H
#define HAL_TIMER_H

#include "hal_types.h"

extern void Timer_Init();

extern void Timer_Start(uint16 timeout, uint8 event);

extern void Timer_Stop();



#endif