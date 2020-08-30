#include "ApplicationMain.h"
#include "ApplicationTaskGui.h"




void system_pre_init(void)
{
        MPU_Memory_Protection();        //初始化MPU
        RT1052_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);//中断优先级分组4
        RT1052_Clock_Init();            //配置系统时钟
        DELAY_Init(600);                //延时函数初始化
        LPUART1_Init(115200);           //初始化串口1
        LED_Init();                     //初始化LED
        KEY_Init();                     //初始化按键
    
#ifndef DEBUG_IN_SDRAM        
        //代码不在SDRAM里面跑的时候需要初始化SDRAM，如果是在SDRAM中调试代码的话不需要在这里初始化SDRAM，SDRAM的初始化会在文件rt1052_sdram.ini中初始化，在这里初始化SDRAM的话可能会导致SDRAM中的数据丢失
        SDRAM_Init();               //初始化SDRAM
#endif
        
        LCD_Init();                     //初始化LCD
}




int main(void )
{
    system_pre_init();


    
    taskENTER_CRITICAL();           //进入临界区
    
    xTaskCreate((TaskFunction_t )ApplicationTaskGui,                    //任务函数
                (const char*    )"ApplicationTaskGui",                  //任务名称
                (uint16_t       )APPLICATION_TASK_GUI_STK_SIZE,         //任务堆栈大小
                (void*          )NULL,                                  //传递给任务函数的参数
                (UBaseType_t    )APPLICATION_TASK_GUI_PRIO,             //任务优先级
                (TaskHandle_t*  )&hApplicationTaskGui);                 //任务句柄       
                
    taskEXIT_CRITICAL();            //退出临界区
    
    vTaskStartScheduler();          //开启任务调度
    
    while(1) {};
}





