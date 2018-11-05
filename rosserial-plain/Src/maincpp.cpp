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
#include <std_msgs/UInt32.h>
#include <std_msgs/String.h>
#include <bombel_msgs/L6470_StatusRegister.h>


extern TIM_HandleTypeDef htim2;

ros::NodeHandle nh;
uint32_t time=0;
std_msgs::UInt64 v_msg;
ros::Publisher chatter("chatter", &v_msg);

MotorParameterData_t *MotorParameterDataGlobal;
StepperMotorBoardHandle_t *StepperMotorBoardHandle;


void init_motors();
void set_speed(int,int);
void set_position(int,int);
void soft_stop(int);
void hard_stop(int);
uint32_t get_abs_pos(int);
sL6470_StatusRegister_t get_status(int);

std_msgs::UInt32 stepper_pos;
ros::Publisher abs_pos_pub("stepper_pos", &stepper_pos);

std_msgs::UInt32 loop_time;
ros::Publisher loop_time_pub("loop_time", &loop_time);

bombel_msgs::L6470_StatusRegister status_msg;
ros::Publisher status_pub("bombel_status", &status_msg);

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart){
  nh.getHardware()->flush();
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
  nh.getHardware()->reset_rbuf();
}

void speed_sub_callback(const std_msgs::UInt64& cmd_msg){
	set_speed(0,cmd_msg.data);
	set_speed(1,cmd_msg.data);
}

void position_sub_callback(const std_msgs::UInt64& cmd_msg){
	set_position(0,cmd_msg.data);
	set_position(1,cmd_msg.data);
}

void stop_sub_callback(const std_msgs::UInt64& cmd_msg){
	if(cmd_msg.data == 0){
		hard_stop(0);
		hard_stop(1);
	}else{
		soft_stop(0);
		soft_stop(1);
	}
}

ros::Subscriber<std_msgs::UInt64> speed_sub("stepper_speed",speed_sub_callback);
//ros::Subscriber<std_msgs::UInt64> position_sub("stepper_pos",position_sub_callback);
ros::Subscriber<std_msgs::UInt64> stop_sub("stepper_stop",stop_sub_callback);

uint32_t abs_pos;
int speed;

void setup(void)
{
	init_motors();
	nh.initNode();
//	nh.advertise(abs_pos_pub);
	nh.advertise(status_pub);

//	set_speed(0,100);
	nh.subscribe(speed_sub);
//	nh.subscribe(position_sub);
	nh.subscribe(stop_sub);
}

void loop(void)
{
//	int start,stop;
//
//	start = HAL_GetTick();
//
//	set_speed(0,speed++);
//	stepper_pos.data = get_abs_pos(0);
//	abs_pos_pub.publish(&stepper_pos);
//
//	stop = HAL_GetTick();
//
//
//	loop_time.data = stop;
//	loop_time_pub.publish(&loop_time);
//
//	nh.spinOnce();

	if(!HAL_GPIO_ReadPin(B1_GPIO_Port,B1_Pin)){
		set_speed(0,100);
	}
//	HAL_Delay(1000);

	sL6470_StatusRegister_t status = get_status(0);
	status_msg.HiZ = status.HiZ;
	status_msg.BUSY = status.BUSY;
	status_msg.SW_F = status.SW_F;
	status_msg.SW_EVN = status.SW_EVN;
	status_msg.DIR = status.DIR;
	status_msg.MOT_STATUS = status.MOT_STATUS;
	status_msg.NOTPERF_CMD = status.NOTPERF_CMD;
	status_msg.WRONG_CMD = status.WRONG_CMD;
	status_msg.UVLO = status.UVLO;
	status_msg.TH_WRN = status.TH_WRN;
	status_msg.TH_SD = status.TH_SD;
	status_msg.OCD = status.OCD;
	status_msg.STEP_LOSS_A = status.STEP_LOSS_A;
	status_msg.STEP_LOSS_B = status.STEP_LOSS_B;
	status_msg.SCK_MOD = status.SCK_MOD;
	status_pub.publish(&status_msg);
	nh.spinOnce();
	HAL_Delay(500);
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


