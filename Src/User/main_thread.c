/*****
  ** @file     : loop.c/h and loop_it.c
  ** @brief    : 
  ** @versions : 
  ** @time     : 
  ** @reviser  : 
  ** @explain  : 
*****/
//硬件驱动头文件(stm32内部驱动交给cubemx完成)
#include "main_thread.h"
#include "w25q128.h"
#include "mt6816.h"
#include "TB67H450.h"


//电机控制器头文件
#include "motor_control.h"

void main_thread(void)
{
	HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_2);
    LoopIT_SysTick_20KHz();		
    Motor_Control_Init();
    
    while(1)
    {
        
    }
}

void main_test(uint8_t task)
{
    switch(task)
    {
        case 0: W25Q128_test();         break;
        case 1: MT6816_test();          break;
        case 2: Motor_Control_test();   break;
    }

}

