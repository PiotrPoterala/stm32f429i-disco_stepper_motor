#ifndef _PP_PARAM_GENERAL_H
#define _PP_PARAM_GENERAL_H
#include <string>

#include "stm32xx.h"

using namespace std;

class defOParamGeneral
{

public:
    defOParamGeneral(){};
		virtual ~defOParamGeneral(){};
    virtual string getName(void)=0;
    virtual int getValue(void)=0;
    virtual int getLowerLimit(void)=0;
    virtual int getUpperLimit(void)=0;
    virtual int getPrecision(void)=0;
    virtual int getUnit(void)=0;
    virtual int getDefaultValue(void)=0;

    virtual int checkRange(int val)=0;

    virtual void setValue(int newValue)=0;
    virtual void resetValue(void)=0;

		virtual void checkCorrectnes()=0;
		virtual void checkRange()=0;

		virtual bool decrementValue()=0;
		virtual bool decrementValue(int val)=0;
		virtual bool incrementValue()=0;
		virtual bool incrementValue(int val)=0;
		
		static int checkRange(int val, int upperLim, int lowerLim){

				if(val>=upperLim)val=upperLim;
				else if(val<=lowerLim)val=lowerLim;

				return val;
		}

};


#endif 