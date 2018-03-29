/*
 * motion_control.h
 *
 *  Created on: 13.03.2018
 *      Author: mromanow
 */

#ifndef MOTION_CONTROL_H_
#define MOTION_CONTROL_H_

#include "stdint.h"
#include "main.h"
#include "limits.h"

#define EPSILON	0.05			/**< defines the accuracy of reached position*/
#define ACCEL_DISTANCE 0.5

/** @file motion_control.h
 *  @brief Function prototypes and public variables for motion controll of the stepper motors.
 *
 *  This contains all functions and variables necessary for proper motion control including velocity,acceleration and position limits (of the joints).
 *  The m_control() and m_updatePositionAll() functions are executed periodically by TIM3 PeriodElapsedCallback event.
 */

/**
 * A structure to represent motion control node.
 */
struct motion_node{

	float 		  max_position;		/**< maximum position that can reached */
	float 		  min_position;		/**< minimum position that can reached */

	uint32_t	  max_speed;		/**< maximum speed limit of the joint */
	uint32_t	  min_speed;		/**< minimum speed limit of the joint */
	float 		  max_accel;		/**< maximum acceleration limit of the joint */

	float 		  actual_position;	/**< actual position of the joint */
	uint32_t	  actual_speed;		/**< actual speed of the joint */
	float 		  goal_position;	/**< goal position of the joint */
	uint32_t	  goal_speed;		/**< goal speed (maximum speed while moving towards goal position)*/

	uint8_t 	  enabled;			/**< determines wheter the motion control node is disabled(0) or enabled(1) */

};

typedef struct motion_node motion_node;

motion_node motion_nodes[STEPPER_N]; /**< array of motion node that are related to stepper motors used by the microcontroller */

/**
 * Initialization function.
 * Sets all required variables that are related to the motion controll node.
 * @see \struct motion_node
 */
void m_motionControllerInit();

/**
 * Periodically executed function. This function oversees all joints (its velocity, acceleration and position)
 * @see \struct motion_node
 */
void m_control();
/**
 * This function sets the goal_position to which the joint is going to.
 * @param motor determines the stepper motor (actually the motion node that are related to the motor)
 * @param position determines the position to which the joint is going to
 * @param time	determines the time of the travel
 * @see \struct motion_node
 * @return Void
 */
void m_setPosition(uint8_t motor,float position,uint32_t time);
/**
 * This function updates the actual_position of the joint
 * @param motor determines the stepper motor (actually the motion node that are related to the motor)
 * @see \struct motion_node
 * @return Void
 */
void m_updatePosition(uint8_t motor);
/**
 * This function updates the actual_position of all joints
 * @see \struct motion_node
 * @return Void
 */
void m_updateAllPosition();

int m_calculateSpeed(uint8_t motor,uint32_t speed);

/**
 * This function enables the motion control node.
 * @param motor determines the stepper motor (actually the motion node that are related to the motor)
 * @see \struct motion_node
 * @return Void
 */
void m_enable(uint8_t motor);
/**
 * This function enables all motion control node.
 * @see \struct motion_node
 * @return Void
 */
void m_enableAll();
/**
 * This function disables the motion control node.
 * @param motor determines the stepper motor (actually the motion node that are related to the motor)
 * @see \struct motion_node
 * @return Void
 */
void m_disable(uint8_t motor);
/**
 * This function disables all motion control node.
 * @see \struct motion_node
 * @return Void
 */
void m_disableAll();

#endif /* MOTION_CONTROL_H_ */
