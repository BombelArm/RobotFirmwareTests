/*
 * maincpp.cpp
 *
 *  Created on: 04.07.2018
 *      Author: mromanow
 */

#include "maincpp.h"
#include <ros.h>
#include <std_msgs/String.h>

extern TIM_HandleTypeDef htim2;
ros::NodeHandle nh;

std_msgs::String str_msg;
uint32_t time=0;
ros::Publisher chatter("chatter", &str_msg);
char hello[] = "Hello world!";

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart){
  nh.getHardware()->flush();
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
  nh.getHardware()->reset_rbuf();
}

void setup(void)
{
  nh.initNode();
  nh.advertise(chatter);
}

void loop(void)
{
//  HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_3);

  str_msg.data = hello;
  chatter.publish(&str_msg);
  nh.spinOnce();
  HAL_Delay(1000);
}


