#include "pp_rtx5_at_commands_interpreter.h"
#include "pstring.h"
#include "at_tags.h"

int defORTX5atCommandInterpreter::interpret(string message){
	
	PString data(message);
	int index=0;
	
	
	 if(data.find("AT+TRVV")!=string::npos){
			map<char, double> values;
			vector<int> valuesToSend;
			index=data.find("AT+TRVV");
			data.erase(0, index+7);
			values=data.findValuesAfterAcronims();
		 
			if(!values.empty()){
				valuesToSend.push_back(AT_TAG_TRVV | qMARK_ATC);
				valuesToSend.push_back(values.size());
				
				for(map<char, double>::iterator it=values.begin(); it!=values.end(); ++it){
					valuesToSend.push_back((*it).first);
					valuesToSend.push_back((*it).second);
				}
				
				
				
				taskCommunicationQueues->xQueueSendConteinerToBackWithSemaphore(valuesToSend);
				return AT_OK;
			}
			return AT_FAIL;
	 }else if(data.find("AT+TRVCO")!=string::npos){
			map<char, double> values;
			vector<int> valuesToSend;
			index=data.find("AT+TRVCO");
			data.erase(0, index+8);
			values=data.findValuesAfterAcronims();
		 
			if(!values.empty()){
				valuesToSend.push_back(AT_TAG_TRVCO | qMARK_ATC);
				valuesToSend.push_back(values.size());
				
				for(map<char, double>::iterator it=values.begin(); it!=values.end(); ++it){
					valuesToSend.push_back((*it).first);
					valuesToSend.push_back((*it).second);
				}
				
				
				
				taskCommunicationQueues->xQueueSendConteinerToBackWithSemaphore(valuesToSend);
				return AT_OK;
			}
			return AT_FAIL;
	 }else if(data.find("AT+BASEC")!=string::npos){
			index=data.find("AT+BASEC");
			if(data.at(index+8)=='?'){	
				
				            for (int i=0; i < auxCoord->getParams()->size(); ++i) {
                sendBuffer+=" ";
                sendBuffer+=auxCoord->getParams()->at(i)->getAcronim();
                sendBuffer+=QByteArray::number(auxCoord->getParams()->at(i)->getValue());
            }
				sprintf(transmitParam->buforTx, "BASEC X%i Y%i Z%i U%i V%i z%i\r\n", 
														(int32_t)(oCoordinates->baseCoord.X.value*pow(10, 3-oCoordinates->baseCoord.X.unit)), 
														(int32_t)(oCoordinates->baseCoord.Y.value*pow(10, 3-oCoordinates->baseCoord.Y.unit)),
														(int32_t)(oCoordinates->baseCoord.Z.value*pow(10, 3-oCoordinates->baseCoord.Z.unit)), 
														(int32_t)(oCoordinates->baseCoord.U.value*pow(10, 3-oCoordinates->baseCoord.U.unit)), 
														(int32_t)(oCoordinates->baseCoord.V.value*pow(10, 3-oCoordinates->baseCoord.V.unit)), 
														(int32_t)(oCoordinates->baseCoord.Zw.value*pow(10, 3-oCoordinates->baseCoord.Zw.unit)));
				sendResponseUART(transmitParam->UARTx, 1, (char *)transmitParam->buforTx, qUartSend);
			}else{		
				data.erase(0, index+8);
				baseCoord->getParamsFromString(&data);
				return AT_OK;
				
			}
		}
               
}