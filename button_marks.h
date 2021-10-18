#ifndef _BUTTON_MARKS_H
	#define _BUTTON_MARKS_H


	#include "keys.h"
//	#include "tags.h"

	#define qMARK_MASK	0x0FFFFFFF
	
	#define qMARK_ATC_PAR	0
	#define qMARK_TAG	(1<<28)
	#define qMARK_KEY	(2<<28)
	#define qMARK_ATC	(3<<28)


	class defOButtonMarks{
		
		public:
		defOButtonMarks();
		unsigned int tag;
		unsigned int key;
		unsigned int atc;
		unsigned int atc_par;

		void decodeToDoMark(unsigned int mark);
	};




#endif

