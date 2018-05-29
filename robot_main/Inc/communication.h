/*! \file
 * \brief Communication with PC via UART
 */

#ifndef COMMUNICATION_H_
#define COMMUNICATION_H_

#include "stdint.h"
#include "usart.h"
#include "msg_defs.h"
#include "motion_control.h"


uint8_t received[ORDER_LENGTH]; /**< \brief Income message  array*/

//int order_num;

/*!
 * \details Initialization function. Sets all required variables that are related to the communication module.
 * \return Void
 */
void c_communicationInit();
/*!
 * \details Sends message to the PC.
 * \param msg Message
 * \return Void
 */
void c_sendCallback(int msg);
/*!
 * \details Executed when message from PC is received
 * \return Void
 */
void c_msgReceivedCallback();

#endif /* COMMUNICATION_H_ */
