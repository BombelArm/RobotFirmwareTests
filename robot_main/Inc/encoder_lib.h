/*
 * encoder.h
 *
 *  Created on: 06.12.2017
 *      Author: Admin
 */

#ifndef APPLICATION_USER_ENCODER_H_
#define APPLICATION_USER_ENCODER_H_

#include "stm32f4xx_hal.h"

HAL_StatusTypeDef encoder_read(uint16_t *data_in, int cs);

#endif /* APPLICATION_USER_ENCODER_H_ */
