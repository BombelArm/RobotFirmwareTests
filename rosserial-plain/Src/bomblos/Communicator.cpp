#include <bomblos/Communicator.hpp>

Communicator::Communicator():
	counter(MSG_PERIOD ,&Communicator::desync_callback, this),
	status_pub(STATUS_PUB_NAME, &status_msg),
	cmd_sub(CMD_SUB_NAME, &Communicator::cmd_callback, this)
{
	nh.initNode();
	HAL_GPIO_WritePin(LED_GPIO_Port,LED_Pin,GPIO_PIN_RESET);
	//publishers
	nh.advertise(status_pub);

	//subscribers
	nh.subscribe(cmd_sub);
}

void Communicator::cmd_callback(const std_msgs::UInt64& cmd_msg){
	counter.resetState();

}

ros::NodeHandle& Communicator::getNodeHandle(){
	return nh;
}

Counter<Communicator>& Communicator::getCounter(){
	return counter;
}

void Communicator::desync_callback(){
//	HAL_GPIO_WritePin(LED_GPIO_Port,LED_Pin,GPIO_PIN_SET);
}

