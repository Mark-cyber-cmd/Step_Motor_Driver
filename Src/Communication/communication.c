/*****
  ** @file     : communication.c/h
  ** @brief    : 通讯协议
  ** @versions : 2.2.3
  ** @time     : 2022/08/17
  ** @reviser  : SSBIO(ShangHai China)
  ** @explain  : null
*****/

#include "communication.h"
#include "motor_control.h"

//以下头文件供测试使用
#include "main_thread.h"

//指令接收完成标志位
bool over_flag = false;
//指令数组
uint8_t cmd[20]={0};
//指令头位置
uint8_t cmd_head_cursor=0;
//指令主体位置
uint8_t cmd_cursor=1;


/**
  * Debug端口中断函数 头文件中配置
  * @param  rxbuff 每次中断收到的1Byte数据
  * @retval NULL
**/
void  DEBUG_USART_IRQHandler(void)
{
	if(__HAL_UART_GET_FLAG(&debug_com, UART_FLAG_RXNE ) != RESET)
	{    
        com_process((uint8_t)READ_REG(debug_com.Instance->DR));
	}
}


/**
  * 通讯回调任务 在USART中断中调用
  * @param  rxbuff 每次中断收到的1Byte数据
  * @retval NULL
**/
void com_process(uint8_t rxbuff)
{
    if(rxbuff == '0' && cmd_head_cursor==0)
    {   
        cmd[0] = rxbuff;
        cmd_head_cursor = 1;
    }
    
    if(rxbuff != '0' && cmd_head_cursor==1)
    {
        cmd[1] = rxbuff;
        cmd_head_cursor = 2;
    }
    
    if(cmd_head_cursor == 2)
    {
        com_receive(cmd, &cmd_cursor, rxbuff);
        
        if (over_flag == true)
        {
            com_function(cmd);
        }
    }
}


/**
  * 通讯功能函数  执行具体串口指令 
  * @param  cmd 指令数组表头指针
  * @retval NULL
**/
void com_function(uint8_t* cmd)
{
    uint32_t parm[3];
    
    switch(cmd[1])
    {
            case cmd_set_rise_fall_freq:     com_extract(cmd,parm,parm_set_rise_fall_freq);                     break;
            case cmd_set_speed:              com_extract(cmd,parm,parm_set_speed);                              break;                            
            case cmd_query_status:           com_extract(cmd,parm,parm_query_status);                           break;
            case cmd_return_zero:            com_extract(cmd,parm,parm_return_zero);                            break;
            case cmd_move_distance:          com_extract(cmd,parm,parm_move_distance);                          break;
            case cmd_stop:                   com_extract(cmd,parm,parm_stop);                                   break;
            case cmd_test:                   com_extract(cmd,parm,parm_test);                                   break;
            default:                         printf(cmd_error);com_clear();                                     break;
    }
/*------------------------------参数提取至parm数组 此处添加功能代码------------------------------------------------------*/
    switch(cmd[1])
    {
            case cmd_set_rise_fall_freq:     printf("\r\nparm: %d, %d\r\n",parm[0],parm[1]);                     break;
            case cmd_set_speed:              printf("\r\nparm: %d, %d\r\n",parm[0],parm[1]);                     break;                            
            case cmd_query_status:           printf("\r\nparm: %d\r\n",    parm[0]);                             break;
            case cmd_return_zero:            printf("\r\nparm: %d, %d\r\n",parm[0],parm[1]);                     break;
            case cmd_move_distance:          printf("\r\nparm: %d, %d, %d\r\n",parm[0],parm[1],parm[2]);         break;
            case cmd_stop:                   printf("\r\nparm: %d\r\n",parm[0]);                                 break;
            case cmd_test:                   main_test(parm[0]);                                                 break;
            default:                                                                                             break;
    }
/*------------------------------参数提取至parm数组 此处添加功能代码------------------------------------------------------*/    
    com_clear();
}

/**
  * 通讯提取函数  通过正则表达式提取字符串中的参数 
  * @param  cmd 指令数组表头指针 parm 指令参数数组表头指针 parm_num 指令参数个数
  * @retval NULL
**/
void com_extract(uint8_t* cmd, uint32_t* parm, uint8_t parm_num)
{
    if(sscanf((char*)(cmd + 2),"(%d,%d,%d)",parm,parm+1,parm+2) == parm_num)
    {
        printf(cmd_correct);
    }
    else
    {
        printf(cmd_error);
        com_clear();
    }
}

/**
  * 通讯接收函数  以')'为指令周期结束标志位
  * @param  buff  缓冲区表头指针 cursor 缓冲区光标指针  rxbuff当前接收字节
  * @retval NULL
**/
void com_receive(uint8_t* buff, uint8_t* cursor, uint8_t rxbuff)
{  
    if(rxbuff != ')')
    {    
        buff[(*cursor)] = rxbuff;
        (*cursor)++;
    }
    else
    {
        buff[(*cursor)] = rxbuff;
        (*cursor)++;
        over_flag = true;
    }
}


/**
  * 通讯清零函数  将所有指针 标志位 缓冲区清零
  * @param  NULL
  * @retval NULL
**/
void com_clear(void)
{
    cmd_head_cursor = 0;
    cmd_cursor = 1;
    over_flag = false;
    memset(cmd, 0, 21);
}

/**
  * 通讯重定向函数  标准输出流定向为串口输出
  * @param  ch 字符 f文件指针(无用)
  * @retval NULL
**/
int fputc(int ch, FILE* f)
{
    HAL_UART_Transmit(&debug_com, (uint8_t *)&ch, 1, 0xFFFF);
    return ch;
}



