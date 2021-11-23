#include "pp_rtx5_at_commands_interpreter.h"
#include "pstring.h"
#include "at_tags.h"

defORTX5atCommandInterpreter::defORTX5atCommandInterpreter(defOUartQueues* uQueues, defORTX5TaskQueues<int>* commQueues, defOParamList *pCoord, defOParamList *bCoord):
																defOUartQueuesDecorator(uQueues), taskCommunicationQueues(commQueues), phyCoord(pCoord), baseCoord(bCoord){

};


void defORTX5atCommandInterpreter::getStringFromReceiveQueue(){
	
	
	defOUartQueuesDecorator::getStringFromReceiveQueue();
	if(defOUartQueuesDecorator::isReceiveString()){
	
		PString data(defOUartQueuesDecorator::getReceiveString());
		string answer="FAIL\r\n";
		int index=0;
		
		 if(data.find("AT+TRVV")!=string::npos){
				map<char, double> values;
				vector<int> valuesToSend;
				index=data.find("AT+TRVV");
				data.erase(0, index+7);
				values=data.findValuesAfterAcronims();
			 
				if(!values.empty()){
					valuesToSend.push_back(qMARK_ATC);
					valuesToSend.push_back(AT_TAG_TRVV);
					valuesToSend.push_back(values.size());
					
					for(auto it=values.begin(); it!=values.end(); ++it){
						valuesToSend.push_back((*it).first);
						valuesToSend.push_back((*it).second*pow(10.0, phyCoord->getParamUnit((*it).first)));
					}
					
					
					taskCommunicationQueues->xQueueSendConteinerToBackWithSemaphore(valuesToSend);
					answer="OK\r\n";
				};
		 }else if(data.find("AT+TRVCO")!=string::npos){
				map<char, double> values;
				vector<int> valuesToSend;
				index=data.find("AT+TRVCO");
				data.erase(0, index+8);
				values=data.findValuesAfterAcronims();
			 
				if(!values.empty()){
					valuesToSend.push_back(qMARK_ATC);
					valuesToSend.push_back(AT_TAG_TRVCO);
					valuesToSend.push_back(values.size());
					
					for(auto it=values.begin(); it!=values.end(); ++it){
						valuesToSend.push_back((*it).first);
						valuesToSend.push_back((*it).second*pow(10.0, phyCoord->getParamUnit((*it).first)));
					}
					
					
					
					taskCommunicationQueues->xQueueSendConteinerToBackWithSemaphore(valuesToSend);
					answer="OK\r\n";
				};
		 }else if(data.find("AT+BASEC")!=string::npos){
				index=data.find("AT+BASEC");
				if(data.at(index+8)=='?'){	
					answer="BASEC ";
					answer+=baseCoord->getStringWithParams();
					answer+="\r\n";
				}else{		
					data.erase(0, index+8);
					baseCoord->setParamsBasedString(&data);
					answer="OK\r\n";
				}
			}else if(data.find("AT+PHYC")!=string::npos){
				index=data.find("AT+PHYC");
				if(data.at(index+7)=='?'){	
					answer="PHYC ";
					answer+=phyCoord->getStringWithParams();
					answer+="\r\n";
				}else{		
					data.erase(0, index+8);
					phyCoord->setParamsBasedString(&data);
					answer="OK\r\n";
				}
			}
		 
			defOUartQueuesDecorator::putStringToSendQueueAndStartSend(answer);
			defOUartQueuesDecorator::clearReceiveString();
		}
               
}