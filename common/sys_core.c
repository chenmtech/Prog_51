
#include "sys_core.h"
#include "hal_timer.h"

static uint8 appEvents = 0x00;

static pfnAppProcessEvent * appProcessEvent = NULL;

static void sysInit();

static void runSystem();

static void registerAppProcessEvent(pfnAppProcessEvent * process);




extern void Sys_InitSystem(pfnAppInit * appInit, 
	pfnAppProcessEvent * process)
{
	sysInit();
	registerAppProcessEvent(process);
	appInit();
	HAL_ENABLE_INTERRUPTS();
}

extern void Sys_StartSystem()
{
	for(;;) {
		runSystem();
	}
}

extern void Sys_SetEvent(uint8 evt)
{
	uint8 intState;
	HAL_ENTER_CRITICAL_SECTION(intState);
	appEvents |= evt;
	HAL_EXIT_CRITICAL_SECTION(intState);
	return;
}

static void sysInit()
{
	appEvents = 0x00;
	appProcessEvent = NULL;
	Timer_Init();
}

static void registerAppProcessEvent(pfnAppProcessEvent * process)
{
	appProcessEvent = process;
}

static void runSystem()
{
	uint8 evt = 0x00;
	uint8 intState;
	
	if(appEvents != 0x00){
		
		HAL_ENTER_CRITICAL_SECTION(intState);
		evt = appEvents;
		appEvents = 0x00;
		HAL_EXIT_CRITICAL_SECTION(intState);
		
		evt = appProcessEvent(evt);
		
		HAL_ENTER_CRITICAL_SECTION(intState);
		appEvents |= evt;
		HAL_EXIT_CRITICAL_SECTION(intState);
	}
}

