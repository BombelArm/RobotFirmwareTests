#pragma once
#ifndef SERIAL_HANDLER
#define SERIAL_HANDLER


#include <string>
#include "SerialPort.h"



#define RECIEVED_DATA_SIZE 40


class SerialHandler
{
	std::string buffer_;
	SerialPort * BombelArm;
	bool is_connected_;
	void Recive_();
public:
	
	bool Is_connected();
	SerialHandler() {};
	bool Send_(std::string & data);
	int Read_(std::string & data);
	void connect(std::string &data);	//creates SerialPort and makes handshake with MCU. if succesfull is_connected_== 1
};
#endif // !SERIAL_HANDLER