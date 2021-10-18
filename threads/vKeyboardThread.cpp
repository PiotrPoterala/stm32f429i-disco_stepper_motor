
#include "cmsis_os2.h"                                               // CMSIS RTOS header file
#include "keyboard.h"
#include "keys.h"
#include "button_marks.h"
//#include "tools.h"


extern osMessageQueueId_t qToDoMark;   
extern osMessageQueueId_t qToDoMarkWorkParam;


//extern defOItems oPowerErrors;
//extern defOItems oTankErrors;
//extern defOItems oEquipmentDetect;
//extern defOTools oTools;
extern defOKeyboard oKeyboard;
//extern defOAutWork oAutWork;

/*----------------------------------------------------------------------------
 *      Thread 1 'Thread_Name': Sample thread
 *---------------------------------------------------------------------------*/
 
void vKeyboardThread (void *argument);                             // thread function
osThreadId_t tid_vKeyboardThread;                                          // thread id                 // thread object

int Init_KeyboardThread (osPriority_t priority) {

  tid_vKeyboardThread = osThreadNew(vKeyboardThread, NULL, NULL);
	osThreadSetPriority (tid_vKeyboardThread, priority);
  if (!tid_vKeyboardThread) return(-1);
  
  return(0);
}

void vKeyboardThread (void *argument) {
	uint32_t auxKey=0;
	uint32_t tick=0;
	osDelay(100);
	
	tick = osKernelGetTickCount(); 
  while (1) {
		

		oKeyboard.readKeyboard();

		//sprawdzanie klawiatury
//		if((oKeyboard.KBRs.KBPFR==KEY_KROPKA || oKeyboard.KBRs.KBPFR==KEY_1 || oKeyboard.KBRs.KBPFR==KEY_2 || oKeyboard.KBRs.KBPFR==KEY_3 || oKeyboard.KBRs.KBPFR==KEY_4 || 
//								oKeyboard.KBRs.KBPFR==KEY_5 || oKeyboard.KBRs.KBPFR==KEY_6 || oKeyboard.KBRs.KBPFR==KEY_7 || oKeyboard.KBRs.KBPFR==KEY_8 || oKeyboard.KBRs.KBPFR==KEY_9) && 
//							(!oDrive.allDriveConditionParam.activeDirectionDriveConditional) && (oDrive.drivePathParam.activeDrivePath==NONE_DRIVE || oDrive.drivePathParam.activeDrivePath==PAUSE_DRIVE) &&
//							(oScreen.windows[mainWINDOW].idScreen!=idINPUT_SCREEN && oScreen.windows[mainWINDOW].idScreen!=idINPUT_PIN_SCREEN && 
//							oScreen.windows[mainWINDOW].idScreen!=idINPUT_PROG_NAME_SCREEN && oScreen.windows[mainWINDOW].idScreen!=idINPUT_CONTACT_SCREEN &&
//							oScreen.windows[mainWINDOW].idScreen!=idINPUT_DB_REG_SCREEN && oScreen.windows[mainWINDOW].idScreen!=idINPUT_APN_SCREEN && oScreen.windows[mainWINDOW].idScreen!=idDRIVE_SCREEN)){	
//			auxKey=oKeyboard.KBRs.KBPFR | qMARK_KEY;
//			xQueueSendToBack(qToDoMarkDriveConditional, &auxKey, 0);
//		}

		if(oKeyboard.KBR){
			auxKey=oKeyboard.KBR | qMARK_KEY;

			if(oKeyboard.KBR==KEY_Posm || oKeyboard.KBR==KEY_Posp || oKeyboard.KBR==KEY_Posrm || oKeyboard.KBR==KEY_Posrp){
				osMessageQueuePut(qToDoMarkWorkParam, &auxKey, 0, 0); 
//			}else if((oMenu.menuParam.menu==MENU_AUTOMATYCZNA || oMenu.menuParam.menu==MENU_TOOLS_FROM_HAND || oMenu.menuParam.menu==MENU_TOOLS_FROM_AUT || oMenu.menuParam.menu==AUT_WORK_ADD_FUN ||
//				oMenu.menuParam.menu==MENU_PARAMETERS_FROM_AUT || oMenu.menuParam.menu==MENU_CHANGE_PARAMETER_FROM_AUT || oMenu.menuParam.menu==VISUALIZATION ) && 
//				(oKeyboard.KBRs.KBR==KEY_F1 || oKeyboard.KBRs.KBR==KEY_F2 || oKeyboard.KBRs.KBR==KEY_F3 || oKeyboard.KBRs.KBR==KEY_F4 || oKeyboard.KBRs.KBR==KEY_STOP)){
//				xQueueSendToBack(qToDoMarkDrivePath, &auxKey, 0);
//			}else if(oDrive.allDriveConditionParam.activeDirectionDriveConditional){
//				auxKey=qMARK_KEY;
//				xQueueSendToBack(qToDoMarkDriveConditional, &auxKey, 0);
			}else{
//				xQueueSendToBackWithSemaphore(auxKey, qToDoMark, xToDoMark);
			}

			oKeyboard.KBR=0;
		}

			osDelayUntil(tick += 50);
		
		
  }
}
