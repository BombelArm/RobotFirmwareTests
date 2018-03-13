/*
 * stepper_lib.c
 *
 *  Created on: 09.03.2018
 *      Author: mromanow
 */

#ifndef STEPPER_LIB_C_
#define STEPPER_LIB_C_

#include "stepper_lib.h"

void s_motorsInit(){
	uint16_t pins[STEPPER_N][2]={
			{MOTOR0_STEP_Pin, MOTOR0_DIR_Pin},
			{MOTOR1_STEP_Pin, MOTOR1_DIR_Pin},
			{MOTOR2_STEP_Pin, MOTOR2_DIR_Pin}
	};
	GPIO_TypeDef  *ports[STEPPER_N][2]={
			{MOTOR0_STEP_GPIO_Port, MOTOR0_DIR_GPIO_Port},
			{MOTOR1_STEP_GPIO_Port, MOTOR1_DIR_GPIO_Port},
			{MOTOR2_STEP_GPIO_Port, MOTOR2_DIR_GPIO_Port}
	};

	int		s_limits[STEPPER_N][3]={
			{MOTOR0_MAX_SPEED, MOTOR0_MIN_SPEED, MOTOR0_MAX_ACCEL},
			{MOTOR1_MAX_SPEED, MOTOR1_MIN_SPEED, MOTOR1_MAX_ACCEL},
			{MOTOR2_MAX_SPEED, MOTOR2_MIN_SPEED, MOTOR2_MAX_ACCEL}
	};

	int		p_limits[STEPPER_N][2]={
			{MOTOR0_MAX_POSITION,MOTOR0_MIN_POSITION},
			{MOTOR1_MAX_POSITION,MOTOR1_MIN_POSITION},
			{MOTOR2_MAX_POSITION,MOTOR2_MIN_POSITION}
		};

	for(int i=0;i<STEPPER_N;i++){
		motors[i].step_pin=pins[i][0];
		motors[i].dir_pin=pins[i][1];

		motors[i].step_port=(GPIO_TypeDef *)ports[i][0];
		motors[i].dir_port=(GPIO_TypeDef *)ports[i][1];

		motors[i].max_speed=s_limits[i][0];
		motors[i].min_speed=s_limits[i][0];
		motors[i].max_accel=s_limits[i][1];
		motors[i].max_positon=p_limits[i][0];
		motors[i].min_position=p_limits[i][0];

		motors[i].enabled = 0;
		motors[i].step = 2;
	}
}
void s_step(uint16_t motor){

	if(motors[motor].timer_period==0 || motors[motor].enabled != 1)return;
	if(steps >= 2*200)return;

	motors[motor].timer_counter+=1;

	if(motors[motor].timer_counter == motors[motor].timer_period){
		HAL_GPIO_TogglePin((GPIO_TypeDef *) motors[motor].step_port, motors[motor].step_pin);
		steps++;
		motors[motor].timer_counter=0;
	}

}

void s_stepAll(){

	for(int i=0;i<STEPPER_N;i++){

		if(motors[i].timer_period==0 || motors[i].enabled != 1)continue;
		motors[i].timer_counter+=1;

		if(motors[i].timer_counter == motors[i].timer_period){
			HAL_GPIO_TogglePin((GPIO_TypeDef *) motors[i].step_port, motors[i].step_pin);
			motors[i].timer_counter=0;
		}
	}

}

void s_updatePosition(uint16_t motor){
	encoder_read(&(motors[motor].position),motor);
}

void s_updateAllPosition(){
	for(int i=0;i<STEPPER_N;i++){
		encoder_read(&(motors[i].position),i);
	}
}


//speed = 100 -> 1 revolution per second
void s_setSpeed(uint16_t motor,int speed){
	stepper stepper1=motors[motor];
	int speed1;

	speed1=100000/(4*stepper1.step*speed);

	if(speed1>stepper1.max_speed || speed1<stepper1.min_speed)return;
	motors[motor].timer_period=speed1;
}

void s_changeDir(uint16_t motor){
	HAL_GPIO_TogglePin(motors[motor].dir_port, motors[motor].dir_pin);
}

void s_enable(uint16_t motor){
	motors[motor].enabled=1;
}

void s_enableAll(){
	for(int i=0;i<STEPPER_N;i++){
			motors[i].enabled=1;
	}
}

void s_disable(uint16_t motor){
	motors[motor].enabled=0;
}

void s_disableAll(){
	for(int i=0;i<STEPPER_N;i++){
				motors[i].enabled=0;
	}
}

#endif /* STEPPER_LIB_C_ */

