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
	uint8_t		 		step;	// 1/2 -> 2 | 1/4 -> 4 ...

	//limits
	uint32_t			max_speed;
	uint32_t			min_speed;
	uint8_t				clockwise_direction; //position is going towards pi (if dir=!clockwise_direction position is going toward -pi)

	uint32_t			timer_period;
	uint32_t			timer_counter;

	uint8_t				enabled;
};
typedef struct stepper stepper;

stepper motors[STEPPER_N];
int steps=0;

void s_motorsInit();

void s_step(uint8_t motor);
void s_stepAll();

void s_changeDir(uint8_t motor,uint8_t dir); //dir==1 clockwise dir==0 counter_clockwise
void s_setSpeed(uint8_t motor,uint32_t speed);

void s_enable(uint8_t motor);
void s_enableAll();
void s_disable(uint8_t motor);
void s_disableAll();

#endif /* STEPPER_LIB_H_ */
