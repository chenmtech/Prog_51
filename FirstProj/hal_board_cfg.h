
#ifndef HAL_BOARD_CFG_H
#define HAL_BOARD_CFG_H

/*****主板晶振频率配置****************/

// 11MHz频率
#define		FREQ_11M			0
// 主板频率为11MHz，目前只支持这一种
#define 	CFG_OSCFREQ		FREQ_11M

/***********************************/


/*****LED配置****************/

#define		LED_ON			0
#define   LED_OFF			1
#define 	CFG_LED		  LED_OFF

sbit LED_Pin = P1^0;

/***********************************/


/**********KEY配置****************/

#define		KEY_ON			0
#define   KEY_OFF			1
#define 	CFG_KEY		  KEY_ON

/***********************************/


/**********LCD1602配置****************/

#define		LCD1602_ON			0
#define   LCD1602_OFF			1
#define 	CFG_LCD1602		  LCD1602_ON

#define LCD1602_PDATA		P2				// 数据端口，要占用整个8位
#define LCD1602_RS			P0^7			// 用于命令/数据切换的Pin
#define LCD1602_RW  		P0^6 			// 用于读/写切换的Pin
#define LCD1602_EN  		P0^5 			// 用于使能的Pin

/***********************************/


/**********串口配置****************/

#define		SERIAL_ON				0
#define   SERIAL_OFF			1
#define 	CFG_SERIAL		  SERIAL_ON

/***********************************/


#endif