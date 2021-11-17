#ifndef _RTX5_AT_COMMAND_INTERPRETER_H
	#define _RTX5_AT_COMMAND_INTERPRETER_H
	
//	#include "pp_command.h"
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
		defORTX5TaskQueues<int>* taskCommunicationQueues;
		defOParamList *phyCoord;
		defOParamList *baseCoord;
		
	public:
		defORTX5atCommandInterpreter(defOUartQueues* uQueues, defORTX5TaskQueues<int>* commQueues, defOParamList *pCoord, defOParamList *bCoord);
		virtual void getStringFromReceiveQueue() override;
	
	
//		virtual void putStringToSendQueueAndStartSend(string &data) override {uartQueues->putStringToSendQueueAndStartSend(data);};
//		virtual int sendSignFromSendQueue() override {return uartQueues->sendSignFromSendQueue();};
//		virtual void receiveSignAndWriteToReceiveQueue() override {uartQueues->receiveSignAndWriteToReceiveQueue();};
//		
//		virtual bool isReceiveString() override {return uartQueues->isReceiveString();};
//		virtual string getReceiveString() override {return uartQueues->getReceiveString();};
//		virtual void clearReceiveString() override {uartQueues->clearReceiveString();};
	
//			virtual void putStringToSendQueueAndStartSend(string &data){defOUartQueuesDecorator::putStringToSendQueueAndStartSend(data);};
//			virtual int sendSignFromSendQueue(){return defOUartQueuesDecorator::sendSignFromSendQueue();};
//			virtual void receiveSignAndWriteToReceiveQueue(){defOUartQueuesDecorator::receiveSignAndWriteToReceiveQueue();};
//			virtual void getStringFromReceiveQueue();
//			
//			virtual bool isReceiveString(){return defOUartQueuesDecorator::isReceiveString();};
//			virtual string getReceiveString(){return defOUartQueuesDecorator::getReceiveString();};
//			virtual void clearReceiveString(){defOUartQueuesDecorator::clearReceiveString();};

	};


#endif
