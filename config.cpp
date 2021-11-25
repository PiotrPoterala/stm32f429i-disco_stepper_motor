#include "config.h"
#include "input_signals.h"
#include "def_pins.h"

//konfigurowanie sygnalow taktujacych
void RCC_Config(void){

		SystemInit();
	
		RCC->CR |= RCC_CR_HSEON;
		while(!(RCC->CR & RCC_CR_HSERDY)) 
			;
	
	  RCC->APB1ENR |= RCC_APB1ENR_PWREN;
    PWR->CR |= PWR_CR_VOS;

		RCC->CR&=~RCC_CR_PLLON;
		while(RCC->CR & RCC_CR_PLLRDY);
		RCC->PLLCFGR|=RCC_PLLCFGR_PLLSRC;
		RCC->PLLCFGR=(RCC->PLLCFGR & ~RCC_PLLCFGR_PLLM) | RCC_PLLCFGR_PLLM_DIV4;
		RCC->PLLCFGR=(RCC->PLLCFGR & ~RCC_PLLCFGR_PLLN) | RCC_PLLCFGR_PLLN_MUL180;
		RCC->PLLCFGR=(RCC->PLLCFGR & ~RCC_PLLCFGR_PLLP) | RCC_PLLCFGR_PLLP_DIV2;
		RCC->CR|=RCC_CR_PLLON;
		while(!(RCC->CR & RCC_CR_PLLRDY)) 
			;
	
   
    PWR->CR |= PWR_CR_ODEN;
    while(!(PWR->CSR & PWR_CSR_ODRDY));
    PWR->CR |= PWR_CR_ODSWEN;
    while(!(PWR->CSR & PWR_CSR_ODSWRDY));    
    /* Configure Flash prefetch, Instruction cache, Data cache and wait state */
    FLASH->ACR = FLASH_ACR_PRFTEN | FLASH_ACR_ICEN | FLASH_ACR_DCEN | FLASH_ACR_LATENCY_5WS;

		RCC->CFGR=(RCC->CFGR & ~RCC_CFGR_SW) | RCC_CFGR_SW_PLL;
		RCC->CFGR |= RCC_CFGR_HPRE_DIV1;
    RCC->CFGR |= RCC_CFGR_PPRE2_DIV2;
    RCC->CFGR |= RCC_CFGR_PPRE1_DIV4;

    /* Wait till the main PLL is used as system clock source */
    while ((RCC->CFGR & (uint32_t)RCC_CFGR_SWS ) != RCC_CFGR_SWS_PLL);

  
		SystemCoreClockUpdate();
		
//odblokowanie taktowania dla niezbędnych peryferiów
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
//		RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;	
//		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN;	
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOGEN;
		
		RCC->APB2ENR|=RCC_APB2ENR_USART1EN;
}

void NVIC_Config(void)
{   
		NVIC_SetPriorityGrouping(NVIC_PriGroup_4); //16 priorytetów preemption, brak subpriorytetów 


		NVIC_SetPriority(USART1_IRQn, 1);  	
		NVIC_EnableIRQ(USART1_IRQn);

}

void GPIO_Config(void)
{
//konfiguracja portu A
	ALT_SET_REG(GPIOA, Pin9, IO_OUT_HS);
	GPIOA->AFR[1]=(GPIOA->AFR[1] & ~(0xF<<((Pin9-8)*4))) | (GPIO_AFR_AF7<<((Pin9-8)*4)); //USART1 TX
	ALT_SET_REG(GPIOA, Pin10, IO_OUT_HS);
	GPIOA->AFR[1]=(GPIOA->AFR[1] & ~(0xF<<((Pin10-8)*4))) | (GPIO_AFR_AF7<<((Pin10-8)*4));	//USART1 RX
	
	//konfiguracja portu B
	OUT_SET_REG(GPIOB, Pin4, IO_PP, IO_OUT_HS);
	OUT_SET_REG(GPIOB, Pin7, IO_PP, IO_OUT_HS);
	
	
////konfiguracja portu D
//	OUT_SET_REG(GPIOD, Pin8, IO_PP, IO_OUT_HS);
//	OUT_SET_REG(GPIOD, Pin9, IO_PP, IO_OUT_HS);
//	OUT_SET_REG(GPIOD, Pin10, IO_PP, IO_OUT_HS);
//	OUT_SET_REG(GPIOD, Pin11, IO_PP, IO_OUT_HS);
//	OUT_SET_REG(GPIOD, Pin12, IO_PP, IO_OUT_HS);
//	OUT_SET_REG(GPIOD, Pin13, IO_PP, IO_OUT_HS);
//	OUT_SET_REG(GPIOD, Pin14, IO_PP, IO_OUT_HS);
//	OUT_SET_REG(GPIOD, Pin15, IO_PP, IO_OUT_HS);

////konfiguracja portu E	
//	OUT_SET_REG(GPIOE, Pin8, IO_PP, IO_OUT_HS);
//	OUT_SET_REG(GPIOE, Pin9, IO_PP, IO_OUT_HS);
//	OUT_SET_REG(GPIOE, Pin10, IO_PP, IO_OUT_HS);
//	OUT_SET_REG(GPIOE, Pin11, IO_PP, IO_OUT_HS);
//	OUT_SET_REG(GPIOE, Pin12, IO_PP, IO_OUT_HS);
//	OUT_SET_REG(GPIOE, Pin13, IO_PP, IO_OUT_HS);
//	OUT_SET_REG(GPIOE, Pin14, IO_PP, IO_OUT_HS);
//	OUT_SET_REG(GPIOE, Pin15, IO_PP, IO_OUT_HS);


//konfiguracja portu G	
	OUT_SET_REG(GPIOG, Pin13, IO_PP, IO_OUT_HS);	//LED1
	OUT_SET_REG(GPIOG, Pin14, IO_PP, IO_OUT_HS);	//LED2
	
	
	
	PIN_CLR(PORT_LED, LED1);
	PIN_CLR(PORT_LED, LED2);

}


void USART_Config(void){
	double divider = 0x00;
	
	USART1->CR1&=~USART_CR1_PCE;		//wyłączenie parzystości		
	USART1->CR1&=~USART_CR1_M;			//8 bitów danych (możliwe 8 lub 9 bitów danych)
	USART1->CR2=(USART1->CR2 & USART_BSTOP_CLR) | USART_BSTOP_1;			//1 bit stopu

	USART1->CR1&=~USART_CR1_OVER8; //próbkowanie typ 16 (potrzebne do przeliczenia baud rate)

  divider = ((double)90000000 / (16*9600));		//zgodnie za wzorem z manual'a PLCK1/(16*BAUD) dla oversampling=16    
  USART1->BRR |= (uint16_t)divider << 4;
  USART1->BRR |= (uint16_t)((divider-(uint16_t)divider)*16);

	USART1->CR1|=USART_CR1_TE;
	USART1->CR1&=~USART_CR1_TXEIE;
	USART1->CR1|=USART_CR1_RE;
	USART1->CR1|=USART_CR1_RXNEIE;
	USART1->CR1|=USART_CR1_UE;	

}


