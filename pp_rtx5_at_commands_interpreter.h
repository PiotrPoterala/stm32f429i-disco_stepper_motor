#ifndef _RTX5_AT_COMMAND_INTERPRETER_H
	#define _RTX5_AT_COMMAND_INTERPRETER_H
	
	#include "pp_command.h"
	
	#include <string>
	
	#define AT_OK	1
	#define AT_FAIL	2	
	
	using namespace std;

class defORTX5atCommandInterpreter{
		
		
		public:
			defORTX5atCommandInterpreter(){};
			int interpret(string message);

	};


#endif
