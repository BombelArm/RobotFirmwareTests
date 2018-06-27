/*! 
 * \brief Communication with PC via UART
 * \addtogroup Communication
 *  @{
 * \file
 * \brief Communication with PC via UART
 */

#ifndef COMMUNICATION_H_
#define COMMUNICATION_H_

#include "stdint.h"
#include "usart.h"
#include "msg_defs.h"
#include "motion_control.h"


uint8_t received[ORDER_LENGTH]; /**< \brief Income message  array*/

int sendFlag;

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
void c_sendCallback(uint8_t msg);


void c_sendRobotState();
/*!
 * \details Executed when message from PC is received
 * \return Void
 */
void c_msgReceivedCallback();

#endif /* COMMUNICATION_H_ */
/** @}*/
