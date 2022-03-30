/**
 * Keil project for stepper motor driver
 
 * @author  Piotr Poterała
 * @email   poterala.piotr@gmail.com
 * @website http://zappp.pl
 * @version v1.0
 * @ide     Keil uVision 5
 * @license GNU GPL v3
 *	
@verbatim
   ----------------------------------------------------------------------
    Copyright (C) Piotr Poterała, 2021
    
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    any later version.
     
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    
    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
   ----------------------------------------------------------------------
@endverbatim
 */
 
#include "RTE_Components.h"
#include  CMSIS_device_header
#include "cmsis_os2.h"
#include "math.h"

#include <map>
 
 #include "EventRecorder.h" 
 
#include "config.h"
#include "def_pins.h"
#include "stm32f_timer.h"
#include "pp_param.h"
#include "pp_paramlist.h"
#include "pp_motorslist.h"
#include "pp_stepper_motor_driver.h"
#include "pp_control_coordinate_decorator.h"
#include "pp_stepper_motor_2clock_driver.h"
#include "pp_stepper_motor_dir_clock_driver.h"
#include "pp_control_2clock_signals_decorator.h"
#include "pp_rtx5_control_dir_clock_signals_decorator.h"
#include "pp_rtx5_select_current_decorator.h"

#include "pp_iodevice.h"
#include "pp_iodevice_decorator.h"
#include "pp_rtx5_serial_port.h"
#include "pp_rtx5_drive_algorithms.h"
#include "pp_rtx5_queue.h"
#include "pp_rtx5_at_commands_interpreter.h"
#include "pp_rtx5_param_mutex_decorator.h"
#include "pp_text_stream.h"

#include "strings_pl.h"

#define COORD_PRECISION_MM 0.0025
#define COORD_UNIT 6	

#define MIN_PHY_COORD_MM		0
#define MIN_BASE_COORD_MM	(-999)
#define MAX_PHY_COORD_MM		999
#define MAX_BASE_COORD_MM		999

extern int Init_vSecondThread (osPriority_t priority);
extern int Init_vRealizationFunctionThread  (osPriority_t priority);
extern int Init_vReceiveAndInterpretDataFromComUartThread (osPriority_t priority); 


defOParamList phyCoord;
defOParamList baseCoord;
defOParamList workParams;

defORTX5TaskQueues<int>* taskCommunicationQueues;
PIOdevice* commSerialPort;

defOMotorsList motors;
defODriveAlgorithms* motorsAlgorithms;

uPin motorXclockPin{GPIOD,Pin5};
uPin motorXselectCurrentPin{GPIOD,Pin2};


unique_ptr<StringsMap> strings= make_unique<StringsMap>(strings_pl);

int main (void) {
	
	//1) Configuration clocks and update the system core clock using the respective CMSIS-Core (Cortex-M) 
	RCC_Config();
	
	//2) Initialization and configuration of hardware including peripherals, memory, pins and the interrupt system.
	GPIO_Config();
	NVIC_Config();																									
	
	
//	EventRecorderInitialize (EventRecordAll, 1);
	
	//3) Initialize CMSIS-RTOS
  osKernelInitialize();                 
	
	phyCoord=defOParamList();
	phyCoord.insert(PParamPair('X', make_shared<defORTX5ParamMutexDecorator>(make_shared<defOParam>("X", 100*pow(10.0, COORD_UNIT), 100*pow(10.0, COORD_UNIT), COORD_PRECISION_MM*pow(10.0, COORD_UNIT), COORD_UNIT, MIN_PHY_COORD_MM*pow(10.0, COORD_UNIT), MAX_PHY_COORD_MM*pow(10.0, COORD_UNIT)))));
	phyCoord.insert(PParamPair('Y', make_shared<defORTX5ParamMutexDecorator>(make_shared<defOParam>("Y", 100*pow(10.0, COORD_UNIT), 100*pow(10.0, COORD_UNIT), COORD_PRECISION_MM*pow(10.0, COORD_UNIT), COORD_UNIT, MIN_PHY_COORD_MM*pow(10.0, COORD_UNIT), MAX_PHY_COORD_MM*pow(10.0, COORD_UNIT)))));

	baseCoord=phyCoord;
	baseCoord.setParamsRealLowerLimit(-999);
	baseCoord.setParamsValueByZero();
	baseCoord.setParamsDefaultValue(0);

	workParams=defOParamList();
	workParams.insert(PParamPair('f', make_shared<defOParam>(strings->find("feed")->second, 5, 5, 1, 0, 1, 2500)));
	workParams.insert(PParamPair('a', make_shared<defOParam>(strings->find("acc")->second, 2, 2, 1, 0, 1, 30)));

	motors.getMotors()->push_back(new defORTX5SelectCurrentDecorator
															(new defOControl2ClockSignalsDecorator
																(new defOControlCoordinateDecorator
																	(new defOStepperMotor2clockDriver
																		(workParams.getParam('a').front(), workParams.getParam('f').front(), MICRO_STEP), 
																			phyCoord.getParamPair('X'), baseCoord.getParam('X').front()), 
																				vector<uPin>{uPin{GPIOD,Pin4},uPin{GPIOD,Pin5},
																												uPin{GPIOE,Pin2},uPin{GPIOE,Pin3},uPin{GPIOE,Pin4},uPin{GPIOE,Pin5},
																												uPin{GPIOE,Pin6},uPin{GPIOC,Pin11},uPin{GPIOC,Pin12},uPin{GPIOC,Pin13}}, new uPin{GPIOD,Pin7}),
																				&motorXselectCurrentPin, osTimerNew(motorXChangeSelectCurrentSignal, osTimerOnce, (void*)B_HIGH, nullptr), B_HIGH));		
																												
																												
//	motors.getMotors()->push_back(new defORTX5SelectCurrentDecorator
//												(new defORTX5ControlDirClockSignalsDecorator
//													(new defOControlCoordinateDecorator
//														(new defOStepperMotorDirClockDriver
//															(new defOParam("acceleration", 2, 2, ACCELERATION_PRECISION_uM_PER_SEC2, ACCELERATION_UNIT, 1, 30),
//																new defOParam("velocity", 2500, 2500, VELOCITY_PRECISION_uM_PER_SEC, VELOCITY_UNIT, 1, 2500)), 
//																	phyCoord->getParamPair('X'), baseCoord->getParam('X')), 
//																	new vector<uPin>{uPin{GPIOD,Pin4}, motorXclockPin}, osTimerNew(motorXClearClockSignal, osTimerOnce, nullptr, nullptr)), 
//																		&motorXselectCurrentPin, osTimerNew(motorXChangeSelectCurrentSignal, osTimerOnce, (void*)B_LOW, nullptr)));																									
												
	motorsAlgorithms= new defORTX5driveAlgorithms(&motors, &phyCoord, &baseCoord);

	
	taskCommunicationQueues= new defORTX5TaskQueues<int>();
	commSerialPort=new defORTX5atCommandInterpreter(new PSerialPortRTX5(USART1), taskCommunicationQueues, &phyCoord, &baseCoord);
	commSerialPort->open(PIOdevice::ReadWrite);		
																										
	//4) Create threads
	Init_vSecondThread(osPriorityBelowNormal);  
	Init_vRealizationFunctionThread(osPriorityNormal);  
	Init_vReceiveAndInterpretDataFromComUartThread (osPriorityHigh); 
	
	//5) Start the RTOS scheduler
  osKernelStart();   

  for (;;) {}
}


