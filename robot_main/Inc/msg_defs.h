/*
 * msg_defs.h
 *
 *  Created on: 15.05.2018
 *      Author: mromanow
 */

#ifndef MSG_DEFS_H_
#define MSG_DEFS_H_


#define ORDER_LENGTH	11

/*
 * 	===============================
 *  ===== ORDER TYPES =============
 *  ===============================
 */

#define HW_CONFIG 		1
#define JOINT_SPACE 	2
#define OPERATION_SPACE 3

/*
 * 	===============================
 *  ===== HW_CONFIG =============
 *  ===============================
 */

#define MOTORS_ON		1
#define MOTORS_OFF		2
#define FANS_ON			3
#define FANS_OFF		4

/*
 * 	===============================
 *  ===== CALLBACK TYPES ==========
 *  ===============================
 */

#define ORDER_OK			00
#define ORDER_ERROR			1
#endif /* MSG_DEFS_H_ */
