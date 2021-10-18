#include "clock.h"
#include <stdio.h>

defOClock::defOClock(){

    clearTime();
    clockActive=false;
}

defOClock::defOClock(int h, int m, int s){

    setTime(h, m, s);
    clockActive=false;
}

defOClock::defOClock(int s){

    setTime(s);
    clockActive=false;
}

void defOClock::setClockActive(bool active){

    clockActive=active;
}

void defOClock::setTime(int h, int m, int s){
    sec=s;
    min=m;
    hour=h;
}

void defOClock::setTime(int s){

    sec=s%60;
    min=(s/60)%60;
    hour=(s/3600)%24;

}


void defOClock::clearTime(){
    sec=0;
    min=0;
    hour=0;
}

void defOClock::addSec(){	//funkcja odmierzająca czas od chwili rozpoczęcia pracy automatycznej

        if(clockActive){
            sec++;
            if (sec==60){
                sec=0;
                min++;
                if (min == 60){
                    min=0;
                    hour++;
                    if (hour>=0x1FFFFFFF){
                        hour=0;
                    }
                }
            }

        }
}

int defOClock::toSec(){

    return (sec+(min*60)+(hour*3600));

}

string defOClock::toString(){
		char buff[64];
		sprintf(buff, "%04u:%02u:%02u", hour, min, sec);
    return string(buff);
}

string defOClock::toString(int sec){
		char buff[64];
		sprintf(buff, "%04u:%02u:%02u", (sec/3600)%24, (sec/60)%60, sec%60);
    return string(buff);
}

