/*
 * task_manager.h
 *
 *  Created on: 29.03.2018
 *      Author: mromanow
 */

#ifndef TASK_MANAGER_H_
#define TASK_MANAGER_H_

#include "stdint.h"
#include "gpio.h"
#include "msg_defs.h"
#include "motion_control.h"



#define first_int(x)	x/10
#define second_int(x)	x%10

#define MOTORS_ENABLED  1
#define FANS_ENABLED	1

#define TASK_BUFFER_SIZE 1

struct task{
	int order_type;
	int hw_task_type;

	float time;

	float f0;
	float f1;
	float f2;
};
typedef struct task task;

int buffer_act_size=0;
task buffer[TASK_BUFFER_SIZE];

void t_taskManagerInit();

void t_append_task(uint8_t msg[ORDER_LENGTH]);
void t_exec();
void t_shift_buffer();

#endif /* TASK_MANAGER_H_ */
