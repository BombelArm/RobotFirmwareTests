/*
 * Validator.cpp
 *
 *  Created on: Dec 18, 2018
 *      Author: michal
 */

#include "bomblos/Validator.hpp"
#include "stdint.h"

Validator::Validator(
		uint32_t vel_j0,
		uint32_t vel_j1,
		uint32_t vel_j2,
		uint32_t pos_j0,
		uint32_t pos_j1,
		uint32_t pos_j2	):
prev_vel_j0(vel_j0),
prev_vel_j1(vel_j1),
prev_vel_j2(vel_j2),
prev_pos_j0(pos_j0),
prev_pos_j1(pos_j1),
prev_pos_j2(pos_j2),
error_register()
{
}

uint8_t Validator::validate(	uint32_t vel_j0,
						uint32_t vel_j1,
						uint32_t vel_j2,
						uint32_t pos_j0,
						uint32_t pos_j1,
						uint32_t pos_j2	){
	uint8_t order_valid = true;
	uint32_t errors = 0;

	uint32_t acc_j0 = vel_j0 - prev_vel_j0;
	uint32_t acc_j1 = vel_j1 - prev_vel_j1;
	uint32_t acc_j2 = vel_j2 - prev_vel_j2;

	if(acc_j0 > ACC_JOINT1_LIMIT){
		errors++;
		order_valid = false;
	}
	if(acc_j1 > ACC_JOINT2_LIMIT){
		errors++;
		order_valid = false;
	}
	if(acc_j2 > ACC_JOINT2_LIMIT){
		errors++;
		order_valid = false;
	}
	if(vel_j0 > VEL_JOINT0_MAX){
		errors++;
		order_valid = false;
	}
	if(vel_j1 > VEL_JOINT1_MAX){
		errors++;
		order_valid = false;
	}
	if(vel_j2 > VEL_JOINT2_MAX){
		errors++;
		order_valid = false;
	}
	if(vel_j0 > VEL_JOINT0_MAX){
		errors++;
		order_valid = false;
	}
	if(vel_j1 > VEL_JOINT1_MAX){
		errors++;
		order_valid = false;
	}
	if(vel_j2 > VEL_JOINT2_MAX){
		errors++;
		order_valid = false;
	}
	if(vel_j0 < VEL_JOINT0_MIN){
		errors++;
		order_valid = false;
	}
	if(vel_j1 < VEL_JOINT1_MIN){
		errors++;
		order_valid = false;
	}
	if(vel_j2 < VEL_JOINT2_MIN){
		errors++;
		order_valid = false;
	}
	if(pos_j0 > POS_JOINT0_MAX){
		errors++;
		order_valid = false;
	}
	if(pos_j1 > POS_JOINT1_MAX){
		errors++;
		order_valid = false;
	}
	if(pos_j2 > POS_JOINT2_MAX){
		errors++;
		order_valid = false;
	}
	if(pos_j0 < POS_JOINT0_MIN){
		errors++;
		order_valid = false;
	}
	if(pos_j1 < POS_JOINT1_MIN){
		errors++;
		order_valid = false;
	}
	if(pos_j2 < POS_JOINT2_MIN){
		errors++;
		order_valid = false;
	}

	if(order_valid){
		prev_vel_j0 = vel_j0;
		prev_vel_j1 = vel_j1;
		prev_vel_j2 = vel_j2;

		prev_pos_j0 = pos_j0;
		prev_pos_j1 = pos_j1;
		prev_pos_j2 = pos_j2;

	}

	return order_valid;
}

std::vector<ValidatorError> Validator::getErrorRegister(){
	return error_register;
}
