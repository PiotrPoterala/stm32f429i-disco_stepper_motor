#include "drive_machine.h"

//extern xSemaphoreHandle xDrive;

//static char *driveFeedrate[NR_OF_LANGUAGE][NR_OF_FEEDRATE]={{"Posuw [um/s]", "Posuw r. [um/s]"}, {"Feed [um/s]", "Jog [um/s]"}};


//void ODriveConstruct(defODrive *oDrive, defOCoordinates *oCoordinates, SCorrectionAllAxes *corrections, uint32_t language){

//		//zainicjowanie zmiennych
//		oDrive->stepDriveMM=0.01;
//		oDrive->errorDrive=0;
//		oDrive->infoDrive=PRZEJ_ZREALIZOWANO;
//		oDrive->phyCoordIgnorance=false;
//		oDrive->circuitIgnorance=true;

//		getDriveMaskFromBackup(&oDrive->driveMask);
//	
//		oDrive->driveMask.mikro_krokX=STEP_1_4;
//		oDrive->driveMask.mikro_krokY=STEP_1_4;
//		oDrive->driveMask.mikro_krokZ=STEP_1_4;
//		oDrive->driveMask.mikro_krokU=STEP_1_4;
//		oDrive->driveMask.mikro_krokV=STEP_1_4;
//		oDrive->driveMask.mikro_krokZw=STEP_1_4;
//	
//		setSygPortDRIVE(&oDrive->driveMask);

//		setLinMask(&oDrive->driveLin.m_lin_krokX, MASKA_linX);
//		setLinMask(&oDrive->driveLin.m_lin_krokY, MASKA_linY);
//		oDrive->driveLin.linCriticalError=false;
//		oDrive->driveLin.b_linX=0;
//		oDrive->driveLin.b_linY=0;

////		setCorrection(&oDrive->corrections.correctX, oFlashSystemParam->getCorrectX());
////		setCorrection(&oDrive->corrections.correctY, oFlashSystemParam->getCorrectY());
////		setCorrection(&oDrive->corrections.correctZ, oFlashSystemParam->getCorrectZ());
////		setCorrection(&oDrive->corrections.correctU, oFlashSystemParam->getCorrectU());
////		setCorrection(&oDrive->corrections.correctV, oFlashSystemParam->getCorrectV());
////		setCorrection(&oDrive->corrections.correctZw, oFlashSystemParam->getCorrectZw());


//		oCoordinates->clearCoord(&oDrive->driveParam.pointA);
//		oCoordinates->clearCoord(&oDrive->driveParam.pointB);
//		oCoordinates->clearCoord(&oDrive->driveParam.indirectCoord);

//		oDrive->focusFeedrate=0;
//		oDrive->feedrate=&oDrive->wireFeedrate;
//		setWireFeedrateParamByDefaultValues(&oDrive->wireFeedrate);
//		setDrillFeedrateParamByDefaultValues(&oDrive->drillFeedrate);

//		oDrive->feedrateList.itemsParam.item=0; 
//		oDrive->feedrateList.itemsParam.nrOfItems=NR_OF_FEEDRATE;
//		setFeedrateList(&oDrive->feedrateList.itemsParam, language);
//		oDrive->feedrateList.setList=setFeedrateList;


//		oDrive->drivePathParam.activeDrivePath=NONE_DRIVE;
//		oDrive->drivePathParam.driveToFirstDischarge=false;
//		oDrive->drivePathParam.typeOfDrive=T_PROSTA;
//		oCoordinates->clearCoord(&oDrive->drivePathParam.pointA); 
//		oCoordinates->clearCoord(&oDrive->drivePathParam.pointB); 
//		oCoordinates->clearCoord(&oDrive->drivePathParam.circleCenter); 
//		oCoordinates->clearCoord(&oDrive->drivePathParam.vectorAB);
//		oDrive->drivePathParam.hypSumStepOfSEG=0;
//		oDrive->drivePathParam.stepOfContour=0;
//		oDrive->drivePathParam.efficiency=0;
//		oDrive->drivePathParam.nrOfStepOnCircuit=0;
//		oDrive->drivePathParam.nrOfStepWithoutWork=0;
//		oDrive->drivePathParam.masterAxis=OS_X;
//		oDrive->drivePathParam.startDetErrSEG=false;
//		oDrive->drivePathParam.nPointX=0; 
//		oDrive->drivePathParam.nPointY=0; 
//		oDrive->drivePathParam.nPointZ=0; 
//		oDrive->drivePathParam.nPointU=0; 
//		oDrive->drivePathParam.nPointV=0; 

//		oCoordinates->clearCoord(&oDrive->drivePathParam.circleCenter);
//		oCoordinates->clearCoord(&oDrive->drivePathParam.kB);
//		oDrive->drivePathParam.turnCircle=ZEGAR_ZGODNIE;
//		oDrive->drivePathParam.circleR2=0;
//		oDrive->drivePathParam.dividerZ=0;
//		oDrive->drivePathParam.dividerXY=0;
//		oDrive->drivePathParam.nrOfStepCircleZ=0;
//		oDrive->drivePathParam.nrOfStepCircleXY=0;
//		oDrive->drivePathParam.nrOfMadeStepCircleZ=0;
//		oDrive->drivePathParam.nrOfMadeStepCircleXY=0;

//		oDrive->allDriveConditionParam.activeDirectionDriveConditional=DIR_NULL;
//		setParamHandWorkDetail(&oDrive->allDriveConditionParam.driveConditionParamX, &oCoordinates->phyCoord.X, &oCoordinates->baseCoord.X, &oDrive->driveMask.m_krokX, &oDrive->driveMask.mikro_krokX, &oDrive->driveLin.b_linX, OS_X, corrections->correctX);
//		setParamHandWorkDetail(&oDrive->allDriveConditionParam.driveConditionParamY, &oCoordinates->phyCoord.Y, &oCoordinates->baseCoord.Y, &oDrive->driveMask.m_krokY, &oDrive->driveMask.mikro_krokY, &oDrive->driveLin.b_linY, OS_Y, corrections->correctY);
//		setParamHandWorkDetail(&oDrive->allDriveConditionParam.driveConditionParamZ, &oCoordinates->phyCoord.Z, &oCoordinates->baseCoord.Z, &oDrive->driveMask.m_krokZ, &oDrive->driveMask.mikro_krokZ, 0, OS_Z, corrections->correctZ);
//		setParamHandWorkDetail(&oDrive->allDriveConditionParam.driveConditionParamU, &oCoordinates->phyCoord.U, &oCoordinates->baseCoord.U, &oDrive->driveMask.m_krokU, &oDrive->driveMask.mikro_krokU, &oDrive->driveLin.b_linU, OS_U, corrections->correctU);
//		setParamHandWorkDetail(&oDrive->allDriveConditionParam.driveConditionParamV, &oCoordinates->phyCoord.V, &oCoordinates->baseCoord.V, &oDrive->driveMask.m_krokV, &oDrive->driveMask.mikro_krokV, &oDrive->driveLin.b_linV, OS_V, corrections->correctV);
//		setParamHandWorkDetail(&oDrive->allDriveConditionParam.driveConditionParamZw, &oCoordinates->phyCoord.Zw, &oCoordinates->baseCoord.Zw, &oDrive->driveMask.m_krokZw, &oDrive->driveMask.mikro_krokZw, 0, OS_Zw, corrections->correctZw);

//		oDrive->tabOfValueFeed[0]=1; //1um/s
//		oDrive->tabOfValueFeed[1]=2;
//		oDrive->tabOfValueFeed[2]=5;
//		oDrive->tabOfValueFeed[3]=7;
//		oDrive->tabOfValueFeed[4]=11;
//		oDrive->tabOfValueFeed[5]=16;
//		oDrive->tabOfValueFeed[6]=22;
//		oDrive->tabOfValueFeed[7]=32;
//		oDrive->tabOfValueFeed[8]=47;
//		oDrive->tabOfValueFeed[9]=67;
//		oDrive->tabOfValueFeed[10]=95;
//		oDrive->tabOfValueFeed[11]=137;
//		oDrive->tabOfValueFeed[12]=203;
//		oDrive->tabOfValueFeed[13]=282;
//		oDrive->tabOfValueFeed[14]=425;
//		oDrive->tabOfValueFeed[15]=567;

//		//zainicjowanie wskaźników funkcji
//		oDrive->setFeedrateParamByDefaultValues=setWireFeedrateParamByDefaultValues;
//		oDrive->setSygPortDRIVE=setSygPortDRIVE;
//		oDrive->setSingleSygPortDRIVE=setSingleSygPortDRIVE;

//		oDrive->ruch_do_przodu=ruch_do_przodu;
//		oDrive->ruch_do_tylu=ruch_do_tylu;
//		oDrive->spr_ruch_do_tylu=spr_ruch_do_tylu;
//		oDrive->spr_ruch_do_przodu=spr_ruch_do_przodu;

//		oDrive->getClockDividerResponsibleForDriveSpeed=getClockDividerResponsibleForDriveSpeed;
//		oDrive->calculateAccelerateNumberOfSteps=calculateAccelerateNumberOfSteps;

//		oDrive->brakingDrive=brakingDrive;
//		oDrive->driveAXES=driveAXES;

//		oDrive->driveForValue=driveForValue;
//		oDrive->driveToBaseCoordinates=driveToBaseCoordinates;
//		oDrive->driveToPhyCoordinates=driveToPhyCoordinates;
//		oDrive->driveToCharacteristicPoint=driveToCharacteristicPoint;
//		oDrive->driveToLimstop=driveToLimstop;

////		oDrive->driveEngineService=driveEngineService;
//		oDrive->setDirectionDriveConditional=setDirectionDriveConditional;
//		oDrive->driveConditionalService=driveConditionalService;
//		oDrive->driveCentering=driveCentering;
//		oDrive->driveWirePlating=driveWirePlating;

//		oDrive->setParamHandWorkDetail=setParamHandWorkDetail;
//		oDrive->setDirectionAndClearAuxParamHandWorkDetail=setDirectionAndClearAuxParamHandWorkDetail;
//		oDrive->copyParamHandWorkDetail=copyParamHandWorkDetail;
//		oDrive->copyDirectionAndClearAuxParamHandWorkDetail=copyDirectionAndClearAuxParamHandWorkDetail;

//		oDrive->drivePathSetSectionParam=drivePathSetSectionParam;
//		oDrive->drivePathSetArcParam=drivePathSetArcParam;
//		oDrive->getRealEndOfArc=getRealEndOfArc;
//		oDrive->drivePath=drivePath;
//		oDrive->drivePathService=drivePathService;

//		oDrive->setLinMask=setLinMask;
//}



//void setFeedrateList(SItemsParam *itemsParam, uint32_t language){

//		itemsParam->itemsList=&driveFeedrate[language];

//}	


//void setWireFeedrateParamByDefaultValues(SDriveFeedrate *feedrate){

//		feedrate->feed.accelerationMMperSEC2=2;
//		feedrate->feed.velocityUMperSEC.value=feedrate_DEFAULT_VALUE;
//		feedrate->feed.auxVelocityUMperSEC=feedrate_NO_VALUE;
//		feedrate->feed.velocityUMperSEC.upperLimit=feedrateMAX;
//		feedrate->feed.velocityUMperSEC.lowerLimit=feedrateMIN;
//		feedrate->feed.velocityUMperSEC.precision=1;

//		feedrate->feedJog.accelerationMMperSEC2=feedrateJog_ACCELERATION;
//		feedrate->feedJog.velocityUMperSEC.value=feedrateJog_DEFAULT_VALUE;
//		feedrate->feedJog.auxVelocityUMperSEC=feedrate_NO_VALUE;
//		feedrate->feedJog.velocityUMperSEC.upperLimit=feedrateJogMAX;
//		feedrate->feedJog.velocityUMperSEC.lowerLimit=feedrateJogMIN;
//		feedrate->feedJog.velocityUMperSEC.precision=1;

//}

//void setDrillFeedrateParamByDefaultValues(SDriveFeedrate *feedrate){

//		feedrate->feed.accelerationMMperSEC2=2;
//		feedrate->feed.velocityUMperSEC.value=drillFeedrate_DEFAULT_VALUE;
//		feedrate->feed.auxVelocityUMperSEC=drillFeedrate_DEFAULT_VALUE;
//		feedrate->feed.velocityUMperSEC.upperLimit=drillFeedrateMAX;
//		feedrate->feed.velocityUMperSEC.lowerLimit=drillFeedrateMIN;
//		feedrate->feed.velocityUMperSEC.precision=1;

//		feedrate->feedJog.accelerationMMperSEC2=drillFeedrateJog_ACCELERATION;
//		feedrate->feedJog.velocityUMperSEC.value=drillFeedrateJog_DEFAULT_VALUE;
//		feedrate->feedJog.auxVelocityUMperSEC=drillFeedrateJog_DEFAULT_VALUE;
//		feedrate->feedJog.velocityUMperSEC.upperLimit=drillFeedrateJogMAX;
//		feedrate->feedJog.velocityUMperSEC.lowerLimit=drillFeedrateJogMIN;
//		feedrate->feedJog.velocityUMperSEC.precision=1;

//}

//static void getDriveMaskFromBackup(SDriveMask *driveMask){
//	
//	driveMask->m_krokX=restoreDriveMaskFromBackup(MKROK_X_BKP);
//	driveMask->m_krokY=restoreDriveMaskFromBackup(MKROK_Y_BKP);
//	driveMask->m_krokZ=restoreDriveMaskFromBackup(MKROK_Z_BKP);
//	driveMask->m_krokU=restoreDriveMaskFromBackup(MKROK_U_BKP);
//	driveMask->m_krokV=restoreDriveMaskFromBackup(MKROK_V_BKP);
//	driveMask->m_krokZw=restoreDriveMaskFromBackup(MKROK_ZW_BKP);

//	driveMask->m_krokX_spr=driveMask->m_krokX;	//ustawiamy maski sprawdzające dla wszystkich osi (konieczne nawet w przypadku gdy domyślnie włączone są liniały, ze względu na możliwość włączenia liniałów tylko dla dwóch osi)
//	driveMask->m_krokY_spr=driveMask->m_krokY;
//	driveMask->m_krokZ_spr=driveMask->m_krokZ;
//	driveMask->m_krokU_spr=driveMask->m_krokU;
//	driveMask->m_krokV_spr=driveMask->m_krokV;
//	driveMask->m_krokZw_spr=driveMask->m_krokZw;

//}

//static uint16_t restoreDriveMaskFromBackup(uint16_t driveMaskFromBackup){
//	uint16_t driveMask=0x3333;	


//	switch(driveMaskFromBackup){
//		case 0x0: driveMask=0xCCCC; break;
//		case 0x1: driveMask=0x9999; break;
//		case 0x2: driveMask=0x6666; break;
//		case 0x3: driveMask=0x3333; break;

//	}
//	return driveMask;
//}



map<char, int> defODriveMachine::getPhyCoordValues(){
	map<char, int> values;
	
	for(vector<defOMotorDriver*>::iterator it=motors->begin(); it != motors->end(); ++it){
		values.insert(pair<char,int>((*it)->phyCoord.first, (*it)->phyCoord.second->getValue()));
		
	}
	return values;
}





//funkcje związane z przejazdami w pracy ręcznej
void defODriveMachine::setParToDriveForValue(map<char, int> values){

	map<char, int>::iterator values_it;
	
	phyStartPoint=getPhyCoordValues();
	phyEndPoint=phyStartPoint;
	phyVector=phyStartPoint;
	
	
	for(vector<defOMotorDriver*>::iterator it=motors->begin(); it != motors->end(); ++it){
		values_it=values.find((*it)->phyCoord.first);
		if(values_it!=values.end())phyEndPoint.find((*it)->phyCoord.first)->second+=values_it->second;
		phyVector.find((*it)->phyCoord.first)->second=phyEndPoint.find((*it)->phyCoord.first)->second-phyStartPoint.find((*it)->phyCoord.first)->second;
	}

														
}

void defODriveMachine::setParToDriveToBaseCoordinates(map<char, int> values){
	
	map<char, int>::iterator values_it;
	
	phyStartPoint=getPhyCoordValues();
	phyEndPoint=phyStartPoint;
	phyVector=phyStartPoint;
	
	
	for(vector<defOMotorDriver*>::iterator it=motors->begin(); it != motors->end(); ++it){
		values_it=values.find((*it)->phyCoord.first);
		if(values_it!=values.end())phyEndPoint.find((*it)->phyCoord.first)->second+=(values_it->second-(*it)->baseCoord.second->getValue());
		phyVector.find((*it)->phyCoord.first)->second=phyEndPoint.find((*it)->phyCoord.first)->second-phyStartPoint.find((*it)->phyCoord.first)->second;
	}
																				
}

//static int32_t driveToPhyCoordinates(defOCoordinates *oCoordinates, defOCheckSignals* oCheckSignalsLimitedStop, SDriveParam *driveParam, int32_t *infoDrive, defOMenu *oMenu, 
//																		uint32_t language, xQueueHandle qToDoMark, SFeedrate *feedrateJog){
//	int32_t answer;

