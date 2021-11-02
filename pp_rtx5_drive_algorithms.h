#ifndef _PP_RTX_DRIVE_ALGORITHMS_H
	#define _PP_RTX_DRIVE_ALGORITHMS_H

#include "pp_drive_algorithms.h"
#include "cmsis_os2.h"

#include <vector>

#define BASE_FREQUENCY_OF_TIMdrive							10000
	
	class defORTX5driveAlgorithms : public defODriveAlgorithms{

		public:
			defORTX5driveAlgorithms(defOMotorsList *motors, defOParamList *pCoord, defOParamList *bCoord):defODriveAlgorithms(motors, pCoord, bCoord){};
		
		
			virtual int drive(void);
		
		

	};



#endif
