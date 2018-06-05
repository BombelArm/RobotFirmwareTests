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
	uint16_t size = 0;


	size=sprintf(Data,"%1.2f\t%1.2f\t%1.2f\n",motion_nodes[0].actual_position,motion_nodes[1].actual_position,motion_nodes[2].actual_position);
	HAL_UART_Transmit_IT(&huart2, Data, size); // Rozpoczecie nadawania danych z wykorzystaniem przerwan

}

void c_msgReceivedCallback(){

	t_append_task(received);

	HAL_UART_Receive_IT(&huart2, received, ORDER_LENGTH); // Ponowne włšczenie nasłuchiwania
}

