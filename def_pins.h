/**
 * Keil project for stepper motor driver
 
 * @author  Piotr Poterała
 * @email   poterala.piotr@gmail.com
 * @website http://zappp.pl
 * @version v1.0
 * @ide     Keil uVision 5
 * @license GNU GPL v3
 *	
@verbatim
   ----------------------------------------------------------------------
    Copyright (C) Piotr Poterała, 2021c
    
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    any later version.
     
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    
    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
   ----------------------------------------------------------------------
@endverbatim
 */


#ifndef _DEF_PINS_H
	#define _DEF_PINS_H

#if defined(STM32L4R5xx)
	#include "stm32l4xx.h"
#else
	#include "stm32f4xx.h"
#endif



	#define Pin0     	 ((uint32_t)	0) 
	#define Pin1       ((uint32_t)	1)
	#define Pin2       ((uint32_t)	2)
	#define Pin3       ((uint32_t)	3)
	#define Pin4       ((uint32_t)	4)
	#define Pin5       ((uint32_t)	5)
	#define Pin6       ((uint32_t)	6)
	#define Pin7       ((uint32_t)	7)
	#define Pin8       ((uint32_t)	8)
	#define Pin9       ((uint32_t)	9)
	#define Pin10      ((uint32_t)	10)
	#define Pin11      ((uint32_t)	11)
	#define Pin12      ((uint32_t)	12)
	#define Pin13      ((uint32_t)	13)
	#define Pin14      ((uint32_t)	14)
	#define Pin15      ((uint32_t)	15)

	#define PORT_A		0
	#define PORT_B		1
	#define PORT_C		2
	#define PORT_D		3
	#define PORT_E		4

	#define Pin0_Mask     	(1<<0)  
	#define Pin1_Mask       (1<<1)
	#define Pin2_Mask       (1<<2)
	#define Pin3_Mask       (1<<3)
	#define Pin4_Mask       (1<<4)
	#define Pin5_Mask       (1<<5)
	#define Pin6_Mask       (1<<6)
	#define Pin7_Mask       (1<<7)
	#define Pin8_Mask       (1<<8)
	#define Pin9_Mask       (1<<9)
	#define Pin10_Mask      (1<<10)
	#define Pin11_Mask      (1<<11)
	#define Pin12_Mask      (1<<12)
	#define Pin13_Mask      (1<<13)
	#define Pin14_Mask      (1<<14)
	#define Pin15_Mask      (1<<15)
	#define Pin16_Mask      (1<<16)

	#define PA0     	(1<<0)  
	#define PA1       (1<<1)
	#define PA2       (1<<2)
	#define PA3       (1<<3)
	#define PA4       (1<<4)
	#define PA5       (1<<5)
	#define PA6       (1<<6)
	#define PA7       (1<<7)
	#define PA8       (1<<8)
	#define PA9       (1<<9)
	#define PA10      (1<<10)
	#define PA11      (1<<11)
	#define PA12      (1<<12)
	#define PA13      (1<<13)
	#define PA14      (1<<14)
	#define PA15      (1<<15)

	#define PB0     	(1<<0)  
	#define PB1       (1<<1)
	#define PB2       (1<<2)
	#define PB3       (1<<3)
	#define PB4       (1<<4)
	#define PB5       (1<<5)
	#define PB6       (1<<6)
	#define PB7       (1<<7)
	#define PB8       (1<<8)
	#define PB9       (1<<9)
	#define PB10      (1<<10)
	#define PB11      (1<<11)
	#define PB12      (1<<12)
	#define PB13      (1<<13)
	#define PB14      (1<<14)
	#define PB15      (1<<15)

	#define PC0     	(1<<0)  
	#define PC1       (1<<1)
	#define PC2       (1<<2)
	#define PC3       (1<<3)
	#define PC4       (1<<4)
	#define PC5       (1<<5)
	#define PC6       (1<<6)
	#define PC7       (1<<7)
	#define PC8       (1<<8)
	#define PC9       (1<<9)
	#define PC10      (1<<10)
	#define PC11      (1<<11)
	#define PC12      (1<<12)
	#define PC13      (1<<13)
	#define PC14      (1<<14)
	#define PC15      (1<<15)

	#define PD0     	(1<<0)  
	#define PD1       (1<<1)
	#define PD2       (1<<2)
	#define PD3       (1<<3)
	#define PD4       (1<<4)
	#define PD5       (1<<5)
	#define PD6       (1<<6)
	#define PD7       (1<<7)
	#define PD8       (1<<8)
	#define PD9       (1<<9)
	#define PD10      (1<<10)
	#define PD11      (1<<11)
	#define PD12      (1<<12)
	#define PD13      (1<<13)
	#define PD14      (1<<14)
	#define PD15      (1<<15)

	#define PE0     	(1<<0)  
	#define PE1       (1<<1)
	#define PE2       (1<<2)
	#define PE3       (1<<3)
	#define PE4       (1<<4)
	#define PE5       (1<<5)
	#define PE6       (1<<6)
	#define PE7       (1<<7)
	#define PE8       (1<<8)
	#define PE9       (1<<9)
	#define PE10      (1<<10)
	#define PE11      (1<<11)
	#define PE12      (1<<12)
	#define PE13      (1<<13)
	#define PE14      (1<<14)
	#define PE15      (1<<15)

	#define PF0     	(1<<0)  
	#define PF1       (1<<1)
	#define PF2       (1<<2)
	#define PF3       (1<<3)
	#define PF4       (1<<4)
	#define PF5       (1<<5)
	#define PF6       (1<<6)
	#define PF7       (1<<7)
	#define PF8       (1<<8)
	#define PF9       (1<<9)
	#define PF10      (1<<10)
	#define PF11      (1<<11)
	#define PF12      (1<<12)
	#define PF13      (1<<13)
	#define PF14      (1<<14)
	#define PF15      (1<<15)

	#define PG0     	(1<<0)  
	#define PG1       (1<<1)
	#define PG2       (1<<2)
	#define PG3       (1<<3)
	#define PG4       (1<<4)
	#define PG5       (1<<5)
	#define PG6       (1<<6)
	#define PG7       (1<<7)
	#define PG8       (1<<8)
	#define PG9       (1<<9)
	#define PG10      (1<<10)
	#define PG11      (1<<11)
	#define PG12      (1<<12)
	#define PG13      (1<<13)
	#define PG14      (1<<14)
	#define PG15      (1<<15)

	#define PH0     	(1<<0)  
	#define PH1       (1<<1)
	#define PH2       (1<<2)
	#define PH3       (1<<3)
	#define PH4       (1<<4)
	#define PH5       (1<<5)
	#define PH6       (1<<6)
	#define PH7       (1<<7)
	#define PH8       (1<<8)
	#define PH9       (1<<9)
	#define PH10      (1<<10)
	#define PH11      (1<<11)
	#define PH12      (1<<12)
	#define PH13      (1<<13)
	#define PH14      (1<<14)
	#define PH15      (1<<15)

	#define PI0     	(1<<0)  
	#define PI1       (1<<1)
	#define PI2       (1<<2)
	#define PI3       (1<<3)
	#define PI4       (1<<4)
	#define PI5       (1<<5)
	#define PI6       (1<<6)
	#define PI7       (1<<7)
	#define PI8       (1<<8)
	#define PI9       (1<<9)
	#define PI10      (1<<10)
	#define PI11      (1<<11)
	#define PI12      (1<<12)
	#define PI13      (1<<13)
	#define PI14      (1<<14)
	#define PI15      (1<<15)


