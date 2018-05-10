/*
 * communication.h
 *
 *  Created on: 29.03.2018
 *      Author: mromanow
 */

#ifndef COMMUNICATION_H_
#define COMMUNICATION_H_

#include "stdint.h"
#include "usart.h"

#define LD2_GPIO_Port ENCODERS_SERIAL_CLOCK_GPIO_Port
#define LD2_Pin ENCODERS_SERIAL_CLOCK_Pin

#define LED_ON HAL_GPIO_WritePin(LD2_GPIO_Port,LD2_Pin,GPIO_PIN_SET)
#define LED_OFF HAL_GPIO_WritePin(LD2_GPIO_Port,LD2_Pin,GPIO_PIN_RESET)


#define MSG_LENGTH 1

uint8_t received;

void c_communicationInit();

void c_sendMsg(int msg);
void c_msgReceivedCallback();

#endif /* COMMUNICATION_H_ */
