#include "pp_rtx5_drive_algorithms.h"
#include "pp_rtx5_uart_queue.h"
 extern defOUartQueues* uartCommunicationQueues;

int defORTX5driveAlgorithms::drive(){
	int tick;
	string str;
	
	tick = osKernelGetTickCount(); 



		driveStatus=DRIVE_IN_PROGRESS;
		phyIndirectPoint.axes.clear();
		phyIndirectPoint=phyEndPoint;
	
		motors->clearCounters();
	
		while(driveStatus!=DRIVE_COMPLETED && driveStatus!=DRIVE_ABORTED){		

			for(auto it=phyStartPoint.axes.begin(); it != phyStartPoint.axes.end(); it++){
				
				if(motors->getIterator((*it).first)!=motors->getMotors()->end()){
					auto cnt_it=counter.find((*it).first);
					if(cnt_it!=counter.end()){
						if(cnt_it->second>=getClockDividerResponsibleForDriveSpeed(abs(phyCoord->getParamValue((*it).first)-(*it).second)/phyCoord->getParamPrecision((*it).first), 
																																			abs(phyEndPoint.axes.find((*it).second)->second-phyCoord->getParamValue((*it).first))/phyCoord->getParamPrecision((*it).first), motors->getMotor((*it).first)->getAccelerationMMperSEC2Value(), 
																																			motors->getMotor((*it).first)->getVelocityUMperSECValue(), BASE_FREQUENCY_OF_TIMdrive, phyCoord->getParamPrecision((*it).first))){
		
//					str=to_string((*cnt_it).second);
//(*uartCommunicationQueues)<<str<<"\r\n";
							if(phyVector.axes.find((*it).first)->second>0){
								motors->getMotor((*it).first)->rotateForward();
							}else if(phyVector.axes.find((*it).first)->second<0){
								motors->getMotor((*it).first)->rotateBackwards();
							}
							(*cnt_it).second=1;
						}else{
							(*cnt_it).second++;
						}
					}
				}
				
			}

			if(phyEndPoint==phyCoord->getParamsValues())driveStatus=DRIVE_COMPLETED;


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

