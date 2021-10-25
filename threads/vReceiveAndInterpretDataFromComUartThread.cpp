#include "cmsis_os2.h"                                            // CMSIS RTOS header file

#include <string>

using namespace std;

extern osMessageQueueId_t qComunicationUartSend; 
extern osMessageQueueId_t qComunicationUartReceive; 


/*----------------------------------------------------------------------------
 *      Thread 1 'Thread_Name': Sample thread
 *---------------------------------------------------------------------------*/
 
void vReceiveAndInterpretDataFromComUartThread (void *argument);                             // thread function
osThreadId_t tid_vReceiveAndInterpretDataFromComUartThread;                                          // thread id

int Init_vReceiveAndInterpretDataFromComUartThread (osPriority_t priority) {

  tid_vReceiveAndInterpretDataFromComUartThread = osThreadNew(vReceiveAndInterpretDataFromComUartThread, NULL, NULL);
	osThreadSetPriority (tid_vReceiveAndInterpretDataFromComUartThread, priority);
  if (!tid_vReceiveAndInterpretDataFromComUartThread) return(-1);
  
  return(0);
}

void vReceiveAndInterpretDataFromComUartThread(void *argument) {
	char receiveChar;
	string receiveString;
	
  while (1) {
		
			if(osMessageQueueGet(qComunicationUartReceive, &receiveChar, NULL, osWaitForever) == osOK){

				receiveString+=receiveChar; 

				if(receiveChar=='\n'){

//					oComunicationWithPP16ster.interpretATcommand(&oComunicationWithPP16ster.transmitParam, &oAutWork, &oTools.tools.itemsParam, &oTankErrors, &oPowerErrors, &oEquipmentDetect,
//																											qUartPP16STERsend, qToDoMarkTools, xGenerSend);
					receiveString.clear();

				}else{
					if(receiveString.size()>64)receiveString.clear();
				}

			}                                        // suspend thread
  }
}
