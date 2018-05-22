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
#include "msg_defs.h"

uint8_t received[ORDER_LENGTH];

int order_num;

void c_communicationInit();

void c_sendCallback(int msg);
void c_msgReceivedCallback();

#endif /* COMMUNICATION_H_ */
