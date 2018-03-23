
#ifndef GLOBAL_FUNC_H
#define GLOBAL_FUNC_H

#include "sys_core.h"

#if (CFG_OSCFREQ == FREQ_11M)

// 毫秒延时
// 开发板的晶振频率为11.0592MHz。频率改变时需要修改此函数
extern void delay_ms(uint8 timer);


#endif

#endif