/*
 * SYS_CORE.h: �Ҹ�51��Ƭ��д��һ����ϵͳ
 *
 * ���ϵͳ��Ӧ�ò��ǻ����¼���
 * �����е�Ӧ�ò��������ͨ�������ʹ����¼�����ɵ�
 * ����������°�ť��Ҫ����LED����Ҫ�ڰ�ť�ж���ֱ�ӵ���
 * ��Ӧ����Ӧ�ò㶨��һ���¼����Լ��¼����������Ȼ�����ж��д����¼�
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

// Ӧ�ò��ʼ������ԭ��
typedef void pfnAppInit(void);
// Ӧ�ò�ʱ�䴦����ԭ��
typedef uint8 pfnAppProcessEvent(uint8 events);


/*
 * EXTERNAL FUNCTION
 */
 
// ��ʼ��ϵͳ����Ҫ�ṩӦ�ò�ĳ�ʼ���������Լ��¼���������
extern void Sys_InitSystem(pfnAppInit * appInit, 
	pfnAppProcessEvent * process);

// ����ϵͳ
extern void Sys_StartSystem();

// ����һ��Ӧ�ò��¼�
extern void Sys_SetEvent(uint8 evt);


#endif