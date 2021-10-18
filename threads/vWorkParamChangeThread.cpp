#include "cmsis_os2.h"                          // CMSIS RTOS header file
 #include "input_signals.h"
 #include "button_marks.h"
/*----------------------------------------------------------------------------
 *      Thread 1 'Thread_Name': Sample thread
 *---------------------------------------------------------------------------*/
 
 extern osMessageQueueId_t qToDoMarkWorkParam;
 
osThreadId_t tid_vWorkParamChangeThread;                        // thread id
 
void vWorkParamChangeThread (void *argument);                   // thread function
 
int Init_vWorkParamChangeThread  (osPriority_t priority) {
 
  tid_vWorkParamChangeThread = osThreadNew(vWorkParamChangeThread, NULL, NULL);
	osThreadSetPriority (tid_vWorkParamChangeThread, priority);
  if (tid_vWorkParamChangeThread == NULL) {
    return(-1);
  }
 
  return(0);
}
 
void vWorkParamChangeThread (void *argument) {
 	osStatus_t status;
	
	defOButtonMarks oButtonMarks=defOButtonMarks();
	int mark=0;
	
  while (1) {
			status=osMessageQueueGet(qToDoMarkWorkParam, &mark, NULL, osWaitForever);
			if(status == osOK){
				bool changeParam=false, changeGenerParam=false;	
				
				oButtonMarks.decodeToDoMark(mark);
				
//								//sprawdzenie parametrów
//				if((oAutWork.focusParam==FOCUSthreshOfWork && oButtonMarks.toDoMark.tag=='-') || oButtonMarks.toDoMark.key==KEY_PPm){ 		
//						oAutWork.decrementParamByValue(&oAutWork.autWorkParam->threshOfWork, oAutWork.autWorkParam->threshOfWork.precision);
//				}else if((oAutWork.focusParam==FOCUSthreshOfWork && oButtonMarks.toDoMark.tag=='+') || oButtonMarks.toDoMark.key==KEY_PPp){	
//						oAutWork.incrementParamByValue(&oAutWork.autWorkParam->threshOfWork, oAutWork.autWorkParam->threshOfWork.precision);
//				}else if((oAutWork.focusParam==FOCUSthreshOfCircuit && oButtonMarks.toDoMark.tag=='-') || oButtonMarks.toDoMark.key==KEY_PZm){	
//						oAutWork.decrementParamByValue(&oAutWork.autWorkParam->threshOfCircuit, oAutWork.autWorkParam->threshOfCircuit.precision);
//				}else if((oAutWork.focusParam==FOCUSthreshOfCircuit && oButtonMarks.toDoMark.tag=='+') || oButtonMarks.toDoMark.key==KEY_PZp){ 	
//						oAutWork.incrementParamByValue(&oAutWork.autWorkParam->threshOfCircuit, oAutWork.autWorkParam->threshOfCircuit.precision);
//				}else if((oAutWork.focusParam==FOCUStimeOfImpulse && oButtonMarks.toDoMark.tag=='-') || oButtonMarks.toDoMark.key==KEY_Im){ 	
//						if(oAutWork.decrementParamByValue(&oAutWork.autWorkParam->timeOfImpulse, oAutWork.autWorkParam->timeOfImpulse.precision))xSemaphoreGive(xGenerSend);
//				}else if((oAutWork.focusParam==FOCUStimeOfImpulse && oButtonMarks.toDoMark.tag=='+') || oButtonMarks.toDoMark.key==KEY_Ip){ 
//						if(oAutWork.incrementParamByValue(&oAutWork.autWorkParam->timeOfImpulse, oAutWork.autWorkParam->timeOfImpulse.precision))xSemaphoreGive(xGenerSend);
//				}else if((oAutWork.focusParam==FOCUStimeOfBreak && oButtonMarks.toDoMark.tag=='-') || oButtonMarks.toDoMark.key==KEY_Przm){ 	
//						if(oAutWork.decrementParamByValue(&oAutWork.autWorkParam->timeOfBreak, 5*oAutWork.autWorkParam->timeOfBreak.precision))xSemaphoreGive(xGenerSend);
//				}else if((oAutWork.focusParam==FOCUStimeOfBreak && oButtonMarks.toDoMark.tag=='+') || oButtonMarks.toDoMark.key==KEY_Przp){	
//						if(oAutWork.incrementParamByValue(&oAutWork.autWorkParam->timeOfBreak, 5*oAutWork.autWorkParam->timeOfBreak.precision))xSemaphoreGive(xGenerSend);
//				}else if((oAutWork.focusParam==FOCUSwireFeed && oButtonMarks.toDoMark.tag=='-') || oButtonMarks.toDoMark.key==KEY_PDm){ 		
//						if(oAutWork.decrementParamByValue(&oAutWork.autWorkParam->wireFeed, oAutWork.autWorkParam->wireFeed.precision)){
//							oWireHead.command=WIRE_HEAD_COMMAND_AT_PAR;
//							xQueueSendToBack(qWireHeadSendCommand, &oWireHead.command, 0);
//						}
//				}else if((oAutWork.focusParam==FOCUSwireFeed && oButtonMarks.toDoMark.tag=='+') || oButtonMarks.toDoMark.key==KEY_PDp){ 	
//						if(oAutWork.incrementParamByValue(&oAutWork.autWorkParam->wireFeed, oAutWork.autWorkParam->wireFeed.precision)){
//							oWireHead.command=WIRE_HEAD_COMMAND_AT_PAR;
//							xQueueSendToBack(qWireHeadSendCommand, &oWireHead.command, 0);
//						}
//				}else if((oAutWork.focusParam==FOCUSwireTension && oButtonMarks.toDoMark.tag=='-') || oButtonMarks.toDoMark.key==KEY_NDm){ 
//						if(oAutWork.decrementParamByValue(&oAutWork.autWorkParam->wireTension, oAutWork.autWorkParam->wireTension.precision)){
//							oWireHead.command=WIRE_HEAD_COMMAND_AT_PAR;
//							xQueueSendToBack(qWireHeadSendCommand, &oWireHead.command, 0);
//						}
//				}else if((oAutWork.focusParam==FOCUSwireTension && oButtonMarks.toDoMark.tag=='+') || oButtonMarks.toDoMark.key==KEY_NDp){ 	
//						if(oAutWork.incrementParamByValue(&oAutWork.autWorkParam->wireTension, oAutWork.autWorkParam->wireTension.precision)){
//							oWireHead.command=WIRE_HEAD_COMMAND_AT_PAR;
//							xQueueSendToBack(qWireHeadSendCommand, &oWireHead.command, 0);
//						}
//				}else if((oDrive.focusFeedrate==FOCUSfeedrate && oButtonMarks.toDoMark.tag=='-') || oButtonMarks.toDoMark.key==KEY_Posm){ 
//						oAutWork.decrementParamByValue(&oDrive.feedrate->feed.velocityUMperSEC, oDrive.feedrate->feed.velocityUMperSEC.precision);
//						oDrive.feedrate->feed.auxVelocityUMperSEC=oDrive.feedrate->feed.velocityUMperSEC.value;
//				}else if((oDrive.focusFeedrate==FOCUSfeedrate && oButtonMarks.toDoMark.tag=='+') || oButtonMarks.toDoMark.key==KEY_Posp){ 
//						oAutWork.incrementParamByValue(&oDrive.feedrate->feed.velocityUMperSEC, oDrive.feedrate->feed.velocityUMperSEC.precision);
//						oDrive.feedrate->feed.auxVelocityUMperSEC=oDrive.feedrate->feed.velocityUMperSEC.value;
//				}else if((oDrive.focusFeedrate==FOCUSfeedrateJog && oButtonMarks.toDoMark.tag=='-') || oButtonMarks.toDoMark.key==KEY_Posrm){ 
//						oAutWork.decrementParamByValue(&oDrive.feedrate->feedJog.velocityUMperSEC, oDrive.feedrate->feedJog.velocityUMperSEC.precision);
//						oDrive.feedrate->feedJog.auxVelocityUMperSEC=oDrive.feedrate->feedJog.velocityUMperSEC.value;
//				}else if((oDrive.focusFeedrate==FOCUSfeedrateJog && oButtonMarks.toDoMark.tag=='+') || oButtonMarks.toDoMark.key==KEY_Posrp){ 
//						oAutWork.incrementParamByValue(&oDrive.feedrate->feedJog.velocityUMperSEC, oDrive.feedrate->feedJog.velocityUMperSEC.precision);
//						oDrive.feedrate->feedJog.auxVelocityUMperSEC=oDrive.feedrate->feedJog.velocityUMperSEC.value;
//				}
//				
//					if(changeGenerParam){
//						osSemaphoreRelease (xGenerSend); 
//					}
//					if(changeParam){
//						osSemaphoreRelease(xPP16sterSend); 
//					}
				
			}
  }
}
