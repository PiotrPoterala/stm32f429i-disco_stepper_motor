/**	
 * |----------------------------------------------------------------------
 * | Copyright (C) Piotr Poterała, 2021
 * | 
 * | This program is free software: you can redistribute it and/or modify
 * | it under the terms of the GNU General Public License as published by
 * | the Free Software Foundation, either version 3 of the License, or
 * | any later version.
 * |  
 * | This program is distributed in the hope that it will be useful,
 * | but WITHOUT ANY WARRANTY; without even the implied warranty of
 * | MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * | GNU General Public License for more details.
 * | 
 * | You should have received a copy of the GNU General Public License
 * | along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * |----------------------------------------------------------------------
 */

#include "stm32f_it.h"

#include "def_pins.h"



void motorXClearClockSignal(void *arg){
	extern uPin motorXclockPin;

	PIN_CLR(motorXclockPin.port, (1<<motorXclockPin.pin));

}

void motorXChangeSelectCurrentSignal(void *arg){
	extern uPin motorXselectCurrentPin;

	int state=(int)arg;
	if(!state)PIN_CLR(motorXselectCurrentPin.port, (1<<motorXselectCurrentPin.pin));
	else PIN_SET(motorXselectCurrentPin.port, (1<<motorXselectCurrentPin.pin));

}


