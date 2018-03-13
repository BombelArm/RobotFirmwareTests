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
//
//	Lib params configured for TIM f=100kHz
//
//


struct stepper{
	uint16_t			step_pin;
	GPIO_TypeDef 		*step_port;
	uint16_t			dir_pin;
	GPIO_TypeDef 		*dir_port;
	int 		step;	// 1/2 -> 2 | 1/4 -> 4 ...

	//limits
	int			max_speed;
	int			min_speed;

	int			timer_period;
	int			timer_counter;

	int			enabled;
};
typedef struct stepper stepper;

stepper motors[STEPPER_N];
int steps=0;

void s_motorsInit();

void s_step(uint16_t motor);
void s_stepAll();

void s_changeDir(uint16_t motor,int dir);
void s_setSpeed(uint16_t motor,int speed);

void s_enable(uint16_t motor);
void s_enableAll();
void s_disable(uint16_t motor);
void s_disableAll();

#endif /* STEPPER_LIB_H_ */
