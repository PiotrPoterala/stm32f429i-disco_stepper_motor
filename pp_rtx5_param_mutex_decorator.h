/**
 * @author  Piotr Poterała
 * @email   poterala.piotr@gmail.com
 * @website http://zappp.pl
 * @version v1.0
 * @ide     Keil uVision 5
 * @license GNU GPL v3
 *	
@verbatim
   ----------------------------------------------------------------------
    Copyright (C) Piotr Poterała, 2021
    
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    any later version.
     
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    
    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
   ----------------------------------------------------------------------
@endverbatim
 */

#ifndef _PP_PARAM_MUTEX_DECORATOR_H
#define _PP_PARAM_MUTEX_DECORATOR_H
#include <string>
#include "pp_param_general.h"

#include "stm32xx.h"

using namespace std;

class defORTX5ParamMutexDecorator : public defOParamGeneral
{

	private:
		defOParamGeneral* paramGeneral;
		osMutexId_t	mutex;
	
	public:
		defORTX5ParamMutexDecorator(defOParamGeneral* param):paramGeneral(param){
				mutex=osMutexNew(NULL);
		};
		
		virtual ~defORTX5ParamMutexDecorator(){
			osMutexDelete(mutex);
		};
		
    virtual string getName(void) override{return paramGeneral->getName();};
    virtual int getValue(void)override{return paramGeneral->getValue();};
    virtual int getLowerLimit(void)override{return paramGeneral->getLowerLimit();};
    virtual int getUpperLimit(void)override{return paramGeneral->getUpperLimit();};
    virtual int getPrecision(void)override{return paramGeneral->getPrecision();};
    virtual int getUnit(void)override{return paramGeneral->getUnit();};
    virtual int getDefaultValue(void)override{return paramGeneral->getDefaultValue();};

    virtual int checkRange(int val) override{return paramGeneral->checkRange(val);};

    virtual void setValue(int newValue) override{		
			if (osMutexAcquire(mutex, osWaitForever) == osOK) paramGeneral->setValue(newValue);
			osMutexRelease (mutex); 
		};
		
    virtual void resetValue(void) override{		
			if (osMutexAcquire(mutex, osWaitForever) == osOK) paramGeneral->resetValue();
			osMutexRelease (mutex); 
		};

		virtual void checkCorrectnes(void) override{		
			if (osMutexAcquire(mutex, osWaitForever) == osOK) paramGeneral->checkCorrectnes();
			osMutexRelease (mutex); 
		};
		virtual void checkRange(void) override{		
			if (osMutexAcquire(mutex, osWaitForever) == osOK) paramGeneral->checkRange();
			osMutexRelease (mutex); 
		};

		virtual bool decrementValue(void) override{		
			bool answer=false;
			if (osMutexAcquire(mutex, osWaitForever) == osOK) answer=paramGeneral->decrementValue();
			osMutexRelease (mutex); 
			return answer;
		};
		virtual bool decrementValue(int val) override{		
			bool answer=false;
			if (osMutexAcquire(mutex, osWaitForever) == osOK) answer=paramGeneral->decrementValue(val);
			osMutexRelease (mutex); 
			return answer;
		};
		virtual bool incrementValue(void) override{		
			bool answer=false;
			if (osMutexAcquire(mutex, osWaitForever) == osOK) answer=paramGeneral->incrementValue();
			osMutexRelease (mutex); 
			return answer;
		};
		virtual bool incrementValue(int val) override{	
			bool answer=false;
			if (osMutexAcquire(mutex, osWaitForever) == osOK) answer=paramGeneral->incrementValue(val);
			osMutexRelease (mutex); 
			return answer;
		};

};


#endif 