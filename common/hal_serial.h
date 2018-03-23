
#ifndef HAL_SERIAL_H
#define HAL_SERIAL_H

#include "sys_core.h"

#if (CFG_SERIAL == SERIAL_ON)

extern void Serial_Init(uint16 baud);

extern void Serial_SetReceiveInfo(uint8 * pData, uint8 evt);

extern void Serial_SetSendFinishEvent(uint8 evt);

extern void Serial_SendByte(uint8 d);

extern void Serial_Start();

extern void Serial_Stop();

#endif

#endif
