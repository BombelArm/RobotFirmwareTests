/*! 
 * \brief Motion control of the robot's joints.
 * \addtogroup Motion Control
 *  @{
 *\file
 * \brief Function prototypes and public variables for motion controll of the stepper motors.
 * \details This contains all functions and variables necessary for proper motion control including velocity,acceleration and position limits (of the joints).
 *  The m_control() and m_updatePositionAll() functions are executed periodically by TIM3 PeriodElapsedCallback event.
 */

#ifndef MOTION_CONTROL_H_
#define MOTION_CONTROL_H_

#include "stdint.h"
#include "main.h"
#include "limits.h"

#define EPSILON	35			/**< defines the accuracy of reached position*/
#define ACCEL_DISTANCE 0.5

/** @file motion_control.h
 *  @brief Function prototypes and public variables for motion controll of the stepper motors.
 *
 *  This contains all functions and variables necessary for proper motion control including velocity,acceleration and position limits (of the joints).
 *  The m_control() and m_updatePositionAll() functions are executed periodically by TIM3 PeriodElapsedCallback event.
 */

/**
 * \brief A structure to represent motion control node.
 */
struct motion_node{

	int16_t		  max_position;		/**<  \brief maximum position that can reached */
	int16_t		  min_position;		/**<  \brief minimum position that can reached */

	uint8_t	 	  max_speed;		/**<  \brief maximum speed limit of the joint */
	uint8_t	 	  min_speed;		/**<  \brief minimum speed limit of the joint */
	uint8_t	  	  max_accel;		/**<  \brief maximum acceleration limit of the joint */

	int16_t       actual_position;	/**<  \brief actual position of the joint */
	uint16_t	  actual_speed;		/**<  \brief actual speed of the joint */
	int16_t 	  goal_position;	/**<  \brief goal position of the joint */
	uint8_t	  	  goal_speed;		/**<  \brief goal speed (maximum speed while moving towards goal position)*/

	uint8_t		  position_reached; /**<  \brief if new position is set the flag "position_reached" is reset to 0, when motion_controller reaches the position it is set to 1*/
	uint8_t 	  enabled;			/**<  \brief determines wheter the motion control node is disabled(0) or enabled(1) */

};

typedef struct motion_node motion_node;

motion_node motion_nodes[JOINTS_N]; /**< array of motion node that are related to stepper motors used by the microcontroller */

/*!
 * \details Initialization function. Sets all required variables that are related to the motion controll node.
 * \return Void
 */
void m_motionControllerInit();

/*!
 * \details Periodically executed function. This function oversees all joints (its velocity, acceleration and position)
 * \return Void
 */
void m_control();
/*!
 * \details This function sets the goal_position to which the joint is going to.
 * \param joint determines the stepper motor (actually the motion node that are related to the motor)
 * \param position determines the position to which the joint is going to
 * \param time	determines the time of the travel
 * \return Void
 */
void m_setPosition(uint8_t joint,int16_t position, uint8_t goal_speed);

uint8_t m_validatePosition(uint8_t joint, uint8_t speed, int16_t position);

/*!
 * \details This function updates the actual_position of the joint
 * \param motor determines the stepper motor (actually the motion node that are related to the motor)
 * \return Void
 */

void m_updatePosition(uint8_t motor);

/*!
 * \details This function updates the actual_position of all joints
 * \return Void
 */
void m_updateAllPosition();

int m_calculateSpeed(uint8_t joint,uint32_t speed);

/*!
 * \details This function enables the motion control node.
 * \param motor determines the stepper motor (actually the motion node that are related to the motor)
 * \return Void
 */
void m_enable(uint8_t joint);
/*!
 * \details This function enables all motion control node.
 * \return Void
 */
void m_enableAll();
/*!
 * \details This function disables the motion control node.
 * \param motor determines the stepper motor (actually the motion node that are related to the motor)
 * \return Void
 */
void m_disable(uint8_t joint);
/*!
 * \details This function disables all motion control node.
 * \return Void
 */
void m_disableAll();

#endif /* MOTION_CONTROL_H_ */
/** @}*/
