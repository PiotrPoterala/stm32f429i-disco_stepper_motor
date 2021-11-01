#include "pp_rtx5_drive_algorithms.h"


int defORTX5driveAlgorithms::drive(){
	uint32_t tick;
	
	tick = osKernelGetTickCount(); 
	//	defOButtonMarks oButtonMarks;
								
													
	//	OButtonMarksConstruct(&oButtonMarks);


		driveStatus=DRIVE_IN_PROGRESS;
		phyIndirectPoint=phyEndPoint;
			
		while(driveStatus!=DRIVE_COMPLETED && driveStatus!=DRIVE_ABORTED){		

			for(map<char, int>::iterator it=phyStartPoint.begin(); it != phyStartPoint.end(); ++it){
				
				if(motors->getIterator((*it).first)!=motors->getMotors()->end()){
					if(motors->getMotor((*it).first)->counter>=getClockDividerResponsibleForDriveSpeed(abs(phyCoord->getParam((*it).first)->getValue()-(*it).second)/phyCoord->getParam((*it).first)->getPrecision(), abs_pp(oDrive.driveParam.indirectCoord.X.value-oCoordinates.phyCoord.X.value)/oCoordinates.phyCoord.X.precision, &oDrive.feedrate->feedJog, BASE_FREQUENCY_OF_TIMdrive, oCoordinates.phyCoord.X.precision)){
	

						if(phyVector.find((*it).first)->second>0){
							motors->getMotor((*it).first)->rotateForward();
						}else if(phyVector.find((*it).first)->second<0){
							motors->getMotor((*it).first)->rotateBackwards();
						}
						motors->getMotor((*it).first)->counter=1;
					}else{
						motors->getMotor((*it).first)->counter++;
					}
				}
				
			}


//			if(xQueueReceive(qToDoMark, &oButtonMarks.toDoMark.mark, 0)){
//				oButtonMarks.decodeToDoMark(&oButtonMarks.toDoMark);

//				if(oButtonMarks.toDoMark.tag==TAG_MENU_PODR_1 || oButtonMarks.toDoMark.tag==TAG_ESC || oButtonMarks.toDoMark.atc==AT_TAG_STOP ||
//						oButtonMarks.toDoMark.key==KEY_STOP || oButtonMarks.toDoMark.key==KEY_F1 || oButtonMarks.toDoMark.key==KEY_ESC){
//					brakingDrive(&oCoordinates->phyCoord.X, driveParam->pointA.X.value, driveParam->pointB.X.value, &driveParam->indirectCoord.X.value, feedrateJog);
//					brakingDrive(&oCoordinates->phyCoord.Y, driveParam->pointA.Y.value, driveParam->pointB.Y.value, &driveParam->indirectCoord.Y.value, feedrateJog);
//					brakingDrive(&oCoordinates->phyCoord.Z, driveParam->pointA.Z.value, driveParam->pointB.Z.value, &driveParam->indirectCoord.Z.value, feedrateJog);
//					brakingDrive(&oCoordinates->phyCoord.U, driveParam->pointA.U.value, driveParam->pointB.U.value, &driveParam->indirectCoord.U.value, feedrateJog);
//					brakingDrive(&oCoordinates->phyCoord.V, driveParam->pointA.V.value, driveParam->pointB.V.value, &driveParam->indirectCoord.V.value, feedrateJog);
//					brakingDrive(&oCoordinates->phyCoord.Zw, driveParam->pointA.Zw.value, driveParam->pointB.Zw.value, &driveParam->indirectCoord.Zw.value, feedrateJog);
//				}

//			}


//			if(driveStatus==PRZEJ_SPAUZOWANO){		
//				stopDrive(oCoordinates, oMenu, driveParam, infoDrive, language, qToDoMark);	
//				taskCount=xTaskGetTickCount();
//			}
			
  		tick += 10000/BASE_FREQUENCY_OF_TIMdrive;    
			osDelayUntil(tick);
		}
		
//		oCheckSignalsLimitedStop->madeSignals=0;

		return driveStatus;

}

