#ifndef _PP_DRIVE_ALGORITHMS_H
	#define _PP_DRIVE_ALGORITHMS_H

#include <map>
#include "pp_stepper_motor_driver.h"
#include "pp_paramlist.h"
#include "pp_motorslist.h"

//	#define NR_OF_FEEDRATE 					2

//	#define feedrate_NO_VALUE 				(-1)


//	#define feedrate_DEFAULT_VALUE			5
//	#define drillFeedrate_DEFAULT_VALUE				400

//	#define feedrateMAX									2500	
//	#define feedrateMIN									1
//	#define drillFeedrateMAX						2500	
//	#define drillFeedrateMIN						1

//	#if defined(AC_SERVO)
//		#define feedrateJog_ACCELERATION		30
//		#define feedrateJog_DEFAULT_VALUE		30000
//		#define feedrateJogMAX							30000	

//		#define drillFeedrateJog_ACCELERATION			30
//		#define drillFeedrateJog_DEFAULT_VALUE		30000
//		#define drillFeedrateJogMAX								30000	
//	#else
//		#define feedrateJog_ACCELERATION		2
//		#define feedrateJog_DEFAULT_VALUE		4000
//		#define feedrateJogMAX							4000	

//		#define drillFeedrateJog_ACCELERATION			2
//		#define drillFeedrateJog_DEFAULT_VALUE		2500
//		#define drillFeedrateJogMAX								2500	
//	#endif


//		#define feedrateJogMIN							1
//		#define drillFeedrateJogMIN					1

//	#define FOCUSfeedrate						1
//	#define FOCUSfeedrateJog				2

//	#define L_KROK_OPOZNIONEJ_DET 20
//	#define L_KROK_SPR_ZWARCIA_ODJ 2000

//	#define T_PROSTA 1
//	#define T_LUK 2

//	#define MASKA_nr_linX 				0x01
//	#define MASKA_nr_linY 				0x02
//	#define MASKA_nr_linU 				0x04
//	#define MASKA_nr_linV 				0x08

//	#define MASKA_linX 				0x00C0
//	#define MASKA_linY 				0x0030
//	#define MASKA_linU 				0x000C
//	#define MASKA_linV 				0x0003
//	#define L_ZGUBIONYCH_KROKOW	50

//enum{
//	NONE_DRIVE,
//	ACTIVE_DRIVE,
//	PAUSE_DRIVE
//};


//	typedef enum
//	{ PRZOD = 0,
//		TYL = 1
//	}defTurn;

//	typedef enum
//	{ ZEGAR_ZGODNIE = 0,
//		ZEGAR_PRZECIWNIE = 1
//	}defTurnCircle;




//	typedef struct{
//	//	uint32_t activeDrive;
//		SCoordinates pointA; 
//		SCoordinates pointB;
//		SCoordinates vectorAB;
//		SCoordinates indirectCoord;		//współrzędne pośrednie wykorzystywane jako współrzędne końcowy przy przerywaniu przejazdu o wartość
//	}SDriveParam;	//parametry wykorzystywane przy przejazdach o wartość


//	typedef struct{
//		uint32_t activeDrivePath;
//		_Bool driveToFirstDischarge;
//		uint8_t typeOfDrive;
//		SCoordinates pointA; 
//		SCoordinates pointB; 
//		SCoordinates vectorAB;
//		
//		int32_t hypSumStepOfSEG;
//		int32_t stepOfContour;
//		double efficiency;

//		int32_t nrOfStepOnCircuit;
//		int32_t nrOfStepWithoutWork;

//		uint8_t masterAxis;
//		_Bool startDetErrSEG;
//		double nPointX; 
//		double nPointY; 
//		double nPointZ; 
//		double nPointU; 
//		double nPointV; 
//		double nPointZw; 

//		SCoordinates circleCenter;
//		defTurnCircle turnCircle;
//		double circleR2;
//		SCoordinates kB;	
//		uint32_t *nrOfStepCircle;
//		double dividerZ;
//		double dividerXY;
//		uint32_t nrOfStepCircleZ;
//		uint32_t nrOfStepCircleXY;
//		uint32_t nrOfMadeStepCircleZ;
//		uint32_t nrOfMadeStepCircleXY;
//	}SDrivePathParam;	//parametry wykorzystywane przy przejazdach w pracy automatycznej

