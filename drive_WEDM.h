#ifndef _DRIVE_WEDM_H
	#define _DRIVE_WEDM_H

#include "drive_machine.h"
	

	
	class defODriveWEDM : public defODriveMachine{

		public:
			defODriveWEDM();
			virtual void driveForValue();
			virtual void driveToBaseCoordinates();
			virtual void driveToPhyCoordinates();
			virtual void driveToCharacteristicPoint();
			virtual void driveToLimstop();
		
			virtual void drivePath();

	};	

	
//	typedef struct{
//		double stepDriveMM;			//zmienna wykorzystywana przy przejazdach o krok
//		fDRIVE_TypeDef errorDrive;
//		int32_t infoDrive;
//		_Bool phyCoordIgnorance;	
//		_Bool circuitIgnorance;	
//		SDriveMask driveMask;
//		SDriveLin driveLin;
////		SCorrectionAllAxes corrections;

//		uint32_t focusFeedrate;
//		SDriveFeedrate *feedrate;
//		SDriveFeedrate wireFeedrate;
//		SDriveFeedrate drillFeedrate;
//		defOItems feedrateList;
//		
//		uint32_t tabOfValueFeed[NR_OF_TAB_FEED_PERMIT_VALUE];
//		
//		SDriveParam driveParam;	
//		SDrivePathParam drivePathParam; 
//		SAllDriveConditionParam allDriveConditionParam;

//		void(*setFeedrateParamByDefaultValues)(SDriveFeedrate*);

//		void (*setSygPortDRIVE)(SDriveMask*);
//		void (*setSingleSygPortDRIVE)(SDriveConditionParam*);

//		void (*ruch_do_przodu)(uint16_t*, SParam*, SParam*, uint8_t *b_lin, fDRIVE_TypeDef*, SCorrection*, uint32_t);
//		void (*ruch_do_tylu)(uint16_t *, SParam*, SParam*, uint8_t*, fDRIVE_TypeDef*, _Bool, SCorrection*, uint32_t);
//		_Bool (*spr_ruch_do_tylu)(uint16_t, uint16_t*, SParam*, SParam*, int32_t*, int32_t*, uint8_t *, SCorrection*);
//		_Bool (*spr_ruch_do_przodu)(uint16_t, uint16_t*, SParam*, SParam*, int32_t*, int32_t*, uint8_t *, SCorrection*);

//		uint16_t (*getClockDividerResponsibleForDriveSpeed)(uint32_t, uint32_t, SFeedrate*, uint32_t, uint32_t);
//		uint32_t (*calculateAccelerateNumberOfSteps)(SFeedrate*, uint32_t);

//		void (*brakingDrive)(SParam *, int32_t, int32_t, int32_t*, SFeedrate*);
//		void (*driveAXES)(SParam*, SParam*, int32_t, uint16_t*, uint16_t*, uint8_t*, fDRIVE_TypeDef*, _Bool, SCorrection *, uint32_t);

//		int32_t (*driveForValue)(defOCoordinates*, defOCheckSignals*, SDriveParam*, int32_t*, defOMenu*, uint32_t, xQueueHandle, SFeedrate*);
//		int32_t (*driveToBaseCoordinates)(defOCoordinates*, defOCheckSignals*, SDriveParam*, int32_t*, defOMenu*, uint32_t, xQueueHandle, SFeedrate*);
//		int32_t (*driveToPhyCoordinates)(defOCoordinates*, defOCheckSignals*, SDriveParam*, int32_t*, defOMenu*, uint32_t, xQueueHandle, SFeedrate*);
//		int32_t (*driveToCharacteristicPoint)(defOCoordinates*, defOCheckSignals*, SDriveParam*, int32_t*, defOMenu*, uint32_t, defOMachineConfig*, xQueueHandle, SFeedrate*);
//		int32_t (*driveToLimstop)(defOCoordinates*, defOCheckSignals*, SDriveParam*, int32_t*, defOMenu*, _Bool*, uint32_t, defOMachineConfig*, xQueueHandle, SFeedrate*);

