/*
 * communicator.hpp
 *
 *  Created on: Nov 20, 2018
 *      Author: michal
 */

#ifndef BOMBLOS_COMMUNICATOR_HPP_
#define BOMBLOS_COMMUNICATOR_HPP_

#include <bomblos/Counter.hpp>
#include <ros.h>
#include <std_msgs/UInt64.h>
#include <std_msgs/UInt32.h>

#define CMD_SUB_NAME "bombel/command"
#define STATUS_PUB_NAME "bombel/status"
#define MSG_PERIOD 10 //in 10ms == 100Hz


class Communicator
{
	private:

		//ROS
		ros::NodeHandle 	nh;
		std_msgs::UInt64  	status_msg;
		ros::Publisher		status_pub;
		ros::Subscriber<std_msgs::UInt64, Communicator> 	cmd_sub;


		void cmd_callback(const std_msgs::UInt64& cmd_msg);

		//SYNC
		Counter<Communicator> counter; //counts in ms (TIM3)
		void desync_callback();


	public:
		Communicator();
		ros::NodeHandle& 	getNodeHandle();
		Counter<Communicator>&	getCounter();
};


#endif /* BOMBLOS_COMMUNICATOR_HPP_ */