//	typedef struct{
//		uint16_t *m_step;
//		uint16_t *micro_step;
//		SParam *phyCoord; 
//		SParam *baseCoord; 
//		uint8_t *b_lin;
//		uint32_t limStop;
//		uint32_t limStopBack;
//		uint32_t axes;	
//		defTurn turn;
//		int32_t l_krok_pom;
//		int32_t l_krok_tot;
//		SCorrection correct;
//		int32_t infoDrive;
//		
//		int32_t pointA; 
//		int32_t vectorAB;
//		
//	}SDriveConditionParam;	//parametry wykorzystywane przy przejazdach warunkowych


//	#define DIR_NULL		0
////	#define DIR_X				1
////	#define DIR_Y				2
////	#define DIR_XY			3
////	#define DIR_Z				4
////	#define DIR_Zw			5

//#define DIR_Zm							1
//#define DIR_XmYm						2
//#define DIR_Ym							3
//#define DIR_XpYm 						4
//#define DIR_Xm							5
//#define DIR_Zp							6
//#define DIR_Xp							7
//#define DIR_XmYp						8
//#define DIR_Yp							9
//#define DIR_XpYp						10
//#define DIR_ZWp							11
//#define DIR_ZWm							12


//	typedef struct{
//		uint32_t activeDirectionDriveConditional;
//		SDriveConditionParam driveConditionParamX;
//		SDriveConditionParam driveConditionParamY;
//		SDriveConditionParam driveConditionParamZ;
//		SDriveConditionParam driveConditionParamU;
//		SDriveConditionParam driveConditionParamV;
//		SDriveConditionParam driveConditionParamZw;
//	}SAllDriveConditionParam;	//parametry wykorzystywane przy przejazdach warunkowych

	#define DRIVE_IN_PROGRESS					(-1)	
	#define DRIVE_COMPLETED				0	
	#define DRIVE_ABORTED					1
	#define DRIVE_PAUSED					2
	#define DRIVE_INTERRUPTED			3

	
	class defODriveAlgorithms{
		
		protected:
			defOMotorsList *motors;
			defOParamList *phyCoord;
			defOParamList *baseCoord;
			map<char,int> phyStartPoint;
			map<char,int> phyEndPoint;
			map<char,int> phyIndirectPoint;
			map<char,int> phyVector;
		
		public:
			int driveStatus;
		
		
		defODriveAlgorithms(defOMotorsList *mot, defOParamList *pCoord, defOParamList *bCoord);
		
		
			void setParToDriveForValue(map<char, int> values);
			void setParToDriveToBaseCoordinates(map<char, int> values);		
		
			virtual int drive(void)=0;
		
		
			static unsigned int getFrequencykResponsibleForDriveSpeed(unsigned int nrOfStepsFromStart, unsigned int nrOfStepsToEnd, int accelerationMMperSEC2, int velocityUMperSEC, unsigned int stepPM);
			static unsigned int getClockDividerResponsibleForDriveSpeed(unsigned int nrOfStepsFromStart, unsigned int nrOfStepsToEnd, int accelerationMMperSEC2, int velocityUMperSEC, unsigned int frequencyOfClock, unsigned int stepPM);
			static unsigned int getFrequencyOfDriveInUniformMovement(int velocityUMperSEC, unsigned int stepPM);
			static unsigned int getClockDividerInUniformMovement(int velocityUMperSEC, unsigned int frequencyOfClock, unsigned int stepPM);
			static unsigned int getClockDividerInUniformMovementWithSecurity(int velocityUMperSEC, int defValue, unsigned int frequencyOfClock, unsigned int stepPM);
			static unsigned int calculateAccelerateNumberOfSteps(int accelerationMMperSEC2, int velocityUMperSEC, unsigned int stepPM);
		
		

	};



#endif
