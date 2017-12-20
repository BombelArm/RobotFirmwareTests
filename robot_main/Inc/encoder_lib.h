/*
 * encoder.h
 *
 *  Created on: 06.12.2017
 *      Author: Admin
 */

#ifndef APPLICATION_USER_ENCODER_H_
#define APPLICATION_USER_ENCODER_H_

#include "stm32f4xx_hal.h"

#define ENCODER0_OFFSET -3524
#define ENCODER1_OFFSET -1059
#define ENCODER2_OFFSET -753

#define ENCODER0_GAIN 1
#define ENCODER1_GAIN 1
#define ENCODER2_GAIN 1


HAL_StatusTypeDef encoder_read(int16_t *data_in, int cs);

#endif /* APPLICATION_USER_ENCODER_H_ */
