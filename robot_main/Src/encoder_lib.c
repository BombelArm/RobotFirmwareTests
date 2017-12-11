/*
 * encoder.c
 *
 *  Created on: 06.12.2017
 *      Author: Admin
 */

#include "encoder_lib.h"
#include "spi.h"

HAL_StatusTypeDef encoder_read(uint16_t *data_in,int cs)
{
	HAL_StatusTypeDef status;
	GPIO_TypeDef*     port;
	uint16_t		  pin;


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
	status=HAL_SPI_Receive(&hspi1, data_in, 1, 0x00ff);
    (*data_in)=(*data_in)>>4;
	HAL_GPIO_WritePin(port, pin, GPIO_PIN_SET);

	return status;

}
