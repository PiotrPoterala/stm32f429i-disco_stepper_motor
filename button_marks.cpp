#include "button_marks.h"

defOButtonMarks::defOButtonMarks(){

	tag=0;
	key=0;
	atc=0;
	atc_par=0;

}


void defOButtonMarks::decodeToDoMark(unsigned int mark){
			tag=0; 
			key=0;
			atc=0;
			atc_par=0;

			switch(mark & ~qMARK_MASK){
				case qMARK_TAG:
					tag=mark & qMARK_MASK;
					break;
				case qMARK_KEY:
					key=mark & qMARK_MASK;
					break;
				case qMARK_ATC:
					atc=mark & qMARK_MASK;
					break;
				case qMARK_ATC_PAR:
					atc_par=mark & qMARK_MASK;
					break;
			}
}

