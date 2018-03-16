/*
 * motion_control.c
 *
 *  Created on: 13.03.2018
 *      Author: mromanow
 */

#include "motion_control.h"



void m_motionControllerInit(){
	float p_limits[STEPPER_N][2]={
			{MOTOR0_MAX_POSITION, MOTOR0_MIN_POSITION},
			{MOTOR1_MAX_POSITION, MOTOR1_MIN_POSITION},
			{MOTOR2_MAX_POSITION, MOTOR2_MIN_POSITION}
	};

	float a_limits[STEPPER_N]={
			MOTOR0_MAX_ACCEL,
			MOTOR1_MAX_ACCEL,
			MOTOR2_MAX_ACCEL
	};

	int		s_limits[STEPPER_N][2]={
			{MOTOR0_MAX_SPEED, MOTOR0_MIN_SPEED},
			{MOTOR1_MAX_SPEED, MOTOR1_MIN_SPEED},
			{MOTOR2_MAX_SPEED, MOTOR2_MIN_SPEED}
	};

	for(int i=0;i<STEPPER_N;i++){
		motion_nodes[i].max_position=p_limits[i][0];
		motion_nodes[i].min_position=p_limits[i][1];

		motion_nodes[i].max_accel=a_limits[i];
		motion_nodes[i].max_speed=s_limits[i][0];
		motion_nodes[i].min_speed=s_limits[i][1];
	}

}

void m_control(){
	float position,goalPosition;

	for(int i=0;i<STEPPER_N;i++){
		if(motion_nodes[i].enabled != 1)continue;

		position=motion_nodes[i].position;
		goalPosition=motion_nodes[i].goal_position;

/*		if(position <= motion_nodes[i].min_position+EPSILON){
			s_disable(i);
		}else if(position >= motion_nodes[i].max_position-EPSILON){
			s_disable(i);
		}else{
			s_enable(i);
		}*/

		if(position >= goalPosition+EPSILON){
			s_changeDir(i,0);
			s_setSpeed(i,40);
		}else if(position <= goalPosition-EPSILON){
			s_changeDir(i,1);
			s_setSpeed(i,40);
		}else{
			s_setSpeed(i,0);
		}
	}
}

void m_updatePosition(uint16_t motor){
	e_read(&(motion_nodes[motor].position),motor);
}

void m_updateAllPosition(){
	for(int i=0;i<STEPPER_N;i++){
		e_read(&(motion_nodes[i].position),i);

	}
}

void m_setPosition(uint8_t motor,float position){
	if(position > motion_nodes[motor].max_position || position<motion_nodes[motor].min_position)return;

	motion_nodes[motor].goal_position=position;
}

void m_enable(uint8_t motor){
	motion_nodes[motor].enabled=1;
}
void m_enableAll(){
	for(int i=0;i<STEPPER_N;i++){
		motion_nodes[i].enabled=1;
	}
}
void m_disable(uint8_t motor){
	motion_nodes[motor].enabled=0;
}
void m_disableAll(){
	for(int i=0;i<STEPPER_N;i++){
			motion_nodes[i].enabled=0;
	}
}
