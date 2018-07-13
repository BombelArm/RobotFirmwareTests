/*
 * encoder.h
 *
 *  Created on: 06.12.2017
 *      Author: Admin
 */

#ifndef APPLICATION_USER_ENCOD ER_H_
#define APPLICATION_USER_ENCODER_H_

#include "stm32f4xx_hal.h"
#include "spi.h"
#include <math.h>

#define ENCODER0_OFFSET -3312//-1473
#define ENCODER1_OFFSET -1059
#define ENCODER2_OFFSET -3312



 int encoders_direc[3]={1, 0, 1}; // {encoder_0, encoder_1, encoder_2}

float bin2rad(uint16_t data_in,int cs){
	float result;

	if(data_in <2048 && data_in>=0){
		result=data_in*M_PI/2048;
	}else{
		result=-(fabs(data_in-4096)*M_PI/2048);
	}

	if(encoders_direc[cs] == 1){
		result*=-1;
	}

	return result;
}

HAL_StatusTypeDef e_read(float *data_in, int cs){

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
	(*data_in)=bin2rad(data,cs);
	//(*data_in)=data;

	return status;

}

#endif /* APPLICATION_USER_ENCODER_H_ */
