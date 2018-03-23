/*
 * yourapp.h: 你要提供的应用层程序
 * 基本上就照着这个框架，写好下面两个函数就可以
 * 
 * Written by Chenm, 2018-03-19
 *
 * 
 */
 
#ifndef YOUR_APP_H
#define YOUR_APP_H

#include "sys_core.h"

// 启动设备事件
#define START_DEVICE_EVT				EVENT0

#define KEY_EVT									EVENT1

#define RECEIVE_DATA_EVT				EVENT2

#define SEND_DATA_EVT						EVENT3

#define SEND_FINISH_EVT					EVENT4


extern void YourApp_Init();

extern uint8 YourApp_ProcessEvent(uint8 events);



#endif