#include "stm32f_it.h"

#include "pp_rtos_uart_queue.h"

extern defOUartQueues* uartCommunicationQueues;


void USART2_IRQHandler(void){

	if(USART2->SR & USART_SR_RXNE){  
		uartCommunicationQueues->receiveSignAndWriteToReceiveQueue();
  }else if(USART2->SR & USART_SR_TXE){  
		 uartCommunicationQueues->sendSignFromSendQueue();
  }

}


