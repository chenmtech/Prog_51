
#ifndef UTIL_NUM2STR_H
#define UTIL_NUM2STR_H

#include "hal_comdefs.h"

extern uint8 NST_IntLength(int16 num);

extern uint8 NST_FloatLength(float num);

extern uint8 NST_Int2Str(int16 num, uint8 * pStr);

extern uint8 NST_Float2Str(float num, uint8 * pStr);

#endif