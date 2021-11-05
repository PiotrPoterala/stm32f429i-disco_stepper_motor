#ifndef _RTX5_AT_COMMAND_INTERPRETER_H
	#define _RTX5_AT_COMMAND_INTERPRETER_H
	
	#include "pp_command.h"
	#include "pp_rtx5_queue.h"
	
	#include <string>
	
	#define AT_OK	1
	#define AT_FAIL	2	
	
		#define qMARK_TAG	(1<<28)
	#define qMARK_KEY	(2<<28)
	#define qMARK_ATC	(3<<28)
	
	using namespace std;

class defORTX5atCommandInterpreter{
		
	private:
		defORTX5TaskQueues* taskCommunicationQueues;
	
	defOParamList *phyCoord;
	defOParamList *baseCoord;
		
	public:
		defORTX5atCommandInterpreter(){};
		int interpret(string message);

	};


#endif
