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

uint32_t  Move_Step_NUM = 200;		  //当前步进电机细分数
uint32_t  Move_Current  = 500;        //当前电流大小

uint32_t  Move_Divide_NUM_Now = 0;    //当前柔性控件位置

void Motor_Control_Init(void)
{
    TB67H450_SetPwmStart();
}

void Motor_set_subdivision(uint32_t Step_NUM)
{
    Move_Step_NUM = Step_NUM;
}

void Motor_move(uint32_t Step_NUM, uint32_t Current)
{
    uint32_t divided_now = Move_Divide_NUM/(Move_Step_NUM/Move_Divied_Step_NUM);
    uint32_t Move_Divide_NUM_Target = Move_Divide_NUM_Now + Step_NUM * divided_now;
    
    for(uint32_t i=Move_Divide_NUM_Now;i<Move_Divide_NUM_Target;i++) 
    {
        TB67H450_SetDivideElec(i,Current);
    }
    
    Move_Divide_NUM_Now = Move_Divide_NUM_Target % Move_Divide_NUM_Total;
}

void Motor_Control_test(void)
{
    printf("\r\nmotor rotates once start\r\n");
    for(uint32_t i=0;i<256 * 200;i++)
    {
        TB67H450_SetDivideElec(i,500);
    }
    printf("\r\nmotor rotates once over\r\n");
}


