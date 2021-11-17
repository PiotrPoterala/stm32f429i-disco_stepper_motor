#include "pp_rtx5_drive_algorithms.h"


int defORTX5driveAlgorithms::drive(){
	int tick;
	
	tick = osKernelGetTickCount(); 



		driveStatus=DRIVE_IN_PROGRESS;
		phyIndirectPoint=phyEndPoint;
	
		motors->clearCounters();
	
		while(driveStatus!=DRIVE_COMPLETED && driveStatus!=DRIVE_ABORTED){		

			for(map<char, int>::iterator it=phyStartPoint.begin(); it != phyStartPoint.end(); ++it){
				
//				if(motors->getIterator((*it).first)!=motors->getMotors()->end()){
//					if(motors->getMotor((*it).first)->counter>=getClockDividerResponsibleForDriveSpeed(abs(phyCoord->getParam((*it).first)->getValue()-(*it).second)/phyCoord->getParam((*it).first)->getPrecision(), 
//																																														abs(phyEndPoint.find((*it).second)->second-phyCoord->getParam((*it).first)->getValue())/phyCoord->getParam((*it).first)->getPrecision(), motors->getMotor((*it).first)->accelerationMMperSEC2, 
//																																														motors->getMotor((*it).first)->velocityUMperSEC->getValue(), BASE_FREQUENCY_OF_TIMdrive, phyCoord->getParam((*it).first)->getPrecision())){
//	

//						if(phyVector.find((*it).first)->second>0){
//							motors->getMotor((*it).first)->rotateForward();
//						}else if(phyVector.find((*it).first)->second<0){
//							motors->getMotor((*it).first)->rotateBackwards();
//						}
//						motors->getMotor((*it).first)->counter=1;
//					}else{
//						motors->getMotor((*it).first)->counter++;
//					}
//				}
				
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

