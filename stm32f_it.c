#include <stdbool.h>
#include "stm32f_it.h"
#include "cmsis_os2.h"

extern osMessageQueueId_t qComunicationUartSend; 
extern osMessageQueueId_t qComunicationUartReceive; 


void USART2_IRQHandler(void){
	char receiveChar;

	if(USART2->SR & USART_SR_RXNE){  

		receiveChar=(uint8_t)(USART2->DR); 
		osMessageQueuePut (qComunicationUartReceive, &receiveChar, 0, 0); 

  }else if(USART2->SR & USART_SR_TXE){  
//		uartTX_ISRbyQueue(UART_PP16ster, qUartPP16STERsend);
  }

}


