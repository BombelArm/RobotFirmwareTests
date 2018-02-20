/*
 * encoder.h
 *
 *  Created on: 06.12.2017
 *      Author: Admin
 */

#ifndef APPLICATION_USER_ENCODER_H_
#define APPLICATION_USER_ENCODER_H_

#include "stm32f4xx_hal.h"

#define ENCODER0_OFFSET -1473
#define ENCODER1_OFFSET -1059
#define ENCODER2_OFFSET -3312

enum dir{
	clockwise,
	counter_clockwise
};

enum dir encoders_dir[3]={counter_clockwise, clockwise, counter_clockwise}; // {encoder_0, encoder_1, encoder_2}

float			  bin2rad(uint16_t data_in,int cs);
HAL_StatusTypeDef encoder_read(float *data_in, int cs);

#endif /* APPLICATION_USER_ENCODER_H_ */
