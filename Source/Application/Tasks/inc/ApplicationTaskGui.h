#ifndef __APPLICATION_TASK_GUI_H__
#define __APPLICATION_TASK_GUI_H__



#include "CommonConfig.h"
#include "FreeRTOS.h"
#include "task.h"


#define APPLICATION_TASK_GUI_PRIO               1   //�������ȼ�
#define APPLICATION_TASK_GUI_STK_SIZE         1024  //�����ջ��С
extern TaskHandle_t hApplicationTaskGui;            //������
void ApplicationTaskGui(void *pvParameters);        //������
















































#endif
