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
