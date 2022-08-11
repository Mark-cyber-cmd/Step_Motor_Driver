/********** A **********/


/********** B **********/


/********** C **********/

/********** D **********/
#define DEBUG_USART                             USART1
#define DEBUG_USART_CLK_ENABLE()                __HAL_RCC_USART1_CLK_ENABLE();

#define DEBUG_USART_RX_GPIO_PORT                GPIOA
#define DEBUG_USART_RX_GPIO_CLK_ENABLE()        __HAL_RCC_GPIOA_CLK_ENABLE()
#define DEBUG_USART_RX_PIN                      GPIO_PIN_10

#define DEBUG_USART_TX_GPIO_PORT                GPIOA
#define DEBUG_USART_TX_GPIO_CLK_ENABLE()       __HAL_RCC_GPIOA_CLK_ENABLE()
#define DEBUG_USART_TX_PIN                      GPIO_PIN_9

#define DEBUG_USART_IRQHandler                  USART1_IRQHandler
#define DEBUG_USART_IRQ                 		USART1_IRQn
/************************************************************/
/********** E **********/

/********** F **********/

/********** G **********/

/********** H **********/

/********** I **********/

/********** J **********/

/********** K **********/

/********** L **********/

/********** M **********/
/********** MT6816 **********/
//(GPIO)
#define MT6816_SPI_CS_GPIO_CLK_ENABLE()		__HAL_RCC_GPIOA_CLK_ENABLE();		//PB12
#define MT6816_SPI_CS_GPIO_Port				(GPIOA)
#define MT6816_SPI_CS_Pin 					(GPIO_PIN_15)

//(SPI)
#define MT6816_SPI_SCK_GPIO_CLK_ENABLE()	__HAL_RCC_GPIOB_CLK_ENABLE();		//PB3
#define MT6816_SPI_SCK_GPIO_Port		    (GPIOB)
#define MT6816_SPI_SCK_Pin 					(GPIO_PIN_3)
#define MT6816_SPI_MISO_GPIO_CLK_ENABLE()	__HAL_RCC_GPIOB_CLK_ENABLE();		//PB4
#define MT6816_SPI_MISO_GPIO_Port		    (GPIOB)
#define MT6816_SPI_MISO_Pin 				(GPIO_PIN_4)
#define MT6816_SPI_MOSI_GPIO_CLK_ENABLE()	__HAL_RCC_GPIOB_CLK_ENABLE();		//PB5
#define MT6816_SPI_MOSI_GPIO_Port			(GPIOB)
#define MT6816_SPI_MOSI_Pin 				(GPIO_PIN_5)
#define MT6816_SPI_CLK_ENABLE()				__HAL_RCC_SPI1_CLK_ENABLE();		//SPI1
#define MT6816_SPI_Get_SPI					(SPI1)
#define MT6816_SPI_Get_HSPI					(hspi1)
#define	MT6816_SPI_Prescaler				(SPI_BAUDRATEPRESCALER_4)			//SPI1_4_9M

/********** N **********/

/********** O **********/


/********** P **********/

/********** Q **********/

/********** R **********/

/********** S **********/

/********** T **********/
/********** HW_ELEC **********/
//(GPIO)
#define TB67H450_AP_GPIO_CLK_ENABLE()		__HAL_RCC_GPIOA_CLK_ENABLE()		//PA5
#define TB67H450_AP_GPIO_Port				(GPIOA)
#define TB67H450_AP_Pin						(GPIO_PIN_5)
#define TB67H450_AM_GPIO_CLK_ENABLE()		__HAL_RCC_GPIOA_CLK_ENABLE()		//PA4
#define TB67H450_AM_GPIO_Port				(GPIOA)
#define TB67H450_AM_Pin						(GPIO_PIN_4)
#define TB67H450_BP_GPIO_CLK_ENABLE()		__HAL_RCC_GPIOA_CLK_ENABLE()		//PA3
#define TB67H450_BP_GPIO_Port				(GPIOA)
#define TB67H450_BP_Pin						(GPIO_PIN_3)
#define TB67H450_BM_GPIO_CLK_ENABLE()		__HAL_RCC_GPIOA_CLK_ENABLE()		//PA2
#define TB67H450_BM_GPIO_Port				(GPIOA)
#define TB67H450_BM_Pin						(GPIO_PIN_2)
//(AFIO & TIM)
#define TB67H450_APWM_GPIO_CLK_ENABLE()	    __HAL_RCC_GPIOB_CLK_ENABLE()		//PB11
#define TB67H450_APWM_GPIO_Port			    (GPIOB)
#define TB67H450_APWM_Pin					(GPIO_PIN_11)
#define TB67H450_APWM_CHANNEL				(TIM_CHANNEL_4)
#define TB67H450_BPWM_GPIO_CLK_ENABLE()	    __HAL_RCC_GPIOB_CLK_ENABLE()		//PB10
#define TB67H450_BPWM_GPIO_Port				(GPIOB)
#define TB67H450_BPWM_Pin					(GPIO_PIN_10)
#define TB67H450_BPWM_CHANNEL				(TIM_CHANNEL_3)
#define TB67H450_PWM_TIM_CLK_ENABLE()		__HAL_RCC_TIM2_CLK_ENABLE()			//TIM2
#define	TB67H450_PWM_Get_TIM				(TIM2)
#define	TB67H450_PWM_Get_HTIM				(htim2)
#define	TB67H450_TIM_AFIO_REMAP				__HAL_AFIO_REMAP_TIM2_PARTIAL_2();	//TIM_AFIO端口重新映射
/********** U **********/

/********** V **********/

/********** W **********/
/********** W25Q16 **********/
//(GPIO)
#define W25Q_SPI_CS_GPIO_CLK_ENABLE()		__HAL_RCC_GPIOB_CLK_ENABLE();		//PB12
#define W25Q_SPI_CS_GPIO_Port				(GPIOB)
#define W25Q_SPI_CS_Pin 					(GPIO_PIN_12)

//(SPI)
#define W25Q_SPI_SCK_GPIO_CLK_ENABLE()	    __HAL_RCC_GPIOB_CLK_ENABLE();		//PB3
#define W25Q_SPI_SCK_GPIO_Port				(GPIOB)
#define W25Q_SPI_SCK_Pin 					(GPIO_PIN_13)
#define W25Q_SPI_MISO_GPIO_CLK_ENABLE()	    __HAL_RCC_GPIOB_CLK_ENABLE();		//PB4
#define W25Q_SPI_MISO_GPIO_Port				(GPIOB)
#define W25Q_SPI_MISO_Pin 					(GPIO_PIN_14)
#define W25Q_SPI_MOSI_GPIO_CLK_ENABLE()	    __HAL_RCC_GPIOB_CLK_ENABLE();		//PB5
#define W25Q_SPI_MOSI_GPIO_Port				(GPIOB)
#define W25Q_SPI_MOSI_Pin 					(GPIO_PIN_15)
#define W25Q_SPI_CLK_ENABLE()				__HAL_RCC_SPI2_CLK_ENABLE();		//SPI1
#define W25Q_SPI_Get_SPI					(SPI2)
#define W25Q_SPI_Get_HSPI					(hspi2)
#define	W25Q_SPI_Prescaler					(SPI_BAUDRATEPRESCALER_4)			//SPI1_4_9M
/********** X **********/

/********** Y **********/

/********** Z **********/


