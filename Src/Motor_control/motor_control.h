/*****
  ** @file     : motor_control.c/h
  ** @brief    : 电机控制
  ** @versions : 2.2.3
  ** @time     : 2022/08/17
  ** @reviser  : SSBIO(ShangHai China)
  ** @explain  : null
*****/

#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

#ifdef __cplusplus
extern "C" {
#endif

//引用端口定义
#include "main.h"
//Base_Drivers
#include "TB67H450.h"

/********************  硬件配置区  ********************/
#define Current_Rated_Current		(3000)		//额定电流(mA)
#define Current_Cali_Current		(2000)		//校准电流(mA)

/********************  运动参数配置区  ********************/
#define Move_Divied_Step_NUM 	((int32_t)(200))                                                                //(每步柔性控制量所对应细分数)
#define Move_Divide_NUM			((int32_t)(256))																//(每步柔性控制量)
#define Move_Divide_NUM_Total   ((int32_t)(1024))																//(柔性件控制总量)

void Motor_Control_Init(void);
void Motor_set_subdivision(uint32_t Step_NUM);
void Motor_move(uint32_t Step_NUM, uint32_t Current, bool direction);
void Motor_Control_test(void);
#ifdef __cplusplus
}
#endif

#endif



