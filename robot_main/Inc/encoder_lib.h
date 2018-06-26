/*! 
 * \brief Encoders implementation
 * \addtogroup Encoders
 *  @{
 * \file
 * \brief Encoders implementation
 */

#ifndef ENCODER_LIB_H_
#define ENCODER_LIB_H_

#include "stm32f4xx_hal.h"
#include "limits.h"

#define ENCODER0_OFFSET -2991 /**<  \brief Encoder 0 offset - base position calibration */
#define ENCODER1_OFFSET -1059 /**<  \brief Encoder 1 offset - base position calibration */
#define ENCODER2_OFFSET -3312 /**<  \brief Encoder 2 offset - base position calibration */

#define ENCODER0_DIR	-1
#define ENCODER1_DIR	1
#define ENCODER2_DIR	-1


int8_t		  e_dirs[JOINTS_N]={
						ENCODER0_DIR,
						ENCODER1_DIR,
						ENCODER2_DIR
				};
GPIO_TypeDef* e_ports[JOINTS_N]={
						ENCODER_CS0_GPIO_Port,
						ENCODER_CS1_GPIO_Port,
						ENCODER_CS2_GPIO_Port
				};
uint16_t	  e_pins[JOINTS_N]={
						ENCODER_CS0_Pin,
						ENCODER_CS1_Pin,
						ENCODER_CS2_Pin
				};
int16_t	  e_offests[JOINTS_N]={
						ENCODER0_OFFSET,
						ENCODER1_OFFSET,
						ENCODER2_OFFSET
					};

/*!
 * \details This function reads angle from the encoder
 * \param data_in variable to which the angle will be written
 * \param cs encoder chip select (0,1,2)
 * \return HAL_StatusTypeDef  return code
 */
HAL_StatusTypeDef e_read(int16_t *data_in, int cs);

#endif /* APPLICATION_USER_ENCODER_H_ */
/** @}*/
