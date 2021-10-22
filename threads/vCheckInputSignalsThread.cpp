
#include "cmsis_os2.h"                                           // CMSIS RTOS header file

//#include "input_signals_analysis.h"
#include "input_signals.h"


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
	uint32_t tick;
	
	tick = osKernelGetTickCount(); 
	
  while (1) {
			//sprawdzenie krańcówek
//			oCheckSignalsLimitedStop.checkSignal(PORT_LIM_STOP, PIN_KRAN_Xplus, kKRAN_Xplus);
//			oCheckSignalsLimitedStop.checkSignal(PORT_LIM_STOP, PIN_KRAN_Xmin, kKRAN_Xmin);
//			oCheckSignalsLimitedStop.checkSignal(PORT_LIM_STOP, PIN_KRAN_Yplus, kKRAN_Yplus);
//			oCheckSignalsLimitedStop.checkSignal(PORT_LIM_STOP, PIN_KRAN_Ymin, kKRAN_Ymin);
//			oCheckSignalsLimitedStop.checkSignal(PORT_LIM_STOP, PIN_KRAN_Zplus, kKRAN_Zplus);
//			oCheckSignalsLimitedStop.checkSignal(PORT_LIM_STOP, PIN_KRAN_Zmin, kKRAN_Zmin);


//			oCheckSignalsLimitedStop.checkSignal(GPIOC, PC13, 1);
//		
//			if((oCheckSignalsLimitedStop.checkedResetSignals & 1) && !(oCheckSignalsLimitedStop.madeSignals & 1)){
//				oCheckSignalsLimitedStop.madeSignals |=1;
//				PIN_SET(GPIOB, LED2);
//			}else if((oCheckSignalsLimitedStop.checkedSetSignals & 1) && (oCheckSignalsLimitedStop.madeSignals & 1)){
//				PIN_CLR(GPIOB, LED2);
//				oCheckSignalsLimitedStop.madeSignals &=~1;
//			}
		
  		tick += 2;    
			osDelayUntil(tick);
			
  }
}


				