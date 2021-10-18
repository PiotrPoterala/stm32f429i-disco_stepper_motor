#ifndef _BACKUP_H
	#define _BACKUP_H


	#define PHY_COORD_X_BKP 							(RTC->BKP0R & 0x3FFFFFFF)
	#define PHY_COORD_X_BKPwrite(data) 	(RTC->BKP0R=(RTC->BKP0R & 0xC0000000) | (data & 0x3FFFFFFF))
	#define MKROK_X_BKP 									((RTC->BKP0R>>30) & 0x03)
	#define MKROK_X_BKPwrite(data) 				(RTC->BKP0R=(RTC->BKP0R & 0x3FFFFFFF) | ((data & 0x03)<<30))
	
	#define PHY_COORD_Y_BKP 								(RTC->BKP1R & 0x3FFFFFFF)
	#define PHY_COORD_Y_BKPwrite(data) 		(RTC->BKP1R=(RTC->BKP1R & 0xC0000000) | (data & 0x3FFFFFFF))
	#define MKROK_Y_BKP 									((RTC->BKP1R>>30) & 0x03)
	#define MKROK_Y_BKPwrite(data) 				(RTC->BKP1R=(RTC->BKP1R & 0x3FFFFFFF) | ((data & 0x03)<<30))
	
	#define PHY_COORD_Z_BKP 								(RTC->BKP2R & 0x3FFFFFFF)
	#define PHY_COORD_Z_BKPwrite(data) 		(RTC->BKP2R=(RTC->BKP2R & 0xC0000000) | (data & 0x3FFFFFFF))
	#define MKROK_Z_BKP 									((RTC->BKP2R>>30) & 0x03)
	#define MKROK_Z_BKPwrite(data) 				(RTC->BKP2R=(RTC->BKP2R & 0x3FFFFFFF) | ((data & 0x03)<<30))
	
	#define PHY_COORD_U_BKP 								(RTC->BKP3R & 0x3FFFFFFF)
	#define PHY_COORD_U_BKPwrite(data) 		(RTC->BKP3R=(RTC->BKP3R & 0xC0000000) | (data & 0x3FFFFFFF))
	#define MKROK_U_BKP 									((RTC->BKP3R>>30) & 0x03)
	#define MKROK_U_BKPwrite(data) 				(RTC->BKP3R=(RTC->BKP3R & 0x3FFFFFFF) | ((data & 0x03)<<30))

	#define PHY_COORD_V_BKP 								(RTC->BKP4R & 0x3FFFFFFF)
	#define PHY_COORD_V_BKPwrite(data) 		(RTC->BKP4R=(RTC->BKP4R & 0xC0000000) | (data & 0x3FFFFFFF))
	#define MKROK_V_BKP 									((RTC->BKP4R>>30) & 0x03)
	#define MKROK_V_BKPwrite(data) 				(RTC->BKP4R=(RTC->BKP4R & 0x3FFFFFFF) | ((data & 0x03)<<30))

	#define PHY_COORD_ZW_BKP 								(RTC->BKP5R & 0x3FFFFFFF)
	#define PHY_COORD_ZW_BKPwrite(data) 		(RTC->BKP5R=(RTC->BKP5R & 0xC0000000) | (data & 0x3FFFFFFF))
	#define MKROK_ZW_BKP 									((RTC->BKP5R>>30) & 0x03)
	#define MKROK_ZW_BKPwrite(data) 				(RTC->BKP5R=(RTC->BKP5R & 0x3FFFFFFF) | ((data & 0x03)<<30))


	#define BASE_COORD_X_BKP 							RTC->BKP6R
	#define BASE_COORD_X_BKPwrite(data) 		(RTC->BKP6R=data)
	#define BASE_COORD_Y_BKP 							RTC->BKP7R 
	#define BASE_COORD_Y_BKPwrite(data) 		(RTC->BKP7R=data)
	#define BASE_COORD_Z_BKP 							RTC->BKP8R 
	#define BASE_COORD_Z_BKPwrite(data) 		(RTC->BKP8R=data)
	#define BASE_COORD_U_BKP 							RTC->BKP9R 
	#define BASE_COORD_U_BKPwrite(data) 		(RTC->BKP9R=data)
	#define BASE_COORD_V_BKP 							RTC->BKP10R
	#define BASE_COORD_V_BKPwrite(data) 		(RTC->BKP10R=data)
	#define BASE_COORD_ZW_BKP 							(RTC->BKP11R)
	#define BASE_COORD_ZW_BKPwrite(data) 	(RTC->BKP11R=data)

	#define MENU_BKP  											(RTC->BKP12R)
	#define MENU_BKPwrite(data) 						(RTC->BKP12R=data)
	
	#define EXEC_SEGMEN_BKP 								RTC->BKP13R
	#define EXEC_SEGMEN_BKPwrite(data) 			(RTC->BKP13R=data)
	
	#define TIME_START_BKP										RTC->BKP14R
	#define TIME_START_BKPwrite(data) 				(RTC->BKP14R=data)
		
	#define OVERALL_WORKING_TIME_BKP						RTC->BKP15R
	#define OVERALL_WORKING_TIME_BKPwrite(data)	(OVERALL_WORKING_TIME_BKP=data)

	#define SELECTED_PROG_BKP			 				(RTC->BKP16R & 0xFF)
	#define SELECTED_PROG_BKPwrite(data) 	(RTC->BKP16R=(RTC->BKP16R & 0xFFFFFF00) | (data & 0xFF))
	#define SELECTED_CONTATCT_BKP			 				((RTC->BKP16R>>8) & 0xFF)
	#define SELECTED_CONTATCT_BKPwrite(data) 	(RTC->BKP16R=(RTC->BKP16R & 0xFFFF00FF) | ((data & 0xFF)<<8))
	#define EQUIPMENT_BKP 								((RTC->BKP16R>>16) & 0x0F)
	#define EQUIPMENT_BKPwrite(data) 			(RTC->BKP16R=(RTC->BKP16R & 0xFFF0FFFF) | ((data & 0x0F)<<16))
	#define LANGUAGE_BKP		 							((RTC->BKP16R>>20) & 0x0F)
	#define LANGUAGE_BKPwrite(data) 			(RTC->BKP16R=(RTC->BKP16R & 0xFF0FFFFF) | ((data & 0x0F)<<20))
	#define FAT_VOLUME_BKP		 						((RTC->BKP16R>>24) & 0x0F)
	#define FAT_VOLUME_BKPwrite(data) 		(RTC->BKP16R=(RTC->BKP16R & 0xF0FFFFFF) | ((data & 0x0F)<<24))
	#define TYPE_PROG_BKP		 							((RTC->BKP16R>>28) & 0x0F)
	#define TYPE_PROG_BKPwrite(data) 			(RTC->BKP16R=(RTC->BKP16R & 0x0FFFFFFF) | ((data & 0x0F)<<28))

	#define FEATURES_BKP 											(RTC->BKP17R & 0xFF)
	#define FEATURES_BKPwrite(data) 					(RTC->BKP17R=(RTC->BKP17R & 0xFFFFFF00) | (data & 0xFF))
	#define GSM_FEATURES_BKP 									((RTC->BKP17R>>8) & 0x0F)
	#define GSM_FEATURES_BKPwrite(data) 			(RTC->BKP17R=(RTC->BKP7R & 0xFFFFF0FF) | ((data & 0x0F)<<8))
	#define AT_WIFI_SETUP_BKP 								((RTC->BKP17R>>12) & 0x0F)
	#define AT_WIFI_SETUP_BKPwrite(data) 			(RTC->BKP17R=(RTC->BKP17R & 0xFFFF0FFF) | ((data & 0x0F)<<12))
	#define AT_USB_SETUP_BKP 									((RTC->BKP17R>>16) & 0x0F)
	#define AT_USB_SETUP_BKPwrite(data) 			(RTC->BKP17R=(RTC->BKP17R & 0xFFF0FFFF) | ((data & 0x0F)<<16))
	#define AUT_WORK_FEATURES_BKP 						((RTC->BKP17R>>20) & 0x0F)
	#define AUT_WORK_FEATURES_BKPwrite(data) 	(RTC->BKP17R=(RTC->BKP17R & 0xFF0FFFFF) | ((data & 0x0F)<<20))
	#define THRESH_OF_CIRCUIT_BKP		 					((RTC->BKP17R>>24) & 0xFF)
	#define THRESH_OF_CIRCUIT_BKPwrite(data) 	(RTC->BKP17R=(RTC->BKP17R & 0x00FFFFFF) | ((data & 0xFF)<<24))

	#define TIME_OF_BREAK_BKP								(RTC->BKP18R & 0x000FFFFF)
	#define TIME_OF_BREAK_BKPwrite(data) 		(RTC->BKP18R=(RTC->BKP18R & 0xFFF00000) | (data & 0x000FFFFF))
	#define WIRE_TENSION_BKP 								((RTC->BKP18R>>20) & 0x0F)
	#define WIRE_TENSION_BKPwrite(data) 		(RTC->BKP18R=(RTC->BKP18R & 0xFF0FFFFF) | ((data & 0x0F)<<20))
	#define THRESH_OF_WORK_BKP 							((RTC->BKP18R>>24)& 0xFF)
	#define THRESH_OF_WORK_BKPwrite(data) 	(RTC->BKP18R=(RTC->BKP18R & 0x00FFFFFF) | ((data & 0xFF)<<24))
	
	#define TIME_OF_IMPULSE_BKP 							(RTC->BKP19R & 0x000FFFFF)
	#define TIME_OF_IMPULSE_BKPwrite(data) 		(RTC->BKP19R=(RTC->BKP19R & 0xFFF00000) | (data & 0x000FFFFF))
	#define WIRE_FEED_BKP 										((RTC->BKP19R>>20) & 0x0F)
	#define WIRE_FEED_BKPwrite(data) 					(RTC->BKP19R=(RTC->BKP19R & 0xFF0FFFFF) | ((data & 0x0F)<<20))
	#define SELECTED_MATERIAL_BKP			 				((RTC->BKP19R>>24)& 0xFF)
	#define SELECTED_MATERIAL_BKPwrite(data) 	(RTC->BKP19R=(RTC->BKP19R & 0x00FFFFFF) | ((data & 0xFF)<<24))
	



#endif
