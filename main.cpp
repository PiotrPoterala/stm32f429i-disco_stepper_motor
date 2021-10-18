/*----------------------------------------------------------------------------
 * CMSIS-RTOS 'main' function template
 *---------------------------------------------------------------------------*/
 
#include "RTE_Components.h"
#include  CMSIS_device_header
#include "cmsis_os2.h"
#include "math.h"

#include <map>
 
#include "config.h"
#include "keyboard.h"
#include "input_signals_analysis.h"
#include "paramlist.h"
#include "backup.h"
#include "strings-pl.h"
#include "aut_work_param_WEDM.h"
#include "motor_parallel_driver.h"
#include "platform_motor_parallel_driver.h"

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
vector<defOParamList*> gBaseList;

defOParamList *autWorkParam;
defOParamList *autWorkWEDMparam;
defOParamList *autWorkDEDMparam;
defOParamList *autWorkAuxParam;

defOKeyboard oKeyboard=defOKeyboard(PORT_KLAW, B_LOW);
defOCheckSignals oCheckSignalsLimitedStop=defOCheckSignals();

vector<defOMotorDriver*> motors;

map<string, string> *strings;


int main (void) {
	
  // System Initialization
	RCC_Config();
	RTC_Config();
	NVIC_Config();
	GPIO_Config();
	USART_Config();
	BKP_Config();
	EXTI_Config();
	
	
	strings=&stringsPL;
	
	
	phyCoord=new defOParamList();
	phyCoord->getParams()->insert(pair<char, defOParam*>('X', new defOParam("X", PHY_COORD_X_BKP, 100*pow(10.0, COORD_UNIT), COORD_PRECISION, COORD_UNIT, MIN_PHY_COORD_MM, MAX_PHY_COORD_MM*pow(10.0, COORD_UNIT))));
	phyCoord->getParams()->insert(pair<char, defOParam*>('Y', new defOParam("Y", PHY_COORD_Y_BKP, 100*pow(10.0, COORD_UNIT), COORD_PRECISION, COORD_UNIT, MIN_PHY_COORD_MM, MAX_PHY_COORD_MM*pow(10.0, COORD_UNIT))));
	phyCoord->getParams()->insert(pair<char, defOParam*>('Z', new defOParam("Z", PHY_COORD_Z_BKP, 100*pow(10.0, COORD_UNIT), COORD_PRECISION, COORD_UNIT, MIN_PHY_COORD_MM, MAX_PHY_COORD_MM*pow(10.0, COORD_UNIT))));
	phyCoord->getParams()->insert(pair<char, defOParam*>('U', new defOParam("U", PHY_COORD_U_BKP, 100*pow(10.0, COORD_UNIT), COORD_PRECISION, COORD_UNIT, MIN_PHY_COORD_MM, MAX_PHY_COORD_MM*pow(10.0, COORD_UNIT))));
	phyCoord->getParams()->insert(pair<char, defOParam*>('V', new defOParam("V", PHY_COORD_V_BKP, 100*pow(10.0, COORD_UNIT), COORD_PRECISION, COORD_UNIT, MIN_PHY_COORD_MM, MAX_PHY_COORD_MM*pow(10.0, COORD_UNIT))));
	phyCoord->getParams()->insert(pair<char, defOParam*>('z', new defOParam("Zw", PHY_COORD_ZW_BKP, 100*pow(10.0, COORD_UNIT), COORD_PRECISION, COORD_UNIT, MIN_PHY_COORD_MM, MAX_PHY_COORD_MM*pow(10.0, COORD_UNIT))));

	baseCoord=new defOParamList();
	baseCoord->getParams()->insert(pair<char, defOParam*>('X', new defOParam("X", PHY_COORD_X_BKP, 100*pow(10.0, COORD_UNIT), COORD_PRECISION, COORD_UNIT, MIN_PHY_COORD_MM, MAX_PHY_COORD_MM*pow(10.0, COORD_UNIT))));
	baseCoord->getParams()->insert(pair<char, defOParam*>('Y', new defOParam("Y", PHY_COORD_Y_BKP, 100*pow(10.0, COORD_UNIT), COORD_PRECISION, COORD_UNIT, MIN_PHY_COORD_MM, MAX_PHY_COORD_MM*pow(10.0, COORD_UNIT))));
	baseCoord->getParams()->insert(pair<char, defOParam*>('Z', new defOParam("Z", PHY_COORD_Z_BKP, 100*pow(10.0, COORD_UNIT), COORD_PRECISION, COORD_UNIT, MIN_PHY_COORD_MM, MAX_PHY_COORD_MM*pow(10.0, COORD_UNIT))));
	baseCoord->getParams()->insert(pair<char, defOParam*>('U', new defOParam("U", PHY_COORD_U_BKP, 100*pow(10.0, COORD_UNIT), COORD_PRECISION, COORD_UNIT, MIN_PHY_COORD_MM, MAX_PHY_COORD_MM*pow(10.0, COORD_UNIT))));
	baseCoord->getParams()->insert(pair<char, defOParam*>('V', new defOParam("V", PHY_COORD_V_BKP, 100*pow(10.0, COORD_UNIT), COORD_PRECISION, COORD_UNIT, MIN_PHY_COORD_MM, MAX_PHY_COORD_MM*pow(10.0, COORD_UNIT))));
	baseCoord->getParams()->insert(pair<char, defOParam*>('z', new defOParam("Zw", PHY_COORD_ZW_BKP, 100*pow(10.0, COORD_UNIT), COORD_PRECISION, COORD_UNIT, MIN_PHY_COORD_MM, MAX_PHY_COORD_MM*pow(10.0, COORD_UNIT))));

	motors.push_back(new defOPlatformParallelMotorDriver(phyCoord->getParamPair('Y'), baseCoord->getParamPair('Y'), GPIOB, new array<int, 2>{Pin15, Pin14}, GPIOE, new array<int, 8>{Pin11, Pin10, Pin9, Pin8, Pin12, Pin13, Pin14, Pin15}, MICRO_STEP, 0));
	motors.push_back(new defOPlatformParallelMotorDriver(phyCoord->getParamPair('X'), baseCoord->getParamPair('X'), GPIOB, new array<int, 2>{Pin13, Pin12}, GPIOD, new array<int, 8>{Pin11, Pin10, Pin9, Pin8, Pin12, Pin13, Pin14, Pin15}, MICRO_STEP, 0));
	motors.push_back(new defOPlatformParallelMotorDriver(phyCoord->getParamPair('Z'), baseCoord->getParamPair('Z'), GPIOB, new array<int, 2>{Pin11, Pin10}, GPIOG, new array<int, 8>{Pin3, Pin2, Pin1, Pin0, Pin4, Pin5, Pin6, Pin7}));	
	motors.push_back(new defOPlatformParallelMotorDriver(phyCoord->getParamPair('V'), baseCoord->getParamPair('V'), GPIOF, new array<int, 2>{Pin14, Pin13}, GPIOD, new array<int, 8>{Pin3, Pin2, Pin1, Pin0, Pin4, Pin5, Pin6, Pin7}));
	motors.push_back(new defOPlatformParallelMotorDriver(phyCoord->getParamPair('U'), baseCoord->getParamPair('U'), GPIOF, new array<int, 2>{Pin12, Pin11}, GPIOG, new array<int, 8>{Pin11, Pin10, Pin9, Pin8, Pin12, Pin13, Pin14, Pin15}));	
	motors.push_back(new defOPlatformParallelMotorDriver(phyCoord->getParamPair('z'), baseCoord->getParamPair('z'), GPIOB, new array<int, 2>{Pin2, Pin1}, GPIOE, new array<int, 8>{Pin3, Pin2, Pin1, Pin0, Pin4, Pin5, Pin6, Pin7}));	
		
		
    for(int i=0; i<5; i++){
  //      auxCoord=new ParamList(*phyCoord->getParams());
        gBaseList.push_back(phyCoord->clone());
    }

//    auxCoord=new ParamList(*baseCoord->getParams());

	autWorkWEDMparam=new defOParamList();
	autWorkWEDMparam->getParams()->insert(pair<char, defOParam*>('T', new defOParam(strings->find("timeOfImpulse")->second, timeOfImpulse_DEFAULT_VALUE, timeOfImpulse_DEFAULT_VALUE, timeOfImpulsePRECISION, 3, timeOfImpulseMIN, timeOfImpulseMAX)));
	autWorkWEDMparam->getParams()->insert(pair<char, defOParam*>('t', new defOParam(strings->find("timeOfBreak")->second, timeOfBreak_DEFAULT_VALUE, timeOfBreak_DEFAULT_VALUE, timeOfBreakPRECISION, 3, timeOfBreakMIN, timeOfBreakMAX)));
	autWorkWEDMparam->getParams()->insert(pair<char, defOParam*>('P', new defOParam(strings->find("threshOfWork")->second, threshOfWork_DEFAULT_VALUE, threshOfWork_DEFAULT_VALUE, threshOfWorkPRECISION, 0, threshOfWorkMIN, threshOfWorkMAX)));
	autWorkWEDMparam->getParams()->insert(pair<char, defOParam*>('z', new defOParam(strings->find("threshOfCircuit")->second, threshOfCircuit_DEFAULT_VALUE, threshOfCircuit_DEFAULT_VALUE, threshOfCircuitPRECISION, 0, threshOfCircuitMIN, threshOfCircuitMAX)));
	autWorkWEDMparam->getParams()->insert(pair<char, defOParam*>('N', new defOParam(strings->find("wireTension")->second, wireTension_DEFAULT_VALUE, wireTension_DEFAULT_VALUE, wireTensionPRECISION, 0, wireTensionMIN, wireTensionMAX)));
	autWorkWEDMparam->getParams()->insert(pair<char, defOParam*>('D', new defOParam(strings->find("wireFeed")->second, wireFeed_DEFAULT_VALUE, wireFeed_DEFAULT_VALUE, wireFeedPRECISION, 0, wireFeedMIN, wireFeedMAX)));
	autWorkWEDMparam->getParams()->insert(pair<char, defOParam*>('a', new defOParam(strings->find("nrOfWorkTransistors")->second, nrOfWorkTransistors_DEFAULT_VALUE, nrOfWorkTransistors_DEFAULT_VALUE, nrOfWorkTransistorsPRECISION, 0, nrOfWorkTransistorsMIN, nrOfWorkTransistorsMAX)));
	autWorkWEDMparam->getParams()->insert(pair<char, defOParam*>('x', new defOParam(strings->find("nrOfImpulseInPack")->second, threshOfWork_DEFAULT_VALUE, threshOfWork_DEFAULT_VALUE, 1, 0, threshOfWorkMIN, threshOfWorkMAX)));
	autWorkWEDMparam->getParams()->insert(pair<char, defOParam*>('b', new defOParam(strings->find("timeOfBreakBetImpulseInPack")->second, threshOfWork_DEFAULT_VALUE, threshOfWork_DEFAULT_VALUE, 1, 0, threshOfWorkMIN, threshOfWorkMAX)));
	autWorkWEDMparam->getParams()->insert(pair<char, defOParam*>('F', new defOParam(strings->find("feed")->second, threshOfWork_DEFAULT_VALUE, threshOfWork_DEFAULT_VALUE, 1, 0, threshOfWorkMIN, threshOfWorkMAX)));
	autWorkWEDMparam->getParams()->insert(pair<char, defOParam*>('J', new defOParam(strings->find("jog")->second, threshOfWork_DEFAULT_VALUE, threshOfWork_DEFAULT_VALUE, 1, 0, threshOfWorkMIN, threshOfWorkMAX)));


	 
  osKernelInitialize();                 // Initialize CMSIS-RTOS
	
	qToDoMark = osMessageQueueNew(256, sizeof(unsigned int), NULL);
	qToDoMarkWorkParam = osMessageQueueNew(16, sizeof(unsigned int), NULL);
	
	Init_KeyboardThread(osPriorityNormal);
  Init_vSecondThread(osPriorityLow);   
	Init_vCheckInputSignalsThread (osPriorityHigh);
	Init_vWorkParamChangeThread(osPriorityNormal); 
	Init_vRealizationFunctionThread(osPriorityNormal);
	
	
	
  osKernelStart();                      // Start thread execution
  for (;;) {}
}