//	oCoordinates->setCoord(&driveParam->pointA, oCoordinates->phyCoord);
//	oCoordinates->setCoord(&driveParam->pointB, oCoordinates->auxCoord);

//	checkCorrectnesCoordinates(&oCoordinates->auxCoord);
//																			
//	oCoordinates->setVector(&driveParam->vectorAB, driveParam->pointB, driveParam->pointA);

//	answer=drive(oCoordinates, driveParam, infoDrive, oMenu, oCheckSignalsLimitedStop, language, qToDoMark, feedrateJog);	

//	return answer;
//}


//static int32_t driveToCharacteristicPoint(defOCoordinates *oCoordinates, defOCheckSignals* oCheckSignalsLimitedStop, SDriveParam *driveParam, int32_t *infoDrive, defOMenu *oMenu, 
//																					uint32_t language, defOMachineConfig *oMachineConfig, xQueueHandle qToDoMark, SFeedrate *feedrateJog){
//	int32_t answer;

//	oCoordinates->setCoord(&driveParam->pointA, oCoordinates->phyCoord);
//	oCoordinates->setCoord(&driveParam->pointB, oCoordinates->phyCoord);	

//	driveParam->pointB.X.value=oMachineConfig->rangeX_UM*pow(10, oCoordinates->phyCoord.X.unit-3)/2;
//	driveParam->pointB.Y.value=oMachineConfig->rangeY_UM*pow(10, oCoordinates->phyCoord.Y.unit-3)/2;
//	driveParam->pointB.Z.value=oMachineConfig->rangeZ_UM*pow(10, oCoordinates->phyCoord.Z.unit-3)/2;
//	driveParam->pointB.U.value=oMachineConfig->rangeU_UM*pow(10, oCoordinates->phyCoord.U.unit-3)/2;
//	driveParam->pointB.V.value=oMachineConfig->rangeV_UM*pow(10, oCoordinates->phyCoord.V.unit-3)/2;

//	checkCorrectnesCoordinates(&driveParam->pointB);
//																						
//	oCoordinates->setVector(&driveParam->vectorAB, driveParam->pointB, driveParam->pointA);
//	answer=drive(oCoordinates, driveParam, infoDrive, oMenu, oCheckSignalsLimitedStop, language, qToDoMark, feedrateJog);

//	return answer;
//}

//static int32_t driveToLimstop(defOCoordinates *oCoordinates, defOCheckSignals* oCheckSignalsLimitedStop, SDriveParam *driveParam, int32_t *infoDrive, defOMenu *oMenu, 
//															_Bool *phyCoordIgnorance, uint32_t language, defOMachineConfig *oMachineConfig, xQueueHandle qToDoMark, SFeedrate *feedrateJog){
//	int32_t answer;

//	#if defined(AC_SERVO)
//		feedrateJog->velocityTabIndex.value=2;
//	#endif

//	oCoordinates->setCoord(&driveParam->pointA, oCoordinates->phyCoord);

//	driveParam->pointB.X.value=oCoordinates->phyCoord.X.value-oMachineConfig->rangeX_UM*pow(10, oCoordinates->phyCoord.X.unit-3);
//	driveParam->pointB.Y.value=oCoordinates->phyCoord.Y.value-oMachineConfig->rangeY_UM*pow(10, oCoordinates->phyCoord.Y.unit-3);
//	driveParam->pointB.Z.value=oCoordinates->phyCoord.Z.value+oMachineConfig->rangeZ_UM*pow(10, oCoordinates->phyCoord.Z.unit-3);
//	driveParam->pointB.U.value=oCoordinates->phyCoord.U.value-oMachineConfig->rangeU_UM*pow(10, oCoordinates->phyCoord.U.unit-3);
//	driveParam->pointB.V.value=oCoordinates->phyCoord.V.value-oMachineConfig->rangeV_UM*pow(10, oCoordinates->phyCoord.V.unit-3);

//	oCoordinates->setVector(&driveParam->vectorAB, driveParam->pointB, driveParam->pointA);

//	*phyCoordIgnorance=true;
//	answer=drive(oCoordinates, driveParam, infoDrive, oMenu, oCheckSignalsLimitedStop, language, qToDoMark, feedrateJog);

//	if((oCheckSignalsLimitedStop->checkedSetSignals & kKRAN_Xmin) && (oCheckSignalsLimitedStop->checkedSetSignals & kKRAN_Ymin) && ((oCheckSignalsLimitedStop->checkedSetSignals & kKRAN_Zplus) || oMachineConfig->rangeZ_UM==0 )){	//jezeli najazd nastąpił na wszystkie zadane krancowki to zeruj wspolrzedne fizyczne
//		oCoordinates->clearCoord(&oCoordinates->phyCoord);	//najpierw zerujemy współrzędne fizyczne a potem zjeżdżamy z krańcówek (chodzi o to, aby zjechać ze wsp. (0, 0, 0))
//		oCoordinates->phyCoord.Z.value=oMachineConfig->rangeZ_UM*pow(10, oCoordinates->phyCoord.Z.unit-3);
//	}else{
//		answer=LACK_OF_PUSH_LIMSTOP;
//	}


//	*phyCoordIgnorance=false;

//	return answer;
//}



//int32_t drive(defOCoordinates *oCoordinates, SDriveParam *driveParam, int32_t *infoDrive, defOMenu *oMenu, defOCheckSignals* oCheckSignalsLimitedStop, 
//							uint32_t language, xQueueHandle qToDoMark, SFeedrate *feedrateJog){
//		portTickType taskCount;
//		defOButtonMarks oButtonMarks;
//								
//													
//		OButtonMarksConstruct(&oButtonMarks);

//		taskCount=xTaskGetTickCount();

//		(*infoDrive)=DRIVE_IN_PROGRESS;
//		oCoordinates->setCoord(&driveParam->indirectCoord, driveParam->pointB);
//			
//		while((*infoDrive)!=PRZEJ_ZREALIZOWANO && (*infoDrive)!=PRZEJ_PORZUCONO){		

//			driveTIM();

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


//			if((*infoDrive)==PRZEJ_SPAUZOWANO){		
//				stopDrive(oCoordinates, oMenu, driveParam, infoDrive, language, qToDoMark);	
//				taskCount=xTaskGetTickCount();
//			}

//			vTaskDelayUntil(&taskCount, pd100US_TO_TICKS(10000/BASE_FREQUENCY_OF_TIMdrive));
//		}
//		
//		oCheckSignalsLimitedStop->madeSignals=0;

//		return (*infoDrive);

//}

//void brakingDrive(SParam *wsp_fiz, int32_t wsp_A, int32_t wsp_B, int32_t *wsp_pos, SFeedrate* feedrate){
//		uint32_t l_krok1=0, l_krok2=0;
//		uint32_t accelerateNumberOfSteps;

//		accelerateNumberOfSteps=calculateAccelerateNumberOfSteps(feedrate, wsp_fiz->precision);

//		l_krok1=abs_pp(wsp_fiz->value-wsp_A)/wsp_fiz->precision;
//		l_krok2=(abs_pp(wsp_B-wsp_A)/wsp_fiz->precision)-l_krok1;

//		if(l_krok1+l_krok2>2*accelerateNumberOfSteps){
//			if(l_krok1<accelerateNumberOfSteps)l_krok2=l_krok1;
//			else if(l_krok1>accelerateNumberOfSteps && l_krok2>accelerateNumberOfSteps)l_krok2=accelerateNumberOfSteps;
//		}else{
//			if(l_krok1<l_krok2)l_krok2=l_krok1;
//		}

//		//określenie zwrotu ruchu aby określić czy dodać czy odjąć obliczoną wartość drogi hamowania
//		if(wsp_B-wsp_fiz->value>0)*wsp_pos=wsp_fiz->value+(l_krok2*wsp_fiz->precision);
//		else *wsp_pos=wsp_fiz->value-(l_krok2*wsp_fiz->precision);

//}

//void stopDrive(defOCoordinates *oCoordinates, defOMenu *oMenu, SDriveParam *driveParam, int32_t *infoDrive, uint32_t language, xQueueHandle qToDoMark){
//		defOButtonMarks oButtonMarks;

//		OButtonMarksConstruct(&oButtonMarks);	

//	//	driveParam->activeDrive=PAUSE_DRIVE;
//		oMenu->setPopupMenu(&oMenu->menuParam, MENU_CONTINUE_DROP, language);
//		
//		while(1){
//			xQueueReceive(qToDoMark, &oButtonMarks.toDoMark.mark, portMAX_DELAY);
//			oButtonMarks.decodeToDoMark(&oButtonMarks.toDoMark);
//	
//			if(oButtonMarks.toDoMark.tag==TAG_MENU_PODR_1 || oButtonMarks.toDoMark.key==KEY_F1|| oButtonMarks.toDoMark.atc==AT_TAG_CONT){ 		//jezeli zadeklarowano "jedz dalej" to kontynuuj wykonywanie przejazdu
//				oCoordinates->setCoord(&driveParam->pointA, driveParam->indirectCoord);
//				oCoordinates->setCoord(&driveParam->indirectCoord, driveParam->pointB);
//				(*infoDrive)=DRIVE_IN_PROGRESS;
//	//			driveParam->activeDrive=ACTIVE_DRIVE;
//				break;
//			}else if(oButtonMarks.toDoMark.tag==TAG_MENU_PODR_2 || oButtonMarks.toDoMark.key==KEY_F2 || oButtonMarks.toDoMark.atc==AT_TAG_ABORT 
//						|| oButtonMarks.toDoMark.tag==TAG_ESC || oButtonMarks.toDoMark.key==KEY_ESC){ 	//jezeli zadeklarowano "porzuc" to zakoncz wykonywanie przejazdu
//				(*infoDrive)=PRZEJ_PORZUCONO;
//				break;
//			}
//		}

//		oMenu->setPopupMenu(&oMenu->menuParam, MENU_STOP, language);
//}


//static void driveAXES(SParam* phyCoord, SParam* baseCoord, int32_t indirectCoord, uint16_t *m_step, uint16_t *micro_step, uint8_t *b_lin, fDRIVE_TypeDef *errorDrive, _Bool phyCoordIgnorance, SCorrection *correct, uint32_t features){
//			int32_t distance;

//			distance=indirectCoord-phyCoord->value;
//	

//			if(distance!=0){	
//				
////				if(distance<=STEP){
////					phyCoord->precision=EXACT_STEP;
////					baseCoord->precision=EXACT_STEP;
////					*micro_step=STEP_1_4;
////				}else if(phyCoord->value%STEP==0){
////					phyCoord->precision=STEP;
////					baseCoord->precision=STEP;
////					*micro_step=FULL_STEP;
////				}
//				
//				
//				if(distance>0){
//					ruch_do_przodu(m_step, phyCoord, baseCoord, b_lin, errorDrive, correct, features);
//				}else{
//					ruch_do_tylu(m_step, phyCoord, baseCoord, b_lin, errorDrive, phyCoordIgnorance, correct, features);
//				}	
//			}
//}


//------------------------------------------------------


//funkcje związane z przejazdami w pracy automatycznej

//uint8_t findMasterAxis(SCoordinates vector, defOCoordinates *oCoordinates){

//	uint32_t l_krX, l_krY, l_krZ, l_krU, l_krV, l_krZw;

//	l_krX=abs_pp(vector.X.value)/oCoordinates->phyCoord.X.precision;
//	l_krY=abs_pp(vector.Y.value)/oCoordinates->phyCoord.Y.precision;
//	l_krZ=abs_pp(vector.Z.value)/oCoordinates->phyCoord.Z.precision;
//	l_krU=abs_pp(vector.U.value)/oCoordinates->phyCoord.U.precision;
//	l_krV=abs_pp(vector.V.value)/oCoordinates->phyCoord.V.precision;
//	l_krZw=abs_pp(vector.Zw.value)/oCoordinates->phyCoord.Zw.precision;

//	if(l_krX>=l_krY && l_krX>=l_krZ && l_krX>=l_krU && l_krX>=l_krV && l_krX>=l_krZw) return OS_X;
//	else if(l_krY>=l_krZ  && l_krY>=l_krU && l_krY>=l_krV && l_krY>=l_krZw) return OS_Y;
//	else if(l_krZ>=l_krU && l_krZ>=l_krV && l_krZ>=l_krZw) return OS_Z;
//	else if(l_krU>=l_krV && l_krU>=l_krZw) return OS_U;
//	else if(l_krV>=l_krZw) return OS_V;
//	return OS_Zw;
//}


//void drivePathSetSectionParam(SDrivePathParam *drivePathParam, SCoordinates pointA, SCoordinates pointB, defOCoordinates *oCoordinates, _Bool driveToFirstDischarge){

//			drivePathParam->typeOfDrive=T_PROSTA;
//			drivePathParam->startDetErrSEG=false;
//			drivePathParam->driveToFirstDischarge=driveToFirstDischarge;

//			oCoordinates->setCoord(&drivePathParam->pointA, pointA);
//			oCoordinates->setCoord(&drivePathParam->pointB, pointB);

//			oCoordinates->setVector(&drivePathParam->vectorAB, drivePathParam->pointB, drivePathParam->pointA);

//			drivePathParam->masterAxis=findMasterAxis(drivePathParam->vectorAB, oCoordinates);
//			getPositionOfTheSection(drivePathParam, oCoordinates);

////			switch(drivePathParam->masterAxis){	//znalezienie największego przesunięcia w osiach X, Y, Z
////				case OS_X:
////					drivePathParam->hypSumStepOfSEG=abs_pp(drivePathParam->nPointX-drivePathParam->pointA.X)/step;	//obliczenie ilości kroków które już zostały wykonane (np. przed ponownym włączeniem maszyny)
////					break;
////				case OS_Y:
////					drivePathParam->hypSumStepOfSEG=abs_pp(drivePathParam->nPointY-drivePathParam->pointA.Y)/step;
////					break;
////				case OS_Z:
////					drivePathParam->hypSumStepOfSEG=abs_pp(drivePathParam->nPointZ-drivePathParam->pointA.Z)/step;
////					break;
////				case OS_U:
////					drivePathParam->hypSumStepOfSEG=abs_pp(drivePathParam->nPointU-drivePathParam->pointA.U)/step;	
////					break;
////				case OS_V:
////					drivePathParam->hypSumStepOfSEG=abs_pp(drivePathParam->nPointV-drivePathParam->pointA.V)/step;	
////					break;
////			}


//}


//void drivePathSetArcParam(SDrivePathParam *drivePathParam, SCoordinates circleCenter, SCoordinates pointA, SCoordinates pointB, defTurnCircle turnCircle, defOCoordinates *oCoordinates){

//			drivePathParam->typeOfDrive=T_LUK;
//			drivePathParam->startDetErrSEG=false;
//			drivePathParam->turnCircle=turnCircle;
//			drivePathParam->driveToFirstDischarge=false;
//			oCoordinates->setCoord(&drivePathParam->pointA, pointA);
//			oCoordinates->setCoord(&drivePathParam->pointB, pointB);
//			oCoordinates->setCoord(&drivePathParam->kB, pointA);
//			oCoordinates->setCoord(&drivePathParam->circleCenter, circleCenter);
//			drivePathParam->circleR2=pow(drivePathParam->circleCenter.X.value-drivePathParam->pointA.X.value, 2)+pow(drivePathParam->circleCenter.Y.value-drivePathParam->pointA.Y.value, 2);

////			drivePathParam->nrOfStepCircle=calculateNrOfStepCircle(drivePathParam, &drivePathParam->pointB);
////			drivePathParam->hypSumStepOfSEG=calculateNrOfStepCircle(drivePathParam, &oCoordinates->phyCoord);

//			drivePathParam->nrOfStepCircleXY=calculateNrOfStepCircle(drivePathParam, &drivePathParam->pointB, oCoordinates);
//			drivePathParam->nrOfStepCircleZ=abs_pp((drivePathParam->pointB.Z.value-drivePathParam->pointA.Z.value)/oCoordinates->phyCoord.Z.precision);

//			if(drivePathParam->nrOfStepCircleZ>drivePathParam->nrOfStepCircleXY){
//				drivePathParam->nrOfStepCircle=&drivePathParam->nrOfStepCircleZ;
//				drivePathParam->dividerZ=1;
//				if(drivePathParam->nrOfStepCircleXY>0)drivePathParam->dividerXY=(double)drivePathParam->nrOfStepCircleZ/drivePathParam->nrOfStepCircleXY;
//				else drivePathParam->dividerXY=drivePathParam->nrOfStepCircleZ+1;
//			}else{
//				drivePathParam->nrOfStepCircle=&drivePathParam->nrOfStepCircleXY;
//				drivePathParam->dividerXY=1;
//				if(drivePathParam->nrOfStepCircleZ>0)drivePathParam->dividerZ=(double)drivePathParam->nrOfStepCircleXY/drivePathParam->nrOfStepCircleZ;
//				else drivePathParam->dividerZ=drivePathParam->nrOfStepCircleXY+1;
//			}

//			getPositionOfTheArc(drivePathParam, oCoordinates);

//}

//void getPositionOfTheArc(SDrivePathParam *drivePathParam, defOCoordinates *oCoordinates){

