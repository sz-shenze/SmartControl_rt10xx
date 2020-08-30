#ifndef __APPLICATION_TASK_GUI_H__
#define __APPLICATION_TASK_GUI_H__



#include "CommonConfig.h"
#include "FreeRTOS.h"
#include "task.h"


#define APPLICATION_TASK_GUI_PRIO               1   //任务优先级
#define APPLICATION_TASK_GUI_STK_SIZE         1024  //任务堆栈大小
extern TaskHandle_t hApplicationTaskGui;            //任务句柄
void ApplicationTaskGui(void *pvParameters);        //任务函数
















































#endif
