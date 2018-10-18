/*
 * maincpp.cpp
 *
 *  Created on: 04.07.2018
 *      Author: mromanow
 */

#include "maincpp.h"
#include "xnucleoihm02a1.h"
#include "motors_param.h"
#include <ros.h>
#include <std_msgs/UInt64.h>


extern TIM_HandleTypeDef htim2;

ros::NodeHandle nh;
uint32_t time=0;
std_msgs::UInt64 v_msg;
ros::Publisher chatter("chatter", &v_msg);

MotorParameterData_t *MotorParameterDataGlobal;
StepperMotorBoardHandle_t *StepperMotorBoardHandle;


void init_motors();
void set_speed(int,int);

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart){
  nh.getHardware()->flush();
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
  nh.getHardware()->reset_rbuf();
}

void msg_received_callback(const std_msgs::UInt64& cmd_msg){
	set_speed(0,cmd_msg.data);
}
ros::Subscriber<std_msgs::UInt64> sub("sub1",msg_received_callback);

void setup(void)
{
	init_motors();
	nh.initNode();
	nh.advertise(chatter);
	nh.subscribe(sub);
}

void loop(void)
{
	nh.spinOnce();
	HAL_Delay(1000);
}


void init_motors(){
	MotorParameterData_t *MotorParameterDataSingle;

	MotorParameterDataGlobal = GetMotorParameterInitData();

	for (uint8_t id = 0; id < EXPBRD_MOUNTED_NR; id++)
	{
		StepperMotorBoardHandle = BSP_GetExpansionBoardHandle(EXPBRD_ID(id));
		MotorParameterDataSingle = MotorParameterDataGlobal+(id*L6470DAISYCHAINSIZE);
		StepperMotorBoardHandle->Config(MotorParameterDataSingle);
	}
}

void set_speed(int motor, int speed){
	MotorParameterData_t *MotorParameterDataSingle;
	uint8_t board, device;
	uint32_t _speed;

	board = EXPBRD_ID(0);
	device = L6470_ID(motor);

	MotorParameterDataSingle = MotorParameterDataGlobal+((board*L6470DAISYCHAINSIZE)+device);
	_speed = Step_s_2_Speed(speed);


	StepperMotorBoardHandle->StepperMotorDriverHandle[device]->Command->PrepareRun(device, L6470_DIR_FWD_ID, _speed);
	StepperMotorBoardHandle->Command->PerformPreparedApplicationCommand();

}
