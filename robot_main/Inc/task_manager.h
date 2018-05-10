/*
 * task_manager.h
 *
 *  Created on: 29.03.2018
 *      Author: mromanow
 */

#ifndef TASK_MANAGER_H_
#define TASK_MANAGER_H_

#define TASK_BUFFER_SIZE 2

enum task_type{
	configuration,
	joint_space
};

struct task{
	uint8_t   task_type;
	float time;

	float joint0;
	float joint1;
	float joint2;
};
typedef struct task task;

task buffer[TASK_BUFFER_SIZE];



#endif /* TASK_MANAGER_H_ */
