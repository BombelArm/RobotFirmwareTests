/*! \file
 * \brief Motion controler source code.
 */


#include "motion_control.h"



void m_motionControllerInit(){
	float p_limits[JOINTS_N][2]={
			{JOINT0_MAX_POSITION, JOINT0_MIN_POSITION},
			{JOINT1_MAX_POSITION, JOINT1_MIN_POSITION},
			{JOINT2_MAX_POSITION, JOINT2_MIN_POSITION}
	};

	float a_limits[JOINTS_N]={
			JOINT0_MAX_ACCEL,
			JOINT1_MAX_ACCEL,
			JOINT2_MAX_ACCEL
	};

	int		s_limits[JOINTS_N][2]={
			{JOINT0_MAX_SPEED, JOINT0_MIN_SPEED},
			{JOINT1_MAX_SPEED, JOINT1_MIN_SPEED},
			{JOINT2_MAX_SPEED, JOINT2_MIN_SPEED}
	};

	m_updateAllPosition();

	for(int i=0;i<JOINTS_N;i++){
		motion_nodes[i].max_position=p_limits[i][0];
		motion_nodes[i].min_position=p_limits[i][1];

		motion_nodes[i].max_accel=a_limits[i];
		motion_nodes[i].max_speed=s_limits[i][0];
		motion_nodes[i].min_speed=s_limits[i][1];

		motion_nodes[i].position_reached=1;
		motion_nodes[i].goal_position=motion_nodes[i].actual_position;
	}
}

void m_control(){
	float position,goalPosition;

	for(int i=0;i<JOINTS_N;i++){
		if(motion_nodes[i].enabled != 1)continue;

		position=motion_nodes[i].actual_position;
		goalPosition=motion_nodes[i].goal_position;

		if(position >= goalPosition+EPSILON){
			s_changeDir(i,0);
			s_setSpeed(i,120);
		}else if(position <= goalPosition-EPSILON){
			s_changeDir(i,1);
			s_setSpeed(i,120);
		}else{
			s_setSpeed(i,0);
			motion_nodes[i].position_reached = 1;
		}
	}
	t_exec();
}

void m_updatePosition(uint8_t motor){
	e_read(&(motion_nodes[motor].actual_position),motor);
}

void m_updateAllPosition(){
	for(int i=0;i<JOINTS_N;i++){
		e_read(&(motion_nodes[i].actual_position),i);

	}
}

void m_setPosition(uint8_t motor,float position){
	if(position > motion_nodes[motor].max_position || position<motion_nodes[motor].min_position)return;

	if(motion_nodes[motor].goal_position != position){
		motion_nodes[motor].goal_position=position;
		motion_nodes[motor].position_reached = 0;
	}


}

int m_calculateSpeed(uint8_t motor,uint32_t speed){
	float 		distanceLeft;
	uint32_t	speed1;
	motion_node m_node=motion_nodes[motor];

	/*if(speed>m_node.max_speed){
		speed1=m_node.max_speed;
	}else if(speed<m_node.min_speed){
		speed1=m_node.min_speed;
	}*/
	distanceLeft=abs(m_node.actual_position-m_node.goal_position);

	if(distanceLeft<ACCEL_DISTANCE){

	}else if(distanceLeft>ACCEL_DISTANCE){

	}
	return 0;
}

void m_enable(uint8_t motor){
	motion_nodes[motor].enabled=1;
}
void m_enableAll(){
	for(int i=0;i<JOINTS_N;i++){
		motion_nodes[i].enabled=1;
	}


}
void m_disable(uint8_t motor){
	motion_nodes[motor].enabled=0;
}
void m_disableAll(){
	for(int i=0;i<JOINTS_N;i++){
			motion_nodes[i].enabled=0;
	}
}
