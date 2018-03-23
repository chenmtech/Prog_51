
#ifndef HAL_BOARD_CFG_H
#define HAL_BOARD_CFG_H

/*****���徧��Ƶ������****************/

// 11MHzƵ��
#define		FREQ_11M			0
// ����Ƶ��Ϊ11MHz��Ŀǰֻ֧����һ��
#define 	CFG_OSCFREQ		FREQ_11M

/***********************************/


/*****LED����****************/

#define		LED_ON			0
#define   LED_OFF			1
#define 	CFG_LED		  LED_OFF

sbit LED_Pin = P1^0;

/***********************************/


/**********KEY����****************/

#define		KEY_ON			0
#define   KEY_OFF			1
#define 	CFG_KEY		  KEY_ON

/***********************************/


/**********LCD1602����****************/

#define		LCD1602_ON			0
#define   LCD1602_OFF			1
#define 	CFG_LCD1602		  LCD1602_ON

#define LCD1602_PDATA		P2				// ���ݶ˿ڣ�Ҫռ������8λ
#define LCD1602_RS			P0^7			// ��������/�����л���Pin
#define LCD1602_RW  		P0^6 			// ���ڶ�/д�л���Pin
#define LCD1602_EN  		P0^5 			// ����ʹ�ܵ�Pin

/***********************************/


/**********��������****************/

#define		SERIAL_ON				0
#define   SERIAL_OFF			1
#define 	CFG_SERIAL		  SERIAL_ON

/***********************************/


#endif