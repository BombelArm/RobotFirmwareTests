/*
 * motion_control.h
 *
 *  Created on: 13.03.2018
 *      Author: mromanow
 */

#ifndef MOTION_CONTROL_H_
#define MOTION_CONTROL_H_

#include "stdint.h"
#include "limits.h"

#endif /* MOTION_CONTROL_H_ */


void m_motionControllerInit();

void m_control();

void m_setPosition(uint8_t motor,float position);
