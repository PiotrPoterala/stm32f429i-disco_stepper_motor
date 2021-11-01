#ifndef _PP_RTX_DRIVE_ALGORITHMS_H
	#define _PP_RTX_DRIVE_ALGORITHMS_H

#include "pp_drive_algorithms.h"
#include "cmsis_os2.h"

#include <vector>

	
	class defORTX5driveAlgorithms : public defODriveAlgorithms{

		public:
			defORTX5driveAlgorithms(defOMotorsList *motors);
		
		
			int drive(void);
		
			unsigned int getFrequencykResponsibleForDriveSpeed(uint32_t nrOfStepsFromStart, uint32_t nrOfStepsToEnd, SFeedrate* feedrate, uint32_t stepPM);
			unsigned int getClockDividerResponsibleForDriveSpeed(uint32_t nrOfStepsFromStart, uint32_t nrOfStepsToEnd, SFeedrate* feedrate, uint32_t frequencyOfClock, uint32_t stepPM);
			unsigned int getFrequencyOfDriveInUniformMovement(int32_t velocity, uint32_t stepPM);
			unsigned int getClockDividerInUniformMovement(int32_t velocity, uint32_t frequencyOfClock, uint32_t stepPM);
			unsigned int getClockDividerInUniformMovementWithSecurity(int32_t velocity, int32_t defValue, uint32_t frequencyOfClock, uint32_t stepPM);
			unsigned int calculateAccelerateNumberOfSteps(SFeedrate* feedrate, uint32_t stepPM);
		

	};



#endif
