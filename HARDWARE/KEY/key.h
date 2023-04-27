#ifndef __KEY_H
#define __KEY_H	 
#include "sys.h"



#define KEY1  GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_4)//读取按键0
#define KEY2  GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_5)//读取按键1

 

#define KEY1_PRES 	1	//KEY0按下
#define KEY2_PRES	  2	//KEY1按下

void KEY_Init(void);//IO初始化
u8 KEY_Scan(u8);  	//按键扫描函数					    
#endif
