/*----------------------------------------------------------------------------
 * CMSIS-RTOS 'main' function template
 *---------------------------------------------------------------------------*/
 
#include "RTE_Components.h"
#include  CMSIS_device_header
#include "cmsis_os2.h"
#include "math.h"

#include <map>
 
#include "config.h"
#include "def_pins.h"
#include "pp_param.h"
#include "pp_paramlist.h"
#include "pp_stepper_motor_driver.h"
#include "pp_stepper_motor_driver.h"

#define COORD_PRECISION 1250				//w rzeczywistości 0,001250
#define COORD_UNIT 6	

#define MIN_PHY_COORD_MM		0
#define MIN_BASE_COORD_MM	(-999)
#define MAX_PHY_COORD_MM		999
#define MAX_BASE_COORD_MM		999


extern int Init_vSecondThread (osPriority_t priority);
extern int Init_KeyboardThread (osPriority_t priority); 
extern int Init_vCheckInputSignalsThread (osPriority_t priority); 
extern int Init_vWorkParamChangeThread  (osPriority_t priority);
extern int Init_vRealizationFunctionThread  (osPriority_t priority);

osMessageQueueId_t qToDoMark;   
osMessageQueueId_t qToDoMarkWorkParam;



defOParamList *auxCoord;
defOParamList *phyCoord;
defOParamList *baseCoord;
//vector<defOParamList*> gBaseList;


//vector<defOMotorDriver*> motors;

map<string, string> *strings;


int main (void) {
	
  // System Initialization
	RCC_Config();
	NVIC_Config();
	GPIO_Config();
	USART_Config();
	
	
	
	
//	phyCoord=new defOParamList();
//	phyCoord->getParams()->insert(pair<char, defOParam*>('X', new defOParam("X", PHY_COORD_X_BKP, 100*pow(10.0, COORD_UNIT), COORD_PRECISION, COORD_UNIT, MIN_PHY_COORD_MM, MAX_PHY_COORD_MM*pow(10.0, COORD_UNIT))));
//	phyCoord->getParams()->insert(pair<char, defOParam*>('Y', new defOParam("Y", PHY_COORD_Y_BKP, 100*pow(10.0, COORD_UNIT), COORD_PRECISION, COORD_UNIT, MIN_PHY_COORD_MM, MAX_PHY_COORD_MM*pow(10.0, COORD_UNIT))));

//	baseCoord=new defOParamList();
//	baseCoord->getParams()->insert(pair<char, defOParam*>('X', new defOParam("X", PHY_COORD_X_BKP, 100*pow(10.0, COORD_UNIT), COORD_PRECISION, COORD_UNIT, MIN_PHY_COORD_MM, MAX_PHY_COORD_MM*pow(10.0, COORD_UNIT))));
//	baseCoord->getParams()->insert(pair<char, defOParam*>('Y', new defOParam("Y", PHY_COORD_Y_BKP, 100*pow(10.0, COORD_UNIT), COORD_PRECISION, COORD_UNIT, MIN_PHY_COORD_MM, MAX_PHY_COORD_MM*pow(10.0, COORD_UNIT))));

//	motors.push_back(new defOPlatformParallelMotorDriver(phyCoord->getParamPair('Y'), baseCoord->getParamPair('Y'), GPIOB, new array<int, 2>{Pin15, Pin14}, GPIOE, new array<int, 8>{Pin11, Pin10, Pin9, Pin8, Pin12, Pin13, Pin14, Pin15}, MICRO_STEP, 0));
//	motors.push_back(new defOPlatformParallelMotorDriver(phyCoord->getParamPair('X'), baseCoord->getParamPair('X'), GPIOB, new array<int, 2>{Pin13, Pin12}, GPIOD, new array<int, 8>{Pin11, Pin10, Pin9, Pin8, Pin12, Pin13, Pin14, Pin15}, MICRO_STEP, 0));

//    for(int i=0; i<5; i++){
//        gBaseList.push_back(phyCoord->clone());
//    }


  osKernelInitialize();                 // Initialize CMSIS-RTOS
	
	qToDoMark = osMessageQueueNew(256, sizeof(unsigned int), NULL);
	qToDoMarkWorkParam = osMessageQueueNew(16, sizeof(unsigned int), NULL);
	
  Init_vSecondThread(osPriorityLow);   
	Init_vCheckInputSignalsThread (osPriorityHigh);
	Init_vRealizationFunctionThread(osPriorityNormal);
	
	
  osKernelStart();                      // Start thread execution
  for (;;) {}
}
