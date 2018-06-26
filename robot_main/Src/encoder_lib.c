/*! \file
 * \brief Encoders source code.
 */


#ifndef ENCODER_LIB_C_
#define ENCODER_LIB_C_

#include "encoder_lib.h"
#include "spi.h"
#include <math.h>


HAL_StatusTypeDef e_read(int16_t *data_in,int cs)
{
	HAL_StatusTypeDef status;
	GPIO_TypeDef*     port;
	uint16_t	  pin;
	uint16_t	  data;

	port=e_ports[cs];
	pin=e_pins[cs];

	HAL_GPIO_WritePin(port, pin, GPIO_PIN_RESET);
	status=HAL_SPI_Receive(&hspi1, &data, 1, 0x00ff);
	data=(uint16_t) data>>4;
	HAL_GPIO_WritePin(port, pin, GPIO_PIN_SET);



	data+=e_offests[cs];
	data&=0x0FFF;

	if(data <2048 && data>=0){
			(*data_in)=data*e_dirs[cs];
		}else{
			(*data_in)=-fabs(data-4096)*e_dirs[cs];
	}

//	data=*e_dirs[cs]*data;

	return status;
}



#endif /* ENCODER_LIB_H_ */
