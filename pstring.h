#ifndef PSTRING_H
#define PSTRING_H

#include <string>
#include <vector>
#include "stm32l4xx.h"

	#define  ZNAK_PLUS 		124
	#define  ZNAK_MINUS 	125
	#define  KROPKA 			126
	#define  SIGN_NULL 		255

using namespace std;

class PString: public string
{
public:
		PString();
		PString(const string &s);
    PString(const char* str);
    PString(string &str);

		double toDouble(bool *ok=NULL);
		uint32_t toInt(bool *ok=NULL);
    double findValueAfterAcronim(char acronim, int defValue, int precision);
    vector<string> split(char sep);
		vector<string> splitWithClamps(char sep, char clamps);
		
		static uint32_t charToInt(char sign);
};

#endif // PSTRING_H
