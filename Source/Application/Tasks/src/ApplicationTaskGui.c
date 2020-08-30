#include "ApplicationTaskGui.h"

#include "sys.h"
#include "delay.h"
#include "lpuart.h" 
#include "led.h"
#include "tftlcd.h"
#include "sdram.h"
#include "key.h"

TaskHandle_t hApplicationTaskGui;

void ApplicationTaskGui(void *pvParameters)
{
    POINT_COLOR=RED;
	LCD_ShowString(30,10,200,16,16,"Commander RT1052");	
	LCD_ShowString(30,30,200,16,16,"FreeRTOS Examp 6-1");
	LCD_ShowString(30,50,200,16,16,"Task Creat and Del");
	LCD_ShowString(30,70,200,16,16,"ATOM@ALIENTEK");
	LCD_ShowString(30,90,200,16,16,"2018/8/13");


    while(1)
    {
        LED0_Toggle();
        LED1_Toggle();

        vTaskDelay(500);
    }
}


























































