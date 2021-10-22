#ifndef _CONFIG_H
	#define _CONFIG_H

	#include "stm32xx.h"

	#define NVIC_PriGroup_0         ((uint32_t)0x7) /*!< 0 bits for pre-emption priority
																															4 bits for subpriority */
	#define NVIC_PriGroup_1         ((uint32_t)0x6) /*!< 1 bits for pre-emption priority
																															3 bits for subpriority */
	#define NVIC_PriGroup_2         ((uint32_t)0x5) /*!< 2 bits for pre-emption priority
																															2 bits for subpriority */
	#define NVIC_PriGroup_3         ((uint32_t)0x4) /*!< 3 bits for pre-emption priority
																															1 bits for subpriority */
	#define NVIC_PriGroup_4         ((uint32_t)0x3) /*!< 4 bits for pre-emption priority
																															0 bits for subpriority */
	#define RCC_PLLCFGR_PLLN_V40	0x2800
	#define RCC_PLLCFGR_PLLR_V2		0x0
	#define RCC_PLLCFGR_PLLM_V2		0x10
	

	#define  USART_BSTOP_CLR   0xCFFF           
	#define  USART_BSTOP_1     0x0000          
	#define  USART_BSTOP_2     0x2000  

	#define  PWR_CR2_PLS_29V    0x000C 
	#define  PWR_CR2_PLS_28V    0x000A      
	#define  PWR_CR2_PLS_26V    0x0008 
	#define  PWR_CR2_PLS_25V    0x0006 

	#define  RCC_BDCR_RTCSEL_LSE                 ((uint32_t)0x00000100)

	#define GPIO_AFR_AF0				0x0
	#define GPIO_AFR_AF1				0x1
	#define GPIO_AFR_AF2				0x2
	#define GPIO_AFR_AF3				0x3
	#define GPIO_AFR_AF4				0x4
	#define GPIO_AFR_AF5				0x5
	#define GPIO_AFR_AF6				0x6
	#define GPIO_AFR_AF7				0x7
	#define GPIO_AFR_AF8				0x8
	#define GPIO_AFR_AF9				0x9
	#define GPIO_AFR_AF10				0xA
	#define GPIO_AFR_AF11				0xB
	#define GPIO_AFR_AF12				0xC
	#define GPIO_AFR_AF13				0xD
	#define GPIO_AFR_AF14				0xE
	#define GPIO_AFR_AF15				0xF


	#define IO_SET_REG1(REG, PIN, SETS) ((REG & ~(0x1<<(PIN))) | ((SETS)<<(PIN)))
	#define IO_SET_REG2(REG, PIN, SETS) ((REG & ~(0x3<<(PIN*2))) | ((SETS)<<(PIN*2)))


  #define IN_SET_REG(REG, PIN, SETS) (REG->MODER=IO_SET_REG2(REG->MODER, PIN, IO_IN), REG->PUPDR=IO_SET_REG2(REG->PUPDR, PIN, SETS))

  #define OUT_SET_REG(REG, PIN, TYPE, SPEED) (REG->MODER=IO_SET_REG2(REG->MODER, PIN, IO_OUT), REG->OTYPER=IO_SET_REG1(REG->OTYPER, PIN, TYPE), REG->OSPEEDR=IO_SET_REG2(REG->OSPEEDR, PIN, SPEED))
	#define ALT_SET_REG(REG, PIN, SPEED) (REG->MODER=IO_SET_REG2(REG->MODER, PIN, IO_ALT), REG->OTYPER&=~(1<<PIN), REG->OSPEEDR=IO_SET_REG2(REG->OSPEEDR, PIN, SPEED))


	void RCC_Config(void);
	void NVIC_Config(void);
	void GPIO_Config(void);
	void USART_Config(void);



#endif
