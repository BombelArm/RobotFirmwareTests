#include <bomblos/Communicator.hpp>

Communicator::Communicator():
	status_pub(STATUS_PUB_NAME,&status_msg),
	cmd_sub(CMD_SUB_NAME,&Communicator::cmd_callback,this)
{
	nh.initNode();
	nh.advertise(status_pub);
	nh.subscribe(cmd_sub);

}

void Communicator::cmd_callback(const std_msgs::UInt64& cmd_msg){
	status_msg.data = cmd_msg.data;
	status_pub.publish(&status_msg);

	HAL_GPIO_TogglePin(IHM02A1_CS0_GPIO_Port,IHM02A1_CS0_Pin);
}

ros::NodeHandle& Communicator::getNodeHandle(){
	return nh;
}

void Communicator::desync_callback(){}
void Communicator::start_counter(){}
void Communicator::reset_counter(){}

void Communicator::spinOnce(){
	nh.spinOnce();
}
