#include "ApplicationMain.h"
#include "ApplicationTaskGui.h"




void system_pre_init(void)
{
        MPU_Memory_Protection();        //��ʼ��MPU
        RT1052_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);//�ж����ȼ�����4
        RT1052_Clock_Init();            //����ϵͳʱ��
        DELAY_Init(600);                //��ʱ������ʼ��
        LPUART1_Init(115200);           //��ʼ������1
        LED_Init();                     //��ʼ��LED
        KEY_Init();                     //��ʼ������
    
#ifndef DEBUG_IN_SDRAM        
        //���벻��SDRAM�����ܵ�ʱ����Ҫ��ʼ��SDRAM���������SDRAM�е��Դ���Ļ�����Ҫ�������ʼ��SDRAM��SDRAM�ĳ�ʼ�������ļ�rt1052_sdram.ini�г�ʼ�����������ʼ��SDRAM�Ļ����ܻᵼ��SDRAM�е����ݶ�ʧ
        SDRAM_Init();               //��ʼ��SDRAM
#endif
        
        LCD_Init();                     //��ʼ��LCD
}




int main(void )
{
    system_pre_init();


    
    taskENTER_CRITICAL();           //�����ٽ���
    
    xTaskCreate((TaskFunction_t )ApplicationTaskGui,                    //������
                (const char*    )"ApplicationTaskGui",                  //��������
                (uint16_t       )APPLICATION_TASK_GUI_STK_SIZE,         //�����ջ��С
                (void*          )NULL,                                  //���ݸ��������Ĳ���
                (UBaseType_t    )APPLICATION_TASK_GUI_PRIO,             //�������ȼ�
                (TaskHandle_t*  )&hApplicationTaskGui);                 //������       
                
    taskEXIT_CRITICAL();            //�˳��ٽ���
    
    vTaskStartScheduler();          //�����������
    
    while(1) {};
}





