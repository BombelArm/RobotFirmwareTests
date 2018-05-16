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


#define LD2_GPIO_Port ENCODERS_SERIAL_CLOCK_GPIO_Port
#define LD2_Pin ENCODERS_SERIAL_CLOCK_Pin

#define LED_ON HAL_GPIO_WritePin(LD2_GPIO_Port,LD2_Pin,GPIO_PIN_SET)
#define LED_OFF HAL_GPIO_WritePin(LD2_GPIO_Port,LD2_Pin,GPIO_PIN_RESET)

#define TASK_BUFFER_SIZE 1

struct task{
	int order_type;
	int hw_task_type;

	float time;

	float f1;
	float f2;
	float f3;
};
typedef struct task task;

int buffer_act_size=0;
task buffer[TASK_BUFFER_SIZE];

void t_append_task(uint8_t msg[ORDER_LENGTH]);
void t_exec();
void t_shift_buffer();

#endif /* TASK_MANAGER_H_ */
