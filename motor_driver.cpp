#include <stdbool.h>
#include "motor_driver.h"


defOMotorDriver::defOMotorDriver(pair<char, defOParam*> pCoord, pair<char, defOParam*> bCoord, int tOfStep, int corrUM):phyCoord(pCoord), baseCoord(bCoord), typeOfStep(tOfStep), correctionUM(corrUM){
	

	
}

void defOMotorDriver::setTypeOfStep(int tOfStep){
	
	typeOfStep=tOfStep;
	
}



