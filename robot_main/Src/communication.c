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

	int16_t f0,f1,f2;


	f0=motion_nodes[0].actual_position;
	f1=motion_nodes[1].actual_position;
	f2=motion_nodes[2].actual_position;


//	HAL_UART_Transmit_IT(&huart2, &f0, 2);
	size=sprintf(Data,"%d %d %d \n",f0,f1,f2);
	HAL_UART_Transmit_IT(&huart2, Data, size);

}

void c_msgReceivedCallback(){

	t_append_task(received);

	HAL_UART_Receive_IT(&huart2, received, ORDER_LENGTH); // Ponowne włšczenie nasłuchiwania
}

