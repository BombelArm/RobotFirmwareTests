/*
 * MotorController.cpp
 *
 *  Created on: Dec 18, 2018
 *      Author: michal
 */

#include "bomblos/MotorController.hpp"

MotorController::MotorController()
{
	MotorParameterData_t params[EXPBRD_MOUNTED_NR][L6470DAISYCHAINSIZE] = {
	  {
	    {
	    		MOTOR_SUPPLY_VOLTAGE,
	    		MIN_STEPS_PER_REVOLUTION,
	    		MAX_MOTOR_PHASE_VOLTAGE_AMPR,
	    		MAX_MOTOR_PHASE_VOLTAGE_VOLT,
	    		MOTOR_INIT_SPEED,
	    		MOTOR_ACC,
	    		MOTOR_DECC,
	    		MOTOR_MAX_SPEED,
	    		MOTOR_MIN_SPEED,
	    		MOTOR_SPEED_THRESHOLD,
	    		MOTOR_HOLDING_KVAL,
	    		MOTOR_CONST_SPEED_KVAL,
	    		MOTOR_ACC_START_KVAL,
	    		MOTOR_DECC_START_KVAL,
	    		MOTOR_INTERSECT_SPEED,
	    		MOTOR_START_SLOPE,
	    		MOTOR_ACC_FINAL_SLOPE,
	    		MOTOR_DECC_FINAL_SLOPE,
	    		MOTOR_THERMAL_COMP,
	    		MOTOR_OCD_THRESHOLD,
	    		MOTOR_STALL_THRESHOLD,
	    		MOTOR_MICROSTEP,
	    		MOTOR_ALARM_CONDITIOnS,
	    		MOTOR_IC_CONFIG
	    },
		{
				MOTOR_SUPPLY_VOLTAGE,
				MIN_STEPS_PER_REVOLUTION,
				MAX_MOTOR_PHASE_VOLTAGE_AMPR,
				MAX_MOTOR_PHASE_VOLTAGE_VOLT,
				MOTOR_INIT_SPEED,
				MOTOR_ACC,
				MOTOR_DECC,
				MOTOR_MAX_SPEED,
				MOTOR_MIN_SPEED,
				MOTOR_SPEED_THRESHOLD,
				MOTOR_HOLDING_KVAL,
				MOTOR_CONST_SPEED_KVAL,
				MOTOR_ACC_START_KVAL,
				MOTOR_DECC_START_KVAL,
				MOTOR_INTERSECT_SPEED,
				MOTOR_START_SLOPE,
				MOTOR_ACC_FINAL_SLOPE,
				MOTOR_DECC_FINAL_SLOPE,
				MOTOR_THERMAL_COMP,
				MOTOR_OCD_THRESHOLD,
				MOTOR_STALL_THRESHOLD,
				MOTOR_MICROSTEP,
				MOTOR_ALARM_CONDITIOnS,
				MOTOR_IC_CONFIG
		},
	  }
	};
	MotorParameterInitData = (MotorParameterData_t*)(params);

	initMotors();
}

void MotorController::initMotors(){
	MotorParameterData_t *MotorParameterDataSingle;
	MotorParameterData_t *MotorParameterDataGlobal;
	StepperMotorBoardHandle_t *StepperMotorBoardHandle;

	MotorParameterDataGlobal = MotorParameterInitData;

	for (uint8_t id = 0; id < EXPBRD_MOUNTED_NR; id++)
	{
		StepperMotorBoardHandle = BSP_GetExpansionBoardHandle(EXPBRD_ID(id));
		MotorParameterDataSingle = MotorParameterDataGlobal+(id*L6470DAISYCHAINSIZE);
		StepperMotorBoardHandle->Config(MotorParameterDataSingle);
	}
}

void MotorController::setSpeed(uint8_t motor, uint32_t speed){
	MotorParameterData_t *MotorParameterDataSingle;
	StepperMotorBoardHandle_t *StepperMotorBoardHandle;
	uint8_t board, device;
	uint32_t _speed;

	board = EXPBRD_ID(0);
	device = L6470_ID(motor);

	MotorParameterDataSingle = MotorParameterInitData+((board*L6470DAISYCHAINSIZE)+device);
	_speed = Step_s_2_Speed(speed);


	StepperMotorBoardHandle->StepperMotorDriverHandle[device]->Command->PrepareRun(device, L6470_DIR_FWD_ID, _speed);
	StepperMotorBoardHandle->Command->PerformPreparedApplicationCommand();
}

void MotorController::setPosition(uint8_t motor, uint32_t position){
	MotorParameterData_t *MotorParameterDataSingle;
	StepperMotorBoardHandle_t *StepperMotorBoardHandle;
	uint8_t board, device;
	uint32_t _speed;

	board = EXPBRD_ID(0);
	device = L6470_ID(motor);

	MotorParameterDataSingle = MotorParameterInitData+((board*L6470DAISYCHAINSIZE)+device);

	StepperMotorBoardHandle->StepperMotorDriverHandle[device]->Command->PrepareGoTo(device, position);
	StepperMotorBoardHandle->Command->PerformPreparedApplicationCommand();

}

uint32_t  MotorController::getPosition(uint8_t motor){
	MotorParameterData_t *MotorParameterDataSingle;
	StepperMotorBoardHandle_t *StepperMotorBoardHandle;
	uint8_t board, device;
	uint32_t _speed;


	board = EXPBRD_ID(0);
	device = L6470_ID(motor);

	MotorParameterDataSingle = MotorParameterInitData+((board*L6470DAISYCHAINSIZE)+device);

	return StepperMotorBoardHandle->StepperMotorDriverHandle[device]->Command->GetParam(device,L6470_ABS_POS_ID);

}

sL6470_StatusRegister_t MotorController::getStatus(uint8_t motor){
	StepperMotorBoardHandle_t *StepperMotorBoardHandle;
	union{
		uint16_t resp;
		sL6470_StatusRegister_t reg;
	}parser;
	uint8_t board, device;

	board = EXPBRD_ID(0);
	device = L6470_ID(motor);

	parser.resp=(uint16_t) StepperMotorBoardHandle->StepperMotorDriverHandle[device]->Command->GetParam(device,L6470_STATUS_ID);

	return parser.reg;

}

void MotorController::softStop(uint8_t motor){
	MotorParameterData_t *MotorParameterDataSingle;
	StepperMotorBoardHandle_t *StepperMotorBoardHandle;
	uint8_t board, device;
	uint32_t _speed;

	board = EXPBRD_ID(0);
	device = L6470_ID(motor);

	MotorParameterDataSingle = MotorParameterInitData+((board*L6470DAISYCHAINSIZE)+device);

	StepperMotorBoardHandle->StepperMotorDriverHandle[device]->Command->PrepareSoftHiZ(device);
	StepperMotorBoardHandle->Command->PerformPreparedApplicationCommand();

}

void MotorController::hardStop(uint8_t motor){
	MotorParameterData_t *MotorParameterDataSingle;
	StepperMotorBoardHandle_t *StepperMotorBoardHandle;
	uint8_t board, device;
	uint32_t _speed;

	board = EXPBRD_ID(0);
	device = L6470_ID(motor);

	MotorParameterDataSingle = MotorParameterInitData+((board*L6470DAISYCHAINSIZE)+device);

	StepperMotorBoardHandle->StepperMotorDriverHandle[device]->Command->PrepareHardHiZ(device);
	StepperMotorBoardHandle->Command->PerformPreparedApplicationCommand();

}


