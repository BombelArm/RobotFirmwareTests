/*
 * stepper_lib.c
 *
 *  Created on: 09.03.2018
 *      Author: mromanow
 */

#include "stepper_lib.h"

void motorsInit(){
	uint16_t pins[STEPPER_N][2]={
			{MOTOR0_STEP_Pin,MOTOR0_DIR_Pin},
			{MOTOR1_STEP_Pin,MOTOR1_DIR_Pin},
			{MOTOR2_STEP_Pin,MOTOR2_DIR_Pin}
	};
	GPIO_TypeDef (*ports)[STEPPER_N][2]={
			{MOTOR0_STEP_GPIO_Port,MOTOR0_DIR_GPIO_Port},
			{MOTOR1_STEP_GPIO_Port,MOTOR1_DIR_GPIO_Port},
			{MOTOR2_STEP_GPIO_Port,MOTOR2_DIR_GPIO_Port}
	};

	for(int i=0;i<STEPPER_N;i++){
		motors[i].step_pin=pins[i][1];
		motors[i].dir_pin=pins[i][2];

		motors[i].step_port=ports[i][1];
		motors[i].step_port=ports[i][2];
	}
}
void step(uint16_t motor){
	stepper stepper1;

	stepper1=motors[motor];

	HAL_GPIO_TogglePin(stepper1.step_port, stepper1.step_pin);
}

void stepAll(){

	for(int i=0;i<STEPPER_N;i++){

		if(motors[i].timer_period==0)continue;

		motors[i].timer_counter+=1;

		if(motors[i].timer_counter == motors[i].timer_period){
			HAL_GPIO_TogglePin(MOTOR2_STEP_GPIO_Port, MOTOR2_STEP_Pin);
			motors[i].timer_counter=0;
		}
	}

}

void setSpeed(uint16_t motor,int speed){
	motors[motor].timer_period=speed;
}

void changeDir(uint16_t motor){
	stepper stepper1;

	stepper1=motors[motor];

	HAL_GPIO_TogglePin(stepper1.dir_port, stepper1.step_port);
}
