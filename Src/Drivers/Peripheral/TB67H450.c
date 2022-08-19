/*****
  ** @file     : hw_elec.c/h
  ** @brief    : 硬件电流控制器
  ** @versions : 2.1.2
  ** @time     : 2020/08/08
  ** @reviser  : unli (HeFei China)
  ** @explain  : null
*****/

//Oneself
#include "TB67H450.h"

//Base_Math
#include "sin_form.h"

//硬件电流实例
Coil_Typedef		coil_a;	//电流控制
Coil_Typedef		coil_b;	//电流控制

/**
  * @brief  开启PWM
  * @param  NULL
  * @param  NULL
  * @retval NULL
  */
void TB67H450_SetPwmStart(void)
{
    HAL_TIM_PWM_Start(&TB67H450_PWM_Get_HTIM, TB67H450_APWM_CHANNEL);
	HAL_TIM_PWM_Start(&TB67H450_PWM_Get_HTIM, TB67H450_BPWM_CHANNEL);
}

/**
  * @brief  关闭PWM
  * @param  NULL
  * @param  NULL
  * @retval NULL
  */
void TB67H450_SetPwmStop(void)
{
    HAL_TIM_PWM_Stop(&TB67H450_PWM_Get_HTIM, TB67H450_APWM_CHANNEL);
	HAL_TIM_PWM_Stop(&TB67H450_PWM_Get_HTIM, TB67H450_BPWM_CHANNEL);
}


/**
  * @brief  12位基准电压PWM A/B相等效占空比输出
  * @param  elec_va: 电流通道a基准
  * @param  elec_vb: 电流通道b基准
  * @retval NULL
  */
void CurrentControl_VREF_16Bit_MixOut(uint16_t elec_va, uint16_t elec_vb)
{
	Out_PWMtoDAC_A(elec_va);
	Out_PWMtoDAC_B(elec_vb);
}


/**
  * @brief  设置睡眠
  * @param  NULL
  * @retval NULL
  */
void TB67H450_SetSleep(void)
{
	coil_a.dac_reg = 0;
	coil_b.dac_reg = 0;
	CurrentControl_VREF_16Bit_MixOut(coil_a.dac_reg, coil_b.dac_reg);
	Out_AP_L();	
    Out_AM_L();
	Out_BP_L();	
    Out_BM_L();
}

/**
  * @brief  设置驱动刹车
  * @param  NULL
  * @retval NULL
  */
void TB67H450_SetBrake(void)
{
	coil_a.dac_reg = 0;
	coil_b.dac_reg = 0;
	CurrentControl_VREF_16Bit_MixOut(coil_a.dac_reg, coil_b.dac_reg);
	Out_AP_H();	Out_AM_H();
	Out_BP_H();	Out_BM_H();
}

/**
  * @brief  设置输出细分电流
  * @param  divide:  细分 (0 ~ 细分数)
  * @param  dac_reg: 电流 (0 ~ 3300mA)
  * @retval NULL
  */
void TB67H450_SetDivideElec(uint32_t divide, int32_t elec_ma)
{
	//由细分数获得数组指针
	coil_b.conver = (divide) & (0x000003FF);								//对1024取余
	coil_a.conver = (coil_b.conver + (256)) & (0x000003FF);	                //对1024取余
	
	//由数据指针获得整形数据(空间换时间方案)
	coil_a.sin_data = sin_pi_m2[coil_a.conver];
	coil_b.sin_data = sin_pi_m2[coil_b.conver];

	//由整形数据获得DAC寄存器数据
	uint32_t dac_reg = abs(elec_ma);								//电压电流关系为1:1(检流电阻为0.1欧)
	dac_reg = (uint32_t)(dac_reg * 81322) >> 12;                    //为了避免浮点数转换/运算 整数估算方法 等效  elec_ma / 3.3 * 65535
	dac_reg = dac_reg & (0x0000FFFF);								//(对65535取余)(向小取整)(舍弃符号位)
	coil_a.dac_reg = (uint32_t)(dac_reg * abs(coil_a.sin_data)) >> sin_pi_m2_dpiybit;	//整除4096的Sin幅值
	coil_b.dac_reg = (uint32_t)(dac_reg * abs(coil_b.sin_data)) >> sin_pi_m2_dpiybit;	
    
    
	//DAC输出
	CurrentControl_VREF_16Bit_MixOut(coil_a.dac_reg, coil_b.dac_reg);
	if(coil_a.sin_data > 0)				
    {	
        Out_AP_H();
        Out_AM_L();		
    }
    if(coil_a.sin_data < 0)	
    {	
        Out_AP_L();		
        Out_AM_H();		
    }
	if(!coil_a.sin_data)													
    {	
        Out_AP_H();		
        Out_AM_H();		
    }
	if(coil_b.sin_data > 0)				
    {	
        Out_BP_H();		
        Out_BM_L();		
    }
	if(coil_b.sin_data < 0)	
    {	
        Out_BP_L();		
        Out_BM_H();		
    }
    if(!coil_b.sin_data)
	{	
        Out_BP_H();		
        Out_BM_H();		
    }
}
