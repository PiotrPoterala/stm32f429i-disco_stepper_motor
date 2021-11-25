#include "pp_drive_algorithms.h"
#include "pp_rtx5_uart_queue.h"

 extern defOUartQueues* uartCommunicationQueues;
 
defODriveAlgorithms::defODriveAlgorithms(defOMotorsList *mot, defOParamList *pCoord, defOParamList *bCoord):motors(mot), phyCoord(pCoord), baseCoord(bCoord){
	
	
}




//funkcje związane z przejazdami w pracy ręcznej
void defODriveAlgorithms::setParToDriveForValue(map<char, int> &values){

	phyStartPoint.axes.clear();
	phyEndPoint.axes.clear();
	phyVector.axes.clear();
	counter.clear();
	
	phyStartPoint.axes=phyCoord->getParamsValues();
	phyEndPoint=phyStartPoint;
	
	
	for(auto it=phyStartPoint.axes.begin(); it != phyStartPoint.axes.end(); it++){
		if(motors->getIterator((*it).first)!=motors->getMotors()->end()){
			auto values_it=values.find((*it).first);
			if(values_it!=values.end()){
				phyEndPoint.axes.find((*it).first)->second=phyCoord->checkRange((*it).first, phyEndPoint.axes.find((*it).first)->second+values_it->second);
			}
			phyVector.axes.insert(pair<char, int>((*it).first, phyEndPoint.axes.find((*it).first)->second-phyStartPoint.axes.find((*it).first)->second));
			counter.insert(pair<char, int>((*it).first, 0));
		}
	}
	
	drive();
	
														
}

void defODriveAlgorithms::setParToDriveToBaseCoordinates(map<char, int> &values){
	
	phyStartPoint.axes.clear();
	phyEndPoint.axes.clear();
	phyVector.axes.clear();
	counter.clear();
	
	phyStartPoint.axes=phyCoord->getParamsValues();
	phyEndPoint=phyStartPoint;
	
	for(auto it=phyStartPoint.axes.begin(); it != phyStartPoint.axes.end(); it++){
		if(motors->getIterator((*it).first)!=motors->getMotors()->end()){
			auto values_it=values.find((*it).first);
			if(values_it!=values.end()){
				phyEndPoint.axes.find((*it).first)->second=phyCoord->checkRange((*it).first, phyEndPoint.axes.find((*it).first)->second+values_it->second-baseCoord->getParamValue((*it).first));
			}
			phyVector.axes.insert(pair<char, int>((*it).first, phyEndPoint.axes.find((*it).first)->second-phyStartPoint.axes.find((*it).first)->second));
			counter.insert(pair<char, int>((*it).first, 0));
		}
	}
	
	drive();
																			
}


unsigned int defODriveAlgorithms::getFrequencykResponsibleForDriveSpeed(unsigned int nrOfStepsFromStart, unsigned int nrOfStepsToEnd, int accelerationMMperSEC2, int velocityUMperSEC, unsigned int stepPM){
			int accelerateNumberOfSteps;
			int nrOfSteps=0;
			unsigned int frequencyOfDriveVelocity=0;

			//k - step

			//s=0.5*V*t	- pole pod wykresem V(t)
			//a=V/t	
			//s=V^2/(2*a)
			//Lk=s/k=V^2/(2*a*k)

			//V=s/t=k/(1/f) => V=kf => f=V/k => f=sqrt(2*a*Lk/k)

			accelerateNumberOfSteps=calculateAccelerateNumberOfSteps(accelerationMMperSEC2, velocityUMperSEC, stepPM);

			nrOfSteps=(nrOfStepsFromStart<=nrOfStepsToEnd)?nrOfStepsFromStart:nrOfStepsToEnd;
			if(nrOfSteps<=accelerateNumberOfSteps){
				frequencyOfDriveVelocity=sqrt(static_cast<double>(2*accelerationMMperSEC2*(nrOfSteps+1))/stepPM)*1000;
			}else{
				frequencyOfDriveVelocity=getFrequencyOfDriveInUniformMovement(velocityUMperSEC, stepPM);
			}
			
			return frequencyOfDriveVelocity;
}


unsigned int defODriveAlgorithms::getClockDividerResponsibleForDriveSpeed(unsigned int nrOfStepsFromStart, unsigned int nrOfStepsToEnd, int accelerationMMperSEC2, int velocityUMperSEC, unsigned int frequencyOfClock, unsigned int stepPM){

			//fmax/x=f
			//x=fmax/f=>x=fmax/sqrt(2*a*Lk/k)

			return frequencyOfClock/getFrequencykResponsibleForDriveSpeed(nrOfStepsFromStart, nrOfStepsToEnd, accelerationMMperSEC2, velocityUMperSEC, stepPM);
}

unsigned int defODriveAlgorithms::getFrequencyOfDriveInUniformMovement(int velocityUMperSEC, unsigned int stepPM){

		if(velocityUMperSEC<=0)velocityUMperSEC=1;
		
		return ((1000*velocityUMperSEC)/stepPM);	
}


unsigned int defODriveAlgorithms::getClockDividerInUniformMovement(int velocityUMperSEC, unsigned int frequencyOfClock, unsigned int stepPM){

	//	if(velocity>0)return (uint16_t)ceil(1000*frequencyOfClock/(200*velocity));
		if(velocityUMperSEC<=0)velocityUMperSEC=1;
		
		return stepPM*frequencyOfClock/(1000*velocityUMperSEC);	
}


unsigned int defODriveAlgorithms::getClockDividerInUniformMovementWithSecurity(int velocityUMperSEC, int defValue, unsigned int frequencyOfClock, unsigned int stepPM){

		if(defValue<=0)defValue=1;
		if(velocityUMperSEC<=0)velocityUMperSEC=defValue;
		
		return stepPM*frequencyOfClock/(1000*velocityUMperSEC);	
}


unsigned int defODriveAlgorithms::calculateAccelerateNumberOfSteps(int accelerationMMperSEC2, int velocityUMperSEC, unsigned int stepPM){

		return (velocityUMperSEC*velocityUMperSEC/(2*accelerationMMperSEC2*stepPM));
}

