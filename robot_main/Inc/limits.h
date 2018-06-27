/*! 
 * \addtogroup Motion Control
 *  @{
 *\file
 * \brief Limitation of the stepper motor and joints.
 */

#ifndef LIMITS_H_
#define LIMITS_H_

#define JOINTS_N		3	/**< \brief Degree of freedom */

#define	HW_MOTOR_MIN_SPEED	37	/**< \brief Stepper motor (NEMA17) minimum speed */
#define HW_MOTOR_MAX_SPEED	200 /**< \brief Stepper motor (NEMA17) maximum speed */

#define JOINT0_MIN_SPEED 20 /**< \brief Joint 0 minimum speed*/
#define JOINT0_MAX_SPEED 150 /**< \brief Joint 0 maximum speed*/
#define JOINT0_MAX_ACCEL 2 /**< \brief Joint 0 maximum acceleration*/

#define JOINT1_MIN_SPEED 20  /**< \brief Joint 0 minimum speed*/
#define JOINT1_MAX_SPEED 150 /**< \brief Joint 0 maximum speed*/
#define JOINT1_MAX_ACCEL 2 /**< \brief Joint 0 maximum acceleration*/

#define JOINT2_MIN_SPEED 20 /**< \brief Joint 0 minimum speed*/
#define JOINT2_MAX_SPEED 150 /**< \brief Joint 0 maximum speed*/
#define JOINT2_MAX_ACCEL 2 /**< \brief Joint 0 maximum acceleration*/

#define JOINT0_MIN_POSITION -1300 /**< \brief Joint 0 minimum position*/
#define JOINT0_MAX_POSITION	1300 /**< \brief Joint 0 maximum position*/

#define JOINT1_MIN_POSITION -900 /**< \brief Joint 1 minimum position*/
#define JOINT1_MAX_POSITION	900 /**< \brief Joint 1 maximum position*/

#define JOINT2_MIN_POSITION -800 /**< \brief Joint 2 minimum position*/
#define JOINT2_MAX_POSITION	1300 /**< \brief Joint 2 maximum position*/


#endif /* LIMITS_H_ */
/** @}*/
