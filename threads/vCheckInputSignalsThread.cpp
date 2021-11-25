
#include "cmsis_os2.h"                                           // CMSIS RTOS header file
 #include "RTX_Config.h"
#include "input_signals.h"
#include "pp_rtos_uart_queue.h"

#include <string>

 #define FREQUENCY_OF_CHECKINPUTS_THREAD	2

//extern defOUartQueues* uartCommunicationQueues;
//extern defOCheckSignals oCheckSignalsLimitedStop;

/*----------------------------------------------------------------------------
 *      Thread 1 'Thread_Name': Sample thread
 *---------------------------------------------------------------------------*/
 
void vCheckInputSignalsThread (void *argument);                             // thread function
osThreadId_t tid_vCheckInputSignalsThread;                                          // thread id             

int Init_vCheckInputSignalsThread (osPriority_t priority) {

  tid_vCheckInputSignalsThread = osThreadNew(vCheckInputSignalsThread, NULL, NULL);
	osThreadSetPriority (tid_vCheckInputSignalsThread, priority);
  if (!tid_vCheckInputSignalsThread) return(-1);
  
  return(0);
}

void vCheckInputSignalsThread (void *argument) {
	int tick;
	
	tick = osKernelGetTickCount(); 
	
  while (1) {
			PIN_TOG(PORT_LED, LED2); 
		
		
  		tick += OS_TICK_FREQ/FREQUENCY_OF_CHECKINPUTS_THREAD;    
			osDelayUntil(tick);
			
  }
}


				