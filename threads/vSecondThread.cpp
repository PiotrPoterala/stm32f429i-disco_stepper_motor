#include "cmsis_os2.h"                          // CMSIS RTOS header file
 #include "input_signals.h"
 #include "RTX_Config.h"
/*----------------------------------------------------------------------------
 *      Thread 1 'Thread_Name': Sample thread
 *---------------------------------------------------------------------------*/
 
 #define FREQUENCY_OF_SECOND_THREAD	1
 
osThreadId_t tid_vSecondThread;                        // thread id
 
void vSecondThread (void *argument);                   // thread function
 
int Init_vSecondThread  (osPriority_t priority) {
 
  tid_vSecondThread = osThreadNew(vSecondThread, NULL, NULL);
	osThreadSetPriority (tid_vSecondThread, priority);
  if (tid_vSecondThread == NULL) {
    return(-1);
  }
 
  return(0);
}
 
void vSecondThread (void *argument) {
 
  while (1) {
    PIN_TOG(PORT_LED, LED1);  
    osDelay(OS_TICK_FREQ/FREQUENCY_OF_SECOND_THREAD);  
  }
}
