#include "cmsis_os2.h"                          // CMSIS RTOS header file
#include "pp_rtx5_queue.h"
#include "pp_rtx5_at_commands_interpreter.h"
#include "at_tags.h"
#include "pp_rtx5_drive_algorithms.h"
#include <string>
/*----------------------------------------------------------------------------
 *      Thread 1 'Thread_Name': Sample thread
 *---------------------------------------------------------------------------*/
 extern defORTX5TaskQueues<int>* taskCommunicationQueues;
 extern defODriveAlgorithms* motorsAlgorithms;
 
 
osThreadId_t tid_vRealizationFunctionThread;                        // thread id
 
void vRealizationFunctionThread (void *argument);                   // thread function
 
int Init_vRealizationFunctionThread  (osPriority_t priority) {
 
  tid_vRealizationFunctionThread = osThreadNew(vRealizationFunctionThread, NULL, NULL);
	osThreadSetPriority (tid_vRealizationFunctionThread, priority);
  if (tid_vRealizationFunctionThread == NULL) {
    return(-1);
  }
 
  return(0);
}
 
void vRealizationFunctionThread (void *argument) {
 	osStatus_t status;
	int tick=0;
	
	int receiveData=0;
	
  while (1) {
		
			if(taskCommunicationQueues->xQueueReceive(&receiveData, osWaitForever) == osOK){
				if(receiveData==qMARK_ATC){
					if(taskCommunicationQueues->xQueueReceive(&receiveData, osWaitForever) == osOK){
						switch(receiveData){
							case AT_TAG_TRVV:
								if(taskCommunicationQueues->xQueueReceive(&receiveData, osWaitForever) == osOK){
									map<char, int>values;
									taskCommunicationQueues->xQueueReceiveMap(values, receiveData, osWaitForever);
									
									motorsAlgorithms->setParToDriveForValue(values);
									motorsAlgorithms->drive();
									
								}
								break;
							case AT_TAG_TRVCO:
								if(taskCommunicationQueues->xQueueReceive(&receiveData, osWaitForever) == osOK){
									map<char, int>values;
									taskCommunicationQueues->xQueueReceiveMap(values, receiveData, osWaitForever);
									motorsAlgorithms->setParToDriveToBaseCoordinates(values);
									motorsAlgorithms->drive();	
								}
								break;			
							
							
							
						}
						
						
						
					}
					
				}			
	
		}
  }
}
