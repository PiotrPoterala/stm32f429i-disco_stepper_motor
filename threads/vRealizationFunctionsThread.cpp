#include "cmsis_os2.h"                          // CMSIS RTOS header file
#include "pp_rtx5_queue.h"
#include "pp_rtx5_at_commands_interpreter.h"
#include "at_tags.h"
#include "pp_rtx5_drive_algorithms.h"
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
//				
//				oButtonMarks.decodeToDoMark(mark);
//				
//				
//				////PRACA RĘCZNA 
//	//przejazd o wartosc
//		if(oMenu.menuParam.menu==O_WARTOSC){	
//			SCoordinates aCoord;
//			uint8_t ans=0;

//			aCoord=oCoordinates.getCoordWithSemaphore(&oCoordinates.auxCoord, oCoordinates.xAuxCoord);
//			ans=oDataInput.axisSelectEntryField(&aCoord, qToDoMark, oDataInput.entryFieldsList[0], &oButtonMarks, &oScreen.windows[mainWINDOW].markEntryField);

//			if(ans==WPISANO_LICZBE){
//				oCoordinates.setCoordWithSemaphore(&oCoordinates.auxCoord, aCoord, oCoordinates.xAuxCoord);					
//			}else if(oButtonMarks.tag==TAG_MENU_PODR_1 || oButtonMarks.key==KEY_F1 || oButtonMarks.atc==AT_TAG_TRVV){
//				
//			
//				
//				
//				
//				xSemaphoreTake(xDrive, portMAX_DELAY);
//				{	
//					oMenu.setPopupMenu(&oMenu.menuParam, MENU_STOP, oLanguage.itemsParam.item);
//					oScreen.windows[mainWINDOW].basicInfo.itemsParam.item=LACK_ofIdBASIC_INFO;
//					oScreen.windows[mainWINDOW].idScreen=idDRIVE_SCREEN;
//					oDrive.driveForValue(&oCoordinates, &oCheckSignalsLimitedStop, &oDrive.driveParam, &oDrive.infoDrive, &oMenu, oLanguage.itemsParam.item, qToDoMark, &oDrive.feedrate->feedJog);

//					oDrive.circuitIgnorance=true;
//					oCoordinates.clearCoord(&oCoordinates.auxCoord);
//					oMenu.setPopupMenu(&oMenu.menuParam, MENU_GO, oLanguage.itemsParam.item);
//					oScreen.windows[mainWINDOW].idScreen=idINPUT_SCREEN;
//					oDrive.infoDrive=PRZEJ_ZREALIZOWANO;
//				}
//				xSemaphoreGive(xDrive);
//			}else if(ans==NIE_OZN_WSP_DO_WPISU){
//				oMenu.escMenu(&oMenu.menuParam, ESC_COND, &oScreen.windows[mainWINDOW].highlightedY, &oScreen.windows[mainWINDOW].highlightedX, oLanguage.itemsParam.item);
//			}
//			
//		}	
				
//				if(oMenu.menuParam.menu==WSPOLRZEDNE_BAZY){	
//					SCoordinates aCoord;
//					uint8_t ans=0;
//					aCoord=oCoordinates.getCoordWithSemaphore(&oCoordinates.auxCoord, oCoordinates.xAuxCoord);

//					ans=oDataInput.axisSelectEntryField(&aCoord, qToDoMark, oDataInput.entryFieldsList[0], &oButtonMarks, &oScreen.windows[mainWINDOW].markEntryField);

//					if(ans==WPISANO_LICZBE){
//						oCoordinates.setCoordWithSemaphore(&oCoordinates.auxCoord, aCoord, oCoordinates.xAuxCoord);					
//					}else if(oButtonMarks.tag==TAG_MENU_PODR_1 || oButtonMarks.toDoMark.key==KEY_F1 || oButtonMarks.toDoMark.atc==AT_TAG_BASEC){
//						oCoordinates.setCoordWithSemaphore(&oCoordinates.baseCoord, aCoord, oCoordinates.xBaseCoord);		
//						oMenu.escMenu(&oMenu.menuParam, true, &oScreen.windows[mainWINDOW].highlightedY, &oScreen.windows[mainWINDOW].highlightedX, oLanguage.itemsParam.item);
//					}else if(oButtonMarks.toDoMark.tag==TAG_MENU_PODR_2 || oButtonMarks.toDoMark.key==KEY_F2){
//						oCoordinates.clearCoord(&aCoord);
//						oCoordinates.setCoordWithSemaphore(&oCoordinates.auxCoord, aCoord, oCoordinates.xAuxCoord);
//					}else if(ans==NIE_OZN_WSP_DO_WPISU){
//						oMenu.escMenu(&oMenu.menuParam, ESC_COND, &oScreen.windows[mainWINDOW].highlightedY, &oScreen.windows[mainWINDOW].highlightedX, oLanguage.itemsParam.item);
//					}

//				}		

//			//ustawienie współrzędnych fizycznych				
//				else if(oMenu.menuParam.menu==WSPOLRZEDNE_FIZYCZNE){	
//					SCoordinates aCoord;
//					uint8_t ans=0;
//					aCoord=oCoordinates.getCoordWithSemaphore(&oCoordinates.auxCoord, oCoordinates.xAuxCoord);

//					ans=oDataInput.axisSelectEntryField(&aCoord, qToDoMark, oDataInput.entryFieldsList[0], &oButtonMarks, &oScreen.windows[mainWINDOW].markEntryField);

//					if(ans==WPISANO_LICZBE){
//						oCoordinates.setCoordWithSemaphore(&oCoordinates.auxCoord, aCoord, oCoordinates.xAuxCoord);					
//					}else if(oButtonMarks.toDoMark.tag==TAG_MENU_PODR_1 || oButtonMarks.toDoMark.key==KEY_F1 || oButtonMarks.toDoMark.atc==AT_TAG_PHYC){
//						oCoordinates.setCoordWithSemaphore(&oCoordinates.phyCoord, aCoord, oCoordinates.xPhyCoord);		
//						oMenu.escMenu(&oMenu.menuParam, true, &oScreen.windows[mainWINDOW].highlightedY, &oScreen.windows[mainWINDOW].highlightedX, oLanguage.itemsParam.item);
//					}else if(oButtonMarks.toDoMark.tag==TAG_MENU_PODR_2 || oButtonMarks.toDoMark.key==KEY_F2){
//						oCoordinates.setCoordByValue(&aCoord, 100);
//						oCoordinates.setCoordWithSemaphore(&oCoordinates.auxCoord, aCoord, oCoordinates.xAuxCoord);
//					}else if(ans==NIE_OZN_WSP_DO_WPISU){
//						oMenu.escMenu(&oMenu.menuParam, ESC_COND, &oScreen.windows[mainWINDOW].highlightedY, &oScreen.windows[mainWINDOW].highlightedX, oLanguage.itemsParam.item);
//			
//				}

//			}
				
				
		}
  }
}
