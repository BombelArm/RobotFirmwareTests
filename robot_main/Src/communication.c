/*! \file
 * \brief Communication source code.
 */

#include "communication.h"

void c_communicationInit(){
	HAL_UART_Receive_IT(&huart2, received, ORDER_LENGTH);
}

void c_sendCallback(uint8_t msg){
	uint8_t Data[10];
	uint16_t size=0;

	size=sprintf(Data,"%d \n",msg);

	HAL_UART_Transmit_IT(&huart2,Data,size);
}

void c_sendRobotState(){
	uint8_t Data[30];
	uint16_t size = 0;
	int16_t f0,f1,f2;


	f0=motion_nodes[0].actual_position;
	f1=motion_nodes[1].actual_position;
	f2=motion_nodes[2].actual_position;

	size=sprintf(Data,"%d %d %d %d \n",RESP_ROBOT_STATE,f0,f1,f2);

	HAL_UART_Transmit_IT(&huart2, Data, size);

}

void c_msgReceivedCallback(){

	t_append_task(received);

	HAL_UART_Receive_IT(&huart2, received, ORDER_LENGTH); // Ponowne włšczenie nasłuchiwania
}

