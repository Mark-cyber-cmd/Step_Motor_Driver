/*****
  ** @file     : mt6816.c/h
  ** @brief    : MT6816传感器硬件驱动
  ** @versions : 1
  ** @time     : 2022/07/27
  ** @reviser  : NULL
  ** @explain  : NULL
*****/

//Oneself
#include "mt6816.h"

/****************************** MT6816_SPI ******************************/

/**
  * @brief  MT6816_SPI采集获取角度数据
  * @param  NULL
  * @retval NULL
**/
void MT6816_SPI_Get_AngleData(MT6816_Typedef* mt6816_spi)
{
	uint8_t data_cmd_03[2]={0x83, 0x00};
    uint8_t data_cmd_04[2]={0x84, 0x00};
	uint8_t data_rec_03[2];
    uint8_t data_rec_04[2];
	uint8_t h_count = 0;
	
	for(uint8_t i=0; i<3; i++)
    {
		//读取SPI数据
		MT6816_Enable();
		HAL_SPI_TransmitReceive(&MT6816_SPI_Get_HSPI, (uint8_t*)&data_cmd_03[0], (uint8_t*)&data_rec_03[0], 2, HAL_MAX_DELAY);
		MT6816_Disable();
        
		MT6816_Enable();
		HAL_SPI_TransmitReceive(&MT6816_SPI_Get_HSPI, (uint8_t*)&data_cmd_04[0], (uint8_t*)&data_rec_04[0], 2, HAL_MAX_DELAY);
		MT6816_Disable();
        
		mt6816_spi->raw_data = ((data_rec_03[1] & 0x00FF) << 8) | (data_rec_04[1] & 0x00FF);
		
        
		//奇偶校验
        
		for(uint8_t j=0; j<16; j++)
        {
			if(mt6816_spi->raw_data & (0x0001 << j))     h_count++;
		}
        
		if(h_count & 0x01)
        {
			mt6816_spi->pc_flag = false;
		}
		else
        {
			mt6816_spi->pc_flag = true;
			break;
		}
	}
	
	if(mt6816_spi->pc_flag)
    {
		mt6816_spi->angle = mt6816_spi->raw_data >> 2;
		mt6816_spi->no_mag_flag = (bool)(mt6816_spi->raw_data & (0x0001 << 1));
	}
}

void MT6816_test(void)
{
    MT6816_Typedef mt6816;
  
    MT6816_SPI_Get_AngleData(&mt6816);
    if(mt6816.no_mag_flag == 1)
    {
        printf("\r\nNO magnet has detected!\r\n");
    }
    else
    {
        printf("\r\nangel: %.2f\r\n", mt6816.angle /16384.0 * 360);
    }
}

















