#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* HAL基本库 ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

//C基本库
#include <stdint.h>		//基本数据类型
#include <stdbool.h>	//Bool数据类型
#include <string.h>		//变量类型,宏,字符数组函数
#include <stdlib.h>		//变量类型,宏,通用工具函数
#include <stdio.h>		//变量类型,宏,输入输出函数

//板级宏定义
#include "Step-Motor-28-mark1.h"

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);
void Error_Handler(void);



#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
