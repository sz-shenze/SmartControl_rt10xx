#ifndef _KEY_H
#define _KEY_H
#include "sys.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEK I.MX RT1052������
//������������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//��������:2012/12/15
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2014-2024
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	

/*******************************************  
    KEY_UP    ->  WAKEUP(GPIO5_IO00)
    KEY0      ->  GPIO_AD_B0_05(GPIO1_IO05)
    KEY1      ->  PMIC_ON_REQ(GPIO5_IO01)
    KEY2      ->  GPIO_EMC_40(GPIO3_IO26)
*******************************************/

#define KEY0	GPIO_PinRead(GPIO1,5)  //KEY0����GPIO1_05
#define KEY1	GPIO_PinRead(GPIO5,1)  //KEY1����GPIO5_01
#define KEY2	GPIO_PinRead(GPIO3,26) //KEY2����GPIO3_26
#define WK_UP	GPIO_PinRead(GPIO5,0)  //WK_UP����GPIO5_00

#define KEY0_PRES 	1  	//KEY0���º󷵻�ֵ
#define KEY1_PRES	2	//KEY1���º󷵻�ֵ
#define KEY2_PRES	3	//KEY2���º󷵻�ֵ
#define WKUP_PRES   4	//WKUP���º󷵻�ֵ

void KEY_Init(void);
u8 KEY_Scan(u8 mode);
#endif
