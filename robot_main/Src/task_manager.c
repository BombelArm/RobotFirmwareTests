/*
 * task_manager.c
 *
 *  Created on: 29.03.2018
 *      Author: mromanow
 */

#include "task_manager.h"

void t_append_task(uint8_t msg[ORDER_LENGTH]){
	int hw_task_type,order_type;
	float f1,f2,f3;
	task newtask;

	if(buffer_act_size == TASK_BUFFER_SIZE){
		return;
	}

	order_type=10*(int)(char)msg[0]+1*(int)(char)msg[1];
	newtask.order_type=order_type;


	switch(order_type){
			case HW_CONFIG:
				hw_task_type=10*msg[2]+1*msg[3];
				newtask.hw_task_type=hw_task_type;
				break;
			case JOINT_SPACE:
				f1=1*msg[2]+0.1*msg[3]+0.01*msg[4];
				f2=1*msg[5]+0.1*msg[6]+0.01*msg[7];
				f3=1*msg[8]+0.1*msg[9]+0.01*msg[10];

				newtask.f1=f1;
				newtask.f2=f2;
				newtask.f3=f3;
				break;
			case OPERATION_SPACE:
				f1=1*msg[2]+0.1*msg[3]+0.01*msg[4];
				f2=1*msg[5]+0.1*msg[6]+0.01*msg[7];
				f3=1*msg[8]+0.1*msg[9]+0.01*msg[10];

				newtask.f1=f1;
				newtask.f2=f2;
				newtask.f3=f3;
				break;
	}

	buffer[buffer_act_size++]=newtask;
	t_exec();
}

void t_exec(){
	task task1=buffer[buffer_act_size--];

	switch(task1.order_type){
			case HW_CONFIG:
				switch(task1.hw_task_type){
					case MOTORS_ON:
						LED_ON;
						break;
					case MOTORS_OFF:
						LED_OFF;
						break;
					case FANS_ON:
						LED_ON;
						break;
					case FANS_OFF:
						LED_ON;
						break;
				}
				break;
			case JOINT_SPACE:
				break;
			case OPERATION_SPACE:
				break;
	}
}

void t_shift_buffer(){
	for(int i=TASK_BUFFER_SIZE-1;i>0;i--){
//		buffer+i=buffer+(i-1);
	}
}
