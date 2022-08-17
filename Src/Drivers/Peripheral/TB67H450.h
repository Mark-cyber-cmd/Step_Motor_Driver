/*****
  ** @file     : hw_elec.c/h
  ** @brief    : 硬件电流控制器
  ** @versions : 2.1.2
  ** @time     : 2020/08/08
  ** @reviser  : 
  ** @explain  : 
*****/

#ifndef TB67H450_H
#define TB67H450_H

#ifdef __cplusplus
extern "C" {
#endif

//引用端口定义
#include "main.h"

/**
  * 线圈定义
**/
typedef struct{
	uint16_t conver;		//SIN数组指针
	int16_t  sin_data;	//SIN换算数值
	uint16_t dac_reg;		//12位DAC数值
}Coil_Typedef;

extern TIM_HandleTypeDef htim2;

//GPIO输出
#define Out_AP_H()		HAL_GPIO_WritePin(TB67H450_AP_GPIO_Port, TB67H450_AP_Pin, GPIO_PIN_SET);
#define Out_AP_L()		HAL_GPIO_WritePin(TB67H450_AP_GPIO_Port, TB67H450_AP_Pin, GPIO_PIN_RESET);
#define Out_AM_H()		HAL_GPIO_WritePin(TB67H450_AM_GPIO_Port, TB67H450_AM_Pin, GPIO_PIN_SET);
#define Out_AM_L()		HAL_GPIO_WritePin(TB67H450_AM_GPIO_Port, TB67H450_AM_Pin, GPIO_PIN_RESET);
#define Out_BP_H()		HAL_GPIO_WritePin(TB67H450_BP_GPIO_Port, TB67H450_BP_Pin, GPIO_PIN_SET);
#define Out_BP_L()		HAL_GPIO_WritePin(TB67H450_BP_GPIO_Port, TB67H450_BP_Pin, GPIO_PIN_RESET);
#define Out_BM_H()		HAL_GPIO_WritePin(TB67H450_BM_GPIO_Port, TB67H450_BM_Pin, GPIO_PIN_SET);
#define Out_BM_L()		HAL_GPIO_WritePin(TB67H450_BM_GPIO_Port, TB67H450_BM_Pin, GPIO_PIN_RESET);
//TIM输出
#define Out_PWMtoDAC_A(value)		__HAL_TIM_SET_COMPARE(&TB67H450_PWM_Get_HTIM, TB67H450_APWM_CHANNEL, value);
#define Out_PWMtoDAC_B(value)		__HAL_TIM_SET_COMPARE(&TB67H450_PWM_Get_HTIM, TB67H450_BPWM_CHANNEL, value);

void TB67H450_SetPwmStart(void);
void TB67H450_SetPwmStop(void);
void TB67H450_SetSleep(void);																		//硬件电流设置驱动睡眠
void TB67H450_SetBrake(void);																		//硬件电流设置驱动刹车
void TB67H450_SetDivideElec(uint32_t divide, int32_t elec_ma);	                                    //硬件电流设置输出细分电流
void CurrentControl_VREF_16Bit_MixOut(uint16_t elec_va, uint16_t elec_vb);
#ifdef __cplusplus
}
#endif

#endif

