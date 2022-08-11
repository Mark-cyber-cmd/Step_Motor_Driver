/*****
  ** @file     : control_config.c/h
  ** @brief    : 电机控制
  ** @versions : 2.2.3
  ** @time     : 2020/09/15
  ** @reviser  : unli (HeFei China)
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
#include "main.h"

//Control
#include "control_config.h"
#include "Current_Tracker.h"

void Motor_Control_Init(void);
void Motor_Control_Callback(void);
void Motor_Control_test(void);
#ifdef __cplusplus
}
#endif

#endif



