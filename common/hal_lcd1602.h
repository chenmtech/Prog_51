
#ifndef HAL_LCD1602_H
#define HAL_LCD1602_H

#include "sys_core.h"

#if (CFG_LCD1602 == LCD1602_ON)

// 初始化
extern void Lcd1602_init();

// 执行命令，命令代码请查阅相关文献，比如0x01为清屏
extern void Lcd1602_ExecuteCmd(uint8 cmd);

extern void Lcd1602_Clear();

// 设置开始显示的位置
// x: 0-第一行 1-第二行
extern bool Lcd1602_SetPosition(uint8 x, uint8 y);

// 显示一个字符
extern void Lcd1602_ShowChar(uint8 c);

// 显示一个字符串
extern void Lcd1602_ShowString(uint8* pStr, uint8 len);

// 显示一个整数
extern void Lcd1602_ShowInt(int16 num);

// 显示一个浮点数
extern void Lcd1602_ShowFloat(float num);


#endif


#endif