//mode
	#define IO_IN 		((uint32_t)0x0)			//wejśie
	#define IO_OUT 		((uint32_t)0x1)			//wyjśie
	#define IO_ALT		((uint32_t)0x2)			//funkcja alternatywna
	#define IO_AN			((uint32_t)0x3)			//analog

//output type
	#define IO_PP 		((uint32_t)0x0)
	#define IO_OD 		((uint32_t)0x1)

//output speed
	#define IO_OUT_LS 		((uint32_t)0x0)
	#define IO_OUT_MS 		((uint32_t)0x1)
	#define IO_OUT_FS 		((uint32_t)0x2)
	#define IO_OUT_HS 		((uint32_t)0x3)

//input pull-up/pull-down
	#define IO_IN_NPUD 	((uint32_t)0x0)
	#define IO_IN_PU 		((uint32_t)0x1)
	#define IO_IN_PD 		((uint32_t)0x2)


#if defined(STM32L4R5xx)
	#define PIN_TOG(PORT, PIN) ((PORT->ODR & PIN)?PIN_CLR(PORT, PIN):PIN_SET(PORT, PIN))
	#define PIN_SET(PORT, PIN) (PORT->BSRR=PIN)
	#define PIN_CLR(PORT, PIN) (PORT->BSRR=(PIN<<16))
#else
	#define PIN_TOG(PORT, PIN) (PORT->ODR^=PIN)
	#define PIN_SET(PORT, PIN) (PORT->BSRRL=PIN)
	#define PIN_CLR(PORT, PIN) (PORT->BSRRH=PIN)
#endif

enum{
	B_LOW=0,
	B_HIGH
};

typedef struct{
	GPIO_TypeDef* port;
	int pin;
}uPin;


#endif
