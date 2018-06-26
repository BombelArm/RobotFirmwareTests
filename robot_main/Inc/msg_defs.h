/*! 
 * \addtogroup Communication
 *  @{
 *\file
 * \brief Message definitions 
 */

#ifndef MSG_DEFS_H_
#define MSG_DEFS_H_


#define ORDER_LENGTH	6 /**< Length of the order sent from PC to micro-controller */


#define MSG_HW_CONFIG 		1 /**< \brief Hardware configuration order type*/
#define MSG_JOINT_SPACE 	2 /**< \brief Joint space order type*/
#define MSG_OPERATION_SPACE 3 /**< \brief Operation space order type*/

#define HW_MOTORS_ON		1 /**< \brief HW config - turns motors on*/
#define HW_MOTORS_OFF		2 /**< \brief HW config - turns motors off*/
#define HW_FANS_ON			3 /**< \brief HW config - turns fans on*/
#define HW_FANS_OFF		4 /**< \brief HW config - turns fans off*/

#define RESP_HW_ERROR 		1
#define RESP_ORDER_ERROR 	2
#define RESP_ROBOT_STATE 	3
#endif /* MSG_DEFS_H_ */
/** @}*/
