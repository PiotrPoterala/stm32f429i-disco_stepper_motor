#include "cmsis_os2.h"                                            // CMSIS RTOS header file

#include <string>

#include "pp_rtos_uart_queue.h"

extern defOUartQueues* uartCommunicationQueues;

using namespace std;
 
void vReceiveAndInterpretDataFromComUartThread (void *argument);                             // thread function
osThreadId_t tid_vReceiveAndInterpretDataFromComUartThread;                                          // thread id

int Init_vReceiveAndInterpretDataFromComUartThread (osPriority_t priority) {
	
	const osThreadAttr_t thread_attr = {
		.stack_size = 2048, 	
		.priority = priority	
	};
	
	
  tid_vReceiveAndInterpretDataFromComUartThread = osThreadNew(vReceiveAndInterpretDataFromComUartThread, NULL, &thread_attr);
	
	
	osThreadSetPriority (tid_vReceiveAndInterpretDataFromComUartThread, priority);
  if (!tid_vReceiveAndInterpretDataFromComUartThread) return(-1);
  
  return(0);
}

void vReceiveAndInterpretDataFromComUartThread(void *argument) {
string receiveString;
	char receiveChar;
	
  while (1) {
		
			uartCommunicationQueues->getStringFromReceiveQueue();    
		
  }
}
