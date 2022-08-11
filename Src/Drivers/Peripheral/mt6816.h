/*****
  ** @file     : mt6816.c/h
  ** @brief    : MT6816传感器硬件驱动
  ** @versions : 1
  ** @time     : 2022/07/27
  ** @reviser  : NULL
  ** @explain  : NULL
*****/

#ifndef MT6816_H
#define MT6816_H

#include "main.h"

extern SPI_HandleTypeDef hspi1;
extern SPI_HandleTypeDef hspi2;

//GPIO输出
#define MT6816_Enable()		    HAL_GPIO_WritePin(MT6816_SPI_CS_GPIO_Port, MT6816_SPI_CS_Pin, GPIO_PIN_RESET);
#define MT6816_Disable()		HAL_GPIO_WritePin(MT6816_SPI_CS_GPIO_Port, MT6816_SPI_CS_Pin, GPIO_PIN_SET);


/********** MT6816_SPI **********/
typedef struct{
    
	uint16_t	raw_data;	    //SPI读取到的原始数据

	uint16_t	angle;			//SPI输出的角度
	bool	    no_mag_flag;	//磁铁数据有效标志
	bool		pc_flag;		//奇偶校验位
    bool        over_speed;     //超速报警位
    bool        rectify_angle;
}MT6816_Typedef;


//MT6816_SPI
void MT6816_SPI_Get_AngleData(MT6816_Typedef* mt6816_spi);      //刷新MT6816结构体
void MT6816_test(void);
#endif