////		void (*driveEngineService)(SDriveConditionParam*, fDRIVE_TypeDef*, SCorrection*, uint32_t);
//		void (*setDirectionDriveConditional)(SAllDriveConditionParam*, SButtonMarksParam *, uint32_t);
//		uint32_t (*driveConditionalService)(SDriveConditionParam *, defOCheckSignals *, uint32_t, fDRIVE_TypeDef *, SFeedrate *, uint32_t, _Bool *);
//		uint8_t (*driveCentering)(SDriveConditionParam, SDriveConditionParam, int32_t*, fDRIVE_TypeDef*, defOMenu*, double, int32_t*, int32_t*, uint32_t, xQueueHandle, defOCheckSignals*, uint32_t, _Bool);
//		uint8_t (*driveWirePlating)(SDriveConditionParam, SDriveConditionParam, int32_t*, fDRIVE_TypeDef*, defOMenu*, double, uint32_t, xQueueHandle, defOCheckSignals*, uint32_t, xQueueHandle);

//		void (*setParamHandWorkDetail)(SDriveConditionParam*, SParam*, SParam*, uint16_t*, uint16_t*, uint8_t*, uint32_t, SCorrection);
//		void (*setDirectionAndClearAuxParamHandWorkDetail)(SDriveConditionParam*, defTurn, uint32_t, uint32_t);
//		void (*copyParamHandWorkDetail)(SDriveConditionParam*, SDriveConditionParam);
//		void (*copyDirectionAndClearAuxParamHandWorkDetail)(SDriveConditionParam*, SDriveConditionParam);

//		void (*drivePathSetSectionParam)(SDrivePathParam*, SCoordinates, SCoordinates, defOCoordinates*, _Bool);
//		void (*drivePathSetArcParam)(SDrivePathParam*, SCoordinates, SCoordinates, SCoordinates, defTurnCircle, defOCoordinates*);

//		void (*getRealEndOfArc)(int32_t*, int32_t*, SCoordinates, int32_t, int32_t, SCoordinates, defTurnCircle, defOCoordinates *);
//		int32_t (*drivePath)(defOCoordinates*, SDrivePathParam*, defOFlashCoordDeparture*, SFeedrate*, int32_t*, defOMenu*, defOSystemsData *, uint32_t, xQueueHandle, uint32_t, xQueueHandle);
//		void (*drivePathService)(SDrivePathParam*, defTurn, SDriveMask*, int32_t*, fDRIVE_TypeDef *, SDriveLin*, defOAutWork*, SFeedrate*, defOCoordinates*, SCorrectionAllAxes*, uint32_t);

//		void (*setLinMask)(uint16_t*, uint32_t);
//	}defODrive;

//	void ODriveConstruct(defODrive *oDrive, defOCoordinates *oCoordinates, SCorrectionAllAxes *corrections, uint32_t language);
//	void setFeedrateList(SItemsParam *itemsParam, uint32_t language);
//	void setWireFeedrateParamByDefaultValues(SDriveFeedrate *feedrate);
//	void setDrillFeedrateParamByDefaultValues(SDriveFeedrate *feedrate);
//	static void getDriveMaskFromBackup(SDriveMask *driveMask);
//	static uint16_t restoreDriveMaskFromBackup(uint16_t driveMaskFromBackup);

//	static void setSygPortDRIVE(SDriveMask *driveMask);
//	static void setSingleSygPortDRIVE(SDriveConditionParam *driveConditionParam);


////	#define IL_KROK_HAM	625

////	#define PRZEJAZD_ZREALIZOWANY	0
////	#define PRZEJAZD_BLAD					1
////	#define LACK_OF_PUSH_LIMSTOP	2

//	int32_t drive(defOCoordinates *oCoordinates, SDriveParam *driveParam, int32_t *infoDrive, defOMenu *oMenu, defOCheckSignals* oCheckSignalsLimitedStop, uint32_t language, 
//								xQueueHandle qToDoMark, SFeedrate *feedrateJog);
//	void brakingDrive(SParam *wsp_fiz, int32_t wsp_A, int32_t wsp_B, int32_t *wsp_pos, SFeedrate* feedrate);
//	void stopDrive(defOCoordinates *oCoordinates, defOMenu *oMenu, SDriveParam *driveParam, int32_t *infoDrive, uint32_t language, xQueueHandle qToDoMark);
//	static void driveAXES(SParam* phyCoord, SParam* baseCoord, int32_t indirectCoord, uint16_t *m_step, uint16_t *micro_step, uint8_t *b_lin, fDRIVE_TypeDef *errorDrive, _Bool phyCoordIgnorance, SCorrection *correct, uint32_t features);
//	_Bool checkLimstopDrive(uint32_t CheckSignalsLimitedStop,  uint16_t limStop_plus, uint16_t limStop_minus, int32_t distans);

