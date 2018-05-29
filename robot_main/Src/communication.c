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
void c_msgReceivedCallback(){
	uint8_t Data[50]; // Tablica przechowujaca wysylana wiadomosc.
	uint16_t size = 0; // Rozmiar wysylanej wiadomosci

	t_append_task(received);

//	HAL_UART_Transmit_IT(&huart2, Data, size); // Rozpoczecie nadawania danych z wykorzystaniem przerwan
	//HAL_UART_Transmit_IT(&huart2, received, ORDER_LENGTH); // Rozpoczecie nadawania danych z wykorzystaniem przerwan
	HAL_UART_Receive_IT(&huart2, received, ORDER_LENGTH); // Ponowne włšczenie nasłuchiwania
}

