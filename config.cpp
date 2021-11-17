#include "config.h"
#include "input_signals.h"
#include "def_pins.h"

//konfigurowanie sygnalow taktujacych
void RCC_Config(void){

		SystemInit();

//odblokowanie taktowania dla niezbędnych peryferiów
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;	
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN;	
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOGEN;
		
		RCC->APB1ENR|=RCC_APB1ENR_USART2EN;
}

void NVIC_Config(void)
{   
		NVIC_SetPriorityGrouping(NVIC_PriGroup_4); //16 priorytetów preemption, brak subpriorytetów 


		NVIC_SetPriority(USART2_IRQn, 1);  	
		NVIC_EnableIRQ(USART2_IRQn);

}

void GPIO_Config(void)
{
//konfiguracja portu A
	ALT_SET_REG(GPIOA, Pin2, IO_OUT_HS);
	GPIOA->AFR[0]=(GPIOA->AFR[0] & ~(0xF<<(Pin2*4))) | (GPIO_AFR_AF7<<(Pin2*4)); //USART2 TX
	ALT_SET_REG(GPIOA, Pin3, IO_OUT_HS);
	GPIOA->AFR[0]=(GPIOA->AFR[0] & ~(0xF<<(Pin3*4))) | (GPIO_AFR_AF7<<(Pin3*4));	//USART2 RX
	
//konfiguracja portu D
	OUT_SET_REG(GPIOD, Pin8, IO_PP, IO_OUT_HS);
	OUT_SET_REG(GPIOD, Pin9, IO_PP, IO_OUT_HS);
	OUT_SET_REG(GPIOD, Pin10, IO_PP, IO_OUT_HS);
	OUT_SET_REG(GPIOD, Pin11, IO_PP, IO_OUT_HS);
	OUT_SET_REG(GPIOD, Pin12, IO_PP, IO_OUT_HS);
	OUT_SET_REG(GPIOD, Pin13, IO_PP, IO_OUT_HS);
	OUT_SET_REG(GPIOD, Pin14, IO_PP, IO_OUT_HS);
	OUT_SET_REG(GPIOD, Pin15, IO_PP, IO_OUT_HS);

//konfiguracja portu E	
	OUT_SET_REG(GPIOE, Pin8, IO_PP, IO_OUT_HS);
	OUT_SET_REG(GPIOE, Pin9, IO_PP, IO_OUT_HS);
	OUT_SET_REG(GPIOE, Pin10, IO_PP, IO_OUT_HS);
	OUT_SET_REG(GPIOE, Pin11, IO_PP, IO_OUT_HS);
	OUT_SET_REG(GPIOE, Pin12, IO_PP, IO_OUT_HS);
	OUT_SET_REG(GPIOE, Pin13, IO_PP, IO_OUT_HS);
	OUT_SET_REG(GPIOE, Pin14, IO_PP, IO_OUT_HS);
	OUT_SET_REG(GPIOE, Pin15, IO_PP, IO_OUT_HS);


//konfiguracja portu G	
	OUT_SET_REG(GPIOG, Pin13, IO_PP, IO_OUT_HS);	//LED1
	OUT_SET_REG(GPIOG, Pin14, IO_PP, IO_OUT_HS);	//LED2
	
	
	
	PIN_CLR(PORT_LED, LED1);
	PIN_CLR(PORT_LED, LED2);

}


void USART_Config(void)
{
	double divider = 0x00;
//konfigurowanie ukladu USART2 
	USART2->CR1&=~USART_CR1_PCE;				
	USART2->CR1&=~USART_CR1_M;			
	USART2->CR2=(USART2->CR2 & USART_BSTOP_CLR) | USART_BSTOP_1;			

	USART2->CR1&=~USART_CR1_OVER8; 

  divider = ((double)45000000 / (16*9600));		   
  USART2->BRR |= (uint16_t)divider << 4;
  USART2->BRR |= (uint16_t)((divider-(uint16_t)divider)*16);


	USART2->CR1|=USART_CR1_TE;
	USART2->CR1&=~USART_CR1_TXEIE;
	USART2->CR1|=USART_CR1_RE;
	USART2->CR1|=USART_CR1_RXNEIE;
//	USART2->CR1|=USART_CR1_UE;	

}


