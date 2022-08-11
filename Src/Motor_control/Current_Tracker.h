/*****
  ** @file     : Current_Tracker.c/h
  ** @brief    : 电流跟踪器
  ** @versions : 1.1.7
  ** @time     : 2019/12/06
  ** @reviser  : unli (JiXi XuanCheng China)
  ** @explain  : null
*****/

#ifndef CURRENT_TRACKER_H
#define CURRENT_TRACKER_H

#ifdef __cplusplus
extern "C" {
#endif

//引用端口定义
#include "main.h"
//Control
#include "Control_Config.h"

/****************************************  电流跟踪器  ****************************************/
/****************************************  电流跟踪器  ****************************************/
/****************************************  电流跟踪器  ****************************************/
/**
  * Electric_Tracker类结构体定义
**/
typedef struct{
	//配置(增加流梯度)
	#define	De_Up_Rate		(Move_Rated_UpCurrentRate / 10)
	bool		valid_up_rate;
	int32_t	up_rate;
	//配置(减流梯度)
	#define	De_Down_Rate	(Move_Rated_DownCurrentRate / 10)
	bool		valid_down_rate;
	int32_t	down_rate;
	//计算过程数据
	int32_t	course_mut;	    //计算过程中的电流(小电流积分)(放大为CONTROL_FREQ_HZ倍)
	int32_t	course;			//计算过程中的电流(大电流)
	//输出跟踪量
	int32_t	go_current;	    //立即电流
}Current_Tracker_Typedef;
extern Current_Tracker_Typedef	current_tck;

void Current_Tracker_Set_UpRate(int32_t value);		        //电流跟踪器设置增流变化率
void Current_Tracker_Set_DownRate(int32_t value);	        //电流跟踪器设置减流变化率
void Current_Tracker_Set_Default(void);						//电流跟踪器参数恢复

void Current_Tracker_Init(void);							//电流跟踪器初始化
void Current_Tracker_NewTask(int16_t real_current);			//电流控制器开始新任务
void Current_Tracker_Capture_Goal(int32_t goal_current);	//电流跟踪器获得立即电流

#ifdef __cplusplus
}
#endif

#endif 