//			oCoordinates->setCoord(&drivePathParam->kB, oCoordinates->phyCoord);

//			if(drivePathParam->nrOfStepCircleZ>drivePathParam->nrOfStepCircleXY){
//				drivePathParam->hypSumStepOfSEG=abs_pp((oCoordinates->phyCoord.Z.value-drivePathParam->pointA.Z.value)/oCoordinates->phyCoord.Z.precision);
//				drivePathParam->nrOfMadeStepCircleZ=drivePathParam->hypSumStepOfSEG;
//				drivePathParam->nrOfMadeStepCircleXY=(uint32_t)((double)drivePathParam->hypSumStepOfSEG/drivePathParam->dividerXY);
//			}else{
//				drivePathParam->hypSumStepOfSEG=calculateNrOfStepCircle(drivePathParam, &oCoordinates->phyCoord, oCoordinates);
//				drivePathParam->nrOfMadeStepCircleXY=drivePathParam->hypSumStepOfSEG;
//				drivePathParam->nrOfMadeStepCircleZ=(uint32_t)((double)drivePathParam->hypSumStepOfSEG/drivePathParam->dividerZ);
//			}

//}



//int32_t drivePath(defOCoordinates *oCoordinates, SDrivePathParam *drivePathParam, defOFlashCoordDeparture *oFlashCoordDeparture, SFeedrate *feedrate, int32_t *infoDrive, 
//									defOMenu *oMenu, defOSystemsData *oSystemsData, uint32_t language, xQueueHandle qToDoMark, uint32_t timeOfDelay, xQueueHandle qToDoMarkTools){
//		portTickType taskCount;							

//			taskCount=xTaskGetTickCount();

//			if((*infoDrive)!=PRZEJ_SPAUZOWANO && (*infoDrive)!=PRZEJ_PRZERWANY){	
//				(*infoDrive)=DRIVE_IN_PROGRESS;
//			}


//			while((*infoDrive)!=BACK_TO_START && (*infoDrive)!=PRZEJ_ZREALIZOWANO && (*infoDrive)!=PRZEJ_PORZUCONO && 
//						(*infoDrive)!=GO_TO_NEXT_SEGMENT && (*infoDrive)!=GO_TO_PREVIOUS_SEGMENT && (*infoDrive)!=DEPARTURE){					
//													
//							
//				if((*infoDrive)==PRZEJ_SPAUZOWANO || (*infoDrive)==PRZEJ_PRZERWANY){	
//					uint32_t auxTag=AT_TAG_ALL_TOOLS_OFF | qMARK_ATC;
//					xQueueSendToBack(qToDoMarkTools, &auxTag, 0);
//		

//					if((*infoDrive)==PRZEJ_SPAUZOWANO){
//						oFlashCoordDeparture->initWriteFlash(&oFlashCoordDeparture->flashParam);
//						oFlashCoordDeparture->writeFlashCoordDeparture(oCoordinates->phyCoord.X.value, oCoordinates->phyCoord.Y.value, oCoordinates->phyCoord.Z.value, oCoordinates->phyCoord.U.value, oCoordinates->phyCoord.V.value, oCoordinates->phyCoord.Zw.value, &oFlashCoordDeparture->flashParam);
//					}
//		
//					stopDrivePath(oCoordinates, oFlashCoordDeparture, drivePathParam, infoDrive, oMenu, oSystemsData, language, qToDoMark);

//					taskCount=xTaskGetTickCount();
//				}else if(timeOfDelay==0){
//					drivePathTIM(true);
//				}else if(timeOfDelay>0){
//					timeOfDelay--;
//					drivePathTIM(false);
//	//				vTaskDelayUntil(&taskCount, pdMS_TO_TICKS(1));
//				}
//	//			else{
//	//				vTaskDelayUntil(&taskCount, pd100US_TO_TICKS(10000*getClockDividerInUniformMovement(feedrate, BASE_FREQUENCY_OF_TIMdrivePath)/BASE_FREQUENCY_OF_TIMdrivePath));
//	//			}
//				
//				vTaskDelayUntil(&taskCount, pd100US_TO_TICKS(10000/BASE_FREQUENCY_OF_TIMdrivePath));
//		//		vTaskDelayUntil(&taskCount, pd100US_TO_TICKS(10));
//			}


//		return (*infoDrive);

//}


//void stopDrivePath(defOCoordinates *oCoordinates, defOFlashCoordDeparture *oFlashCoordDeparture, SDrivePathParam *drivePathParam, int32_t *infoDrive, 
//									defOMenu *oMenu, defOSystemsData *oSystemsData, uint32_t language, xQueueHandle qToDoMark){
//		defOButtonMarks oButtonMarks;

//		OButtonMarksConstruct(&oButtonMarks);	

//		oSystemsData->oTimeOfWork.clockActive=false;
//		oSystemsData->oOverallWorkingTime.clockActive=false;
//		oMenu->setPopupMenu(&oMenu->menuParam, MENU_AUT_WORK_PAUSE, language);
//		drivePathParam->activeDrivePath=PAUSE_DRIVE;
//	//	drivePathParam->pauseDrivePath=true;

//		xSemaphoreGive(xDrive);						
//		{
//			while(1){
//				xQueueReceive(qToDoMark, &oButtonMarks.toDoMark.mark, portMAX_DELAY);
//				oButtonMarks.decodeToDoMark(&oButtonMarks.toDoMark);
//				
//				if(oButtonMarks.toDoMark.tag==TAG_MENU_PODR_1 || oButtonMarks.toDoMark.key==KEY_F1 || oButtonMarks.toDoMark.atc==AT_TAG_CONT){ 		//jezeli zadeklarowano "jedz dalej" to kontynuuj wykonywanie przejazdu

//					oFlashCoordDeparture->initReadFlash(&oFlashCoordDeparture->flashParam);
//					oFlashCoordDeparture->readFlashCoordDeparture(&oCoordinates->auxCoord.X.value, &oCoordinates->auxCoord.Y.value, &oCoordinates->auxCoord.Z.value, &oCoordinates->auxCoord.U.value, &oCoordinates->auxCoord.V.value, &oCoordinates->auxCoord.Zw.value, &oFlashCoordDeparture->flashParam);
//					oFlashCoordDeparture->initWriteFlash(&oFlashCoordDeparture->flashParam);

//					if(oCoordinates->auxCoord.X.value==0xFFFFFFFF || oCoordinates->comparingCoordinates(oCoordinates->phyCoord, oCoordinates->auxCoord)){
//						(*infoDrive)=DRIVE_IN_PROGRESS;	
//					}else{
//						(*infoDrive)=DEPARTURE;
//					}
//					oMenu->setPopupMenu(&oMenu->menuParam, MENU_STOP, language);
//					oSystemsData->oTimeOfWork.clockActive=true;
//					oSystemsData->oOverallWorkingTime.clockActive=true;
//					break;
//				}else if(oButtonMarks.toDoMark.tag==TAG_MENU_PODR_2 || oButtonMarks.toDoMark.key==KEY_F2 || oButtonMarks.toDoMark.atc==AT_TAG_SEGNEXT){ 
//					(*infoDrive)=GO_TO_NEXT_SEGMENT;
//					break;
//				}else if(oButtonMarks.toDoMark.tag==TAG_MENU_PODR_3 || oButtonMarks.toDoMark.key==KEY_F3 || oButtonMarks.toDoMark.atc==AT_TAG_SEGBACK){ 	
//					(*infoDrive)=GO_TO_PREVIOUS_SEGMENT;
//					break;
//				}else if(oButtonMarks.toDoMark.tag==TAG_MENU_PODR_4 || oButtonMarks.toDoMark.key==KEY_F4 || oButtonMarks.toDoMark.atc==AT_TAG_ABORT){ 	//jezeli zadeklarowano "porzuc" to zakoncz wykonywanie przejazdu
//					(*infoDrive)=PRZEJ_PORZUCONO;
//					break;
//				}
//			}
//		}
//		xSemaphoreTake(xDrive, portMAX_DELAY);

//		drivePathParam->activeDrivePath=ACTIVE_DRIVE;
//	//	drivePathParam->pauseDrivePath=false;

//}


//void drivePathService(SDrivePathParam *drivePathParam, defTurn turn, SDriveMask *driveMask, int32_t *infoDrive, fDRIVE_TypeDef *errorDrive, SDriveLin *driveLin, defOAutWork *oAutWork, SFeedrate* feedrate, 
//											defOCoordinates *oCoordinates, SCorrectionAllAxes *corrects, uint32_t features){

//		switch(turn){
//			case PRZOD:
//					if(oCoordinates->comparingCoordinates(drivePathParam->pointB, oCoordinates->phyCoord)){	
//						(*infoDrive)=PRZEJ_ZREALIZOWANO; //jezeli wszystkie silniki zrealizowaly swoje przejazdy to ustaw flage kończącą segment
//					}else{
//						if(drivePathParam->typeOfDrive==T_PROSTA){
//							uint32_t moveAxis=OS_NULL;
//							
//							moveAxis=drivePathSection(drivePathParam, drivePathParam->pointA, drivePathParam->pointB, driveMask, errorDrive, driveLin, oCoordinates, feedrate, corrects, features); 
//							if(moveAxis!=OS_NULL)drivePathParam->stepOfContour++;
//						}else if(drivePathParam->typeOfDrive==T_LUK){
//							drivePathArc(drivePathParam, drivePathParam->pointB, driveMask, errorDrive, driveLin, oCoordinates, feedrate, drivePathParam->pointB.Z.value-drivePathParam->pointA.Z.value, drivePathParam->turnCircle, turn, corrects, features);
//							drivePathParam->stepOfContour++;
//						}
//						setSygPortDRIVE(driveMask);
//					}
//					break;
//			case TYL:
//					if(oCoordinates->comparingCoordinates(drivePathParam->pointA, oCoordinates->phyCoord)){//jezeli wszystkie silniki wróciły do punktu startu to...
//						(*infoDrive)=BACK_TO_START; 
//					}else{
//						if(drivePathParam->typeOfDrive==T_PROSTA){
//							uint32_t moveAxis=OS_NULL;
//							
//							moveAxis=drivePathSection(drivePathParam, drivePathParam->pointB, drivePathParam->pointA, driveMask, errorDrive, driveLin, oCoordinates, feedrate, corrects, features); 
//							if(moveAxis!=OS_NULL)drivePathParam->stepOfContour--;
//						}else if(drivePathParam->typeOfDrive==T_LUK){
//							drivePathArc(drivePathParam, drivePathParam->pointA, driveMask, errorDrive, driveLin, oCoordinates, feedrate, drivePathParam->pointA.Z.value-drivePathParam->pointB.Z.value, (1-drivePathParam->turnCircle), turn, corrects, features);
//							drivePathParam->stepOfContour--;
//						}
//						setSygPortDRIVE(driveMask);
//					}
//					break;
//		}

//}

//uint32_t drivePathSection(SDrivePathParam *drivePathParam, SCoordinates pointA, SCoordinates pointB, SDriveMask *driveMask, fDRIVE_TypeDef *errorDrive, SDriveLin *driveLin, 
//										defOCoordinates *oCoordinates, SFeedrate* feedrate, SCorrectionAllAxes *corrects, uint32_t features){
//			static uint32_t toogleX=OS_X;
//			static _Bool pauseStep=false;
//			_Bool realizePauseStep=false;				
//			double t=0, nPt=0;	
//			uint32_t moveAxis=OS_NULL;
//			double halfStep=0;
//											
//										


//			//jeżeli oś wiodąca dojechała do swojej pozycji, to wszystkimi osiami najkrótszą drogą podążamy do punktu docelowego
//			if((drivePathParam->masterAxis==OS_X && pointB.X.value==oCoordinates->phyCoord.X.value) || 
//					(drivePathParam->masterAxis==OS_Y && pointB.Y.value==oCoordinates->phyCoord.Y.value) || 
//					(drivePathParam->masterAxis==OS_Z && pointB.Z.value==oCoordinates->phyCoord.Z.value) || 
//					(drivePathParam->masterAxis==OS_U && pointB.U.value==oCoordinates->phyCoord.U.value) ||
//					(drivePathParam->masterAxis==OS_V && pointB.V.value==oCoordinates->phyCoord.V.value) ||
//					(drivePathParam->masterAxis==OS_Zw && pointB.Zw.value==oCoordinates->phyCoord.Zw.value)){

//				pauseStep=false;
//						
//				oCoordinates->setVector(&drivePathParam->vectorAB, pointB, oCoordinates->phyCoord);

//				if(drivePathParam->vectorAB.X.value>0)ruch_do_przodu(&driveMask->m_krokX, &oCoordinates->phyCoord.X, &oCoordinates->baseCoord.X, &driveLin->b_linX, errorDrive, &corrects->correctX, features);
//				else if(drivePathParam->vectorAB.X.value<0)ruch_do_tylu(&driveMask->m_krokX, &oCoordinates->phyCoord.X, &oCoordinates->baseCoord.X, &driveLin->b_linX, errorDrive, false, &corrects->correctX, features);

//				if(drivePathParam->vectorAB.Y.value>0)ruch_do_przodu(&driveMask->m_krokY, &oCoordinates->phyCoord.Y, &oCoordinates->baseCoord.Y, &driveLin->b_linY, errorDrive, &corrects->correctY, features);
//				else if(drivePathParam->vectorAB.Y.value<0)ruch_do_tylu(&driveMask->m_krokY, &oCoordinates->phyCoord.Y, &oCoordinates->baseCoord.Y, &driveLin->b_linY, errorDrive, false, &corrects->correctY, features);

//				if(drivePathParam->vectorAB.Z.value>0)ruch_do_przodu(&driveMask->m_krokZ, &oCoordinates->phyCoord.Z, &oCoordinates->baseCoord.Z, 0, errorDrive, &corrects->correctZ, features); 
//				else if(drivePathParam->vectorAB.Z.value<0)ruch_do_tylu(&driveMask->m_krokZ, &oCoordinates->phyCoord.Z, &oCoordinates->baseCoord.Z, 0, errorDrive, false, &corrects->correctZ, features);
//		
//				if(drivePathParam->vectorAB.U.value>0)ruch_do_przodu(&driveMask->m_krokU, &oCoordinates->phyCoord.U, &oCoordinates->baseCoord.U, &driveLin->b_linU, errorDrive, &corrects->correctU, features);
//				else if(drivePathParam->vectorAB.U.value<0)ruch_do_tylu(&driveMask->m_krokU, &oCoordinates->phyCoord.U, &oCoordinates->baseCoord.U, &driveLin->b_linU, errorDrive, false, &corrects->correctU, features);

//				if(drivePathParam->vectorAB.V.value>0)ruch_do_przodu(&driveMask->m_krokV, &oCoordinates->phyCoord.V, &oCoordinates->baseCoord.V, &driveLin->b_linV, errorDrive, &corrects->correctV, features);
//				else if(drivePathParam->vectorAB.V.value<0)ruch_do_tylu(&driveMask->m_krokV, &oCoordinates->phyCoord.V, &oCoordinates->baseCoord.V, &driveLin->b_linV, errorDrive, false, &corrects->correctV, features);

//				if(drivePathParam->vectorAB.Zw.value>0)ruch_do_przodu(&driveMask->m_krokZw, &oCoordinates->phyCoord.Zw, &oCoordinates->baseCoord.Zw, 0, errorDrive, &corrects->correctZw, features); 
//				else if(drivePathParam->vectorAB.Zw.value<0)ruch_do_tylu(&driveMask->m_krokZw, &oCoordinates->phyCoord.Zw, &oCoordinates->baseCoord.Zw, 0, errorDrive, false, &corrects->correctZw, features);
//		

//				return 0;
//			}

//			if(pauseStep==false){
//				//każdorazowe obliczenie wektora przesunięcia (potrzebne przy zmianie zwrotu ruchu)
//				oCoordinates->setVector(&drivePathParam->vectorAB, pointB, pointA);		

