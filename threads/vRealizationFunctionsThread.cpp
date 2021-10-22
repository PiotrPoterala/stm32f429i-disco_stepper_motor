#include "cmsis_os2.h"                          // CMSIS RTOS header file
 #include "input_signals.h"
 //#include "button_marks.h"
/*----------------------------------------------------------------------------
 *      Thread 1 'Thread_Name': Sample thread
 *---------------------------------------------------------------------------*/
 
 extern osMessageQueueId_t qToDoMark;
 
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
	
//	defOButtonMarks oButtonMarks=defOButtonMarks();
//	int mark=0;
//	
//  while (1) {
//			status=osMessageQueueGet(qToDoMark, &mark, NULL, osWaitForever);
//			if(status == osOK){
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
//			tick = osKernelGetTickCount(); 

//		(*infoDrive)=DRIVE_IN_PROGRESS;
//		oCoordinates->setCoord(&driveParam->indirectCoord, driveParam->pointB);
//			
//		while((*infoDrive)!=PRZEJ_ZREALIZOWANO && (*infoDrive)!=PRZEJ_PORZUCONO){		

//			driveTIM();

//			status=osMessageQueueGet(qToDoMark, &mark, NULL, 0);
//			if(status == osOK){
//				oButtonMarks.decodeToDoMark(mark);

//				if(oButtonMarks.toDoMark.tag==TAG_MENU_PODR_1 || oButtonMarks.toDoMark.tag==TAG_ESC || oButtonMarks.toDoMark.atc==AT_TAG_STOP ||
//						oButtonMarks.toDoMark.key==KEY_STOP || oButtonMarks.toDoMark.key==KEY_F1 || oButtonMarks.toDoMark.key==KEY_ESC){
//					brakingDrive(&oCoordinates->phyCoord.X, driveParam->pointA.X.value, driveParam->pointB.X.value, &driveParam->indirectCoord.X.value, feedrateJog);
//					brakingDrive(&oCoordinates->phyCoord.Y, driveParam->pointA.Y.value, driveParam->pointB.Y.value, &driveParam->indirectCoord.Y.value, feedrateJog);
//					brakingDrive(&oCoordinates->phyCoord.Z, driveParam->pointA.Z.value, driveParam->pointB.Z.value, &driveParam->indirectCoord.Z.value, feedrateJog);
//					brakingDrive(&oCoordinates->phyCoord.U, driveParam->pointA.U.value, driveParam->pointB.U.value, &driveParam->indirectCoord.U.value, feedrateJog);
//					brakingDrive(&oCoordinates->phyCoord.V, driveParam->pointA.V.value, driveParam->pointB.V.value, &driveParam->indirectCoord.V.value, feedrateJog);
//					brakingDrive(&oCoordinates->phyCoord.Zw, driveParam->pointA.Zw.value, driveParam->pointB.Zw.value, &driveParam->indirectCoord.Zw.value, feedrateJog);
//				}

//			}


//			if((*infoDrive)==PRZEJ_SPAUZOWANO){		
//				stopDrive(oCoordinates, oMenu, driveParam, infoDrive, language, qToDoMark);	
//				taskCount=xTaskGetTickCount();
//			}

//			osDelayUntil(tick += pd100US_TO_TICKS(10000/BASE_FREQUENCY_OF_TIMdrive));
//		}
//		
//		oCheckSignalsLimitedStop->madeSignals=0;
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
				
				
//		}
//  }
}
