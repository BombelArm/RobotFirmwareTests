/*! \file
 * \brief Stepper source code.
 */


#ifndef STEPPER_LIB_C_
#define STEPPER_LIB_C_

#include "stepper_lib.h"

void s_motorsInit(){
	stepper *s_node;

	uint16_t pins[JOINTS_N][2]={
			{MOTOR0_STEP_Pin, MOTOR0_DIR_Pin},
			{MOTOR1_STEP_Pin, MOTOR1_DIR_Pin},
			{MOTOR2_STEP_Pin, MOTOR2_DIR_Pin}
	};
	GPIO_TypeDef  *ports[JOINTS_N][2]={
			{MOTOR0_STEP_GPIO_Port, MOTOR0_DIR_GPIO_Port},
			{MOTOR1_STEP_GPIO_Port, MOTOR1_DIR_GPIO_Port},
			{MOTOR2_STEP_GPIO_Port, MOTOR2_DIR_GPIO_Port}
	};

	uint8_t	directions[JOINTS_N]={
			1,
			1,
			1
	};

	uint8_t steps[JOINTS_N]={
			16,
			32,
			8
	};

	for(int i=0;i<JOINTS_N;i++){
		s_node=&(motors[i]);

		(*s_node).step_pin=pins[i][0];
		(*s_node).dir_pin=pins[i][1];

		(*s_node).step_port=(GPIO_TypeDef *)ports[i][0];
		(*s_node).dir_port=(GPIO_TypeDef *)ports[i][1];

		(*s_node).max_speed=HW_MOTOR_MAX_SPEED;
		(*s_node).min_speed=HW_MOTOR_MIN_SPEED;
		(*s_node).direction=directions[i];

		(*s_node).enabled = 0;
		(*s_node).step = steps[i];
	}
}
void s_step(uint8_t motor){
	stepper *s_node=&(motors[motor]);

	if(motor> JOINTS_N)return;

	if((*s_node).timer_period==0 || (*s_node).enabled != 1)return;

	(*s_node).timer_counter+=1;

	if((*s_node).timer_counter == (*s_node).timer_period){
		HAL_GPIO_TogglePin((GPIO_TypeDef *) (*s_node).step_port, (*s_node).step_pin);
		(*s_node).timer_counter=0;
	}

}

void s_stepAll(){
	stepper *s_node;

	for(int i=0;i<JOINTS_N;i++){
		s_node=&(motors[i]);

		if((*s_node).timer_period==0 || (*s_node).enabled != 1)continue;
		(*s_node).timer_counter+=1;

		if((*s_node).timer_counter == (*s_node).timer_period){
			HAL_GPIO_TogglePin((GPIO_TypeDef *) (*s_node).step_port, (*s_node).step_pin);
			(*s_node).timer_counter=0;
		}
	}

}


//speed = 100 -> 1 revolution per second
void s_setSpeed(uint8_t motor,uint32_t speed){
	stepper stepper1=motors[motor];
	int speed1;

	if(motor> JOINTS_N)return;

	if(speed == 0){
		speed1=0;
	}else if(speed>stepper1.max_speed){
		speed1=100000/(2*stepper1.step*stepper1.max_speed);
	}else if(speed<stepper1.min_speed){
		speed1=100000/(2*stepper1.step*stepper1.min_speed);
	}else{
		speed1=100000/(2*stepper1.step*speed);
	}

	motors[motor].timer_period=speed1;
}

void s_changeDir(uint8_t motor,uint8_t dir){
	if(dir==1){
		HAL_GPIO_WritePin(motors[motor].dir_port, motors[motor].dir_pin, motors[motor].direction);
	}else if(dir==0){
		HAL_GPIO_WritePin(motors[motor].dir_port, motors[motor].dir_pin, !motors[motor].direction);
	}
}

void s_enable(uint8_t motor){
	if(motor> JOINTS_N)return;
	motors[motor].enabled=1;
}

void s_enableAll(){
	for(int i=0;i<JOINTS_N;i++){
			motors[i].enabled=1;
	}
}

void s_disable(uint8_t motor){
	if(motor> JOINTS_N)return;
	motors[motor].enabled=0;
}

void s_disableAll(){
	for(int i=0;i<JOINTS_N;i++){
				motors[i].enabled=0;
	}
}

#endif /* STEPPER_LIB_C_ */