//				switch (drivePathParam->masterAxis){
//					case OS_X:
//							nPt=(drivePathParam->vectorAB.X.value>0)?drivePathParam->nPointX+oCoordinates->phyCoord.X.precision:drivePathParam->nPointX-oCoordinates->phyCoord.X.precision;		//obliczenie wartości współrzędnych dla kolejnych punktów trajektorii na podstawie wzorów opisujących prostą w przestrzeni
//							if(abs_pp((int32_t)nPt-pointA.X.value)<=abs_pp(drivePathParam->vectorAB.X.value) && abs_pp((int32_t)nPt-pointB.X.value)<=abs_pp(drivePathParam->vectorAB.X.value)){ //jeżeli jesteśmy w zakresie ruchu to oblicz kolejny punkt trajektorii
//							drivePathParam->nPointX=nPt;
//							t=(drivePathParam->nPointX-pointA.X.value)/drivePathParam->vectorAB.X.value;			
//							drivePathParam->nPointY=t*drivePathParam->vectorAB.Y.value+pointA.Y.value;
//							drivePathParam->nPointZ=t*drivePathParam->vectorAB.Z.value+pointA.Z.value;
//							drivePathParam->nPointU=t*drivePathParam->vectorAB.U.value+pointA.U.value;
//							drivePathParam->nPointV=t*drivePathParam->vectorAB.V.value+pointA.V.value;
//							drivePathParam->nPointZw=t*drivePathParam->vectorAB.Zw.value+pointA.Zw.value;
//						}
//						break;
//					case OS_Y:
//						nPt=(drivePathParam->vectorAB.Y.value>0)?drivePathParam->nPointY+oCoordinates->phyCoord.Y.precision:drivePathParam->nPointY-oCoordinates->phyCoord.Y.precision;
//						if(abs_pp((int32_t)nPt-pointA.Y.value)<=abs_pp(drivePathParam->vectorAB.Y.value) && abs_pp((int32_t)nPt-pointB.Y.value)<=abs_pp(drivePathParam->vectorAB.Y.value)){
//							drivePathParam->nPointY=nPt;
//							t=(drivePathParam->nPointY-pointA.Y.value)/drivePathParam->vectorAB.Y.value;			
//							drivePathParam->nPointX=t*drivePathParam->vectorAB.X.value+pointA.X.value;
//							drivePathParam->nPointZ=t*drivePathParam->vectorAB.Z.value+pointA.Z.value;
//							drivePathParam->nPointU=t*drivePathParam->vectorAB.U.value+pointA.U.value;
//							drivePathParam->nPointV=t*drivePathParam->vectorAB.V.value+pointA.V.value;
//							drivePathParam->nPointZw=t*drivePathParam->vectorAB.Zw.value+pointA.Zw.value;
//						}
//						break;
//					case OS_Z:
//						nPt=(drivePathParam->vectorAB.Z.value>0)?drivePathParam->nPointZ+oCoordinates->phyCoord.Z.precision:drivePathParam->nPointZ-oCoordinates->phyCoord.Z.precision;
//						if(abs_pp((int32_t)nPt-pointA.Z.value)<=abs_pp(drivePathParam->vectorAB.Z.value) && abs_pp((int32_t)nPt-pointB.Z.value)<=abs_pp(drivePathParam->vectorAB.Z.value)){
//							drivePathParam->nPointZ=nPt;
//							t=(drivePathParam->nPointZ-pointA.Z.value)/drivePathParam->vectorAB.Z.value;			
//							drivePathParam->nPointX=t*drivePathParam->vectorAB.X.value+pointA.X.value;
//							drivePathParam->nPointY=t*drivePathParam->vectorAB.Y.value+pointA.Y.value;
//							drivePathParam->nPointU=t*drivePathParam->vectorAB.U.value+pointA.U.value;
//							drivePathParam->nPointV=t*drivePathParam->vectorAB.V.value+pointA.V.value;
//							drivePathParam->nPointZw=t*drivePathParam->vectorAB.Zw.value+pointA.Zw.value;
//						}
//						break;
//					case OS_U:
//						nPt=(drivePathParam->vectorAB.U.value>0)?drivePathParam->nPointU+oCoordinates->phyCoord.U.precision:drivePathParam->nPointU-oCoordinates->phyCoord.U.precision;		//obliczenie wartości współrzędnych dla kolejnych punktów trajektorii na podstawie wzorów opisujących prostą w przestrzeni
//						if(abs_pp((int32_t)nPt-pointA.U.value)<=abs_pp(drivePathParam->vectorAB.U.value) && abs_pp((int32_t)nPt-pointB.U.value)<=abs_pp(drivePathParam->vectorAB.U.value)){ //jeżeli jesteśmy w zakresie ruchu to oblicz kolejny punkt trajektorii
//							drivePathParam->nPointU=nPt;
//							t=(drivePathParam->nPointU-pointA.U.value)/drivePathParam->vectorAB.U.value;	
//							drivePathParam->nPointX=t*drivePathParam->vectorAB.X.value+pointA.X.value;		
//							drivePathParam->nPointY=t*drivePathParam->vectorAB.Y.value+pointA.Y.value;
//							drivePathParam->nPointZ=t*drivePathParam->vectorAB.Z.value+pointA.Z.value;
//							drivePathParam->nPointV=t*drivePathParam->vectorAB.V.value+pointA.V.value;
//							drivePathParam->nPointZw=t*drivePathParam->vectorAB.Zw.value+pointA.Zw.value;
//						}
//						break;
//					case OS_V:
//						nPt=(drivePathParam->vectorAB.V.value>0)?drivePathParam->nPointV+oCoordinates->phyCoord.V.precision:drivePathParam->nPointV-oCoordinates->phyCoord.V.precision;		//obliczenie wartości współrzędnych dla kolejnych punktów trajektorii na podstawie wzorów opisujących prostą w przestrzeni
//						if(abs_pp((int32_t)nPt-pointA.V.value)<=abs_pp(drivePathParam->vectorAB.V.value) && abs_pp((int32_t)nPt-pointB.V.value)<=abs_pp(drivePathParam->vectorAB.V.value)){ //jeżeli jesteśmy w zakresie ruchu to oblicz kolejny punkt trajektorii
//							drivePathParam->nPointV=nPt;
//							t=(drivePathParam->nPointV-pointA.V.value)/drivePathParam->vectorAB.V.value;	
//							drivePathParam->nPointX=t*drivePathParam->vectorAB.X.value+pointA.X.value;			
//							drivePathParam->nPointY=t*drivePathParam->vectorAB.Y.value+pointA.Y.value;
//							drivePathParam->nPointZ=t*drivePathParam->vectorAB.Z.value+pointA.Z.value;
//							drivePathParam->nPointU=t*drivePathParam->vectorAB.U.value+pointA.U.value;
//							drivePathParam->nPointZw=t*drivePathParam->vectorAB.Zw.value+pointA.Zw.value;
//						}
//						break;
//					case OS_Zw:
//						nPt=(drivePathParam->vectorAB.Zw.value>0)?drivePathParam->nPointZw+oCoordinates->phyCoord.Zw.precision:drivePathParam->nPointZw-oCoordinates->phyCoord.Zw.precision;		//obliczenie wartości współrzędnych dla kolejnych punktów trajektorii na podstawie wzorów opisujących prostą w przestrzeni
//						if(abs_pp((int32_t)nPt-pointA.Zw.value)<=abs_pp(drivePathParam->vectorAB.Zw.value) && abs_pp((int32_t)nPt-pointB.Zw.value)<=abs_pp(drivePathParam->vectorAB.Zw.value)){ //jeżeli jesteśmy w zakresie ruchu to oblicz kolejny punkt trajektorii
//							drivePathParam->nPointZw=nPt;
//							t=(drivePathParam->nPointZw-pointA.Zw.value)/drivePathParam->vectorAB.Zw.value;	
//							drivePathParam->nPointX=t*drivePathParam->vectorAB.X.value+pointA.X.value;			
//							drivePathParam->nPointY=t*drivePathParam->vectorAB.Y.value+pointA.Y.value;
//							drivePathParam->nPointZ=t*drivePathParam->vectorAB.Z.value+pointA.Z.value;
//							drivePathParam->nPointU=t*drivePathParam->vectorAB.U.value+pointA.U.value;
//							drivePathParam->nPointV=t*drivePathParam->vectorAB.V.value+pointA.V.value;
//						}
//						break;
//				}

//			}else{
//				pauseStep=false;
//				realizePauseStep=true;	
//			}

//			halfStep=((double)oCoordinates->phyCoord.Y.precision)/2;
//			if((double)(oCoordinates->phyCoord.Y.value)+halfStep<drivePathParam->nPointY){
//				moveAxis|=OS_Y;
//				ruch_do_przodu(&driveMask->m_krokY, &oCoordinates->phyCoord.Y, &oCoordinates->baseCoord.Y, &driveLin->b_linY, errorDrive, &corrects->correctY, features);
//			}else if((double)(oCoordinates->phyCoord.Y.value)-halfStep>drivePathParam->nPointY){
//				moveAxis|=OS_Y;
//				ruch_do_tylu(&driveMask->m_krokY, &oCoordinates->phyCoord.Y, &oCoordinates->baseCoord.Y, &driveLin->b_linY, errorDrive, false, &corrects->correctY, features);
//			}
//			
//			halfStep=((double)oCoordinates->phyCoord.Z.precision)/2;
//			if((double)(oCoordinates->phyCoord.Z.value)+halfStep<drivePathParam->nPointZ){
//				moveAxis|=OS_Z;
//				ruch_do_przodu(&driveMask->m_krokZ, &oCoordinates->phyCoord.Z, &oCoordinates->baseCoord.Z, 0, errorDrive, &corrects->correctZ, features); 
//			}else if((double)(oCoordinates->phyCoord.Z.value)-halfStep>drivePathParam->nPointZ){
//				moveAxis|=OS_Z;
//				ruch_do_tylu(&driveMask->m_krokZ, &oCoordinates->phyCoord.Z, &oCoordinates->baseCoord.Z, 0, errorDrive, false, &corrects->correctZ, features);
//			}
//			
//		
//			if(features & onX_INCREMENT){
//				double halfStepX=((double)oCoordinates->phyCoord.X.precision)/2;
//				double halfStepU=((double)oCoordinates->phyCoord.U.precision)/2;
//				
//				if((double)(oCoordinates->phyCoord.U.value)+halfStepU<drivePathParam->nPointU && (double)(oCoordinates->phyCoord.X.value)+halfStepX<drivePathParam->nPointX){
//					moveAxis|=OS_U;
//					moveAxis|=OS_X;
//					ruch_do_przodu(&driveMask->m_krokU, &oCoordinates->phyCoord.U, &oCoordinates->baseCoord.U, &driveLin->b_linU, errorDrive, &corrects->correctU, features);
//				}else if((double)(oCoordinates->phyCoord.U.value)-halfStepU>drivePathParam->nPointU && (double)(oCoordinates->phyCoord.X.value)-halfStepX>drivePathParam->nPointX){
//					moveAxis|=OS_U;
//					moveAxis|=OS_X;
//					ruch_do_tylu(&driveMask->m_krokU, &oCoordinates->phyCoord.U, &oCoordinates->baseCoord.U, &driveLin->b_linU, errorDrive, false, &corrects->correctU, features);
//				}else{
//					
//					if((double)(oCoordinates->phyCoord.X.value)+halfStepX<drivePathParam->nPointX || (double)(oCoordinates->phyCoord.X.value)-halfStepX>drivePathParam->nPointX)moveAxis|=OS_X;
//					if((double)(oCoordinates->phyCoord.U.value)+halfStepU<drivePathParam->nPointU || (double)(oCoordinates->phyCoord.U.value)-halfStepU>drivePathParam->nPointU)moveAxis|=OS_U;

//					if((moveAxis & OS_X) && (moveAxis & OS_U))pauseStep=true;
//					
//					if((toogleX==OS_X || (toogleX==OS_U && !(moveAxis & OS_U))) && (moveAxis & OS_X)){
//						if((double)(oCoordinates->phyCoord.X.value)+halfStepX<drivePathParam->nPointX){
//							ruch_do_przodu(&driveMask->m_krokX, &oCoordinates->phyCoord.X, &oCoordinates->baseCoord.X, &driveLin->b_linX, errorDrive, &corrects->correctX, features);
//						}else{
//							ruch_do_tylu(&driveMask->m_krokX, &oCoordinates->phyCoord.X, &oCoordinates->baseCoord.X, &driveLin->b_linX, errorDrive, false, &corrects->correctX, features);
//						}
//						toogleX=OS_U;
//					}else if((toogleX==OS_U || (toogleX==OS_X && !(moveAxis & OS_X))) && (moveAxis & OS_U)){
//						if((double)(oCoordinates->phyCoord.U.value)+halfStepU<drivePathParam->nPointU){
//							ruch_do_przodu(&driveMask->m_krokU, &oCoordinates->phyCoord.U, &oCoordinates->baseCoord.U, &driveLin->b_linU, errorDrive, &corrects->correctU, features);
//							ruch_do_tylu(&driveMask->m_krokX, &oCoordinates->phyCoord.X, &oCoordinates->baseCoord.X, &driveLin->b_linX, errorDrive, false, &corrects->correctX, features);
//						}else{
//							ruch_do_tylu(&driveMask->m_krokU, &oCoordinates->phyCoord.U, &oCoordinates->baseCoord.U, &driveLin->b_linU, errorDrive, false, &corrects->correctU, features);
//							ruch_do_przodu(&driveMask->m_krokX, &oCoordinates->phyCoord.X, &oCoordinates->baseCoord.X, &driveLin->b_linX, errorDrive, &corrects->correctX, features);
//						}
//						toogleX=OS_X;
//					}
//					
//				}
//			}else{
//				
//				halfStep=((double)oCoordinates->phyCoord.X.precision)/2;
//				if((double)(oCoordinates->phyCoord.X.value)+halfStep<drivePathParam->nPointX){
//					moveAxis|=OS_X;
//					ruch_do_przodu(&driveMask->m_krokX, &oCoordinates->phyCoord.X, &oCoordinates->baseCoord.X, &driveLin->b_linX, errorDrive, &corrects->correctX, features);
//				}else if((double)(oCoordinates->phyCoord.X.value)-halfStep>drivePathParam->nPointX){
//					moveAxis|=OS_X;
//					ruch_do_tylu(&driveMask->m_krokX, &oCoordinates->phyCoord.X, &oCoordinates->baseCoord.X, &driveLin->b_linX, errorDrive, false, &corrects->correctX, features);
//				}
//				
//				halfStep=((double)oCoordinates->phyCoord.U.precision)/2;
//				if((double)(oCoordinates->phyCoord.U.value)+halfStep<drivePathParam->nPointU){
//					moveAxis|=OS_U;
//					ruch_do_przodu(&driveMask->m_krokU, &oCoordinates->phyCoord.U, &oCoordinates->baseCoord.U, &driveLin->b_linU, errorDrive, &corrects->correctU, features);
//				}else if((double)(oCoordinates->phyCoord.U.value)-halfStep>drivePathParam->nPointU){
//					moveAxis|=OS_U;
//					ruch_do_tylu(&driveMask->m_krokU, &oCoordinates->phyCoord.U, &oCoordinates->baseCoord.U, &driveLin->b_linU, errorDrive, false, &corrects->correctU, features);
//				}
//				
//			}
//			
//			halfStep=((double)oCoordinates->phyCoord.V.precision)/2;
//			if((double)(oCoordinates->phyCoord.V.value)+halfStep<drivePathParam->nPointV){
//				moveAxis|=OS_V;
//				ruch_do_przodu(&driveMask->m_krokV, &oCoordinates->phyCoord.V, &oCoordinates->baseCoord.V, &driveLin->b_linV, errorDrive, &corrects->correctV, features);
//			}else if((double)(oCoordinates->phyCoord.V.value)-halfStep>drivePathParam->nPointV){
//				moveAxis|=OS_V;
//				ruch_do_tylu(&driveMask->m_krokV, &oCoordinates->phyCoord.V, &oCoordinates->baseCoord.V, &driveLin->b_linV, errorDrive, false, &corrects->correctV, features);
//			}
//			
//			halfStep=((double)oCoordinates->phyCoord.Zw.precision)/2;
//			if((double)(oCoordinates->phyCoord.Zw.value)+halfStep<drivePathParam->nPointZw){
//				moveAxis|=OS_Zw;
//				ruch_do_przodu(&driveMask->m_krokZw, &oCoordinates->phyCoord.Zw, &oCoordinates->baseCoord.Zw, 0, errorDrive, &corrects->correctZw, features);
//			}else if((double)(oCoordinates->phyCoord.Zw.value)-halfStep>drivePathParam->nPointZw){
//				moveAxis|=OS_Zw;
//				ruch_do_tylu(&driveMask->m_krokZw, &oCoordinates->phyCoord.Zw, &oCoordinates->baseCoord.Zw, 0, errorDrive, false, &corrects->correctZw, features);
//			}
//			
//			if(realizePauseStep)moveAxis=OS_NULL;
//			
//			return moveAxis;
//}


//void getPositionOfTheSection(SDrivePathParam *drivePathParam, defOCoordinates *oCoordinates){
//			double t=0, kPt;
//			uint32_t odl, min_odl;	

//			drivePathParam->nPointX=(double)drivePathParam->pointA.X.value;
//			drivePathParam->nPointY=(double)drivePathParam->pointA.Y.value;
//			drivePathParam->nPointZ=(double)drivePathParam->pointA.Z.value;
//			drivePathParam->nPointU=(double)drivePathParam->pointA.U.value;
//			drivePathParam->nPointV=(double)drivePathParam->pointA.V.value;
//			drivePathParam->nPointZw=(double)drivePathParam->pointA.Zw.value;

//			oCoordinates->setVector(&drivePathParam->vectorAB, drivePathParam->pointB, drivePathParam->pointA);	

