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

#define EPSILON	0.2


struct motion_node{

	float 		  max_position;
	float 		  min_position;

	uint32_t	  max_speed;
	uint32_t	  min_speed;
	float max_accel;

	float position;
	float goal_position;

	int   enabled;

};
typedef struct motion_node motion_node;

motion_node motion_nodes[STEPPER_N];

void m_motionControllerInit();

void m_control();

void m_setPosition(uint8_t motor,float position);

void m_updatePosition(uint16_t motor);
void m_updateAllPosition();

void m_enable(uint8_t motor);
void m_enableAll();
void m_disable(uint8_t motor);
void m_disableAll();

#endif /* MOTION_CONTROL_H_ */
