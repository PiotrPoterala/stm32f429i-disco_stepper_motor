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

#ifndef _AT_TAGI_H
	#define _AT_TAGI_H

#define AT_TAG_EMPTY						0


#define AT_TAG_FILTR_ON 				1
#define AT_TAG_PUMP_ON					2
#define AT_TAG_DRILL_PUMP_ON 		3
#define AT_TAG_WIRE_ON 					4
#define AT_TAG_GENER_ON 				5
#define AT_TAG_DRILL_ON 				6
#define AT_TAG_SINTER_ON				7

#define AT_TAG_FILTR_OFF 				8
#define AT_TAG_PUMP_OFF 				9
#define AT_TAG_DRILL_PUMP_OFF  	10
#define AT_TAG_WIRE_OFF  				11
#define AT_TAG_GENER_OFF 				12
#define AT_TAG_DRILL_OFF  			13
#define AT_TAG_SINTER_OFF				14
#define AT_TAG_ALL_TOOLS_OFF		15

//AT tagi wysyłane do vMainTask
enum{
	AT_TAG_TRVCO=1,
	AT_TAG_TRVV,
	AT_TAG_TRVLS,
	AT_TAG_TRVCP,
	AT_TAG_WP,
	AT_TAG_TRVBP,
	AT_TAG_PHYC,
	AT_TAG_BASEC,
	AT_TAG_GBASE,
	AT_TAG_ALIGIN,
	AT_TAG_ALIGOUT,
	AT_TAG_MEASANG,
	AT_TAG_MPAR,
	AT_TAG_MEYES,
	AT_TAG_MRAN,
	AT_TAG_MCOR,
	AT_TAG_FEATON,
	AT_TAG_FEATOFF,
	AT_TAG_GMSCON,
	AT_TAG_GMSCOFF,
	AT_TAG_GSMPIN,
	AT_TAG_GSMAPN,
	AT_TAG_WIFIAP,
	AT_TAG_LANG,
	AT_TAG_AFUNON,
	AT_TAG_AFUNOFF,
	AT_TAG_CFLASH,
	AT_TAG_PROG,
	AT_TAG_GSMPN,
	AT_TAG_DBREG,
	AT_TAG_GBASE_SAVE,
	AT_TAG_SMEM
};

//AT tagi wysyłane do vDrivePathTask
enum{
	AT_TAG_AUT=1,
};

//AT tagi wysyłane do vDriveConditionalTask
enum{
AT_TAG_TRVM_OFF,
AT_TAG_Zm,
AT_TAG_XmYm,
AT_TAG_Ym,
AT_TAG_XpYm,
AT_TAG_Xm,
AT_TAG_Zp,
AT_TAG_Xp,
AT_TAG_XmYp,
AT_TAG_Yp,
AT_TAG_XpYp
};


#define AT_TAG_SEGBACK					251
#define AT_TAG_SEGNEXT					252
#define AT_TAG_STOP							253
#define AT_TAG_ABORT						254
#define AT_TAG_CONT							255

#endif