//				switch (drivePathParam->masterAxis){
//					case OS_X:
//						kPt=drivePathParam->nPointX;
//						min_odl=abs_pp(oCoordinates->phyCoord.X.value-kPt);
//						if(!min_odl)break;	//jeżeli odległość jest równa 0 to wyjdź z klucza
//						while((int32_t)kPt!=drivePathParam->pointB.X.value){
//							kPt=(drivePathParam->vectorAB.X.value>0)?kPt+oCoordinates->phyCoord.X.precision:kPt-oCoordinates->phyCoord.X.precision;	
//							odl=abs_pp(oCoordinates->phyCoord.X.value-kPt);
//							if(odl<min_odl){
//								min_odl=odl;
//								drivePathParam->nPointX=kPt;
//								t=(drivePathParam->nPointX-drivePathParam->pointA.X.value)/drivePathParam->vectorAB.X.value;			
//								drivePathParam->nPointY=t*drivePathParam->vectorAB.Y.value+drivePathParam->pointA.Y.value;
//								drivePathParam->nPointZ=t*drivePathParam->vectorAB.Z.value+drivePathParam->pointA.Z.value;
//								drivePathParam->nPointU=t*drivePathParam->vectorAB.U.value+drivePathParam->pointA.U.value;
//								drivePathParam->nPointV=t*drivePathParam->vectorAB.V.value+drivePathParam->pointA.V.value;
//								drivePathParam->nPointZw=t*drivePathParam->vectorAB.Zw.value+drivePathParam->pointA.Zw.value;
//							}
//						}
//						break;
//					case OS_Y:
//						kPt=drivePathParam->nPointY;
//						min_odl=abs_pp(oCoordinates->phyCoord.Y.value-kPt);
//						if(!min_odl)break;	//jeżeli odległość jest równa 0 to wyjdź z klucza
//						while((int32_t)kPt!=drivePathParam->pointB.Y.value){
//							kPt=(drivePathParam->vectorAB.Y.value>0)?kPt+oCoordinates->phyCoord.Y.precision:kPt-oCoordinates->phyCoord.Y.precision;
//							odl=abs_pp(oCoordinates->phyCoord.Y.value-kPt);
//							if(odl<min_odl){
//								min_odl=odl;
//								drivePathParam->nPointY=kPt;
//								t=(drivePathParam->nPointY-drivePathParam->pointA.Y.value)/drivePathParam->vectorAB.Y.value;			
//								drivePathParam->nPointX=t*drivePathParam->vectorAB.X.value+drivePathParam->pointA.X.value;
//								drivePathParam->nPointZ=t*drivePathParam->vectorAB.Z.value+drivePathParam->pointA.Z.value;
//								drivePathParam->nPointU=t*drivePathParam->vectorAB.U.value+drivePathParam->pointA.U.value;
//								drivePathParam->nPointV=t*drivePathParam->vectorAB.V.value+drivePathParam->pointA.V.value;
//								drivePathParam->nPointZw=t*drivePathParam->vectorAB.Zw.value+drivePathParam->pointA.Zw.value;
//							}
//						}
//						break;
//					case OS_Z:
//						kPt=drivePathParam->nPointZ;
//						min_odl=abs_pp(oCoordinates->phyCoord.Z.value-kPt);
//						if(!min_odl)break;	//jeżeli odległość jest równa 0 to wyjdź z klucza
//						while((int32_t)kPt!=drivePathParam->pointB.Z.value){
//							kPt=(drivePathParam->vectorAB.Z.value>0)?kPt+oCoordinates->phyCoord.Z.precision:kPt-oCoordinates->phyCoord.Z.precision;
//							odl=abs_pp(oCoordinates->phyCoord.Z.value-kPt);
//							if(odl<min_odl){
//								min_odl=odl;
//								drivePathParam->nPointZ=kPt;
//								t=(drivePathParam->nPointZ-drivePathParam->pointA.Z.value)/drivePathParam->vectorAB.Z.value;			
//								drivePathParam->nPointX=t*drivePathParam->vectorAB.X.value+drivePathParam->pointA.X.value;
//								drivePathParam->nPointY=t*drivePathParam->vectorAB.Y.value+drivePathParam->pointA.Y.value;
//								drivePathParam->nPointU=t*drivePathParam->vectorAB.U.value+drivePathParam->pointA.U.value;
//								drivePathParam->nPointV=t*drivePathParam->vectorAB.V.value+drivePathParam->pointA.V.value;
//								drivePathParam->nPointZw=t*drivePathParam->vectorAB.Zw.value+drivePathParam->pointA.Zw.value;
//							}
//						}
//						break;
//					case OS_U:
//						kPt=drivePathParam->nPointU;
//						min_odl=abs_pp(oCoordinates->phyCoord.U.value-kPt);
//						if(!min_odl)break;	//jeżeli odległość jest równa 0 to wyjdź z klucza
//						while((int32_t)kPt!=drivePathParam->pointB.U.value){
//							kPt=(drivePathParam->vectorAB.U.value>0)?kPt+oCoordinates->phyCoord.U.precision:kPt-oCoordinates->phyCoord.U.precision;
//							odl=abs_pp(oCoordinates->phyCoord.U.value-kPt);
//							if(odl<min_odl){
//								min_odl=odl;
//								drivePathParam->nPointU=kPt;
//								t=(drivePathParam->nPointU-drivePathParam->pointA.U.value)/drivePathParam->vectorAB.U.value;			
//								drivePathParam->nPointX=t*drivePathParam->vectorAB.X.value+drivePathParam->pointA.X.value;
//								drivePathParam->nPointY=t*drivePathParam->vectorAB.Y.value+drivePathParam->pointA.Y.value;
//								drivePathParam->nPointZ=t*drivePathParam->vectorAB.Z.value+drivePathParam->pointA.Z.value;
//								drivePathParam->nPointV=t*drivePathParam->vectorAB.V.value+drivePathParam->pointA.V.value;
//								drivePathParam->nPointZw=t*drivePathParam->vectorAB.Zw.value+drivePathParam->pointA.Zw.value;
//							}
//						}
//						break;
//					case OS_V:
//						kPt=drivePathParam->nPointV;
//						min_odl=abs_pp(oCoordinates->phyCoord.V.value-kPt);
//						if(!min_odl)break;	//jeżeli odległość jest równa 0 to wyjdź z klucza
//						while((int32_t)kPt!=drivePathParam->pointB.V.value){
//							kPt=(drivePathParam->vectorAB.V.value>0)?kPt+oCoordinates->phyCoord.V.precision:kPt-oCoordinates->phyCoord.V.precision;
//							odl=abs_pp(oCoordinates->phyCoord.V.value-kPt);
//							if(odl<min_odl){
//								min_odl=odl;
//								drivePathParam->nPointV=kPt;
//								t=(drivePathParam->nPointV-drivePathParam->pointA.V.value)/drivePathParam->vectorAB.V.value;			
//								drivePathParam->nPointX=t*drivePathParam->vectorAB.X.value+drivePathParam->pointA.X.value;
//								drivePathParam->nPointY=t*drivePathParam->vectorAB.Y.value+drivePathParam->pointA.Y.value;
//								drivePathParam->nPointZ=t*drivePathParam->vectorAB.Z.value+drivePathParam->pointA.Z.value;
//								drivePathParam->nPointU=t*drivePathParam->vectorAB.U.value+drivePathParam->pointA.U.value;
//								drivePathParam->nPointZw=t*drivePathParam->vectorAB.Zw.value+drivePathParam->pointA.Zw.value;
//							}
//						}
//						break;
//					case OS_Zw:
//						kPt=drivePathParam->nPointZw;
//						min_odl=abs_pp(oCoordinates->phyCoord.Zw.value-kPt);
//						if(!min_odl)break;	//jeżeli odległość jest równa 0 to wyjdź z klucza
//						while((int32_t)kPt!=drivePathParam->pointB.Zw.value){
//							kPt=(drivePathParam->vectorAB.Zw.value>0)?kPt+oCoordinates->phyCoord.Zw.precision:kPt-oCoordinates->phyCoord.Zw.precision;
//							odl=abs_pp(oCoordinates->phyCoord.Zw.value-kPt);
//							if(odl<min_odl){
//								min_odl=odl;
//								drivePathParam->nPointZw=kPt;
//								t=(drivePathParam->nPointZw-drivePathParam->pointA.Zw.value)/drivePathParam->vectorAB.Zw.value;			
//								drivePathParam->nPointX=t*drivePathParam->vectorAB.X.value+drivePathParam->pointA.X.value;
//								drivePathParam->nPointY=t*drivePathParam->vectorAB.Y.value+drivePathParam->pointA.Y.value;
//								drivePathParam->nPointZ=t*drivePathParam->vectorAB.Z.value+drivePathParam->pointA.Z.value;
//								drivePathParam->nPointU=t*drivePathParam->vectorAB.U.value+drivePathParam->pointA.U.value;
//								drivePathParam->nPointV=t*drivePathParam->vectorAB.V.value+drivePathParam->pointA.V.value;
//							}
//						}
//						break;
//				}

//}


//void drivePathArc(SDrivePathParam *drivePathParam, SCoordinates pointB, SDriveMask *driveMask, fDRIVE_TypeDef *errorDrive, SDriveLin *driveLin, defOCoordinates *oCoordinates, 
//									SFeedrate* feedrate, int32_t vectorZ, defTurnCircle turnCircle, defTurn turn, SCorrectionAllAxes *corrects, uint32_t features){
//			int32_t x0=0, y0=0;
//			uint32_t lkZ, lkXY;
//			int32_t suma_krok;
//									
//			double halfStepX=((double)oCoordinates->phyCoord.X.precision)/2;
//			double halfStepY=((double)oCoordinates->phyCoord.Y.precision)/2;									

//			if(turn==PRZOD)suma_krok=drivePathParam->hypSumStepOfSEG+1;
//			else suma_krok=drivePathParam->hypSumStepOfSEG-1;

//			if(suma_krok>0 && (*drivePathParam->nrOfStepCircle)>=suma_krok){

//				if(turn==PRZOD)drivePathParam->hypSumStepOfSEG=suma_krok;

//				lkZ=(uint32_t)(((double)drivePathParam->hypSumStepOfSEG)/drivePathParam->dividerZ);
//				lkXY=(uint32_t)(((double)drivePathParam->hypSumStepOfSEG)/drivePathParam->dividerXY);


//				if(lkZ==drivePathParam->nrOfMadeStepCircleZ+1 || lkZ==drivePathParam->nrOfMadeStepCircleZ-1){
//					if(lkZ==drivePathParam->nrOfMadeStepCircleZ+1)drivePathParam->nrOfMadeStepCircleZ++;
//					else drivePathParam->nrOfMadeStepCircleZ--;

//					if(vectorZ>0)drivePathParam->kB.Z.value+=oCoordinates->phyCoord.Z.precision;
//					else drivePathParam->kB.Z.value-=oCoordinates->phyCoord.Z.precision;
//				}

//				if(lkXY==drivePathParam->nrOfMadeStepCircleXY+1 || lkXY==drivePathParam->nrOfMadeStepCircleXY-1){
//					if(lkXY==drivePathParam->nrOfMadeStepCircleXY+1)drivePathParam->nrOfMadeStepCircleXY++;
//					else drivePathParam->nrOfMadeStepCircleXY--;

//					x0=drivePathParam->kB.X.value-drivePathParam->circleCenter.X.value;
//					y0=drivePathParam->kB.Y.value-drivePathParam->circleCenter.Y.value;

//					if(turnCircle==ZEGAR_ZGODNIE){
//						if(y0>0 && x0>=0 && x0<y0){												//opis II oktetu	
//							drivePathParam->kB.X.value+=oCoordinates->phyCoord.X.precision;
//							if(arcImplicitFunction(x0+oCoordinates->phyCoord.X.precision, (double)(y0)-halfStepY, drivePathParam->circleR2)>=0)drivePathParam->kB.Y.value-=oCoordinates->phyCoord.Y.precision;
//						}else if(y0>0 && x0<0 && abs_pp(x0)<=y0){					//opis III oktetu
//							drivePathParam->kB.X.value+=oCoordinates->phyCoord.X.precision;
//							if(arcImplicitFunction(x0+oCoordinates->phyCoord.X.precision, (double)(y0)+halfStepY, drivePathParam->circleR2)<=0)drivePathParam->kB.Y.value+=oCoordinates->phyCoord.Y.precision;
//						}else if(y0<0 && x0<=0 && abs_pp(x0)<abs_pp(y0)){	//opis VI oktetu
//							drivePathParam->kB.X.value-=oCoordinates->phyCoord.X.precision;
//							if(arcImplicitFunction(x0-oCoordinates->phyCoord.X.precision, (double)(y0)+halfStepY, drivePathParam->circleR2)>=0)drivePathParam->kB.Y.value+=oCoordinates->phyCoord.Y.precision;
//						}else if(y0<0 && x0>0 && x0<=abs_pp(y0)){				//opis VII oktetu
//							drivePathParam->kB.X.value-=oCoordinates->phyCoord.X.precision;
//							if(arcImplicitFunction(x0-oCoordinates->phyCoord.X.precision, (double)(y0)-halfStepY, drivePathParam->circleR2)<=0)drivePathParam->kB.Y.value-=oCoordinates->phyCoord.Y.precision;
//						}
//						else if(y0>0 && x0>0 && x0>=y0){									//opis I oktetu	
//							drivePathParam->kB.Y.value-=oCoordinates->phyCoord.Y.precision;
//							if(arcImplicitFunction((double)(x0)+halfStepX, y0-oCoordinates->phyCoord.Y.precision, drivePathParam->circleR2)<=0)drivePathParam->kB.X.value+=oCoordinates->phyCoord.X.precision;
//						}else if(y0<=0 && x0>0 && x0>abs_pp(y0)){					//opis VIII oktetu
//							drivePathParam->kB.Y.value-=oCoordinates->phyCoord.Y.precision;
//							if(arcImplicitFunction((double)(x0)-halfStepX, y0-oCoordinates->phyCoord.Y.precision, drivePathParam->circleR2)>=0)drivePathParam->kB.X.value-=oCoordinates->phyCoord.X.precision;
//						}else if(y0>=0 && x0<0 && abs_pp(x0)>y0){					//opis IV oktetu
//							drivePathParam->kB.Y.value+=oCoordinates->phyCoord.Y.precision;
//							if(arcImplicitFunction((double)(x0)+halfStepX, y0+oCoordinates->phyCoord.Y.precision, drivePathParam->circleR2)>=0)drivePathParam->kB.X.value+=oCoordinates->phyCoord.X.precision;
//						}else if(y0<0 && x0<0 && abs_pp(x0)>=abs_pp(y0)){	//opis V oktetu
//							drivePathParam->kB.Y.value+=oCoordinates->phyCoord.Y.precision;
//							if(arcImplicitFunction((double)(x0)-halfStepX, y0+oCoordinates->phyCoord.Y.precision, drivePathParam->circleR2)<=0)drivePathParam->kB.X.value-=oCoordinates->phyCoord.X.precision;
//						}
//					}else{

//						if(y0>0 && x0>0 && x0<=y0){												//opis II oktetu	
//							drivePathParam->kB.X.value-=oCoordinates->phyCoord.X.precision;
//							if(arcImplicitFunction(x0-oCoordinates->phyCoord.X.precision, (double)(y0)+halfStepY, drivePathParam->circleR2)<=0)drivePathParam->kB.Y.value+=oCoordinates->phyCoord.Y.precision;
//						}else if(y0>0 && x0<=0 && abs_pp(x0)<y0){					//opis III oktetu
//							drivePathParam->kB.X.value-=oCoordinates->phyCoord.X.precision;
//							if(arcImplicitFunction(x0-oCoordinates->phyCoord.X.precision, (double)(y0)-halfStepY, drivePathParam->circleR2)>=0)drivePathParam->kB.Y.value-=oCoordinates->phyCoord.Y.precision;
//						}else if(y0<0 && x0<0 && abs_pp(x0)<=abs_pp(y0)){	//opis VI oktetu
//							drivePathParam->kB.X.value+=oCoordinates->phyCoord.X.precision;
//							if(arcImplicitFunction(x0+oCoordinates->phyCoord.X.precision, (double)(y0)-halfStepY, drivePathParam->circleR2)<=0)drivePathParam->kB.Y.value-=oCoordinates->phyCoord.Y.precision;
//						}else if(y0<0 && x0>=0 && x0<abs_pp(y0)){				//opis VII oktetu
//							drivePathParam->kB.X.value+=oCoordinates->phyCoord.X.precision;
//							if(arcImplicitFunction(x0+oCoordinates->phyCoord.X.precision, (double)(y0)+halfStepY, drivePathParam->circleR2)>=0)drivePathParam->kB.Y.value+=oCoordinates->phyCoord.Y.precision;
//						}
//						else if(y0>=0 && x0>0 && x0>y0){									//opis I oktetu	
//							drivePathParam->kB.Y.value+=oCoordinates->phyCoord.Y.precision;
//							if(arcImplicitFunction((double)(x0)-halfStepX, y0+oCoordinates->phyCoord.Y.precision, drivePathParam->circleR2)>=0)drivePathParam->kB.X.value-=oCoordinates->phyCoord.X.precision;
//						}else if(y0<0 && x0>0 && x0>=abs_pp(y0)){					//opis VIII oktetu
//							drivePathParam->kB.Y.value+=oCoordinates->phyCoord.Y.precision;
//							if(arcImplicitFunction((double)(x0)+halfStepX, y0+oCoordinates->phyCoord.Y.precision, drivePathParam->circleR2)<=0)drivePathParam->kB.X.value+=oCoordinates->phyCoord.X.precision;
//						}else if(y0>0 && x0<0 && abs_pp(x0)>=y0){					//opis IV oktetu
//							drivePathParam->kB.Y.value-=oCoordinates->phyCoord.Y.precision;
//							if(arcImplicitFunction((double)(x0)-halfStepX, y0-oCoordinates->phyCoord.Y.precision, drivePathParam->circleR2)<=0)drivePathParam->kB.X.value-=oCoordinates->phyCoord.X.precision;
//						}else if(y0<=0 && x0<0 && abs_pp(x0)>abs_pp(y0)){	//opis V oktetu
//							drivePathParam->kB.Y.value-=oCoordinates->phyCoord.Y.precision;
//							if(arcImplicitFunction((double)(x0)+halfStepX, y0-oCoordinates->phyCoord.Y.precision, drivePathParam->circleR2)>=0)drivePathParam->kB.X.value+=oCoordinates->phyCoord.X.precision;
//						}
//					}
//				}

