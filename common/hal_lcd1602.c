

#include "hal_lcd1602.h"

#include "hal_delay.h"

#include "util_num2str.h"

sbit RS = LCD1602_RS;  
sbit RW = LCD1602_RW;  
sbit E  = LCD1602_EN;   

static uint8 buf[10] = {0};

 

static bool Lcd1602_ReadBusy();

static bool Lcd1602_ReadBusy()  
{
	uint8 temp;
	RS=0;
	RW=1;
	_nop_();
	LCD1602_PDATA = 0xff;             

	E=1;
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	temp = LCD1602_PDATA;   
	E=0;
	return (temp & 0x80) ? TRUE : FALSE; 
}


extern void Lcd1602_ExecuteCmd(uint8 cmd) 
{
   while(Lcd1602_ReadBusy()); 
   RS=0;   
   RW=0;   
   _nop_();
   LCD1602_PDATA=cmd;   
   _nop_();
   E=1;      
   _nop_();
   _nop_();
   E=0;      
   _nop_();
   _nop_();   
}

extern void Lcd1602_Clear()
{
	Lcd1602_ExecuteCmd(0x01);
}

extern void Lcd1602_ShowChar(uint8 c)  
{
   while(Lcd1602_ReadBusy());   
   RS=1;   
   RW=0;   
   _nop_();
   LCD1602_PDATA = c;
   _nop_();
   E=1;
   _nop_();
   _nop_();
   E=0;
   _nop_();
   _nop_();   
}

extern void Lcd1602_ShowString(uint8* pStr, uint8 len)
{
	uint8 i = 0;
	for(i = 0; i < len; i++) {
		Lcd1602_ShowChar(*(pStr+i));
	}
}

extern void Lcd1602_ShowInt(int16 num)
{
	uint8 len = NST_Int2Str(num, buf);
	Lcd1602_ShowString(buf, len);
}

extern void Lcd1602_ShowFloat(float num)
{
	uint8 len = NST_Float2Str(num, buf);
	Lcd1602_ShowString(buf, len);
}

extern bool Lcd1602_SetPosition(uint8 x, uint8 y)
{
	if(x == 0) {
		Lcd1602_ExecuteCmd(0x80+y);
		return TRUE;
	} else if(x == 1) {
		Lcd1602_ExecuteCmd(0xC0+y);
		return TRUE;
	}
	return FALSE;
}

extern void Lcd1602_init()   
{
   delay_ms(15);
   Lcd1602_ExecuteCmd(0x38);   
   delay_ms(5);
   Lcd1602_ExecuteCmd(0x38);
   delay_ms(5);
   Lcd1602_ExecuteCmd(0x38);
   Lcd1602_ExecuteCmd(0x0c);  
   Lcd1602_ExecuteCmd(0x06);  
   Lcd1602_ExecuteCmd(0x01);  
}