//	static int32_t driveForValue(defOCoordinates *oCoordinates, defOCheckSignals* oCheckSignalsLimitedStop, SDriveParam *driveParam, int32_t *infoDrive, defOMenu *oMenu, uint32_t language, xQueueHandle qToDoMark, SFeedrate *feedrateJog);
//	static int32_t driveToBaseCoordinates(defOCoordinates *oCoordinates, defOCheckSignals* oCheckSignalsLimitedStop, SDriveParam *driveParam, int32_t *infoDrive, defOMenu *oMenu, uint32_t language, xQueueHandle qToDoMark, SFeedrate *feedrateJog);
//	static int32_t driveToPhyCoordinates(defOCoordinates *oCoordinates, defOCheckSignals* oCheckSignalsLimitedStop, SDriveParam *driveParam, int32_t *infoDrive, defOMenu *oMenu, uint32_t language, xQueueHandle qToDoMark, SFeedrate *feedrateJog);
//	static int32_t driveToCharacteristicPoint(defOCoordinates *oCoordinates, defOCheckSignals* oCheckSignalsLimitedStop, SDriveParam *driveParam, int32_t *infoDrive, defOMenu *oMenu, uint32_t language, defOMachineConfig *oMachineConfig, xQueueHandle qToDoMark, SFeedrate *feedrateJog);
//	static int32_t driveToLimstop(defOCoordinates *oCoordinates, defOCheckSignals* oCheckSignalsLimitedStop, SDriveParam *driveParam, int32_t *infoDrive, defOMenu *oMenu, _Bool *phyCoordIgnorance, uint32_t language, defOMachineConfig *oMachineConfig, xQueueHandle qToDoMark, SFeedrate *feedrateJog);
//	
//	void driveEngineService(SDriveConditionParam *driveConditionParam, fDRIVE_TypeDef *fDrive, uint32_t features);


//	uint32_t driveConditionalService(SDriveConditionParam *driveConditionParam, defOCheckSignals* oCheckSignalsLimitedStop, uint32_t key, fDRIVE_TypeDef *errorDrive, SFeedrate* feedrate, 
//																uint32_t features, _Bool *circuitIgnorance);									
//	void setDirectionDriveConditional(SAllDriveConditionParam *allDriveConditionParam, SButtonMarksParam *toDoMark, uint32_t equipmentDetect);
//	void setParamHandWorkDetail(SDriveConditionParam *sDriveConditionParam, SParam *phyCoord, SParam *baseCoord, uint16_t *m_step, uint16_t *micro_step, uint8_t *b_lin, uint32_t axes, SCorrection correct);
//	void setDirectionAndClearAuxParamHandWorkDetail(SDriveConditionParam *sDriveConditionParam, defTurn turn, uint32_t limStop, uint32_t limStopBack);
//	void copyParamHandWorkDetail(SDriveConditionParam *setDriveConditionParam, SDriveConditionParam putDriveConditionParam);
//	void copyDirectionAndClearAuxParamHandWorkDetail(SDriveConditionParam *setDriveConditionParam, SDriveConditionParam putDriveConditionParam);

//	#define CENTER_I_STAGE				0
//	#define CENTER_II_STAGE				1

//	#define CENTR_BLAD						0
//	#define CENTR_ZWARCIE					1
//	#define CENTR_PELEN_PRZEJAZD	2
//	#define CENTR_KONIEC 					3