//				if(turn==TYL)drivePathParam->hypSumStepOfSEG=suma_krok;


////				*clockDivider=getClockDividerResponsibleForDriveSpeed(drivePathParam->hypSumStepOfSEG, *(drivePathParam->nrOfStepCircle)-drivePathParam->hypSumStepOfSEG, feedrate, BASE_FREQUENCY_OF_TIMdrivePath);

//				drivePathParam->vectorAB.X.value=drivePathParam->kB.X.value-oCoordinates->phyCoord.X.value;
//				drivePathParam->vectorAB.Y.value=drivePathParam->kB.Y.value-oCoordinates->phyCoord.Y.value;
//				drivePathParam->vectorAB.Z.value=drivePathParam->kB.Z.value-oCoordinates->phyCoord.Z.value;
//				drivePathParam->vectorAB.U.value=drivePathParam->vectorAB.X.value;
//				drivePathParam->vectorAB.V.value=drivePathParam->vectorAB.Y.value;
//				drivePathParam->vectorAB.Zw.value=0;


//			}else{
//				if(features & onX_INCREMENT)drivePathParam->vectorAB.X.value=0;
//				else drivePathParam->vectorAB.X.value=pointB.X.value-oCoordinates->phyCoord.X.value;
//					
//				drivePathParam->vectorAB.Y.value=pointB.Y.value-oCoordinates->phyCoord.Y.value;
//				drivePathParam->vectorAB.Z.value=pointB.Z.value-oCoordinates->phyCoord.Z.value;
//				drivePathParam->vectorAB.U.value=pointB.U.value-oCoordinates->phyCoord.U.value;
//				drivePathParam->vectorAB.V.value=pointB.V.value-oCoordinates->phyCoord.V.value;
//				drivePathParam->vectorAB.Zw.value=pointB.Zw.value-oCoordinates->phyCoord.Zw.value;

//			}


//			if(!(features & onX_INCREMENT)){
//				if(drivePathParam->vectorAB.X.value>0)ruch_do_przodu(&driveMask->m_krokX, &oCoordinates->phyCoord.X, &oCoordinates->baseCoord.X, &driveLin->b_linX, errorDrive, &corrects->correctX, features);
//				else if(drivePathParam->vectorAB.X.value<0)ruch_do_tylu(&driveMask->m_krokX, &oCoordinates->phyCoord.X, &oCoordinates->baseCoord.X, &driveLin->b_linX, errorDrive, false, &corrects->correctX, features);
//			}
//			
//			if(drivePathParam->vectorAB.Y.value>0)ruch_do_przodu(&driveMask->m_krokY, &oCoordinates->phyCoord.Y, &oCoordinates->baseCoord.Y, &driveLin->b_linY, errorDrive, &corrects->correctY, features);
//			else if(drivePathParam->vectorAB.Y.value<0)ruch_do_tylu(&driveMask->m_krokY, &oCoordinates->phyCoord.Y, &oCoordinates->baseCoord.Y, &driveLin->b_linY, errorDrive, false, &corrects->correctY, features);

//			if(drivePathParam->vectorAB.Z.value>0)ruch_do_przodu(&driveMask->m_krokZ, &oCoordinates->phyCoord.Z, &oCoordinates->baseCoord.Z, 0, errorDrive, &corrects->correctZ, features);
//			else if(drivePathParam->vectorAB.Z.value<0)ruch_do_tylu(&driveMask->m_krokZ, &oCoordinates->phyCoord.Z, &oCoordinates->baseCoord.Z, 0, errorDrive, false, &corrects->correctZ, features);

//			
//			if(drivePathParam->vectorAB.U.value>0){
//				ruch_do_przodu(&driveMask->m_krokU, &oCoordinates->phyCoord.U, &oCoordinates->baseCoord.U, &driveLin->b_linU, errorDrive, &corrects->correctU, features);
//			}else if(drivePathParam->vectorAB.U.value<0){
//				ruch_do_tylu(&driveMask->m_krokU, &oCoordinates->phyCoord.U, &oCoordinates->baseCoord.U, &driveLin->b_linU, errorDrive, false, &corrects->correctU, features);
//			}
//			
//			if(drivePathParam->vectorAB.V.value>0)ruch_do_przodu(&driveMask->m_krokV, &oCoordinates->phyCoord.V, &oCoordinates->baseCoord.V, &driveLin->b_linV, errorDrive, &corrects->correctV, features);
//			else if(drivePathParam->vectorAB.V.value<0)ruch_do_tylu(&driveMask->m_krokV, &oCoordinates->phyCoord.V, &oCoordinates->baseCoord.V, &driveLin->b_linV, errorDrive, false, &corrects->correctV, features);

//			if(drivePathParam->vectorAB.Zw.value>0)ruch_do_przodu(&driveMask->m_krokZw, &oCoordinates->phyCoord.Zw, &oCoordinates->baseCoord.Zw, 0, errorDrive, &corrects->correctZw, features);
//			else if(drivePathParam->vectorAB.Zw.value<0)ruch_do_tylu(&driveMask->m_krokZw, &oCoordinates->phyCoord.Zw, &oCoordinates->baseCoord.Zw, 0, errorDrive, false, &corrects->correctZw, features);


//															
//}

//double arcImplicitFunction(double X1, double Y1, double R2){
//			double F=0;

//			F=(Y1*Y1)+(X1*X1)-R2;	

//			return F;
//}


//uint32_t calculateNrOfStepCircle(SDrivePathParam *drivePathParam, SCoordinates *endCoord, defOCoordinates *oCoordinates){
//			int32_t xp=0, yp=0, x0=0, y0=0, x1=0, y1=0;
//			uint32_t il_krok=0;

//			double halfStepX=((double)oCoordinates->phyCoord.X.precision)/2;
//			double halfStepY=((double)oCoordinates->phyCoord.Y.precision)/2;	

//			xp=drivePathParam->pointA.X.value-drivePathParam->circleCenter.X.value;
//			yp=drivePathParam->pointA.Y.value-drivePathParam->circleCenter.Y.value;

//			x0=xp;
//			y0=yp;

//			x1=endCoord->X.value-drivePathParam->circleCenter.X.value;
//			y1=endCoord->Y.value-drivePathParam->circleCenter.Y.value;

//			while(x0!=x1 || y0!=y1){
//				if(drivePathParam->turnCircle==ZEGAR_ZGODNIE){
//					if(y0>0 && x0>=0 && x0<y0){												//opis II oktetu	
//						x0+=oCoordinates->phyCoord.X.precision;
//						if(arcImplicitFunction(x0, (double)(y0)-halfStepY, drivePathParam->circleR2)>=0)y0-=oCoordinates->phyCoord.Y.precision; 
//					}else if(y0>0 && x0<0 && abs_pp(x0)<=y0){					//opis III oktetu
//						x0+=oCoordinates->phyCoord.X.precision;
//						if(arcImplicitFunction(x0, (double)(y0)+halfStepY, drivePathParam->circleR2)<=0)y0+=oCoordinates->phyCoord.Y.precision;
//					}else if(y0<0 && x0<=0 && abs_pp(x0)<abs_pp(y0)){	//opis VI oktetu
//						x0-=oCoordinates->phyCoord.X.precision;
//						if(arcImplicitFunction(x0, (double)(y0)+halfStepY, drivePathParam->circleR2)>=0)y0+=oCoordinates->phyCoord.Y.precision;
//					}else if(y0<0 && x0>0 && x0<=abs_pp(y0)){				//opis VII oktetu
//						x0-=oCoordinates->phyCoord.X.precision;
//						if(arcImplicitFunction(x0, (double)(y0)-halfStepY, drivePathParam->circleR2)<=0)y0-=oCoordinates->phyCoord.Y.precision; 
//					}
//					else if(y0>0 && x0>0 && x0>=y0){									//opis I oktetu	
//						y0-=oCoordinates->phyCoord.Y.precision;
//						if(arcImplicitFunction((double)(x0)+halfStepX, y0, drivePathParam->circleR2)<=0)x0+=oCoordinates->phyCoord.X.precision;
//					}else if(y0<=0 && x0>0 && x0>abs_pp(y0)){					//opis VIII oktetu
//						y0-=oCoordinates->phyCoord.Y.precision;
//						if(arcImplicitFunction((double)(x0)-halfStepX, y0, drivePathParam->circleR2)>=0)x0-=oCoordinates->phyCoord.X.precision;
//					}else if(y0>=0 && x0<0 && abs_pp(x0)>y0){					//opis IV oktetu
//						y0+=oCoordinates->phyCoord.Y.precision;
//						if(arcImplicitFunction((double)(x0)+halfStepX, y0, drivePathParam->circleR2)>=0)x0+=oCoordinates->phyCoord.X.precision;
//					}else if(y0<0 && x0<0 && abs_pp(x0)>=abs_pp(y0)){	//opis V oktetu
//						y0+=oCoordinates->phyCoord.Y.precision;
//						if(arcImplicitFunction((double)(x0)-halfStepX, y0, drivePathParam->circleR2)<=0)x0-=oCoordinates->phyCoord.X.precision;
//					}
//				}else{
//					if(y0>0 && x0>0 && x0<=y0){												//opis II oktetu	
//						x0-=oCoordinates->phyCoord.X.precision;
//						if(arcImplicitFunction(x0, (double)(y0)+halfStepX, drivePathParam->circleR2)<=0)y0+=oCoordinates->phyCoord.Y.precision;
//					}else if(y0>0 && x0<=0 && abs_pp(x0)<y0){					//opis III oktetu
//						x0-=oCoordinates->phyCoord.X.precision;
//						if(arcImplicitFunction(x0, (double)(y0)-halfStepX, drivePathParam->circleR2)>=0)y0-=oCoordinates->phyCoord.Y.precision; 
//					}else if(y0<0 && x0<0 && abs_pp(x0)<=abs_pp(y0)){	//opis VI oktetu
//						x0+=oCoordinates->phyCoord.X.precision;
//						if(arcImplicitFunction(x0, (double)(y0)-halfStepX, drivePathParam->circleR2)<=0)y0-=oCoordinates->phyCoord.Y.precision;
//					}else if(y0<0 && x0>=0 && x0<abs_pp(y0)){				//opis VII oktetu
//						x0+=oCoordinates->phyCoord.X.precision;
//						if(arcImplicitFunction(x0, (double)(y0)+halfStepX, drivePathParam->circleR2)>=0)y0+=oCoordinates->phyCoord.Y.precision;
//					}
//					else if(y0>=0 && x0>0 && x0>y0){									//opis I oktetu	
//						y0+=oCoordinates->phyCoord.Y.precision;
//						if(arcImplicitFunction((double)(x0)-halfStepY, y0, drivePathParam->circleR2)>=0)x0-=oCoordinates->phyCoord.X.precision;
//					}else if(y0<0 && x0>0 && x0>=abs_pp(y0)){					//opis VIII oktetu
//						y0+=oCoordinates->phyCoord.Y.precision;
//						if(arcImplicitFunction((double)(x0)+halfStepY, y0, drivePathParam->circleR2)<=0)x0+=oCoordinates->phyCoord.X.precision;
//					}else if(y0>0 && x0<0 && abs_pp(x0)>=y0){					//opis IV oktetu
//						y0-=oCoordinates->phyCoord.Y.precision;
//						if(arcImplicitFunction((double)(x0)-halfStepY, y0, drivePathParam->circleR2)<=0)x0-=oCoordinates->phyCoord.X.precision;
//					}else if(y0<=0 && x0<0 && abs_pp(x0)>abs_pp(y0)){	//opis V oktetu
//						y0-=oCoordinates->phyCoord.Y.precision;
//						if(arcImplicitFunction((double)(x0)+halfStepY, y0, drivePathParam->circleR2)>=0)x0+=oCoordinates->phyCoord.X.precision;
//					}
//				}
//		
//				il_krok++;
//				if(x0==xp && y0==yp)return 0;	//jeżeli okrąg jest źle zapisany i w trakcie obliczania ilości kroków wrócimy do tego samego miejsca to nie wykonuj łuku
//			};


//			return il_krok;
//}

//void getRealEndOfArc(int32_t *Xkon_real, int32_t *Ykon_real, SCoordinates wsp_srodka, int32_t Xkon, int32_t Ykon, SCoordinates wsp_pocz, defTurnCircle turnCircle, defOCoordinates *oCoordinates){
//			int32_t xp=0, yp=0, x0=0, y0=0, x1=0, y1=0;
//			uint32_t min_odl=0xFFFFFFFF, odl_pom=0;
//	
//			double R2=0;
//			double halfStepX=((double)oCoordinates->phyCoord.X.precision)/2;
//			double halfStepY=((double)oCoordinates->phyCoord.Y.precision)/2;	

//			R2=pow(wsp_srodka.X.value-wsp_pocz.X.value,2)+pow(wsp_srodka.Y.value-wsp_pocz.Y.value, 2);

//			xp=wsp_pocz.X.value-wsp_srodka.X.value;
//			yp=wsp_pocz.Y.value-wsp_srodka.Y.value;

//			x0=xp;
//			y0=yp;

//			x1=Xkon-wsp_srodka.X.value;
//			y1=Ykon-wsp_srodka.Y.value;

//			*Xkon_real=xp;
//			*Ykon_real=yp;

//			do{
//				if(turnCircle==ZEGAR_ZGODNIE){
//					if(y0>0 && x0>=0 && x0<y0){												//opis II oktetu	
//						x0+=oCoordinates->phyCoord.X.precision;
//						if(arcImplicitFunction(x0, (double)(y0)-halfStepY, R2)>=0)y0-=oCoordinates->phyCoord.Y.precision; 
//					}else if(y0>0 && x0<0 && abs_pp(x0)<=y0){					//opis III oktetu
//						x0+=oCoordinates->phyCoord.X.precision;
//						if(arcImplicitFunction(x0, (double)(y0)+halfStepY, R2)<=0)y0+=oCoordinates->phyCoord.Y.precision;
//					}else if(y0<0 && x0<=0 && abs_pp(x0)<abs_pp(y0)){	//opis VI oktetu
//						x0-=oCoordinates->phyCoord.X.precision;
//						if(arcImplicitFunction(x0, (double)(y0)+halfStepY, R2)>=0)y0+=oCoordinates->phyCoord.Y.precision;
//					}else if(y0<0 && x0>0 && x0<=abs_pp(y0)){				//opis VII oktetu
//						x0-=oCoordinates->phyCoord.X.precision;
//						if(arcImplicitFunction(x0, (double)(y0)-halfStepY, R2)<=0)y0-=oCoordinates->phyCoord.Y.precision; 
//					}
//					else if(y0>0 && x0>0 && x0>=y0){									//opis I oktetu	
//						y0-=oCoordinates->phyCoord.Y.precision;
//						if(arcImplicitFunction((double)(x0)+halfStepX, y0, R2)<=0)x0+=oCoordinates->phyCoord.X.precision;
//					}else if(y0<=0 && x0>0 && x0>abs_pp(y0)){					//opis VIII oktetu
//						y0-=oCoordinates->phyCoord.Y.precision;
//						if(arcImplicitFunction((double)(x0)-halfStepX, y0, R2)>=0)x0-=oCoordinates->phyCoord.X.precision;
//					}else if(y0>=0 && x0<0 && abs_pp(x0)>y0){					//opis IV oktetu
//						y0+=oCoordinates->phyCoord.Y.precision;
//						if(arcImplicitFunction((double)(x0)+halfStepX, y0, R2)>=0)x0+=oCoordinates->phyCoord.X.precision;
//					}else if(y0<0 && x0<0 && abs_pp(x0)>=abs_pp(y0)){	//opis V oktetu
//						y0+=oCoordinates->phyCoord.Y.precision;
//						if(arcImplicitFunction((double)(x0)-halfStepX, y0, R2)<=0)x0-=oCoordinates->phyCoord.X.precision;
//					}
//				}else{
//					if(y0>0 && x0>0 && x0<=y0){												//opis II oktetu	
//						x0-=oCoordinates->phyCoord.X.precision;
//						if(arcImplicitFunction(x0, (double)(y0)+halfStepY, R2)<=0)y0+=oCoordinates->phyCoord.Y.precision;
//					}else if(y0>0 && x0<=0 && abs_pp(x0)<y0){					//opis III oktetu
//						x0-=oCoordinates->phyCoord.X.precision;
//						if(arcImplicitFunction(x0, (double)(y0)-halfStepY, R2)>=0)y0-=oCoordinates->phyCoord.Y.precision; 
//					}else if(y0<0 && x0<0 && abs_pp(x0)<=abs_pp(y0)){	//opis VI oktetu
//						x0+=oCoordinates->phyCoord.X.precision;
//						if(arcImplicitFunction(x0, (double)(y0)-halfStepY, R2)<=0)y0-=oCoordinates->phyCoord.Y.precision;
//					}else if(y0<0 && x0>=0 && x0<abs_pp(y0)){				//opis VII oktetu
//						x0+=oCoordinates->phyCoord.X.precision;
//						if(arcImplicitFunction(x0, (double)(y0)+halfStepY, R2)>=0)y0+=oCoordinates->phyCoord.Y.precision;
//					}
//					else if(y0>=0 && x0>0 && x0>y0){									//opis I oktetu	
//						y0+=oCoordinates->phyCoord.Y.precision;
//						if(arcImplicitFunction((double)(x0)-halfStepX, y0, R2)>=0)x0-=oCoordinates->phyCoord.X.precision;
//					}else if(y0<0 && x0>0 && x0>=abs_pp(y0)){					//opis VIII oktetu
//						y0+=oCoordinates->phyCoord.Y.precision;
//						if(arcImplicitFunction((double)(x0)+halfStepX, y0, R2)<=0)x0+=oCoordinates->phyCoord.X.precision;
//					}else if(y0>0 && x0<0 && abs_pp(x0)>=y0){					//opis IV oktetu
//						y0-=oCoordinates->phyCoord.Y.precision;
//						if(arcImplicitFunction((double)(x0)-halfStepX, y0, R2)<=0)x0-=oCoordinates->phyCoord.X.precision;
//					}else if(y0<=0 && x0<0 && abs_pp(x0)>abs_pp(y0)){	//opis V oktetu
//						y0-=oCoordinates->phyCoord.Y.precision;
//						if(arcImplicitFunction((double)(x0)+halfStepX, y0, R2)>=0)x0+=oCoordinates->phyCoord.X.precision;
//					}
//				}
//		
//				odl_pom=abs_pp(x1-x0)+abs_pp(y1-y0);
//				if(odl_pom<min_odl){
//					*Xkon_real=x0;
//					*Ykon_real=y0;
//					min_odl=odl_pom;
//				}

