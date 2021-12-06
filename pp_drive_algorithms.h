/**
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

#ifndef _PP_DRIVE_ALGORITHMS_H
	#define _PP_DRIVE_ALGORITHMS_H

#include <map>
#include "pp_stepper_motor_driver.h"
#include "pp_paramlist.h"
#include "pp_motorslist.h"
#include "pp_point.h"


	#define DRIVE_IN_PROGRESS					(-1)	
	#define DRIVE_COMPLETED				0	
	#define DRIVE_ABORTED					1
	#define DRIVE_PAUSED					2
	#define DRIVE_INTERRUPTED			3

	
	class defODriveAlgorithms{
		
		protected:
			defOMotorsList *motors;
			defOParamList *phyCoord;
			defOParamList *baseCoord;
			PPpoint<char, int> phyStartPoint;
			PPpoint<char, int> phyEndPoint;
			PPpoint<char, int> phyIndirectPoint;
			PPpoint<char, int> phyVector;
		
			map<char, int> counter;

		
		public:
			int driveStatus;
		
			defODriveAlgorithms(defOMotorsList *mot, defOParamList *pCoord, defOParamList *bCoord);
		
		
			void setParToDriveForValue(map<char, int> &values);
			void setParToDriveToBaseCoordinates(map<char, int> &values);		
		
			virtual int drive(void)=0;
		
		
			static unsigned int getFrequencykResponsibleForDriveSpeed(unsigned int nrOfStepsFromStart, unsigned int nrOfStepsToEnd, int accelerationMMperSEC2, int velocityUMperSEC, unsigned int stepPM);
			static unsigned int getClockDividerResponsibleForDriveSpeed(unsigned int nrOfStepsFromStart, unsigned int nrOfStepsToEnd, int accelerationMMperSEC2, int velocityUMperSEC, unsigned int frequencyOfClock, unsigned int stepPM);
			static unsigned int getFrequencyOfDriveInUniformMovement(int velocityUMperSEC, unsigned int stepPM);
			static unsigned int getClockDividerInUniformMovement(int velocityUMperSEC, unsigned int frequencyOfClock, unsigned int stepPM);
			static unsigned int getClockDividerInUniformMovementWithSecurity(int velocityUMperSEC, int defValue, unsigned int frequencyOfClock, unsigned int stepPM);
			static unsigned int calculateAccelerateNumberOfSteps(int accelerationMMperSEC2, int velocityUMperSEC, unsigned int stepPM);
		
		

	};



#endif
