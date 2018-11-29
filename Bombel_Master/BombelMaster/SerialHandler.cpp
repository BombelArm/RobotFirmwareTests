#include "SerialHandler.h"




bool SerialHandler::Send_(std::string & data)
{
	if (BombelArm->isConnected())
	{
		BombelArm->writeSerialPort(data.c_str(), data.size());
		return true;
	}
	return false;
}



void SerialHandler::Recive_()
{
	if (BombelArm->isConnected())
	{
		Sleep(10);
		char buf_[RECIEVED_DATA_SIZE];
		BombelArm->readSerialPort(buf_, RECIEVED_DATA_SIZE);
		buffer_ = buf_;
	}
}

int SerialHandler::Read_(std::string & data)
{
	buffer_.clear();
	Recive_();
	if (buffer_.empty())
	{
		return 0;
	}
	else
	{
		data = buffer_;
		return 1;
	}
}
void SerialHandler::connect(std::string &data)
{
	int wait_time = 0;
	BombelArm = new SerialPort(data.c_str());
	while (!BombelArm->isConnected() || wait_time > 10)
	{

		wait_time++;
		if (wait_time == 10)
		{
			Sleep(1000);
			std::cout << "failed to connect" << std::endl;
			return;
		}
	}
	if (BombelArm->isConnected())
	{
		std::string data = "SYN\n";
		Send_(data);
		Recive_();

		if (buffer_.compare("SYN-ACK\n") == 0)
		{
			std::string data = "ACK\n";
			Send_(data);
			Recive_();
			if (buffer_.compare("OK\n") == 0)
			{
				std::cout << "Handshake established" << std::endl;
				is_connected_ = true;
			}
			else if (buffer_.compare("ERROR\n") == 0)
			{
				std::cout << "Error: Message not recieved correctly" << std::endl;
			}
			else
			{
				std::cout << "unexpected feedback: \"" << buffer_ << "\"" << std::endl;
			}
		}
		else if (buffer_.compare("ERROR\n") == 1)
		{
			std::cout << "Error: Message not recieved correctly" << std::endl;
		}
		else
		{
			std::cout << "unexpected feedback: \" " << buffer_ << "\"" << std::endl;
		}
	}

};

bool SerialHandler::Is_connected()
{
	return is_connected_;
}
