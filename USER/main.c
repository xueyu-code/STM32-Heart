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
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//�����ж����ȼ�����Ϊ��2��2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	delay_init();	    	 //��ʱ������ʼ��	  
	uart_init(9600);	 //���ڳ�ʼ��Ϊ9600
	printf("���\r\n");
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
	
	
   
	
	/*****esp8266  ���ӻ�����  �����ʼ��  *******/
			usart3_init(9600);					//��esp8266ͨѶ��������9600
			TIM3_Int_Init(71,999);				//һ���붨ʱ
			userInit();
			gizwitsInit();//��������ʼ��
//			gizwitsSetMode(WIFI_RESET_MODE);
			delay_ms(500);
//			gizwitsSetMode(WIFI_AIRLINK_MODE);//�����

//			gizwitsSetMode(WIFI_SOFTAP_MODE);
	/*******************���ӻ�����  �����ʼ�� *************************/
	
	for(i = 0;i < 128;i++) 
	{
		
		while(MAX30102_INTPin_Read()==0)
		{
			printf("read INT\r\n");
			ceshi=GPIOB->IDR & GPIO_Pin_8;
			//��ȡFIFO
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

