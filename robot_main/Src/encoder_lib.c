/*! \file
 * \brief Encoders source code.
 */


#ifndef ENCODER_LIB_C_
#define ENCODER_LIB_C_

#include "encoder_lib.h"
#include "spi.h"
#include <math.h>


float e_bin2rad(uint16_t data_in,int cs){
	float result;

	if(data_in <2048 && data_in>=0){
		result=data_in*M_PI/2048;
	}else{
		result=-(fabs(data_in-4096)*M_PI/2048);
	}

	if(encoders_dir[cs] == counter_clockwise){
		result*=-1;
	}

	return result;
}

HAL_StatusTypeDef e_read(float *data_in,int cs)
{
	HAL_StatusTypeDef status;
	GPIO_TypeDef*     port;
	uint16_t		  pin;
	uint16_t		  data;

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
	data=(uint16_t) data>>4;
	HAL_GPIO_WritePin(port, pin, GPIO_PIN_SET);

	switch(cs){
		case 0:
			data+=ENCODER0_OFFSET;
			break;
		case 1:
			data+=ENCODER1_OFFSET;
			break;
		case 2:
			data+=ENCODER2_OFFSET;
			break;
		default:
			return status=HAL_ERROR;
	}

	data&=0x0FFF;
	(*data_in)=e_bin2rad(data,cs);
	//(*data_in)=data;

	return status;
}



#endif /* ENCODER_LIB_H_ */
