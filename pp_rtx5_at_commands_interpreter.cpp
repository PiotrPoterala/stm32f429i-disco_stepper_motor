#include "pp_rtx5_at_commands_interpreter.h"
#include "pstring.h"
#include "at_tags.h"

void defORTX5atCommandInterpreter::getStringFromReceiveQueue(){
	
	
	defOUartQueuesDecorator::getStringFromReceiveQueue();
	if(uartQueues->isReceiveString()){
	
		PString data(uartQueues->getReceiveString());
		string answer="FAIL";
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
					
					for(map<char, double>::iterator it=values.begin(); it!=values.end(); ++it){
						valuesToSend.push_back((*it).first);
						valuesToSend.push_back((*it).second);
					}
					
					
					taskCommunicationQueues->xQueueSendConteinerToBackWithSemaphore(valuesToSend);
					answer="OK";
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
					
					for(map<char, double>::iterator it=values.begin(); it!=values.end(); ++it){
						valuesToSend.push_back((*it).first);
						valuesToSend.push_back((*it).second);
					}
					
					
					
					taskCommunicationQueues->xQueueSendConteinerToBackWithSemaphore(valuesToSend);
					answer="OK";
				};
		 }else if(data.find("AT+BASEC")!=string::npos){
				index=data.find("AT+BASEC");
				if(data.at(index+8)=='?'){	
					answer="BASEC";
					for (map<char, defOParam*>::iterator i=baseCoord->getParams()->begin(); i!=baseCoord->getParams()->end(); ++i) {
							answer+=" ";
							answer+=(*i).first;  
							answer+=to_string((*i).second->getValue()); 
					}

				}else{		
					data.erase(0, index+8);
					baseCoord->getParamsFromString(&data);
					answer="OK";
				}
			}else if(data.find("AT+PHYC")!=string::npos){
				index=data.find("AT+PHYC");
				if(data.at(index+7)=='?'){	
					answer="PHYC";
					for (map<char, defOParam*>::iterator i=phyCoord->getParams()->begin(); i!=phyCoord->getParams()->end(); ++i) {
							answer+=" ";
							answer+=(*i).first;  
							answer+=to_string((*i).second->getValue()); 
					}

				}else{		
					data.erase(0, index+8);
					phyCoord->getParamsFromString(&data);
					answer="OK";
				}
			}
		 
			
			putStringToSendQueueAndStartSend(answer);
			uartQueues->clearReceiveString();
		}
               
}