//			}while(x0!=xp || y0!=yp);

//			(*Xkon_real)+=wsp_srodka.X.value;
//			(*Ykon_real)+=wsp_srodka.Y.value;

//}



//void driveEngineService(SDriveConditionParam *driveConditionParam, fDRIVE_TypeDef *errorDrive, uint32_t features){


//			if(driveConditionParam->turn==PRZOD){
//				ruch_do_przodu(driveConditionParam->m_step, driveConditionParam->phyCoord, driveConditionParam->baseCoord, driveConditionParam->b_lin, errorDrive, &driveConditionParam->correct, features);
//			}else{
//				ruch_do_tylu(driveConditionParam->m_step, driveConditionParam->phyCoord, driveConditionParam->baseCoord, driveConditionParam->b_lin, errorDrive, false, &driveConditionParam->correct, features);
//			}	
//			setSingleSygPortDRIVE(driveConditionParam);
//			driveConditionParam->l_krok_pom++;


//}


//uint32_t driveConditionalService(SDriveConditionParam *driveConditionParam, defOCheckSignals* oCheckSignalsLimitedStop, uint32_t key, fDRIVE_TypeDef *errorDrive, SFeedrate* feedrate, 
//																uint32_t features, _Bool *circuitIgnorance){
//		uint32_t clockDivider=0;
//		uint32_t accelerateNumberOfSteps;
//											

//			if(oCheckSignalsLimitedStop->checkedSetSignals & driveConditionParam->limStop){
//				driveConditionParam->infoDrive=PRZEJ_PORZUCONO;
//			}else{
//				driveConditionParam->infoDrive=checkDriveError2();
//			}

//			if(driveConditionParam->infoDrive==DRIVE_IN_PROGRESS){

//				if(!key){// jeżeli spuszczony został klawisz kierunku  to...
//						accelerateNumberOfSteps=calculateAccelerateNumberOfSteps(feedrate, driveConditionParam->phyCoord->precision);
//						driveEngineService(driveConditionParam, errorDrive, features);																																																																		// dohamuj silnik
//						if(!driveConditionParam->l_krok_tot)driveConditionParam->l_krok_tot=(driveConditionParam->l_krok_pom>accelerateNumberOfSteps)?driveConditionParam->l_krok_pom+accelerateNumberOfSteps:driveConditionParam->l_krok_pom*2;
//						if(driveConditionParam->l_krok_tot-driveConditionParam->l_krok_pom>0){
//							clockDivider=getFrequencykResponsibleForDriveSpeed(driveConditionParam->l_krok_tot-driveConditionParam->l_krok_pom, driveConditionParam->l_krok_tot-driveConditionParam->l_krok_pom, feedrate, driveConditionParam->phyCoord->precision);// sekwencja hamowania silnika
//						}else{

//							driveConditionParam->infoDrive=PRZEJ_ZREALIZOWANO;
//							*circuitIgnorance=true;
//						}
//						
////						if((driveConditionParam->l_krok_tot-driveConditionParam->l_krok_pom)*driveConditionParam->phyCoord->precision<=STEP){
////							driveConditionParam->phyCoord->precision=EXACT_STEP;
////							driveConditionParam->baseCoord->precision=EXACT_STEP;
////							*driveConditionParam->micro_step=STEP_1_4;
////						}	
//				}else{
//					
////					if(driveConditionParam->phyCoord->value%STEP==0){
////						driveConditionParam->phyCoord->precision=STEP;
////						driveConditionParam->baseCoord->precision=STEP;
////						*driveConditionParam->micro_step=FULL_STEP;
////					}

//					
//					driveEngineService(driveConditionParam, errorDrive, features);
//					clockDivider=getFrequencykResponsibleForDriveSpeed(driveConditionParam->l_krok_pom, driveConditionParam->l_krok_pom, feedrate, driveConditionParam->phyCoord->precision);// sekwencja rozpędzania silnika
//				}
//			}

//		if(clockDivider==0)clockDivider=getFrequencykResponsibleForDriveSpeed(1, 1, feedrate, driveConditionParam->phyCoord->precision);
//		
//		return clockDivider;
//}


//void setDirectionDriveConditional(SAllDriveConditionParam *allDriveConditionParam, SButtonMarksParam *toDoMark, uint32_t equipmentDetect){


//			if(toDoMark->key==KEY_KROPKA || toDoMark->atc==AT_TAG_Zm){
//				if(equipmentDetect & nWW){
//					allDriveConditionParam->activeDirectionDriveConditional=DIR_ZWm;
//					setDirectionAndClearAuxParamHandWorkDetail(&allDriveConditionParam->driveConditionParamZw, TYL, kKRAN_ZWmin, kKRAN_ZWplus);
//				}else{
//					allDriveConditionParam->activeDirectionDriveConditional=DIR_Zm;
//					setDirectionAndClearAuxParamHandWorkDetail(&allDriveConditionParam->driveConditionParamZ, TYL, kKRAN_Zmin, kKRAN_Zplus);
//				}
//			}else if(toDoMark->key==KEY_1 || toDoMark->atc==AT_TAG_XmYm){
//				allDriveConditionParam->activeDirectionDriveConditional=DIR_XmYm;
//				setDirectionAndClearAuxParamHandWorkDetail(&allDriveConditionParam->driveConditionParamX, TYL, kKRAN_Xmin, kKRAN_Xplus);
//				setDirectionAndClearAuxParamHandWorkDetail(&allDriveConditionParam->driveConditionParamY, TYL, kKRAN_Ymin, kKRAN_Yplus);
//				setDirectionAndClearAuxParamHandWorkDetail(&allDriveConditionParam->driveConditionParamU, TYL, kKRAN_Xmin, kKRAN_Xplus);
//				setDirectionAndClearAuxParamHandWorkDetail(&allDriveConditionParam->driveConditionParamV, TYL, kKRAN_Ymin, kKRAN_Yplus);
//			}else if(toDoMark->key==KEY_2 || toDoMark->atc==AT_TAG_Ym){
//				allDriveConditionParam->activeDirectionDriveConditional=DIR_Ym;
//				setDirectionAndClearAuxParamHandWorkDetail(&allDriveConditionParam->driveConditionParamY, TYL, kKRAN_Ymin, kKRAN_Yplus);
//				setDirectionAndClearAuxParamHandWorkDetail(&allDriveConditionParam->driveConditionParamV, TYL, kKRAN_Ymin, kKRAN_Yplus);
//			}else if(toDoMark->key==KEY_3 || toDoMark->atc==AT_TAG_XpYm){
//				allDriveConditionParam->activeDirectionDriveConditional=DIR_XpYm;
//				setDirectionAndClearAuxParamHandWorkDetail(&allDriveConditionParam->driveConditionParamX, PRZOD, kKRAN_Xplus, kKRAN_Xmin);
//				setDirectionAndClearAuxParamHandWorkDetail(&allDriveConditionParam->driveConditionParamY, TYL, kKRAN_Ymin, kKRAN_Yplus);
//				setDirectionAndClearAuxParamHandWorkDetail(&allDriveConditionParam->driveConditionParamU, PRZOD, kKRAN_Xplus, kKRAN_Xmin);
//				setDirectionAndClearAuxParamHandWorkDetail(&allDriveConditionParam->driveConditionParamV, TYL, kKRAN_Ymin, kKRAN_Yplus);
//			}else if(toDoMark->key==KEY_4 || toDoMark->atc==AT_TAG_Xm){
//				allDriveConditionParam->activeDirectionDriveConditional=DIR_Xm;
//				setDirectionAndClearAuxParamHandWorkDetail(&allDriveConditionParam->driveConditionParamX, TYL, kKRAN_Xmin, kKRAN_Xplus);
//				setDirectionAndClearAuxParamHandWorkDetail(&allDriveConditionParam->driveConditionParamU, TYL, kKRAN_Xmin, kKRAN_Xplus);
//			}else if(toDoMark->key==KEY_5 || toDoMark->atc==AT_TAG_Zp){
//				if(equipmentDetect & nWW){
//					allDriveConditionParam->activeDirectionDriveConditional=DIR_ZWp;
//					setDirectionAndClearAuxParamHandWorkDetail(&allDriveConditionParam->driveConditionParamZw, PRZOD, kKRAN_ZWplus, kKRAN_ZWmin);
//				}else{
//					allDriveConditionParam->activeDirectionDriveConditional=DIR_Zp;
//					setDirectionAndClearAuxParamHandWorkDetail(&allDriveConditionParam->driveConditionParamZ, PRZOD, kKRAN_Zplus, kKRAN_Zmin);
//				}
//			}else if(toDoMark->key==KEY_6 || toDoMark->atc==AT_TAG_Xp){
//				allDriveConditionParam->activeDirectionDriveConditional=DIR_Xp;
//				setDirectionAndClearAuxParamHandWorkDetail(&allDriveConditionParam->driveConditionParamX, PRZOD, kKRAN_Xplus, kKRAN_Xmin);
//				setDirectionAndClearAuxParamHandWorkDetail(&allDriveConditionParam->driveConditionParamU, PRZOD, kKRAN_Xplus, kKRAN_Xmin);
//			}else if(toDoMark->key==KEY_7 || toDoMark->atc==AT_TAG_XmYp){
//				allDriveConditionParam->activeDirectionDriveConditional=DIR_XmYp;
//				setDirectionAndClearAuxParamHandWorkDetail(&allDriveConditionParam->driveConditionParamX, TYL, kKRAN_Xmin, kKRAN_Xplus);
//				setDirectionAndClearAuxParamHandWorkDetail(&allDriveConditionParam->driveConditionParamY, PRZOD, kKRAN_Yplus, kKRAN_Ymin);
//				setDirectionAndClearAuxParamHandWorkDetail(&allDriveConditionParam->driveConditionParamU, TYL, kKRAN_Xmin, kKRAN_Xplus);
//				setDirectionAndClearAuxParamHandWorkDetail(&allDriveConditionParam->driveConditionParamV, PRZOD, kKRAN_Yplus, kKRAN_Ymin);
//			}else if(toDoMark->key==KEY_8 || toDoMark->atc==AT_TAG_Yp){
//				allDriveConditionParam->activeDirectionDriveConditional=DIR_Yp;
//				setDirectionAndClearAuxParamHandWorkDetail(&allDriveConditionParam->driveConditionParamY, PRZOD, kKRAN_Yplus, kKRAN_Ymin);
//				setDirectionAndClearAuxParamHandWorkDetail(&allDriveConditionParam->driveConditionParamV, PRZOD, kKRAN_Yplus, kKRAN_Ymin);
//			}else if(toDoMark->key==KEY_9 || toDoMark->atc==AT_TAG_XpYp){
//				allDriveConditionParam->activeDirectionDriveConditional=DIR_XpYp;
//				setDirectionAndClearAuxParamHandWorkDetail(&allDriveConditionParam->driveConditionParamX, PRZOD, kKRAN_Xplus, kKRAN_Xmin);
//				setDirectionAndClearAuxParamHandWorkDetail(&allDriveConditionParam->driveConditionParamY, PRZOD, kKRAN_Yplus, kKRAN_Ymin);
//				setDirectionAndClearAuxParamHandWorkDetail(&allDriveConditionParam->driveConditionParamU, PRZOD, kKRAN_Xplus, kKRAN_Xmin);
//				setDirectionAndClearAuxParamHandWorkDetail(&allDriveConditionParam->driveConditionParamV, PRZOD, kKRAN_Yplus, kKRAN_Ymin);
//			}

//}



//uint8_t driveCentering(SDriveConditionParam driveConditionParamUpperAxis, SDriveConditionParam driveConditionParamLowerAxis, int32_t *infoDrive, fDRIVE_TypeDef *errorDrive, defOMenu *oMenu, 
//											double maxDistansMM, int32_t *centrStartCoord, int32_t *centrTrackedCoord, uint32_t language, xQueueHandle qToDoMark, defOCheckSignals *oCheckAutWorkSignals,
//											uint32_t features, _Bool roughly){
//	#define VELOCITY_OF_FASTcentering			1500
//	#define VELOCITY_OF_SLOWcentering			100
//												
//												
//		portTickType taskCount;
//		defOButtonMarks oButtonMarks;
//		uint32_t clockDivider;
//		_Bool delayShortCircuitDet=true;
//		uint32_t maxDistans=maxDistansMM*pow(10, driveConditionParamLowerAxis.phyCoord->unit);

//		OButtonMarksConstruct(&oButtonMarks);

//		driveConditionParamLowerAxis.l_krok_pom=0;
//		clockDivider=getFrequencyOfDriveInUniformMovement(VELOCITY_OF_FASTcentering, driveConditionParamUpperAxis.phyCoord->precision);
//	//	clockDivider=BASE_FREQUENCY_OF_TIMcenteringFast;	
//		taskCount=xTaskGetTickCount();
//		(*infoDrive)=DRIVE_IN_PROGRESS;	


//		while(1){


//			//dojazd do materiału-----------------------------
//			while(1){			

//				checkDriveError();

//				if(delayShortCircuitDet==true){
//					if(driveConditionParamLowerAxis.l_krok_pom>=L_KROK_OPOZNIONEJ_DET)delayShortCircuitDet=false;
//				}
//				
//				if(xQueueReceive(qToDoMark, &oButtonMarks.toDoMark.mark, 0)){
//					oButtonMarks.decodeToDoMark(&oButtonMarks.toDoMark);

//					if(oButtonMarks.toDoMark.tag==TAG_MENU_PODR_1 || oButtonMarks.toDoMark.atc==AT_TAG_STOP || oButtonMarks.toDoMark.key==KEY_STOP || oButtonMarks.toDoMark.key==KEY_F1){
//						(*infoDrive)=PRZEJ_SPAUZOWANO;
//					}

//				}else if(oCheckAutWorkSignals->checkedResetSignals & nZW){ 	
//					if(!delayShortCircuitDet) break;
//				}else if(centrStartCoord!=NULL && centrTrackedCoord!=NULL && (*centrStartCoord)==(*centrTrackedCoord)){
//					return CENTR_KONIEC;
//				}else if(maxDistans/driveConditionParamLowerAxis.phyCoord->precision>0 && driveConditionParamLowerAxis.l_krok_pom>=maxDistans/driveConditionParamLowerAxis.phyCoord->precision){ 
//					return CENTR_PELEN_PRZEJAZD;
//				}