uint32_t getFrequencykResponsibleForDriveSpeed(uint32_t nrOfStepsFromStart, uint32_t nrOfStepsToEnd, SFeedrate* feedrate, uint32_t stepPM){
			uint32_t accelerateNumberOfSteps;
			uint32_t nrOfSteps=0;
			uint32_t frequencyOfDriveVelocity=0;

			//k - step

			//s=0.5*V*t	- pole pod wykresem V(t)
			//a=V/t	
			//s=V^2/(2*a)
			//Lk=s/k=V^2/(2*a*k)

			//V=s/t=k/(1/f) => V=kf => f=V/k => f=sqrt(2*a*Lk/k)

			accelerateNumberOfSteps=calculateAccelerateNumberOfSteps(feedrate, stepPM);

			nrOfSteps=(nrOfStepsFromStart<=nrOfStepsToEnd)?nrOfStepsFromStart:nrOfStepsToEnd;
			if(nrOfSteps<=accelerateNumberOfSteps){
				frequencyOfDriveVelocity=sqrt((double)(2*feedrate->accelerationMMperSEC2*(nrOfSteps+1))/stepPM)*1000;
//				#if !defined(AC_SERVO)
//				if(frequencyOfDriveVelocity>180 && frequencyOfDriveVelocity<220){	//wycięcie częstotliwości z zakresu (180; 220) [Hz]
//					frequencyOfDriveVelocity=180;
//				}
//				#endif	
			}else{
				frequencyOfDriveVelocity=getFrequencyOfDriveInUniformMovement(feedrate->velocityUMperSEC.value, stepPM);
			}

			return frequencyOfDriveVelocity;
}


uint16_t getClockDividerResponsibleForDriveSpeed(uint32_t nrOfStepsFromStart, uint32_t nrOfStepsToEnd, SFeedrate* feedrate, uint32_t frequencyOfClock, uint32_t stepPM){

			//fmax/x=f
			//x=fmax/f=>x=fmax/sqrt(2*a*Lk/k)

			return (uint16_t)(frequencyOfClock/getFrequencykResponsibleForDriveSpeed(nrOfStepsFromStart, nrOfStepsToEnd, feedrate, stepPM));
}

uint32_t getFrequencyOfDriveInUniformMovement(int32_t velocity, uint32_t stepPM){

		if(velocity<=0)velocity=1;
		
		return ((1000*velocity)/stepPM);	
}


uint16_t getClockDividerInUniformMovement(int32_t velocity, uint32_t frequencyOfClock, uint32_t stepPM){

	//	if(velocity>0)return (uint16_t)ceil(1000*frequencyOfClock/(200*velocity));
		if(velocity<=0)velocity=1;
		
		return (uint16_t)(stepPM*frequencyOfClock/(1000*velocity));	
}


uint16_t getClockDividerInUniformMovementWithSecurity(int32_t velocity, int32_t defValue, uint32_t frequencyOfClock, uint32_t stepPM){

		if(defValue<=0)defValue=1;
		if(velocity<=0)velocity=defValue;
		
		return (uint16_t)(stepPM*frequencyOfClock/(1000*velocity));	
}


uint32_t calculateAccelerateNumberOfSteps(SFeedrate* feedrate, uint32_t stepPM){

		//return ((feedrate->velocityUMperSEC.value*feedrate->velocityUMperSEC.value/feedrate->accelerationMMperSEC2)*100)/1000000;
		//return (feedrate->velocityUMperSEC.value*feedrate->velocityUMperSEC.value/feedrate->accelerationMMperSEC2)/10000;
		return (feedrate->velocityUMperSEC.value*feedrate->velocityUMperSEC.value/(2*feedrate->accelerationMMperSEC2*stepPM));
}