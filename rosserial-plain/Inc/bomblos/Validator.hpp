/*
 * Validator.hpp
 *
 *  Created on: Dec 18, 2018
 *      Author: michal
 */

#ifndef BOMBLOS_VALIDATOR_HPP_
#define BOMBLOS_VALIDATOR_HPP_

#include "stdint.h"
#include <vector>

#define ACC_JOINT1_LIMIT 0
#define ACC_JOINT0_LIMIT 0
#define ACC_JOINT2_LIMIT 0

#define VEL_JOINT0_MIN 0
#define VEL_JOINT1_MIN 0
#define VEL_JOINT2_MIN 0

#define VEL_JOINT0_MAX 0
#define VEL_JOINT1_MAX 0
#define VEL_JOINT2_MAX 0

#define POS_JOINT0_MIN 0
#define POS_JOINT1_MIN 0
#define POS_JOINT2_MIN 0

#define POS_JOINT0_MAX 0
#define POS_JOINT1_MAX 0
#define POS_JOINT2_MAX 0

enum ValidatorErrorName{
	acc_joint0=1,
	acc_joint1,
	acc_joint2,
	vel_joint0_min,
	vel_joint1_min,
	vel_joint2_min,
	vel_joint0_max,
	vel_joint1_max,
	vel_joint2_max,
	pos_joint0_min,
	pos_joint1_min,
	pos_joint2_min,
	pos_joint0_max,
	pos_joint1_max,
	pos_joint2_max,
};

typedef struct ValidatorError{
	ValidatorErrorName name;
	uint32_t	value;
	uint32_t	acceptable_value;
} ValidatorError;

class Validator{
private:
	uint32_t prev_vel_j0;
	uint32_t prev_vel_j1;
	uint32_t prev_vel_j2;

	uint32_t prev_pos_j0;
	uint32_t prev_pos_j1;
	uint32_t prev_pos_j2;

	std::vector<ValidatorError> error_register;

public:
	Validator(	uint32_t vel_j0,
				uint32_t vel_j1,
				uint32_t vel_j2,
				uint32_t pos_j0,
				uint32_t pos_j1,
				uint32_t pos_j2	);

	uint8_t validate(	uint32_t vel_j0,
						uint32_t vel_j1,
						uint32_t vel_j2,
						uint32_t pos_j0,
						uint32_t pos_j1,
						uint32_t pos_j2	);

	std::vector<ValidatorError> getErrorRegister();
};



#endif /* BOMBLOS_VALIDATOR_HPP_ */
