/*! \file
 * \brief Message definitions 
 */

#ifndef MSG_DEFS_H_
#define MSG_DEFS_H_


#define ORDER_LENGTH	6 /**< Length of the order sent from PC to micro-controller */


#define HW_CONFIG 		1 /**<Hardware configuration order type*/
#define JOINT_SPACE 	2 /**<Joint space order type*/
#define OPERATION_SPACE 3 /**<Operation space order type*/

#define MOTORS_ON		1 /**<HW config - turns motors on*/
#define MOTORS_OFF		2 /**<HW config - turns motors off*/
#define FANS_ON			3 /**<HW config - turns fans on*/
#define FANS_OFF		4 /**<HW config - turns fans off*/


#define ORDER_OK			00 /**< Return msg - ok */
#define ORDER_ERROR			1 /**< Return msg - error */
#endif /* MSG_DEFS_H_ */
