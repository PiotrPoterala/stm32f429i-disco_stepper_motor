/**	
 * |----------------------------------------------------------------------
 * | Copyright (C) Piotr Poterała, 2021
 * | 
 * | This program is free software: you can redistribute it and/or modify
 * | it under the terms of the GNU General Public License as published by
 * | the Free Software Foundation, either version 3 of the License, or
 * | any later version.
 * |  
 * | This program is distributed in the hope that it will be useful,
 * | but WITHOUT ANY WARRANTY; without even the implied warranty of
 * | MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * | GNU General Public License for more details.
 * | 
 * | You should have received a copy of the GNU General Public License
 * | along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * |----------------------------------------------------------------------
 */

#include "pp_rtx5_drive_algorithms.h"
#include "pp_rtx5_uart_queue.h"
#include "RTX_Config.h"

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
																																		abs(phyEndPoint.axes.find((*it).first)->second-phyCoord->getParamValue((*it).first))/phyCoord->getParamPrecision((*it).first), 
																																		motors->getMotor((*it).first)->getAccelerationMMperSEC2Value(), 
																																		motors->getMotor((*it).first)->getVelocityUMperSECValue(), 
																																		BASE_FREQUENCY_OF_TIMdrive, phyCoord->getParamPrecision((*it).first))){
																												
																																			
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
		
		tick += OS_TICK_FREQ /BASE_FREQUENCY_OF_TIMdrive;    
		osDelayUntil(tick);
	}
	
	return driveStatus;

}

