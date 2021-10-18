#ifndef _AUT_WORK_PARAM_WEDM_H
	#define _AUT_WORK_PARAM_WEDM_H

	#define NR_OF_PARAM	9
	#define NR_OF_WIRE_WORK_PARAM			8

	#define threshOfWork_DEFAULT_VALUE				50
	#define threshOfCircuit_DEFAULT_VALUE			50
	#define timeOfImpulse_DEFAULT_VALUE				5000
	#define timeOfBreak_DEFAULT_VALUE 				160000
	#define nrOfImpulseInPack_DEFAULT_VALUE		2
	#define wireTension_DEFAULT_VALUE					3
	#define wireFeed_DEFAULT_VALUE						6
	#define nrOfWorkTransistors_DEFAULT_VALUE	9
	#define timeOfBreakBetImpulseInPack_DEFAULT_VALUE		10000

	#define BREAK_IN_PACK						10000	//nano sekundy [ns] 

	#define timeOfImpulseMAX				9000	//nano sekundy [ns] 
	#define timeOfImpulseMIN				1000
	#define timeOfBreakMAX					999000 //nano sekundy [ns] 
	#define timeOfBreakMIN					10000
	#define threshOfWorkMAX					90		
	#define threshOfWorkMIN					1
	#define threshOfCircuitMAX			90		
	#define threshOfCircuitMIN			1
	#define wireTensionMAX					3	
	#define wireTensionMIN					1
	#define wireFeedMAX							9	
	#define wireFeedMIN							1
	#define nrOfWorkTransistorsMAX	9
	#define nrOfWorkTransistorsMIN	1
	#define nrOfImpulseInPackMAX		9
	#define nrOfImpulseInPackMIN		1
	#define timeOfBreakBetImpulseInPackMAX		10000	//nano sekundy [ns] 
	#define timeOfBreakBetImpulseInPackMIN		1000

	#define timeOfImpulsePRECISION				125
	#define timeOfBreakPRECISION					1000
	#define threshOfWorkPRECISION				1
	#define threshOfCircuitPRECISION		1
	#define wireTensionPRECISION									1
	#define wireFeedPRECISION										1
	#define nrOfWorkTransistorsPRECISION					1
	#define nrOfImpulseInPackPRECISION						1
	#define timeOfBreakBetImpulseInPackPRECISION	1000

	#define FOCUSthreshOfWork				1
	#define FOCUSthreshOfCircuit		2
	#define FOCUStimeOfImpulse			3
	#define FOCUStimeOfBreak				4
	#define FOCUSnrOfWorkTransistors	5
	#define FOCUSnrOfImpulseInPack	6
	#define FOCUSwireFeed						7
	#define FOCUSwireTension				8


#endif
