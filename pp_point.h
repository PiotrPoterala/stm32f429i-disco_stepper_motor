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

#ifndef _PP_POINT_H
	#define _PP_POINT_H

	#include <map>
	
	#include "cmsis_os2.h"
	
	using namespace std;

template <typename T1, typename T2>
	class PPpoint{
		
		public:
		map<T1, T2> axes;	
		
		PPpoint(){};
	
			
		void operator=(PPpoint &point){

			axes=point.axes;

		};		
			
		
		bool operator==(map<T1, T2> point){
			if(axes.size()==point.size()){
				for(auto it=axes.begin(); it!=axes.end(); it++){
					auto it_to_comp=point.find((*it).first);
					if(it_to_comp!=point.end()){
						if((*it_to_comp).second!=(*it).second)return false;		
					}else return false;
					
				}
					
			}
			return true;
	};
		
		bool operator==(PPpoint &point){
			if(axes.size()==point.axes.size()){
				for(auto it=axes.begin(); it!=axes.end(); it++){
					auto it_to_comp=point.axes.find((*it).first);
					if(it_to_comp!=point.axes.end()){
						if((*it_to_comp).second!=(*it).second)return false;		
					}else return false;
					
				}
				
				
			}
			return true;

	}
};


//template <typename T1, typename T2>
//bool PPpoint<T1, T2>::operator==(PPpoint &point){
//	
//		if(this.size()==point.size()){
//			for(auto it=this.begin(); it!=this.end(); it++){
//				auto it_to_comp=point.find((*it).first);
//				if(it_to_comp!=point.end()){
//					if((*it_to_comp).second!=(*it).second)return false;		
//				}else return false;
//				
//			}
//			
//			
//		}
//		return true;

//}

#endif	
