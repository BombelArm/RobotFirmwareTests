/*
 * example_msp.c
 *
 *  Created on: Jan 5, 2015
 *      Author: peter
 */

/**
 * @brief I2C MSP Initialization
 *        This function configures the hardware resources used in this example:
 *           - Peripheral's clock enable
 *           - Peripheral's GPIO Configuration
 *           - DMA configuration for transmission request by peripheral
 *           - NVIC configuration for DMA interrupt request enable
 * @param hi2c: I2C handle pointer
 * @retval None
 */




/*
void HAL_I2C_MspInit(I2C_HandleTypeDef *hi2c) {
	GPIO_InitTypeDef GPIO_InitStruct;

	if (hi2c->Instance == I2C1) {

		__GPIOB_CLK_ENABLE();

		GPIO_InitStruct.Pin = GPIO_PIN_6 | GPIO_PIN_7;
		GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
		GPIO_InitStruct.Pull = GPIO_PULLUP;
		GPIO_InitStruct.Speed = GPIO_SPEED_FAST;
		GPIO_InitStruct.Alternate = GPIO_AF4_I2C1;
		HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

		__I2C1_CLK_ENABLE();
	}
}

*/

/**
 * @brief I2C MSP De-Initialization
 *        This function frees the hardware resources used in this example:
 *          - Disable the Peripheral's clock
 *          - Revert GPIO, DMA and NVIC configuration to their default state
 * @param hi2c: I2C handle pointer
 * @retval None
 */

//void HAL_I2C_MspDeInit(I2C_HandleTypeDef *hi2c) {
	/*##-1- Reset peripherals ##################################################*/
//	__I2C1_FORCE_RESET();
//	__I2C1_RELEASE_RESET();

	/*##-2- Disable peripherals and GPIO Clocks ################################*/
	/* Configure I2C Tx as alternate function  */
//	HAL_GPIO_DeInit(GPIOB, GPIO_PIN_6);
	/* Configure I2C Rx as alternate function  */
//	HAL_GPIO_DeInit(GPIOB, GPIO_PIN_7);
//}
