
#include "sys_core.h"
#include "yourapp.h"


void main(void)
{
	Sys_InitSystem(YourApp_Init, YourApp_ProcessEvent);
		
	Sys_StartSystem();
}

