#ifndef COM_H
#define COM_H

#ifdef __cplusplus
extern "C" {
#endif

/* HAL基本库 ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"
/* C标准库 (MicroLIB)--------------------------------------------------------------------*/
#include <stdint.h>		//基本数据类型
#include <stdbool.h>	//Bool数据类型
#include <string.h>		//变量类型,宏,字符数组函数
#include <stdlib.h>		//变量类型,宏,通用工具函数
#include <stdio.h>		//变量类型,宏,输入输出函数


//配置板级Debug端口
#define debug_com                               huart1
#define DEBUG_USART_IRQHandler                  USART1_IRQHandler
#define DEBUG_USART_IRQ                 		USART1_IRQn
//常用返回指令
#define cmd_error           "(_err)"
#define cmd_correct         "(_end)"
//设置升降频时间
#define cmd_set_rise_fall_freq   'A'
//设置电机运行速度
#define cmd_set_speed            'S'
//查询步进电机状态
#define cmd_query_status         'C'
//电机回零
#define cmd_return_zero          'H'
//电机位置控制
#define cmd_move_distance        'P'
//电机停止运行
#define cmd_stop                 'T'
//测试
#define cmd_test                 'M'
//各命令参数数量
#define parm_set_rise_fall_freq     2
#define parm_set_speed              2
#define parm_query_status           1
#define parm_return_zero            2
#define parm_move_distance          3
#define parm_stop                   1
#define parm_test                   1

extern UART_HandleTypeDef debug_com;


void com_receive(uint8_t* buff, uint8_t* cursor, uint8_t rxbuff);
void com_extract(uint8_t* cmd,  uint32_t* parm, uint8_t parm_num);
void com_function(uint8_t* cmd);
void com_process(uint8_t rxbuff);
void com_clear(void);
#ifdef __cplusplus
}
#endif

#endif
