#include "main_thread.h"
#include "motor_control.h"
#include "communication.h"

//核心中断标志数据
bool systick_20khz_flag = false;	//20KHz系统时钟标志
uint8_t lit_1ms_divider = 0;			//副时钟分频器(1ms)

struct Loop_IT_Typedef{
	//中断计数器
	uint32_t	systick_count;
	uint32_t	exti7_count;
	uint32_t	time3_count;
	uint32_t	dma1_ch4_count;
	uint32_t	dma1_ch5_count;
	uint32_t	uart1_count;
}loop_it;

/**
* @brief  系统计时器修改为20KHz
  * @param  NULL
  * @retval NULL
**/
void LoopIT_SysTick_20KHz(void)
{
	systick_20khz_flag = true;
	HAL_SYSTICK_Config(SystemCoreClock / 20000);	    //更新为20K中断
    
}


/**
  * @brief This function handles System tick timer.
	* 启动初期由HAL库自动初始化的SysTick为1KHz
	* 由REIN库接管后修改的SysTick为20KHz
**/
void SysTick_Handler(void)
{
	if(systick_20khz_flag)
    {  
        //1Khz分频
		lit_1ms_divider++;
		if(lit_1ms_divider >= 20)
        {
			lit_1ms_divider  = 0;
			HAL_IncTick();	                            //提供HAL库的1ms中断调用,维持HAL_Delay等超时动作的有效执行
		}
	}
	else
    {
		HAL_IncTick();	                                //提供HAL库的1ms中断调用,维持HAL_Delay等超时动作的有效执行
	}
	
	loop_it.systick_count++;
}
