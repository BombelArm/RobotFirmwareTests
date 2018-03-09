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

#define STEPPER_N	3


struct stepper{
	uint16_t			step_pin;
	GPIO_TypeDef 		*step_port;
	uint16_t			dir_pin;
	GPIO_TypeDef 		*dir_port;

	int			timer_period;
	int			timer_counter;
};
typedef struct stepper stepper;

stepper motors[STEPPER_N];

void motorsInit();

void step(uint16_t motor);
void stepAll();

void changeDir(uint16_t motor);
void setSpeed(uint16_t motor,int speed);

#endif /* STEPPER_LIB_H_ */
