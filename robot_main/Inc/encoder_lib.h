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

#define ENCODER0_OFFSET -2991 /**<  \brief Encoder 0 offset - base position calibration */
#define ENCODER1_OFFSET -1059 /**<  \brief Encoder 1 offset - base position calibration */
#define ENCODER2_OFFSET -3312 /**<  \brief Encoder 2 offset - base position calibration */


/**
 * \brief Enum of two possible directions of rotation. This division is necessary beacuse of differences in encoders' placement on the robotic arm.
 */
enum dir{
	clockwise,
	counter_clockwise
};
/**
 * \brief Enum of three encoders to which certain direction is assigned. 
 */
enum dir encoders_dir[3]={counter_clockwise, clockwise, counter_clockwise}; 

/*!
 * \details This function converts angle from binary code to radians (encoders passes message to the micro-controller unit with angle in binary code)
 * \param data_in angle in binary code
 * \param cs encoder chip select (0,1,2)
 * \return float  angle in radians
 */
float			  e_bin2rad(uint16_t data_in,int cs);
/*!
 * \details This function reads angle from the encoder
 * \param data_in variable to which the angle will be written
 * \param cs encoder chip select (0,1,2)
 * \return HAL_StatusTypeDef  return code
 */
HAL_StatusTypeDef e_read(float *data_in, int cs);

#endif /* APPLICATION_USER_ENCODER_H_ */
/** @}*/
