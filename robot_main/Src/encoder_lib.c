/*
 * encoder.c
 *
 *  Created on: 06.12.2017
 *      Author: Admin
 */

#include "encoder_lib.h"
#include "spi.h"

HAL_StatusTypeDef encoder_read(int16_t *data_in,int cs)
{
	HAL_StatusTypeDef status;
	GPIO_TypeDef*     port;
	uint16_t		  pin;
	int16_t		      data;

	switch(cs){
		case 0:
			port =	ENCODER_CS0_GPIO_Port;
			pin =	ENCODER_CS0_Pin;
			break;
		case 1:
			port =	ENCODER_CS1_GPIO_Port;
			pin =	ENCODER_CS1_Pin;
			break;
		case 2:
			port =	ENCODER_CS2_GPIO_Port;
			pin =	ENCODER_CS2_Pin;
			break;
		default:
			return status=HAL_ERROR;
	}

	HAL_GPIO_WritePin(port, pin, GPIO_PIN_RESET);
	status=HAL_SPI_Receive(&hspi1, &data, 1, 0x00ff);
    (*data_in)=(int) data>>4;
	HAL_GPIO_WritePin(port, pin, GPIO_PIN_SET);

	switch(cs){
		case 0:
			(*data_in)+=ENCODER0_OFFSET;
			(*data_in)*=ENCODER0_GAIN;
			break;
		case 1:
			(*data_in)+=ENCODER1_OFFSET;
			(*data_in)*=ENCODER1_GAIN;
			break;
		case 2:
			(*data_in)+=ENCODER2_OFFSET;
			(*data_in)*=ENCODER2_GAIN;
			break;
		default:
			return status=HAL_ERROR;
	}

	return status;

}
