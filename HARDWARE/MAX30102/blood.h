#ifndef _BLOOD_H
#define _BLOOD_H
#include "stm32f10x.h"                  // Device header
#include "MAX30102.h"
#include "algorithm.h"
#include "math.h"
#include "oled.h"
typedef enum
{
	BLD_NORMAL,		//����
	BLD_ERROR,		//������
	
}BloodState;//ѪҺ״̬

typedef struct
{
	int 		heart;		//��������
	float 			SpO2;			//Ѫ������
}BloodData;

extern BloodData g_blooddata;
void blood_data_translate(void);//ѪҺ��Ϣת��
void blood_data_update(void);	//ѪҺ�����Ϣ����
void blood_Loop(void);			//ѪҺѭ������

#endif


