/*****
  ** @file     : control_config.c/h
  ** @brief    : 电机控制
  ** @versions : 2.2.3
  ** @time     : 2020/09/15
  ** @reviser  : unli (HeFei China)
  ** @explain  : null
*****/

//Oneself
#include "motor_control.h"


    
void Motor_Control_Init(void)
{
    TB67H450_SetPwmStart();
}


void Motor_Control_Callback(void)
{
    //for(uint32_t i=0;i<1024;i++) TB67H450_SetDivideElec(i,500);
}

void Motor_Control_test(void)
{
    printf("\r\nmotor rotates once start\r\n");
    for(uint32_t i=0;i<Move_Pulse_NUM;i++)
    {
        TB67H450_SetDivideElec(i,500);
    }
    printf("\r\nmotor rotates once over\r\n");
}


