/*
 * SYS_CORE.h: 我给51单片机写的一个简单系统
 *
 * 这个系统的应用层是基于事件的
 * 即所有的应用层操作都是通过触发和处理事件来完成的
 * 比如如果按下按钮想要点亮LED，不要在按钮中断中直接点亮
 * 而应该在应用层定义一个事件，以及事件处理操作，然后在中断中触发事件
 * 
 * Written by Chenm, 2018-03-19
 *
 * 
 */


#ifndef SYS_CORE_H
#define SYS_CORE_H

#include "hal_comdefs.h"
#include "hal_board_cfg.h"

/*
 * CONSTANT
 */
#define EVENT0		0x01
#define EVENT1		0x02
#define EVENT2		0x04
#define EVENT3		0x08
#define EVENT4		0x10
#define EVENT5		0x20
#define EVENT6		0x40
#define EVENT7		0x80
 

/* 
 * TYPEDEF
 */

// 应用层初始化函数原型
typedef void pfnAppInit(void);
// 应用层时间处理函数原型
typedef uint8 pfnAppProcessEvent(uint8 events);


/*
 * EXTERNAL FUNCTION
 */
 
// 初始化系统，需要提供应用层的初始化函数名以及事件处理函数名
extern void Sys_InitSystem(pfnAppInit * appInit, 
	pfnAppProcessEvent * process);

// 启动系统
extern void Sys_StartSystem();

// 触发一个应用层事件
extern void Sys_SetEvent(uint8 evt);


#endif