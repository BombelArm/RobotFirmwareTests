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

#define EPSILON	0.05
#define ACCEL_DISTANCE 0.5

struct motion_node{

	float 		  max_position;
	float 		  min_position;

	uint32_t	  max_speed;	//maximum speed limit of the joint
	uint32_t	  min_speed;	//minimum speed limit of the joint
	float 		  max_accel;	//maximum acceleration limit of the joint

	float 		  actual_position;	//position of the joint
	uint32_t	  actual_speed;		//actual speed of the joint
	float 		  goal_position;	//goal position of the joint
	uint32_t	  goal_speed;		//goal speed (maximum speed while moving towards goal position)

	int   		  enabled;

};
typedef struct motion_node motion_node;

motion_node motion_nodes[STEPPER_N];

void m_motionControllerInit();

void m_control();

void m_setPosition(uint8_t motor,float position,uint32_t speed);

void m_updatePosition(uint8_t motor);
void m_updateAllPosition();

int m_calculateSpeed(uint8_t motor,uint32_t speed);

void m_enable(uint8_t motor);
void m_enableAll();
void m_disable(uint8_t motor);
void m_disableAll();

#endif /* MOTION_CONTROL_H_ */
