#include "pp_rtx5_at_commands_interpreter.h"
#include "pstring.h"


int defORTX5atCommandInterpreter::interpret(string message){
	
	PString data(message);
	int index=0;
	
	
	 if(data.find("AT+TRVV")!=string::npos){
			map<char, double> values;
	//		map<char, double>::iterator values_it;
			index=data.find("AT+TRVV");
			data.erase(0, index+7);
			values=data.findValuesAfterAcronims();
		 
	//		values_it=values.begin();
			if(!values.empty()){
				
				return AT_OK;
			}
			return AT_FAIL;
	 }
               
	
//	if(!strncmp((char *)transmitParam->buforRx, "AT+TRVCO", 8)){

//					if(oDrive->drivePathParam.activeDrivePath==ACTIVE_DRIVE){
//						sendResponseUART(transmitParam->UARTx, (transmitParam->atSetups & nATQ), "AUT_DRV\r\n", qUartSend);	
//					}else{
//						SCoordinates aCoord;
//						SParam* coord;
//						oCoordinates->setCoord(&aCoord, oCoordinates->getCoordWithSemaphore(&oCoordinates->baseCoord, oCoordinates->xBaseCoord));
//						
//						coord=&aCoord.X;
//						for(uint32_t i=0;i<LICZBA_OSI;i++){
//							coord->value*=pow(10, 3-coord->unit);
//							coord++;
//						}
//						
//						if(findCoordinates(&aCoord, &transmitParam->buforRx[7], BUFOR_RX-7, 0)){
//							uint32_t auxTag[7];
//							
//							coord=&aCoord.X;
//							for(uint32_t i=0;i<LICZBA_OSI;i++){
//								coord->value*=pow(10, coord->unit-3);
//								coord++;
//							}
//							oCoordinates->checkCorrectnesCoordinates(&aCoord);
//							
//							auxTag[0]=AT_TAG_TRVCO | qMARK_ATC;
//							auxTag[1]=aCoord.X.value;
//							auxTag[2]=aCoord.Y.value;
//							auxTag[3]=aCoord.Z.value;
//							auxTag[4]=aCoord.U.value;
//							auxTag[5]=aCoord.V.value;
//							auxTag[6]=aCoord.Zw.value;
//							xQueueSendTabToBackWithSemaphore(auxTag, 7, qToDoMark, xToDoMark);
//							
//							sendResponseUART(transmitParam->UARTx, (transmitParam->atSetups & nATQ), "OK\r\n", qUartSend);	
//						}else{
//							sendResponseUART(transmitParam->UARTx, (transmitParam->atSetups & nATQ), "FAIL\r\n", qUartSend);	
//						}
//					}
//				}else if(!strncmp((char *)transmitParam->buforRx, "AT+TRVV", 7)){

//					if(oDrive->drivePathParam.activeDrivePath==ACTIVE_DRIVE){
//						sendResponseUART(transmitParam->UARTx, (transmitParam->atSetups & nATQ), "AUT_DRV\r\n", qUartSend);	
//					}else{ 
//						SCoordinates aCoord;
//						oCoordinates->setCoord(&aCoord, oCoordinates->getCoordWithSemaphore(&oCoordinates->baseCoord, oCoordinates->xBaseCoord));
//						oCoordinates->clearCoord(&aCoord);
//						
//						if(findCoordinates(&aCoord, &transmitParam->buforRx[7], BUFOR_RX-7, 0)){
//							uint32_t auxTag[7];
//							
//							SParam* coord=&aCoord.X;
//							for(uint32_t i=0;i<LICZBA_OSI;i++){
//								coord->value*=pow(10, coord->unit-3);
//								coord++;
//							}
//							oCoordinates->checkCorrectnesCoordinates(&aCoord);
//							
//							auxTag[0]=AT_TAG_TRVV | qMARK_ATC;
//							auxTag[1]=aCoord.X.value;
//							auxTag[2]=aCoord.Y.value;
//							auxTag[3]=aCoord.Z.value;
//							auxTag[4]=aCoord.U.value;
//							auxTag[5]=aCoord.V.value;
//							auxTag[6]=aCoord.Zw.value;
//							xQueueSendTabToBackWithSemaphore(auxTag, 7, qToDoMark, xToDoMark);

//							sendResponseUART(transmitParam->UARTx, (transmitParam->atSetups & nATQ), "OK\r\n", qUartSend);	
//						}else{
//							sendResponseUART(transmitParam->UARTx, (transmitParam->atSetups & nATQ), "FAIL\r\n", qUartSend);	
//						}
//					}
//				}
	
}