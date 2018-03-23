
#ifndef HAL_LCD1602_H
#define HAL_LCD1602_H

#include "sys_core.h"

#if (CFG_LCD1602 == LCD1602_ON)

// ��ʼ��
extern void Lcd1602_init();

// ִ�����������������������ף�����0x01Ϊ����
extern void Lcd1602_ExecuteCmd(uint8 cmd);

extern void Lcd1602_Clear();

// ���ÿ�ʼ��ʾ��λ��
// x: 0-��һ�� 1-�ڶ���
extern bool Lcd1602_SetPosition(uint8 x, uint8 y);

// ��ʾһ���ַ�
extern void Lcd1602_ShowChar(uint8 c);

// ��ʾһ���ַ���
extern void Lcd1602_ShowString(uint8* pStr, uint8 len);

// ��ʾһ������
extern void Lcd1602_ShowInt(int16 num);

// ��ʾһ��������
extern void Lcd1602_ShowFloat(float num);


#endif


#endif