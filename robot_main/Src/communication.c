/*! \file
 * \brief Communication source code.
 */

#include "communication.h"

void c_communicationInit(){
	HAL_UART_Receive_IT(&huart2, received, ORDER_LENGTH); // Ponowne włšczenie nasłuchiwania
}

void c_sendCallback(int msg){
	uint8_t pdata;
	pdata=msg;

	HAL_UART_Transmit_IT(&huart2,pdata,ORDER_LENGTH);
}

void c_sendRobotState(){
	uint8_t Data[50];
	int sign_flag=2;
	uint16_t size = 0;

	float f0,f1,f2;


	f0=motion_nodes[0].actual_position;
	f1=motion_nodes[1].actual_position;
	f2=motion_nodes[2].actual_position;

	if(f0<0){
		f0=-f0;
		sign_flag+=1;
	}
	if(f1<0){
		f1=-f1;
		sign_flag+=2;
	}
	if(f2<0){
		f2=-f2;
		sign_flag+=4;
	}

	size=sprintf(Data,"%1.2f %1.2f %1.2f %i \n",f0,f1,f2,sign_flag);
//	size=sprintf(Data,"RobotState \n");
	HAL_UART_Transmit_IT(&huart2, Data, size); // Rozpoczecie nadawania danych z wykorzystaniem przerwan

}

void c_msgReceivedCallback(){

	t_append_task(received);

	HAL_UART_Receive_IT(&huart2, received, ORDER_LENGTH); // Ponowne włšczenie nasłuchiwania
}

