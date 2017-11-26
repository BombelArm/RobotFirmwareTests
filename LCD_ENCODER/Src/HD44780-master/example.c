/*
 * example.c
 *
 *  Created on: Jan 5, 2015
 *      Author: peter
 */
/*
LCD_PCF8574_HandleTypeDef	lcd;

int main(void) {

	HAL_Init();
	SystemClock_Config();
	HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);
	HAL_NVIC_SetPriority(SysTick_IRQn, 0, 1);

	lcd.pcf8574.PCF_I2C_ADDRESS = 7;
	lcd.pcf8574.PCF_I2C_TIMEOUT = 1000;
	lcd.pcf8574.i2c.Instance = I2C1;
	lcd.pcf8574.i2c.Init.ClockSpeed = 400000;
	lcd.NUMBER_OF_LINES = NUMBER_OF_LINES_2;
	lcd.type = TYPE0;

	if(LCD_Init(&lcd)!=LCD_OK){
		// error occured
		while(1);
	}

	LCD_ClearDisplay(&lcd);
	LCD_SetLocation(&lcd, 0, 0);
	LCD_WriteString(&lcd, "pi:");
	LCD_SetLocation(&lcd, 0, 1);
	LCD_WriteString(&lcd, "e:");

	while (1) {
		LCD_SetLocation(&lcd, 6, 0);
		LCD_WriteFloat(&lcd,3.1415926,7);
		LCD_SetLocation(&lcd, 6, 1);
		LCD_WriteFloat(&lcd,2.71,2);
		HAL_Delay(3000);
	}
}
*/
