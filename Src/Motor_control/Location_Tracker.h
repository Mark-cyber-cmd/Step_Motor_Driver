/*****
  ** @file     : Location_Tracker.c/h
  ** @brief    : 位置跟踪器
  ** @versions : 1.1.7
  ** @time     : 2019/12/06
  ** @reviser  : unli (JiXi XuanCheng China)
  ** @explain  : null
*****/

#ifndef LOCATION_TRACKER_H
#define LOCATION_TRACKER_H

#ifdef __cplusplus
extern "C" {
#endif

//引用端口定义
#include "main.h"
//Control
#include "Control_Config.h"

/****************************************  位置跟踪器  ****************************************/
/****************************************  位置跟踪器  ****************************************/
/****************************************  位置跟踪器  ****************************************/
/**
  * Location_Tracker类结构体定义
**/
typedef struct{
	//配置(速度)
	#define	DE_MAX_SPEED	(Move_Rated_Speed)
	bool		valid_max_speed;
	int32_t	max_speed;
	//配置(加速加速度)
	#define	DE_UP_ACC			(Move_Rated_UpAcc / 10)
	bool		valid_up_acc;
	int32_t	up_acc;
	//配置(减速加速度)
	#define	DE_Down_ACC		(Move_Rated_DownAcc / 10)
	bool		valid_down_acc;
	int32_t	down_acc;
	float		down_acc_quick;	//快速运算数		1.0f / (2.0f * down_acc)
	//静态配置的跟踪参数
	int32_t		speed_locking_stop;			//允许直接抱死停车的速度
	//计算过程数据
	int32_t		course_acc_integral;		//过程加速度积分(放大CONTROL_FREQ_HZ倍)
	int32_t		course_speed;						//过程速度
	int32_t		course_speed_integral;	//过程速度积分(放大CONTROL_FREQ_HZ倍)
	int32_t		course_location;				//过程位置
	//输出跟踪控制量
	int32_t		go_location;	//立即位置
	int32_t		go_speed;			//立即速度
}Location_Tracker_Typedef;
extern Location_Tracker_Typedef	location_tck;

void Location_Tracker_Set_MaxSpeed(int32_t value);//位置跟踪器设置最大速度
void Location_Tracker_Set_UpAcc(int32_t value);		//位置跟踪器设置加速加速度
void Location_Tracker_Set_DownAcc(int32_t value);	//位置跟踪器设置减速加速度
void Location_Tracker_Set_Default(void);					//位置跟踪器参数恢复

void Location_Tracker_Init(void);																					//位置跟踪器初始化
void Location_Tracker_NewTask(int32_t real_location, int32_t real_speed);	//位置跟踪器开始新任务
void Location_Tracker_Capture_Goal(int32_t goal_location);								//位置跟踪器获得立即位置和立即速度

#ifdef __cplusplus
}
#endif

#endif //LOCATION_TRACKER_H
