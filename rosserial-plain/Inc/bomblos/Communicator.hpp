/*
 * communicator.hpp
 *
 *  Created on: Nov 20, 2018
 *      Author: michal
 */

#ifndef BOMBLOS_COMMUNICATOR_HPP_
#define BOMBLOS_COMMUNICATOR_HPP_

#include <ros.h>
#include <std_msgs/UInt64.h>
#include <std_msgs/UInt32.h>

#define CMD_SUB_NAME "bombel/cmd_sub"
#define STATUS_PUB_NAME "bombel/status_pub"

class Communicator
{
	private:

		ros::NodeHandle nh;

		std_msgs::UInt64  	status_msg;

		ros::Publisher		status_pub;

		ros::Subscriber<std_msgs::UInt64, Communicator> 	cmd_sub;

		void cmd_callback(const std_msgs::UInt64& cmd_msg);

	public:
		Communicator();
		ros::NodeHandle& getNodeHandle();
		void spinOnce();

};


#endif /* BOMBLOS_COMMUNICATOR_HPP_ */
