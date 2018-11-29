#pragma once
#include <vector>
#include "SerialHandler.h"
#ifndef MANIPULATOR
#define MANIPULATOR


struct config_type
{
	float speed_val_;
	int accel_val_;
	bool update_;
	config_type();

};

class Hinge_type
{

public:
	 virtual int update(int acc, int V_max)=0;		//synchronises data with arm returns 1 if succesfull 0 if not
	 virtual void set_pos(float pos)=0;	//sets position
	 virtual float read_pos(void)=0;		//returns data from pos
	 virtual void set_real_pos(float pos)=0;
	 virtual bool is_fin()=0;
	
};
class stepper_motor :public Hinge_type
{
private:
	int number_;
	float set_pos_;										//position that is send to arm
	float real_pos_;									// position that is recieved from arm
	SerialHandler Bombel;
public:
	config_type config;
	int update(int acc, int V_max);									//updates acc and V_max vals
	void set_pos(float pos);										//sets position
	void set_real_pos(float pos);
	float read_pos(void);								//returns data from pos
	bool is_fin();
	stepper_motor(SerialHandler& Bombel_,int num, int acc, int V_max);
	stepper_motor(SerialHandler& Bombel_,int num);

};

class servo_motor :public Hinge_type
{

private:
	int number_;
	float set_pos_;		//position that is send to arm
	float real_pos_;	// position that is recieved from arm
public:
	int update( int acc, int V_max);		//synchronises data with arm returns 1 if succesfull 0 if not
	 void set_pos(float pos);	//sets position
	 float read_pos(void);		//returns data from pos
};

class Arm_type  
{

private:
	SerialHandler Bombel;
	std::vector<Hinge_type*> Hinges_;
	int Degrees_of_freedom_;
	bool init_flag;
	void move(int mot_, float pos_);

public:
	Arm_type(std::string port);
	void update();
	void begin_movement(int mot_no_, float pos_);				// set position for arm to execute.
	int is_movment_fin();				// returns 1 if movment is still in progress
	void stop();						// hold position
	void disable();						// disables arm
	void init_arm(config_type config);	// inits all hinges with vector of config files.
	void init_arm();					// inits all hinges with default values. And sets internal angle of motors to 0.0f
};
#endif // !MANIPULATOR