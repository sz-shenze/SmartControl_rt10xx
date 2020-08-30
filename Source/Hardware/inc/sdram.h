#ifndef _SDRAM_H
#define _SDRAM_H
#include "sys.h"

#define SDRAM_START_ADDR    ((u32)(0X80000000)) //SDRAM开始地址
#define SDRAM_SIZE_KBYTES   ((u32)(32*1024))    //SDRAM大小，单位kBytes

void SDRAM_Init(void);

#endif
