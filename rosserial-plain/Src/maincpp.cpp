/*
 * maincpp.cpp
 *
 *  Created on: 04.07.2018
 *      Author: mromanow
 */


#include "maincpp.h"
#include "xnucleoihm02a1.h"
#include <cstddef>
#include <ros.h>
#include <std_msgs/UInt64.h>
#include <std_msgs/UInt32.h>
#include <std_msgs/String.h>
#include <bomblos/Communicator.hpp>
#include <bombel_msgs/AddTwoInts.h>


//extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim3;

ros::NodeHandle nh;

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


