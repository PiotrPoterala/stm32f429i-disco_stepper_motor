#include "keyboard.h"

defOKeyboard::defOKeyboard(GPIO_TypeDef* uCport, uint32_t logStateDetected):port(uCport), logicalStateDetected(logStateDetected){
	
	KBR=0;
	KBPFR=0;
	checkingLine=0;
	checkingButton=0;
	step=0;
	
}

unsigned int defOKeyboard::readARP(){

	if(KBR==KEY_P) return 'P';
	else if(KBR==KEY_R) return 'R';
	else if(KBR==KEY_A) return 'A';

	return 0;

}


void defOKeyboard::setKBR(uint8_t nr_klaw){

//uzupełnienie rejetrów klawiatury
			if(!KBPFR){
				if(nr_klaw!=SIGN_NULL)KBPFR=nr_klaw;		
			}else if(KBPFR){		//sprawdzenie czy wszystkie klawisze zostały zwolnione
				if(nr_klaw==SIGN_NULL){ //...jeśli tak, to znaczy że nasz uprzednio wciśnięty klawisz został spuszczony
					KBR=KBPFR;																	// innymi słowy wszystkie klawisze muszą być spuszczone by można było zainicjować akcję ukrytą pod danym klawiszem
					KBPFR=0; 
				}
			}
}



void defOKeyboard::readKeyboard(){
		//I etap: ustawienie sprawdzanego wiersza klawiatury
		//II etap: sprawdzenie klawiszy w danym wierszu
		//III etap: potwierdzenie wciśnięcia klawisza

		if((checkingButton>=1+(6*(checkingLine)) && checkingButton<=6+(6*(checkingLine))) || !(checkingButton)){
			switch(step){
				case 0:	port->ODR=(port->ODR & KLAW_WIERSZE) | (checkingLine);		//załączanie kolejnych wierszy
								break;
				case 1:	if(!checkingButton){
									if(KEY_SELECT(port->IDR, KLAW_KOLUMNA_1)==logicalStateDetected)checkingButton=1+(6*checkingLine); 
									if(KEY_SELECT(port->IDR, KLAW_KOLUMNA_2)==logicalStateDetected)checkingButton=2+(6*checkingLine); 
									if(KEY_SELECT(port->IDR, KLAW_KOLUMNA_3)==logicalStateDetected)checkingButton=3+(6*checkingLine);
									if(KEY_SELECT(port->IDR, KLAW_KOLUMNA_4)==logicalStateDetected)checkingButton=4+(6*checkingLine);
								}
								break;
				case 2:	if(KEY_SELECT(port->IDR, KLAW_KOLUMNA_1)==logicalStateDetected && checkingButton==1+(6*checkingLine)){setKBR(checkingButton); break;} 
								if(KEY_SELECT(port->IDR, KLAW_KOLUMNA_2)==logicalStateDetected && checkingButton==2+(6*checkingLine)){setKBR(checkingButton); break;} 
								if(KEY_SELECT(port->IDR, KLAW_KOLUMNA_3)==logicalStateDetected && checkingButton==3+(6*checkingLine)){setKBR(checkingButton); break;} 
								if(KEY_SELECT(port->IDR, KLAW_KOLUMNA_4)==logicalStateDetected && checkingButton==4+(6*checkingLine)){setKBR(checkingButton); break;} 
								setKBR(SIGN_NULL);
								checkingButton=0;
								break;
			}
		}

		if(++(step)>2){
			step=0;
			if(++(checkingLine)>7)checkingLine=0;
		}

	
}