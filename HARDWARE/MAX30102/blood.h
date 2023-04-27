#ifndef _BLOOD_H
#define _BLOOD_H
#include "stm32f10x.h"                  // Device header
#include "MAX30102.h"
#include "algorithm.h"
#include "math.h"
#include "oled.h"
typedef enum
{
	BLD_NORMAL,		//正常
	BLD_ERROR,		//侦测错误
	
}BloodState;//血液状态

typedef struct
{
	int 		heart;		//心率数据
	float 			SpO2;			//血氧数据
}BloodData;

extern BloodData g_blooddata;
void blood_data_translate(void);//血液信息转换
void blood_data_update(void);	//血液检测信息更新
void blood_Loop(void);			//血液循环函数

#endif