//	uint8_t driveCentering(SDriveConditionParam driveConditionParamUpperAxis, SDriveConditionParam driveConditionParamLowerAxis, int32_t *infoDrive, fDRIVE_TypeDef *errorDrive, defOMenu *oMenu, double maxDistansMM, int32_t *centrStartCoord, 
//												int32_t *centrTrackedCoord, uint32_t language, xQueueHandle qToDoMark, defOCheckSignals *oCheckAutWorkSignals, uint32_t features, _Bool roughly);	
//	uint8_t driveWirePlating(SDriveConditionParam driveConditionParamUpperAxis, SDriveConditionParam driveConditionParamLowerAxis, int32_t *infoDrive, fDRIVE_TypeDef *errorDrive, defOMenu *oMenu, 
//											double maxDistansMM, uint32_t language, xQueueHandle qToDoMark, defOCheckSignals *oCheckAngleBracketSignals, uint32_t features,xQueueHandle qToDoMarkTools);
//	void stopConditionalDrive(defOMenu *oMenu, int32_t *infoDrive, uint32_t language, xQueueHandle qToDoMark);

////	#define TRAJE_ERROR										0
////	#define TRAJE_BACK_TO_START						1
////	#define TRAJE_FINISH									2
////	#define TRAJE_GO_TO_NEXT_SEGMENT			3
////	#define TRAJE_GO_TO_PREVIOUS_SEGMENT	4
////	#define TRAJE_DEPARTURE								5



//	double arcImplicitFunction(double X1, double Y1, double R2);

//	uint8_t findMasterAxis(SCoordinates vector, defOCoordinates *oCoordinates);
//	void drivePathSetSectionParam(SDrivePathParam *drivePathParam, SCoordinates pointA, SCoordinates pointB, defOCoordinates *oCoordinates, _Bool driveToFirstDischarge);
//	void getPositionOfTheSection(SDrivePathParam *drivePathParam, defOCoordinates *oCoordinates);
//	void drivePathSetArcParam(SDrivePathParam *drivePathParam, SCoordinates circleCenter, SCoordinates pointA, SCoordinates pointB, defTurnCircle turnCircle, defOCoordinates *oCoordinates);
//	uint32_t calculateNrOfStepCircle(SDrivePathParam *drivePathParam, SCoordinates *endCoord, defOCoordinates *oCoordinates);
//	void getPositionOfTheArc(SDrivePathParam *drivePathParam, defOCoordinates *oCoordinates);
//	void getRealEndOfArc(int32_t *Xkon_real, int32_t *Ykon_real, SCoordinates wsp_srodka, int32_t Xkon, int32_t Ykon, SCoordinates wsp_pocz, defTurnCircle turnCircle, defOCoordinates *oCoordinates);

//	int32_t drivePath(defOCoordinates *oCoordinates, SDrivePathParam *drivePathParam, defOFlashCoordDeparture *oFlashCoordDeparture, SFeedrate *feedrate, int32_t *infoDrive, 
//										defOMenu *oMenu, defOSystemsData *oSystemsData, uint32_t language, xQueueHandle qToDoMark, uint32_t timeOfDelay, xQueueHandle qToDoMarkTools);
//	void stopDrivePath(defOCoordinates *oCoordinates, defOFlashCoordDeparture *oFlashCoordDeparture, SDrivePathParam *drivePathParam, int32_t *infoDrive, defOMenu *oMenu, defOSystemsData *oSystemsData, uint32_t language, xQueueHandle qToDoMark);

//	void drivePathService(SDrivePathParam *drivePathParam, defTurn turn, SDriveMask *driveMask, int32_t *infoDrive, fDRIVE_TypeDef *errorDrive, SDriveLin *driveLin, defOAutWork *oAutWork, 
//											SFeedrate* feedrate, defOCoordinates *oCoordinates, SCorrectionAllAxes *corrects, uint32_t features);
//	uint32_t drivePathSection(SDrivePathParam *drivePathParam, SCoordinates pointA, SCoordinates pointB, SDriveMask *driveMask, fDRIVE_TypeDef *errorDrive, SDriveLin *driveLin, 
//														defOCoordinates *oCoordinates, SFeedrate* feedrate, SCorrectionAllAxes *corrects, uint32_t features);
//	void drivePathArc(SDrivePathParam *drivePathParam, SCoordinates pointB, SDriveMask *driveMask, fDRIVE_TypeDef *errorDrive, SDriveLin *driveLin, defOCoordinates *oCoordinates, 
//										SFeedrate* feedrate, int32_t vectorZ, defTurnCircle turnCircle, defTurn turn, SCorrectionAllAxes *corrects, uint32_t features);
//	

#endif
