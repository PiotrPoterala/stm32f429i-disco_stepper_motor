#ifndef _RTX5_AT_COMMAND_INTERPRETER_H
	#define _RTX5_AT_COMMAND_INTERPRETER_H
	
	#include "pp_command.h"
	#include "pp_rtos_uart_queue_decorator.h"
	#include "pp_rtx5_queue.h"
	#include "pp_paramlist.h"
	
	#include <string>
	
	
		#define qMARK_TAG	(1<<28)
	#define qMARK_KEY	(2<<28)
	#define qMARK_ATC	(3<<28)
	
	using namespace std;

class defORTX5atCommandInterpreter: public defOUartQueuesDecorator{
		
	private:
		defORTX5TaskQueues* taskCommunicationQueues;
		defOParamList *phyCoord;
		defOParamList *baseCoord;
		
	public:
		defORTX5atCommandInterpreter(defOUartQueues* uQueues, defORTX5TaskQueues* commQueues, defOParamList *pCoord, defOParamList *bCoord):
																defOUartQueuesDecorator(uQueues), taskCommunicationQueues(commQueues), phyCoord(pCoord), baseCoord(bCoord){};
		virtual void getStringFromReceiveQueue();
	//	int interpret(string message);

	};


#endif
