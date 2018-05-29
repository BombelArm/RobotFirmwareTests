/*! 
 * \brief Steper motor control.
 * \addtogroup Stepper
 *  @{
 *\file
 * \brief Function prototypes and public variables for stepper motor control
 * \details This contains all functions and variables necessary for proper stpper motor control including velocity limits and motor specification (physical
 *  connections from MICRO-CONTROLLER to MOTOR, micro-step info etc.) The s_step() or s_stepAll() functions are executed periodically by TIM2 PeriodElapsedCallback event.
 */


#ifndef STEPPER_LIB_H_
#define STEPPER_LIB_H_

#include "stdint.h"
#include "main.h"
#include "limits.h"

/**
 * \brief A structure to represent stepper motor
 */
struct stepper{ 
	uint16_t			step_pin;		/**<  \brief pin of micro-controller that is connected to the driver step input */
	GPIO_TypeDef 		*step_port;		/**<  \brief port of micro-controller that is connected to the driver step input */
	uint16_t			dir_pin;		/**<  \brief pin of micro-controller that is connected to the driver direction input */
	GPIO_TypeDef 		*dir_port;		/**<  \brief port of micro-controller that is connected to the driver direction input */
	uint8_t		 		step;	  		/**<  \brief micro-step of the stepper motor (eg. step=2 means that the stepper motor runs with 1/2 micro-step) */

	//limits
	uint32_t			max_speed;		/**<  \brief maximum speed of the stepper motor (related to the physical limitations of the stepper motor) */
	uint32_t			min_speed;		/**<  \brief minimum speed of the stepper motor (related to the physical limitations of the stepper motor) */
	uint8_t				direction; 		/**<  \brief determines direction of the rotation (if direction=!1 position is going toward -pi) */

	uint32_t			timer_period;   /**<  \brief maximum value to which timer_counter is counting up  */
	uint32_t			timer_counter;  /**<  \brief if timer_counter==timer_period the toggle on the step pin occurs */

	uint8_t				enabled;		/**<  \brief determines whether the stepper motor is enabled or disabled */
};
typedef struct stepper stepper;
stepper motors[JOINTS_N]; /**< array of stepper motors that are used by the microcontroller */


/*!
 * \details Initialization function. Sets all required variables that are related to the stepper motor
 */
void s_motorsInit();

/*!
 * \details This function simply counts up timer_counter of the stepper motor. If timer_counter=timer_period the toggle on the step pin occurs.
 * \param motor determines the stepper motor
 * \return Void
 */
void s_step(uint8_t motor);
/*!
 * \details Periodically executed function.This function counts up timer_counter of all stepper motors. If timer_counter=timer_period the toggle on the step pin occurs.
 * \return Void
 */
void s_stepAll();

/*!
 * \details This function changes the direction of rotation of the stepper motor.
 * \param motor determines the stepper motor
 * \param dir desired direction of the rotation
 * \return Void
 */
void s_changeDir(uint8_t motor,uint8_t dir);
/*!
 * \details This function changes the speed of rotation of the stepper motor.
 * \param motor determines the stepper motor
 * \param speed desired speed of the rotation
 * \return Void
 */
void s_setSpeed(uint8_t motor,uint32_t speed);

/*!
 * \details This function enables the stepper motor.
 * \param motor determines the stepper motor
 * \return Void
 */
void s_enable(uint8_t motor);
/*!
 * \details This function enables of disables all of stepper motors.
 * \return Void
 */
void s_enableAll();
/*!
 * \details This function disables the stepper motor.
 * \param motor determines the stepper motor
 * \return Void
 */
void s_disable(uint8_t motor);
/*!
 * \details This function enables of disables all of stepper motors.
 * \return Void
 */
void s_disableAll();


#endif /* STEPPER_LIB_H_ */
/** @}*/
