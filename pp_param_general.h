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
    virtual string getName(void) noexcept=0;
    virtual int getValue(void) noexcept=0;
    virtual int getLowerLimit(void) noexcept=0;
    virtual int getUpperLimit(void) noexcept=0;
    virtual int getPrecision(void) noexcept=0;
    virtual int getUnit(void) noexcept=0;
    virtual int getDefaultValue(void) noexcept=0;

    virtual int checkRange(int val) noexcept=0;

    virtual void setValue(int newValue) noexcept=0;
    virtual void resetValue(void) noexcept=0;

		virtual void checkCorrectnes() noexcept=0;
		virtual void checkRange() noexcept=0;

		virtual bool decrementValue() noexcept=0;
		virtual bool decrementValue(int val) noexcept=0;
		virtual bool incrementValue() noexcept=0;
		virtual bool incrementValue(int val) noexcept=0;
		
		static int checkRange(int val, int upperLim, int lowerLim) noexcept{

				if(val>=upperLim)val=upperLim;
				else if(val<=lowerLim)val=lowerLim;

				return val;
		}

};


#endif 