/*! \file
 * \brief Motion controler source code.
 */


#include "motion_control.h"



void m_motionControllerInit(){
	motion_node *m_node;

	int16_t p_limits[JOINTS_N][2]={
			{JOINT0_MAX_POSITION, JOINT0_MIN_POSITION},
			{JOINT1_MAX_POSITION, JOINT1_MIN_POSITION},
			{JOINT2_MAX_POSITION, JOINT2_MIN_POSITION}
	};

	uint8_t a_limits[JOINTS_N]={
			JOINT0_MAX_ACCEL,
			JOINT1_MAX_ACCEL,
			JOINT2_MAX_ACCEL
	};

	uint8_t	s_limits[JOINTS_N][2]={
			{JOINT0_MAX_SPEED, JOINT0_MIN_SPEED},
			{JOINT1_MAX_SPEED, JOINT1_MIN_SPEED},
			{JOINT2_MAX_SPEED, JOINT2_MIN_SPEED}
	};

	m_updateAllPosition();

	for(int i=0;i<JOINTS_N;i++){
		m_node=&(motion_nodes[i]);

		(*m_node).max_position=p_limits[i][0];
		(*m_node).min_position=p_limits[i][1];

		(*m_node).max_accel=a_limits[i];
		(*m_node).max_speed=s_limits[i][0];
		(*m_node).min_speed=s_limits[i][1];

		(*m_node).position_reached=1;
		(*m_node).goal_position=motion_nodes[i].actual_position;
	}
}

void m_control(){
	int16_t position,goal_position,delta;
	uint8_t goal_speed;
	motion_node *m_node;

	for(int i=0;i<JOINTS_N;i++){
		m_node=&(motion_nodes[i]);

		if((*m_node).enabled != 1)continue;

		position=(*m_node).actual_position;
		goal_position=(*m_node).goal_position;
		goal_speed=(*m_node).goal_speed;
		delta=position-goal_position;

		if(delta >= EPSILON){
			s_changeDir(i,0);
			s_setSpeed(i,goal_speed);
		}else if(delta <= -EPSILON){
			s_changeDir(i,1);
			s_setSpeed(i,goal_speed);
		}else{
			(*m_node).position_reached = 1;
			s_setSpeed(i,0);
		}
	}
	t_exec();
}

uint8_t m_validatePosition(uint8_t joint, uint8_t speed, int16_t position){
	motion_node *m_node=(&motion_nodes[joint]);

	if(joint > JOINTS_N)return 1;

	if(position > (*m_node).max_position || position<(*m_node).min_position || speed>(*m_node).max_speed || speed < (*m_node).min_speed ){
		return 1;
	}else{
		return 0;
	}
}

void m_updatePosition(uint8_t joint){
	if(joint > JOINTS_N)return;
	e_read(&(motion_nodes[joint].actual_position),joint);
}

void m_updateAllPosition(){
	for(int i=0;i<JOINTS_N;i++){
		e_read(&(motion_nodes[i].actual_position),i);

	}
}

void m_setPosition(uint8_t joint,int16_t position, uint8_t goal_speed){
	motion_node *m_node=(&motion_nodes[joint]);

	if(joint > JOINTS_N)return;
	if(m_validatePosition(joint,goal_speed,position) != 0) return;

	if((*m_node).goal_position != position){
		(*m_node).goal_position=position;
		(*m_node).goal_speed=goal_speed;
		(*m_node).position_reached = 0;
	}


}

int m_calculateSpeed(uint8_t joint,uint32_t speed){
	float 		distanceLeft;
	uint32_t	speed1;
	motion_node m_node=motion_nodes[joint];

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

void m_enable(uint8_t joint){
	if(joint > JOINTS_N)return;
	motion_nodes[joint].enabled=1;
}
void m_enableAll(){
	for(int i=0;i<JOINTS_N;i++){
		motion_nodes[i].enabled=1;
	}


}
void m_disable(uint8_t joint){
	if(joint > JOINTS_N)return;
	motion_nodes[joint].enabled=0;
}
void m_disableAll(){
	for(int i=0;i<JOINTS_N;i++){
			motion_nodes[i].enabled=0;
	}
}
