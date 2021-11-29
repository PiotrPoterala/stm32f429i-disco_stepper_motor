/*----------------------------------------------------------------------------
 * CMSIS-RTOS 'main' function template
 *---------------------------------------------------------------------------*/
 
#include "RTE_Components.h"
#include  CMSIS_device_header
#include "cmsis_os2.h"
#include "math.h"

#include <map>
 
 #include "EventRecorder.h" 
 
#include "config.h"
#include "def_pins.h"
#include "pp_param.h"
#include "pp_paramlist.h"
#include "pp_motorslist.h"
#include "pp_stepper_motor_driver.h"
#include "pp_control_coordinate_decorator.h"
#include "pp_stepper_motor_2clock_driver.h"
#include "pp_control_2clock_signals_decorator.h"

#include "pp_rtos_uart_queue_decorator.h"
#include "pp_rtx5_uart_queue.h"
#include "pp_rtx5_drive_algorithms.h"
#include "pp_rtx5_queue.h"
#include "pp_rtx5_at_commands_interpreter.h"
#include "pp_rtx5_param_mutex_decorator.h"

//#define COORD_PRECISION_MM 0.001250	
#define COORD_PRECISION_MM 0.005
#define COORD_UNIT 6	

#define MIN_PHY_COORD_MM		0
#define MIN_BASE_COORD_MM	(-999)
#define MAX_PHY_COORD_MM		999
#define MAX_BASE_COORD_MM		999

#define VELOCITY_PRECISION_uM_PER_SEC 1				
#define VELOCITY_UNIT 1

#define ACCELERATION_PRECISION_uM_PER_SEC2 1				
#define ACCELERATION_UNIT 1

extern int Init_vSecondThread (osPriority_t priority);
extern int Init_vCheckInputSignalsThread (osPriority_t priority); 
extern int Init_vRealizationFunctionThread  (osPriority_t priority);
extern int Init_vReceiveAndInterpretDataFromComUartThread (osPriority_t priority); 


defOParamList *phyCoord;
defOParamList *baseCoord;

defORTX5TaskQueues<int>* taskCommunicationQueues;
defOUartQueues* uartCommunicationQueues;

defOMotorsList motors;
defODriveAlgorithms* motorsAlgorithms;


//vector<int> test[5]={
//										vector<int>{0,0,0,0},
//										vector<int>{0,0,0,0},
//										vector<int>{0,0,0,0},
//										vector<int>{0,0,0,0},
//										vector<int>{0,0,0,0}};

//vector<vector<int>> test={
//										vector<int>{0,0,0,0},
//										vector<int>{0,0,0,0},
//										vector<int>{0,0,0,0},
//										vector<int>{0,0,0,0},
//										vector<int>{0,0,0,0}};

//int tab2[40];

//										
//void funTest(vector<vector<int>> &tab){
//	int k=0;
//	
//	for(auto &line : tab){
//		for(auto &column : line){
//			column+=k;
//			tab2[k]=column;
//			k++;
//		}
//	}
//	
//}									
										
										
										
//void funTest(vector<int> tab[]){
//	int k=0;
//	
//	for(int i=0; i<5; i++){
//		for(auto &x : tab[i]){
//			x+=k;
//			tab2[k]=x;
//			k++;
//		}
//	}
	
//	for(int i=0; i<5; i++){
//		for(auto x=tab[i].begin(); x!=tab[i].end(); x++){
//			(*x)+=k;
//			tab2[k]=*x;
//			k++;
//		}
//	}
	
//}

int main (void) {
	
  // System Initialization
	RCC_Config();
	GPIO_Config();
	
//	funTest(test);


//	for(auto &x: tab){
//		for(auto &line: x){
//			line+=k;
//			k++;
//		}
//	}
	EventRecorderInitialize (EventRecordAll, 1);
  osKernelInitialize();                 // Initialize CMSIS-RTOS
	
	phyCoord=new defOParamList();
	phyCoord->insert(pair<char, defOParamGeneral*>('X', new defORTX5ParamMutexDecorator(new defOParam("X", 100*pow(10.0, COORD_UNIT), 100*pow(10.0, COORD_UNIT), COORD_PRECISION_MM*pow(10.0, COORD_UNIT), COORD_UNIT, MIN_PHY_COORD_MM*pow(10.0, COORD_UNIT), MAX_PHY_COORD_MM*pow(10.0, COORD_UNIT)))));
	phyCoord->insert(pair<char, defOParamGeneral*>('Y', new defORTX5ParamMutexDecorator(new defOParam("Y", 100*pow(10.0, COORD_UNIT), 100*pow(10.0, COORD_UNIT), COORD_PRECISION_MM*pow(10.0, COORD_UNIT), COORD_UNIT, MIN_PHY_COORD_MM*pow(10.0, COORD_UNIT), MAX_PHY_COORD_MM*pow(10.0, COORD_UNIT)))));

	baseCoord=new defOParamList();
	baseCoord->insert(pair<char, defOParamGeneral*>('X', new defORTX5ParamMutexDecorator(new defOParam("X", 0, 0, COORD_PRECISION_MM*pow(10.0, COORD_UNIT), COORD_UNIT, MIN_PHY_COORD_MM*pow(10.0, COORD_UNIT), MAX_PHY_COORD_MM*pow(10.0, COORD_UNIT)))));
	baseCoord->insert(pair<char, defOParamGeneral*>('Y', new defORTX5ParamMutexDecorator(new defOParam("Y", 0, 0, COORD_PRECISION_MM*pow(10.0, COORD_UNIT), COORD_UNIT, MIN_PHY_COORD_MM*pow(10.0, COORD_UNIT), MAX_PHY_COORD_MM*pow(10.0, COORD_UNIT)))));


	motors.getMotors()->push_back(new defOControl2ClockSignalsDecorator
																(new defOControlCoordinateDecorator
																	(new defOStepperMotor2clockDriver
																		(new defOParam("acceleration", 2, 2, ACCELERATION_PRECISION_uM_PER_SEC2, ACCELERATION_UNIT, 1, 30),
																			new defOParam("velocity", 2500, 2500, VELOCITY_PRECISION_uM_PER_SEC, VELOCITY_UNIT, 1, 2500), 
																				FULL_STEP), phyCoord->getParamPair('X'), baseCoord->getParam('X')), 
																				new vector<uPin>{uPin{GPIOB,Pin4},uPin{GPIOB,Pin7},
																												uPin{GPIOE,Pin2},uPin{GPIOE,Pin3},uPin{GPIOE,Pin4},uPin{GPIOE,Pin5},
																												uPin{GPIOE,Pin6},uPin{GPIOC,Pin11},uPin{GPIOC,Pin12},uPin{GPIOC,Pin13}}));
	
																		//			GPIOD, new array<int, 8>{Pin11, Pin10, Pin9, Pin8, Pin12, Pin13, Pin14, Pin15}
													
	motorsAlgorithms= new defORTX5driveAlgorithms(&motors, phyCoord, baseCoord);

	
	taskCommunicationQueues= new defORTX5TaskQueues<int>();
	uartCommunicationQueues=new defORTX5atCommandInterpreter(new defOUartRTX5queues(USART1), taskCommunicationQueues, phyCoord, baseCoord);
	NVIC_Config();
	USART_Config();
	

	Init_vSecondThread(osPriorityLow);  
	Init_vCheckInputSignalsThread (osPriorityBelowNormal);
	Init_vRealizationFunctionThread(osPriorityNormal);  
	Init_vReceiveAndInterpretDataFromComUartThread (osPriorityHigh); 
	
	
  osKernelStart();                      // Start thread execution
  for (;;) {}
}


