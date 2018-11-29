#include "Manipulator.h"
#include <string>
#include <vector>
#include <sstream>
#include <stdlib.h>

Arm_type::Arm_type(std::string port)
{
	Bombel.connect(port);
	std::string tmp_ = "SYS_INFO\n";
	Bombel.Send_(tmp_);
	init_flag = 0;
}

void Arm_type::update()
{
	std::string tmp;
	tmp = "SYS_INFO\n";
	Bombel.Send_(tmp);
	float rel_pos[3];
	tmp.clear();
	Sleep(10);
	if (Bombel.Read_(tmp))
	{
		sscanf_s(tmp.c_str(), "M1: %f\nM2: %f\nM3: %f\n", &rel_pos[0], &rel_pos[1], &rel_pos[2]);
	}
	std::cout <<"POS 1:"<< rel_pos[0] <<std::endl
		<<"POS 2:"<< rel_pos[1]<< std::endl 
		<<"POS 3:"<< rel_pos[2] << std::endl;
	for (int i = 0; i < 2; i++)
	{
		Hinges_[i]->set_real_pos(rel_pos[i]);
	}
}

void Arm_type::begin_movement(int mot_no_, float pos_)
{
	std::string tmp,val;
	std::ostringstream ss;
	Hinges_[mot_no_]->set_pos(pos_);
	tmp = "MSP\n";
	Bombel.Send_(tmp);

	ss << mot_no_;
	val = ss.str();
	tmp = val+"\n";
	Bombel.Send_(tmp);

	ss.str("");
	val.clear();
	tmp.clear();
	
	ss << pos_;
	val = ss.str();
	tmp = val+"\n";
	Bombel.Send_(tmp);

	tmp = "FIN\n";
	Bombel.Send_(tmp);
	tmp.clear();
	Sleep(10);
	Bombel.Read_(tmp);
	if (tmp.compare("OK\n"))
	{
		std::cout << "data transmited\n";
	}
	else
	{
		std::cout << "data not transmited\n";
	}
}

int Arm_type::is_movment_fin()
{
/*	int is_fin=0;
	for (int i = 0; i < 2; i++)
	{	
		is_fin = is_fin + Hinges_[i]->is_fin();	
	}
	if(is_fin==3)
	{
		return true;
	}
	*/
	return Hinges_[0]->is_fin();
}

void Arm_type::disable()
{
	std::string tmp = "REST\n";
	Bombel.Send_(tmp);
}

void Arm_type::init_arm(config_type config)
{

}

void Arm_type::init_arm()
{
	
	if (!init_flag)
	{
		Hinges_.push_back(new stepper_motor(Bombel,0));
		Hinges_.push_back(new stepper_motor(Bombel,1));
		Hinges_.push_back(new stepper_motor(Bombel,2));
		init_flag = 1;
	}
	for (int i=0; i < 3; i++)
	{
		Hinges_[i]->set_pos(0.0f);
	}
		std::string tmp = "INIT_ALL\n";
	Bombel.Send_(tmp);
}

void stepper_motor::set_pos(float pos)
{
	std::string tmp, val;
	std::ostringstream ss;
	tmp = "MSP\n";
	Bombel.Send_(tmp);

	ss << number_;
	val = ss.str();
	tmp = val + "\n";
	Bombel.Send_(tmp);

	ss.str("");
	val.clear();
	tmp.clear();
	set_pos_ = pos;
	ss << set_pos_;
	val = ss.str();

	tmp = val + "\n";
	Bombel.Send_(tmp);

	tmp = "FIN\n";
	Bombel.Send_(tmp);
}

void stepper_motor::set_real_pos(float pos)
{
	real_pos_ = pos;
}

float stepper_motor::read_pos()
{
	return 0.0f;
}

bool stepper_motor::is_fin()
{
	if (abs(set_pos_ - real_pos_) < 0.15)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int stepper_motor::update(int acc, int V_max)
{
	return 0;
}

stepper_motor::stepper_motor(SerialHandler& Bombel_,int num, int acc, int V_max)
{
	Bombel = Bombel_;
	config.accel_val_ = acc;
	number_ = num;
	config.speed_val_ = V_max;
}

stepper_motor::stepper_motor(SerialHandler& Bombel_,int num)
{
	Bombel = Bombel_;
	number_ = num;
}

int servo_motor::update(int acc, int V_max)
{
	return 0;
}

void servo_motor::set_pos(float pos)
{

}

float servo_motor::read_pos(void)
{
	return 0.0f;
}

config_type::config_type()
{

}
