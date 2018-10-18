/*
 * motors_param.h
 *
 *  Created on: Oct 18, 2018
 *      Author: michal
 */

#ifndef MOTORS_PARAM_H_
#define MOTORS_PARAM_H_


#ifdef __cplusplus
 extern "C" {
#endif

#include "L6470.h"

MotorParameterData_t *GetMotorParameterInitData(void);

#ifdef __cplusplus
}
#endif


#endif /* MOTORS_PARAM_H_ */
