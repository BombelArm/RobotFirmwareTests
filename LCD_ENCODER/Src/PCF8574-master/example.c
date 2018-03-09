/*
PCF8574_HandleTypeDef	pcf;

int main(void) {

	HAL_Init();
	SystemClock_Config();
	HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);
	HAL_NVIC_SetPriority(SysTick_IRQn, 0, 1);

	pcf.PCF_I2C_ADDRESS=7;
	pcf.PCF_I2C_TIMEOUT=1000;
	pcf.i2c.Instance=I2C1;
	pcf.i2c.Init.ClockSpeed=400000;

	if(PCF8574_Init(&pcf)!=PCF8574_OK){
		// error occured
		while(1);
	}

	while (1) {
		uint8_t val;
		PCF8574_Read(&pcf,&val);
		val++;
		PCF8574_Write(&pcf,val);
		HAL_Delay(100);
	}
}
*/
