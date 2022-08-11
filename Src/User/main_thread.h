/******
	************************************************************************
	******
	** @project : XDrive_Step
	** @brief   : Stepper motor with multi-function interface and closed loop function. 
	** @brief   : 具有多功能接口和闭环功能的步进电机
	** @author  : 
	** @contacts: 
	******
	** @address : 
******/

/*****
  ** @file     : loop.c/h and loop_it.c
  ** @brief    : 用户应用文件
  ** @versions : 
  ** @time     : 
  ** @reviser  : 
  ** @explain  : 
*****/

#ifndef LOOP_H
#define LOOP_H

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"
extern UART_HandleTypeDef huart1;


//主进程入口
void main_thread(void);
//测试功能使用
void main_test(uint8_t task);
//主进程中断服务
void LoopIT_SysTick_20KHz(void);		//系统计时器修改为20KHz

#ifdef __cplusplus
}
#endif

#endif
