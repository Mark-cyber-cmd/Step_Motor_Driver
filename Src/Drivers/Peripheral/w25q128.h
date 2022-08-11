#include "main.h"

extern SPI_HandleTypeDef hspi1;
extern SPI_HandleTypeDef hspi2;


//定位到页
void Write_Page(uint8_t* pBuffer,uint32_t WriteAddr,uint16_t NumByteToWrite);
//写字，一次最多一页
void Write_Word(uint8_t* pBuffer, uint32_t WriteAddr, uint16_t NumByteToWrite);
//读取W25Q128数据
void Read_W25Q128_data(uint8_t* pBuffer,uint32_t ReadAddr,uint16_t NumByteToRead);
//擦除整个芯片 等待时间超长... 10-20S
void Erase_W25Q128_Chip(void);
//擦除地址所在的扇区
void Erase_Write_data_Sector(uint32_t Address,uint32_t Write_data_NUM);
//擦除地址所在的一个扇区
void Erase_one_Sector(uint32_t Address);
//等待空闲
void W25Q128_Wait_Busy(void);
//读取寄存器状态
uint8_t W25Q128_ReadSR(void);
//W25Q128写失能,将WEL置0 
void W25Q128_Write_Disable(void);
//W25Q128写使能,将WEL置1 
void W25Q128_Write_Enable(void);
//SPI2 接收 1 个字节数据
uint8_t spi2_Receive_one_byte(void);
//器件失能
void W25Q128_Disable(void);
//器件使能
void W25Q128_Enable(void);

//测试程序
void W25Q128_test(void);

// 读取 ID 测试 OK 0xEF 0X17
void read_W25Q128_ID(void);



