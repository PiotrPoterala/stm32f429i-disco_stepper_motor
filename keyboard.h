#ifndef _KEYBOARD_H
	#define _KEYBOARD_H

	#include "stm32l4xx.h"
	#include "keys.h"
	#include "input_signals.h"
	#include "input_signals_analysis.h"

//flagi klawiatury


//	typedef struct{
//		void (*decrementDataAndScroll)(int32_t*, uint8_t, uint8_t);
//		void (*incrementDataAndScroll)(int32_t*, uint8_t, uint8_t);

//		void (*scrollSettings)(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, int32_t*, int32_t*);
//		void (*scrollList)(uint32_t, uint32_t, int32_t*);
//		void (*scrollHorizontalList)(uint32_t, uint32_t, int32_t*);
//		void (*scrollTable)(uint32_t, uint32_t, uint32_t, int32_t*, int32_t*);
//		void (*scrollPage)(uint32_t, uint32_t, int32_t*);
//	}defOJoystick;


	#define  SIGN_NULL 		255


	class defOKeyboard{

		private:
			unsigned int logicalStateDetected;
			unsigned int checkingLine; 
			unsigned int checkingButton;
			unsigned int step;

		public:
			defOKeyboard(GPIO_TypeDef* uCport, uint32_t logStateDetected);	
		
			GPIO_TypeDef* port;
		  unsigned int KBR;		//Keyboard Register
			unsigned int KBPFR;	//Keyboard Period Flag Register; flagi ustawiane na czas trwania stanu wysokiego na wejściu
		
			unsigned int readARP();
			void setKBR(uint8_t nr_klaw);
			void readKeyboard();
		
		
		
	};



//	void OJoystickConstruct(defOJoystick *oJoystick);

//	void scrollSettings(uint32_t KBR, uint32_t upperLimitY, uint32_t upperLimitX, uint32_t lowerLimitY, uint32_t lowerLimitX, int32_t *highlightedY, int32_t *highlightedX);
//	void scrollList(uint32_t KBR, uint32_t nrOfElemY, int32_t *highlightedY);
//	void scrollHorizontalList(uint32_t KBR, uint32_t nrOfElemX, int32_t *highlightedX);
//	void scrollTable(uint32_t KBR, uint32_t nrOfElemY, uint32_t nrOfElemX, int32_t *highlightedY, int32_t *highlightedX);
//	void scrollPage(uint32_t KBR, uint32_t nrOfPage, int32_t *page);
//	void scrollPageByKeyboard(uint32_t KBR, uint32_t nrOfPage, int32_t *page);

#endif
