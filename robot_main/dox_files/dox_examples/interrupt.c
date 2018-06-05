//! [ISR]

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
 if(htim->Instance == TIM2){
	 s_stepAll();
 }else if(htim->Instance == TIM3){
	 m_updateAllPosition();
 }else if(htim->Instance == TIM4){
	 m_control();
 }
}

//! [ISR]