#include "stm32f_it.h"

#include "pp_rtos_uart_queue.h"

extern defOUartQueues* uartCommunicationQueues;


void USART1_IRQHandler(void){

	uartCommunicationQueues->portListen();

}


