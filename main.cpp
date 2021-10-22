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
#include "pp_control_coordinate_decorator.h"
#include "pp_stepper_motor_2clock_driver.h"
#include "pp_control_2clock_signals_decorator.h"

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


defOParamList *phyCoord;
defOParamList *baseCoord;


vector<defOStepperMotorDriver*> motors;

map<string, string> *strings;


int main (void) {
	
  // System Initialization
	RCC_Config();
	NVIC_Config();
	GPIO_Config();
	USART_Config();
	
	
	phyCoord=new defOParamList();
	phyCoord->getParams()->insert(pair<char, defOParam*>('X', new defOParam("X", 0, 100*pow(10.0, COORD_UNIT), COORD_PRECISION, COORD_UNIT, MIN_PHY_COORD_MM, MAX_PHY_COORD_MM*pow(10.0, COORD_UNIT))));
	phyCoord->getParams()->insert(pair<char, defOParam*>('Y', new defOParam("Y", 0, 100*pow(10.0, COORD_UNIT), COORD_PRECISION, COORD_UNIT, MIN_PHY_COORD_MM, MAX_PHY_COORD_MM*pow(10.0, COORD_UNIT))));

	baseCoord=new defOParamList();
	baseCoord->getParams()->insert(pair<char, defOParam*>('X', new defOParam("X", 0, 100*pow(10.0, COORD_UNIT), COORD_PRECISION, COORD_UNIT, MIN_PHY_COORD_MM, MAX_PHY_COORD_MM*pow(10.0, COORD_UNIT))));
	baseCoord->getParams()->insert(pair<char, defOParam*>('Y', new defOParam("Y", 0, 100*pow(10.0, COORD_UNIT), COORD_PRECISION, COORD_UNIT, MIN_PHY_COORD_MM, MAX_PHY_COORD_MM*pow(10.0, COORD_UNIT))));

	motors.push_back(new defOControl2ClockSignalsDecorator(new defOControlCoordinateDecorator( new defOStepperMotor2clockDriver(MICRO_STEP), phyCoord->getParam('X'), baseCoord->getParam('X')), GPIOB, new array<int, 2>{Pin13, Pin12}, GPIOD, new array<int, 8>{Pin11, Pin10, Pin9, Pin8, Pin12, Pin13, Pin14, Pin15}));
	

  osKernelInitialize();                 // Initialize CMSIS-RTOS
	
	qToDoMark = osMessageQueueNew(256, sizeof(unsigned int), NULL);
	qToDoMarkWorkParam = osMessageQueueNew(16, sizeof(unsigned int), NULL);
	
  Init_vSecondThread(osPriorityLow);   
	Init_vCheckInputSignalsThread (osPriorityHigh);
	Init_vRealizationFunctionThread(osPriorityNormal);
	
	
  osKernelStart();                      // Start thread execution
  for (;;) {}
}
