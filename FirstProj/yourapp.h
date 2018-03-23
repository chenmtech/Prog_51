/*
 * yourapp.h: ��Ҫ�ṩ��Ӧ�ò����
 * �����Ͼ����������ܣ�д���������������Ϳ���
 * 
 * Written by Chenm, 2018-03-19
 *
 * 
 */
 
#ifndef YOUR_APP_H
#define YOUR_APP_H

#include "sys_core.h"

// �����豸�¼�
#define START_DEVICE_EVT				EVENT0

#define KEY_EVT									EVENT1

#define RECEIVE_DATA_EVT				EVENT2

#define SEND_DATA_EVT						EVENT3

#define SEND_FINISH_EVT					EVENT4


extern void YourApp_Init();

extern uint8 YourApp_ProcessEvent(uint8 events);



#endif