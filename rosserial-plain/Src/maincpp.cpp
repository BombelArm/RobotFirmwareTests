/*
 * maincpp.cpp
 *
 *  Created on: 04.07.2018
 *      Author: mromanow
 */


#include "maincpp.h"
#include "xnucleoihm02a1.h"
#include <cstddef>
#include "motors_param.h"
#include <ros.h>
#include <std_msgs/UInt64.h>
#include <std_msgs/UInt32.h>
#include <std_msgs/String.h>
#include <bomblos/Communicator.hpp>
#include <bombel_msgs/AddTwoInts.h>


//extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim3;

ros::NodeHandle nh;
MotorParameterData_t *MotorParameterDataGlobal;
StepperMotorBoardHandle_t *StepperMotorBoardHandle;

void init_motors();
void set_speed(int,int);
void set_position(int,int);
void soft_stop(int);
void hard_stop(int);
uint32_t get_abs_pos(int);
sL6470_StatusRegister_t get_status(int);

Communicator *c1;

void bombel_callback(const bombel_msgs::AddTwoIntsRequest &req, bombel_msgs::AddTwoIntsResponse &res){
	res.Sum = 2;
}

ros::ServiceServer<bombel_msgs::AddTwoIntsRequest,bombel_msgs::AddTwoIntsResponse> server("add_two_ints",&bombel_callback);

void TIM3_PeriodElapsedCallback(){
//	c1->getCounter().inc();
}
void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart){
//	c1->getNodeHandle().getHardware()->flush();
	nh.getHardware()->flush();
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
//	c1->getNodeHandle().getHardware()->reset_rbuf();
	nh.getHardware()->reset_rbuf();
}
void setup(void)
{
//	c1 = new Communicator();
//	nh = &(c1->getNodeHandle());
//	nh = new ros::NodeHandle();
	nh.initNode();
	nh.advertiseService(server);
	HAL_TIM_Base_Start_IT(&htim3);
}

void loop(void)
{
	nh.spinOnce();
//	for(int i=0; i<9999999999;i++);
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

void set_position(int motor, int position){
	MotorParameterData_t *MotorParameterDataSingle;
	uint8_t board, device;
	uint32_t _speed;

	board = EXPBRD_ID(0);
	device = L6470_ID(motor);

	MotorParameterDataSingle = MotorParameterDataGlobal+((board*L6470DAISYCHAINSIZE)+device);

	StepperMotorBoardHandle->StepperMotorDriverHandle[device]->Command->PrepareGoTo(device, position);
	StepperMotorBoardHandle->Command->PerformPreparedApplicationCommand();

}

void soft_stop(int motor){
	MotorParameterData_t *MotorParameterDataSingle;
	uint8_t board, device;
	uint32_t _speed;

	board = EXPBRD_ID(0);
	device = L6470_ID(motor);

	MotorParameterDataSingle = MotorParameterDataGlobal+((board*L6470DAISYCHAINSIZE)+device);

	StepperMotorBoardHandle->StepperMotorDriverHandle[device]->Command->PrepareSoftHiZ(device);
	StepperMotorBoardHandle->Command->PerformPreparedApplicationCommand();
}

void hard_stop(int motor){
	MotorParameterData_t *MotorParameterDataSingle;
	uint8_t board, device;
	uint32_t _speed;

	board = EXPBRD_ID(0);
	device = L6470_ID(motor);

	MotorParameterDataSingle = MotorParameterDataGlobal+((board*L6470DAISYCHAINSIZE)+device);

	StepperMotorBoardHandle->StepperMotorDriverHandle[device]->Command->PrepareHardHiZ(device);
	StepperMotorBoardHandle->Command->PerformPreparedApplicationCommand();
}

uint32_t get_abs_pos(int motor){
	MotorParameterData_t *MotorParameterDataSingle;
	uint8_t board, device;
	uint32_t _speed;



	board = EXPBRD_ID(0);
	device = L6470_ID(motor);

	MotorParameterDataSingle = MotorParameterDataGlobal+((board*L6470DAISYCHAINSIZE)+device);

	return StepperMotorBoardHandle->StepperMotorDriverHandle[device]->Command->GetParam(device,L6470_ABS_POS_ID);
}

sL6470_StatusRegister_t get_status(int motor){
	union{
		uint16_t resp;
		sL6470_StatusRegister_t reg;
	}parser;
	uint8_t board, device;

	board = EXPBRD_ID(0);
	device = L6470_ID(motor);

	parser.resp=(uint16_t) StepperMotorBoardHandle->StepperMotorDriverHandle[device]->Command->GetParam(device,L6470_STATUS_ID);

	return parser.reg;
}


