/*****
  ** @file     : motor_control.c/h
  ** @brief    : 电机控制
  ** @versions : 2.2.3
  ** @time     : 2022/08/17
  ** @reviser  : SSBIO(ShangHai China)
  ** @explain  : null
*****/
#include "motor_control.h"

uint32_t  Move_Step_NUM = 200;		  //当前步进电机细分数
uint32_t  Move_Current  = 500;        //当前电流大小

uint32_t  Move_Divide_NUM_Now = 0;    //当前柔性控件位置


/**
* 硬件初始化函数
  * @param  NULL
  * @retval NULL
**/
void Motor_Control_Init(void)
{
    TB67H450_SetPwmStart();
}

/**
* 设置步进电机细分数
  * @param  NULL
  * @retval NULL
**/
void Motor_set_subdivision(uint32_t Step_NUM)
{
    Move_Step_NUM = Step_NUM;
}

/**
* 步进电机运动执行函数
  * @param  Step_NUM 执行步数 Current 执行电流
  * @retval NULL
**/
void Motor_move(uint32_t Step_NUM, uint32_t Current, bool direction)
{
    uint32_t divided_now = Move_Divide_NUM/(Move_Step_NUM/Move_Divied_Step_NUM);
    int32_t Move_Divide_NUM_Target = 0;
    
    if(direction)
    {
        Move_Divide_NUM_Target = Move_Divide_NUM_Now + Step_NUM * divided_now;
        
        for(int32_t i=Move_Divide_NUM_Now;i<Move_Divide_NUM_Target;i++) 
        {
            TB67H450_SetDivideElec(i,Current);
        }
        
        Move_Divide_NUM_Now = Move_Divide_NUM_Target % Move_Divide_NUM_Total;
    }
    else
    {
        Move_Divide_NUM_Target = Move_Divide_NUM_Now - Step_NUM * divided_now;
        
        for(int32_t i=Move_Divide_NUM_Now;i>Move_Divide_NUM_Target;i--) 
        {
            TB67H450_SetDivideElec(i,Current);
        }
        
        Move_Divide_NUM_Now = Move_Divide_NUM_Target % Move_Divide_NUM_Total;
    }
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


