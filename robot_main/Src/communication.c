/*
 * communication.c
 *
 *  Created on: 29.03.2018
 *      Author: mromanow
 */

#include "communication.h"

void c_communicationInit(){
	HAL_UART_Receive_IT(&huart2, &received, 1); // Ponowne włšczenie nasłuchiwania
}

void c_sendMsg(int msg){
	uint8_t pdata;
	pdata=msg;

	HAL_UART_Transmit_IT(&huart2,pdata,1);
}
void c_msgReceivedCallback(){
	uint8_t Data[50]; // Tablica przechowujaca wysylana wiadomosc.
	uint16_t size = 0; // Rozmiar wysylanej wiadomosci
	float f1=3.141516;
	float f2=10.12343;
	// Odebrany znak zostaje przekonwertowany na liczbe calkowita i sprawdzony
	// instrukcja warunkowa
/*	switch (atoi(&received)) {
	case 0: // Jezeli odebrany zostanie znak 0
		size = sprintf(Data, "STOP\n\r");
		LED_OFF;
		break;

	case 1: // Jezeli odebrany zostanie znak 1
		size = sprintf(Data, "START\n\r");
		LED_ON;
		break;

	default: // Jezeli odebrano nieobslugiwany znak
		size = sprintf(Data, "Odebrano nieznany znak: %c\n\r", received);
		break;
	}*/
	// 	size=sprintf(Data,"%d",atoi(&received));

	size=sprintf(Data,"%1.3f",f1);
//	size=sprintf(Data,"%d",size);
	HAL_UART_Transmit_IT(&huart2, Data, size); // Rozpoczecie nadawania danych z wykorzystaniem przerwan
	HAL_UART_Receive_IT(&huart2, &received, 1); // Ponowne włšczenie nasłuchiwania
}

