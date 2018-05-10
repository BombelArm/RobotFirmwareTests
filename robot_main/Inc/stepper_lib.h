/*
 * stepper_lib.h
 *
 *  Created on: 09.03.2018
 *      Author: mromanow
 */

#ifndef STEPPER_LIB_H_
#define STEPPER_LIB_H_

#include "stdint.h"
#include "main.h"
#include "limits.h"

/** @file stepper_lib.h
 *  @brief Function prototypes and public variables for stepper motor control
 *
 *  This contains all functions and variables necessary for proper stpper motor control including velocity limits and motor specification (physical
 *  connections from MICRO-CONTROLLER to MOTOR, micro-step info etc.) The s_step() or s_stepAll() functions are executed periodically by TIM2 PeriodElapsedCallback event.
 */

/**
 * A structure to represent stepper motor
 */
struct stepper{
	uint16_t			step_pin;		/**< pin of micro-controller that is connected to the driver step input*/
	GPIO_TypeDef 		*step_port;		/**< port of micro-controller that is connected to the driver step input*/
	uint16_t			dir_pin;		/**< pin of micro-controller that is connected to the driver direction input*/
	GPIO_TypeDef 		*dir_port;		/**< port of micro-controller that is connected to the driver direction input*/
	uint8_t		 		step;	  		/**< micro-step of the stepper motor (eg. step=2 means that the stepper motor runs with 1/2 micro-step)*/

	//limits
	uint32_t			max_speed;		/**< maximum speed of the stepper motor (related to the physical limitations of the stepper motor)*/
	uint32_t			min_speed;		/**< minimum speed of the stepper motor (related to the physical limitations of the stepper motor)*/
	uint8_t				direction; 		/**< determines direction of the rotation (if direction=!1 position is going toward -pi)*/

	uint32_t			timer_period;   /**< maximum value to which timer_counter is counting up */
	uint32_t			timer_counter;  /**< if timer_counter==timer_period the toggle on the step pin occurs*/

	uint8_t				enabled;		/**< determines whether the stepper motor is enabled or disabled*/
};
typedef struct stepper stepper;

stepper motors[JOINTS_N]; /**< array of stepper motors that are used by the microcontroller */
int steps=0;


/**
 * Initialization function.
 * Sets all required variables that are related to the stepper motor
 * @see \struct stepper
 */
void s_motorsInit();

/**
 * This function simply counts up timer_counter of the stepper motor. If timer_counter=timer_period the toggle on the step pin occurs.
 * @param motor determines the stepper motor
 * @see \struct stepper
 * @return Void
 */
void s_step(uint8_t motor);
/**
 * Periodically executed function.This function counts up timer_counter of all stepper motors. If timer_counter=timer_period the toggle on the step pin occurs.
 * @see \struct stepper
 * @see s_step()
 * @return Void
 */
void s_stepAll();

/**
 * This function changes the direction of rotation of the stepper motor.
 * @param motor determines the stepper motor
 * @param dir desired direction of the rotation
 * @see \struct stepper
 * @return Void
 */
void s_changeDir(uint8_t motor,uint8_t dir);
/**
 * This function changes the speed of rotation of the stepper motor.
 * @param motor determines the stepper motor
 * @param speed desired speed of the rotation
 * @see \struct stepper
 * @return Void
 */
void s_setSpeed(uint8_t motor,uint32_t speed);

/**
 * This function enables the stepper motor.
 * @param motor determines the stepper motor
 * @see \struct stepper
 * @return Void
 */
void s_enable(uint8_t motor);
/**
 * This function enables of disables all of stepper motors.
 * @see \struct stepper
 * @return Void
 */
void s_enableAll();
/**
 * This function disables the stepper motor.
 * @param motor determines the stepper motor
 * @see \struct stepper
 * @return Void
 */
void s_disable(uint8_t motor);
/**
 * This function enables of disables all of stepper motors.
 * @see \struct stepper
 * @return Void
 */
void s_disableAll();

#endif /* STEPPER_LIB_H_ */
