#include "sys.h"
#include "delay.h"
#include "usart.h"

#include "led.h"
#include "key.h"
#include "beep.h"

#include "oled.h"

#include "MAX30102.h"
#include "algorithm.h"
#include "blood.h"
#include "iic.h"


#include "usart3.h"
#include "timer.h"
#include "gizwits_product.h"
#include "common.h"
int main(void)
{		

	int i;
	u16 ceshi;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置中断优先级分组为组2：2位抢占优先级，2位响应优先级
	delay_init();	    	 //延时函数初始化	  
	uart_init(9600);	 //串口初始化为9600
	printf("你好\r\n");
//	LED_Init();
//	BEEP_Init();
//	KEY_Init();
	
	OLED_Init();
	OLED_ShowString(32,32,"OLED OK",16,1);
	OLED_Refresh();
	delay_ms(500);
	OLED_Clear();
	OLED_Refresh();
	
	IIC_GPIO_INIT();
	MAX30102_GPIO();
	Max30102_reset();
	MAX30102_Config();
	
	
   
	
	/*****esp8266  连接机智云  代码初始化  *******/
			usart3_init(9600);					//跟esp8266通讯，必须是9600
			TIM3_Int_Init(71,999);				//一毫秒定时
			userInit();
			gizwitsInit();//缓冲区初始化
//			gizwitsSetMode(WIFI_RESET_MODE);
			delay_ms(500);
//			gizwitsSetMode(WIFI_AIRLINK_MODE);//用这个

//			gizwitsSetMode(WIFI_SOFTAP_MODE);
	/*******************连接机智云  代码初始化 *************************/
	
	for(i = 0;i < 128;i++) 
	{
		
		while(MAX30102_INTPin_Read()==0)
		{
			printf("read INT\r\n");
			ceshi=GPIOB->IDR & GPIO_Pin_8;
			//读取FIFO
			max30102_read_fifo();
		}
	}
	while(1)
	{
		blood_Loop();
		userHandle();
        
        gizwitsHandle((dataPoint_t *)&currentDataPoint);
	}	 
} 