//				if((*infoDrive)==DRIVE_IN_PROGRESS){
//					if(driveConditionParamUpperAxis.axes==OS_X && (features & onX_INCREMENT)){
//						driveEngineService(&driveConditionParamLowerAxis, errorDrive, features);
//					}else{
//						driveEngineService(&driveConditionParamUpperAxis, errorDrive, features);
//						driveEngineService(&driveConditionParamLowerAxis, errorDrive, features);
//					}
//				}else if((*infoDrive)==PRZEJ_SPAUZOWANO){		
//					stopConditionalDrive(oMenu, infoDrive, language, qToDoMark);	
//					if((*infoDrive)==PRZEJ_PORZUCONO) return CENTR_BLAD;
//					taskCount=xTaskGetTickCount();
//				}else if((*infoDrive)==PRZEJ_PORZUCONO){
//					return CENTR_BLAD;
//				}

//				vTaskDelayUntil(&taskCount, pd100US_TO_TICKS(10000/clockDivider));
//			}


//			//odjazd od materiału aż do usunięcia zwarcia-----------------------------
//			driveConditionParamUpperAxis.turn=(1-driveConditionParamUpperAxis.turn);
//			driveConditionParamLowerAxis.turn=(1-driveConditionParamLowerAxis.turn);
//			driveConditionParamLowerAxis.l_krok_pom=0;
//			if(roughly==false)clockDivider=getFrequencyOfDriveInUniformMovement(VELOCITY_OF_SLOWcentering, driveConditionParamUpperAxis.phyCoord->precision);
//			taskCount=xTaskGetTickCount();
//			(*infoDrive)=DRIVE_IN_PROGRESS;

//			
//			while(1){		//dopoki jest zwarcie	

//				checkDriveError();

//				if(xQueueReceive(qToDoMark, &oButtonMarks.toDoMark.mark, 0)){
//					oButtonMarks.decodeToDoMark(&oButtonMarks.toDoMark);

//					if(oButtonMarks.toDoMark.tag==TAG_MENU_PODR_1 || oButtonMarks.toDoMark.atc==AT_TAG_STOP || oButtonMarks.toDoMark.key==KEY_STOP || oButtonMarks.toDoMark.key==KEY_F1){
//						(*infoDrive)=PRZEJ_SPAUZOWANO;
//					}

//				}else if(oCheckAutWorkSignals->checkedSetSignals & nZW){ 	//sprawdzenie czy jest potwierdzenie braku zwarcia
//					break;
//				}else	if(driveConditionParamLowerAxis.l_krok_pom>=L_KROK_SPR_ZWARCIA_ODJ){
//					(*infoDrive)=PRZEJ_PORZUCONO;
//				}

//				if((*infoDrive)==DRIVE_IN_PROGRESS){
//					if(driveConditionParamUpperAxis.axes==OS_X && (features & onX_INCREMENT)){
//						driveEngineService(&driveConditionParamLowerAxis, errorDrive, features);
//					}else{
//						driveEngineService(&driveConditionParamUpperAxis, errorDrive, features);
//						driveEngineService(&driveConditionParamLowerAxis, errorDrive, features);
//					}
//				}else if((*infoDrive)==PRZEJ_SPAUZOWANO){		
//					stopConditionalDrive(oMenu, infoDrive, language, qToDoMark);	
//					if((*infoDrive)==PRZEJ_PORZUCONO) return CENTR_BLAD;
//					taskCount=xTaskGetTickCount();
//				}else if((*infoDrive)==PRZEJ_PORZUCONO){
//					return CENTR_BLAD;
//				}

//				vTaskDelayUntil(&taskCount, pd100US_TO_TICKS(10000/clockDivider));
//			}

//			if((driveConditionParamLowerAxis.l_krok_pom*driveConditionParamLowerAxis.phyCoord->precision)<=(0.005*pow(10, driveConditionParamLowerAxis.phyCoord->unit)) || roughly==true)break;

//			driveConditionParamUpperAxis.turn=(1-driveConditionParamUpperAxis.turn);
//			driveConditionParamLowerAxis.turn=(1-driveConditionParamLowerAxis.turn);
//			driveConditionParamLowerAxis.l_krok_pom=0;
//			(*infoDrive)=DRIVE_IN_PROGRESS;	
//			taskCount=xTaskGetTickCount();

//		}
//		return CENTR_ZWARCIE;
//		
//}


//uint8_t driveWirePlating(SDriveConditionParam driveConditionParamUpperAxis, SDriveConditionParam driveConditionParamLowerAxis, int32_t *infoDrive, fDRIVE_TypeDef *errorDrive, defOMenu *oMenu, 
//											double maxDistansMM, uint32_t language, xQueueHandle qToDoMark, defOCheckSignals *oCheckAngleBracketSignals, uint32_t features, xQueueHandle qToDoMarkTools){
//	#define VELOCITY_OF_FASTplating			1500
//	#define VELOCITY_OF_SLOWplating			100

//		portTickType taskCount;
//		defOButtonMarks oButtonMarks;
//		uint32_t clockDivider;
//		_Bool simultaneouslyCircutit=false;
//		uint32_t maxDistans=maxDistansMM*pow(10, driveConditionParamLowerAxis.phyCoord->unit);
//												
//		OButtonMarksConstruct(&oButtonMarks);

//		clockDivider=getFrequencyOfDriveInUniformMovement(VELOCITY_OF_FASTplating, driveConditionParamUpperAxis.phyCoord->precision);
//		taskCount=xTaskGetTickCount();
//		(*infoDrive)=DRIVE_IN_PROGRESS;

//		while(1){


//			//dojazd do materiału-----------------------------
//			while(1){			
//				
//				checkDriveErrorWirePlating();

//				if(xQueueReceive(qToDoMark, &oButtonMarks.toDoMark.mark, 0)){
//					oButtonMarks.decodeToDoMark(&oButtonMarks.toDoMark);

//					if(oButtonMarks.toDoMark.tag==TAG_MENU_PODR_1 || oButtonMarks.toDoMark.atc==AT_TAG_STOP || oButtonMarks.toDoMark.key==KEY_STOP || oButtonMarks.toDoMark.key==KEY_F1){
//						(*infoDrive)=PRZEJ_SPAUZOWANO;
//					}

//				}else if(oCheckAngleBracketSignals->checkedSetSignals & (nZWG | nZWD)){ 
//					if((oCheckAngleBracketSignals->checkedSetSignals & nZWG) && (oCheckAngleBracketSignals->checkedSetSignals & nZWD))simultaneouslyCircutit=true;
//					break;
//				}else if(maxDistans/driveConditionParamLowerAxis.phyCoord->precision>0 && driveConditionParamLowerAxis.l_krok_pom>=maxDistans/driveConditionParamLowerAxis.phyCoord->precision){ 
//					return CENTR_PELEN_PRZEJAZD;
//				}

//				if((*infoDrive)==DRIVE_IN_PROGRESS){
//					if(driveConditionParamUpperAxis.axes==OS_X && (features & onX_INCREMENT)){
//						driveEngineService(&driveConditionParamLowerAxis, errorDrive, features);
//					}else{
//						driveEngineService(&driveConditionParamUpperAxis, errorDrive, features);
//						driveEngineService(&driveConditionParamLowerAxis, errorDrive, features);
//					}
//				}else if((*infoDrive)==PRZEJ_SPAUZOWANO){		
//					uint32_t auxTag=AT_TAG_WIRE_OFF | qMARK_ATC;
//					xQueueSendToBack(qToDoMarkTools, &auxTag, 0);	
//					stopConditionalDrive(oMenu, infoDrive, language, qToDoMark);	
//					if((*infoDrive)==PRZEJ_PORZUCONO) return CENTR_BLAD;
//					auxTag=AT_TAG_WIRE_ON | qMARK_ATC;
//					xQueueSendToBack(qToDoMarkTools, &auxTag, 0);	
//					taskCount=xTaskGetTickCount();
//				}else if((*infoDrive)==PRZEJ_PORZUCONO){
//					uint32_t auxTag=AT_TAG_WIRE_OFF | qMARK_ATC;
//					xQueueSendToBack(qToDoMarkTools, &auxTag, 0);	
//					return CENTR_BLAD;
//				}

//				vTaskDelayUntil(&taskCount, pd100US_TO_TICKS(10000/clockDivider));
//			}


//			//odjazd od materiału aż do usunięcia zwarcia-----------------------------
//			driveConditionParamUpperAxis.turn=(1-driveConditionParamUpperAxis.turn);
//			driveConditionParamLowerAxis.turn=(1-driveConditionParamLowerAxis.turn);
//			driveConditionParamLowerAxis.l_krok_pom=0;
//			clockDivider=getFrequencyOfDriveInUniformMovement(VELOCITY_OF_SLOWplating, driveConditionParamUpperAxis.phyCoord->precision);
//			taskCount=xTaskGetTickCount();
//			(*infoDrive)=DRIVE_IN_PROGRESS;

//			
//			while(1){		//dopoki jest zwarcie	

//				checkDriveErrorWirePlating();

//				if(xQueueReceive(qToDoMark, &oButtonMarks.toDoMark.mark, 0)){
//					oButtonMarks.decodeToDoMark(&oButtonMarks.toDoMark);

//					if(oButtonMarks.toDoMark.tag==TAG_MENU_PODR_1 || oButtonMarks.toDoMark.atc==AT_TAG_STOP || oButtonMarks.toDoMark.key==KEY_STOP || oButtonMarks.toDoMark.key==KEY_F1){
//						(*infoDrive)=PRZEJ_SPAUZOWANO;
//					}

//				}else if((oCheckAngleBracketSignals->checkedResetSignals & nZWG) && (oCheckAngleBracketSignals->checkedResetSignals & nZWD)){ 	//sprawdzenie czy jest potwierdzenie braku zwarcia
//					break;
//				}else	if(driveConditionParamLowerAxis.l_krok_pom>=L_KROK_SPR_ZWARCIA_ODJ){
//					(*infoDrive)=PRZEJ_PORZUCONO;
//				}

//				if((*infoDrive)==DRIVE_IN_PROGRESS){
//					if((oCheckAngleBracketSignals->checkedSetSignals & nZWG) && (oCheckAngleBracketSignals->checkedSetSignals & nZWD)){ 	
//						if(driveConditionParamUpperAxis.axes==OS_X && (features & onX_INCREMENT)){
//							driveEngineService(&driveConditionParamLowerAxis, errorDrive, features);
//						}else{
//							driveEngineService(&driveConditionParamUpperAxis, errorDrive, features);
//							driveEngineService(&driveConditionParamLowerAxis, errorDrive, features);
//						}
//					}else if(oCheckAngleBracketSignals->checkedSetSignals & nZWG){
//						driveEngineService(&driveConditionParamUpperAxis, errorDrive, features);
//					}else if(oCheckAngleBracketSignals->checkedSetSignals & nZWD){
//						if(driveConditionParamUpperAxis.axes==OS_X && (features & onX_INCREMENT)){
//							driveConditionParamUpperAxis.turn=(1-driveConditionParamUpperAxis.turn);
//							driveEngineService(&driveConditionParamUpperAxis, errorDrive, features);
//							driveConditionParamUpperAxis.turn=(1-driveConditionParamUpperAxis.turn);
//							driveEngineService(&driveConditionParamLowerAxis, errorDrive, features);
//						}else{
//							driveEngineService(&driveConditionParamLowerAxis, errorDrive, features);
//						}
//					}

//				}else if((*infoDrive)==PRZEJ_SPAUZOWANO){
//					uint32_t auxTag=AT_TAG_WIRE_OFF | qMARK_ATC;
//					xQueueSendToBack(qToDoMarkTools, &auxTag, 0);			
//					stopConditionalDrive(oMenu, infoDrive, language, qToDoMark);	
//					if((*infoDrive)==PRZEJ_PORZUCONO) return CENTR_BLAD;
//					auxTag=AT_TAG_WIRE_ON | qMARK_ATC;
//					xQueueSendToBack(qToDoMarkTools, &auxTag, 0);	
//					taskCount=xTaskGetTickCount();
//				}else if((*infoDrive)==PRZEJ_PORZUCONO){
//					uint32_t auxTag=AT_TAG_WIRE_OFF | qMARK_ATC;
//					xQueueSendToBack(qToDoMarkTools, &auxTag, 0);	
//					return CENTR_BLAD;
//				}

//				vTaskDelayUntil(&taskCount, pd100US_TO_TICKS(10000/clockDivider));
//			}

//			if(simultaneouslyCircutit){
//				if((driveConditionParamLowerAxis.l_krok_pom*driveConditionParamLowerAxis.phyCoord->precision)<=(0.005*pow(10, driveConditionParamLowerAxis.phyCoord->unit)))break;
////				if(driveConditionParamLowerAxis.l_krok_pom==1)break;
//				simultaneouslyCircutit=false;
//			}

//			driveConditionParamUpperAxis.turn=(1-driveConditionParamUpperAxis.turn);
//			driveConditionParamLowerAxis.turn=(1-driveConditionParamLowerAxis.turn);
//			driveConditionParamLowerAxis.l_krok_pom=0;
//			(*infoDrive)=DRIVE_IN_PROGRESS;
//			taskCount=xTaskGetTickCount();

//		}
//		return CENTR_ZWARCIE;
//		
//}

//void stopConditionalDrive(defOMenu *oMenu, int32_t *infoDrive, uint32_t language, xQueueHandle qToDoMark){
//		defOButtonMarks oButtonMarks;

//		OButtonMarksConstruct(&oButtonMarks);	

//		oMenu->setPopupMenu(&oMenu->menuParam, MENU_CONTINUE_DROP, language);
//		
//		while(1){
//			xQueueReceive(qToDoMark, &oButtonMarks.toDoMark.mark, portMAX_DELAY);
//			oButtonMarks.decodeToDoMark(&oButtonMarks.toDoMark);
//	
//			if(oButtonMarks.toDoMark.tag==TAG_MENU_PODR_1 || oButtonMarks.toDoMark.atc==AT_TAG_CONT || oButtonMarks.toDoMark.key==KEY_F1){ 		//jezeli zadeklarowano "jedz dalej" to kontynuuj wykonywanie przejazdu
//				(*infoDrive)=DRIVE_IN_PROGRESS;
//				break;
//			}else if(oButtonMarks.toDoMark.tag==TAG_MENU_PODR_2 || oButtonMarks.toDoMark.atc==AT_TAG_ABORT || oButtonMarks.toDoMark.key==KEY_F2 || oButtonMarks.toDoMark.tag==TAG_ESC || oButtonMarks.toDoMark.key==KEY_ESC){ 	//jezeli zadeklarowano "porzuc" to zakoncz wykonywanie przejazdu
//				(*infoDrive)=PRZEJ_PORZUCONO;
//				break;
//			}
//		}

//		oMenu->setPopupMenu(&oMenu->menuParam, MENU_STOP, language);

//}


//void setParamHandWorkDetail(SDriveConditionParam *sDriveConditionParam, SParam *phyCoord, SParam *baseCoord, uint16_t *m_step, uint16_t *micro_step, uint8_t *b_lin, 
//				uint32_t axes, SCorrection correct){

//			sDriveConditionParam->phyCoord=phyCoord;
//			sDriveConditionParam->baseCoord=baseCoord;
//			sDriveConditionParam->m_step=m_step;
//			sDriveConditionParam->micro_step=micro_step;
//			sDriveConditionParam->axes=axes;
//			sDriveConditionParam->b_lin=b_lin;
//			sDriveConditionParam->correct=correct;
//}

//void setDirectionAndClearAuxParamHandWorkDetail(SDriveConditionParam *sDriveConditionParam, defTurn turn, uint32_t limStop, uint32_t limStopBack){

//			sDriveConditionParam->turn=turn;
//			sDriveConditionParam->limStop=limStop;
//			sDriveConditionParam->limStopBack=limStopBack;
//			sDriveConditionParam->l_krok_pom=0;	
//			sDriveConditionParam->l_krok_tot=0;
//			sDriveConditionParam->infoDrive=DRIVE_IN_PROGRESS;
//			sDriveConditionParam->pointA=sDriveConditionParam->phyCoord->value;

//}

//void copyParamHandWorkDetail(SDriveConditionParam *setDriveConditionParam, SDriveConditionParam putDriveConditionParam){

//			setDriveConditionParam->phyCoord=putDriveConditionParam.phyCoord;
//			setDriveConditionParam->baseCoord=putDriveConditionParam.baseCoord;
//			setDriveConditionParam->m_step=putDriveConditionParam.m_step;
//			setDriveConditionParam->micro_step=putDriveConditionParam.micro_step;
//			setDriveConditionParam->b_lin=putDriveConditionParam.b_lin;
//			setDriveConditionParam->axes=putDriveConditionParam.axes;
//			setDriveConditionParam->correct=putDriveConditionParam.correct;
//}

//void copyDirectionAndClearAuxParamHandWorkDetail(SDriveConditionParam *setDriveConditionParam, SDriveConditionParam putDriveConditionParam){

//			setDriveConditionParam->turn=putDriveConditionParam.turn;
//			setDriveConditionParam->limStop=putDriveConditionParam.limStop;
//			setDriveConditionParam->limStopBack=putDriveConditionParam.limStopBack;
//			setDriveConditionParam->l_krok_pom=putDriveConditionParam.l_krok_pom;	
//			setDriveConditionParam->l_krok_tot=putDriveConditionParam.l_krok_tot;

//}

