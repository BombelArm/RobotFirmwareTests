/*
 * motors_param.c
 *
 *  Created on: Oct 18, 2018
 *      Author: michal
 */


#include "motors_param.h"
#include "xnucleoihm02a1.h"

const MotorParameterData_t MotorParameterInitData[EXPBRD_MOUNTED_NR][L6470DAISYCHAINSIZE] = {
  {
    {
    		9.0,				//!< motor supply voltage in V
    		400,				//!< min number of steps per revolution for the motor
    		1.7,				//!< max motor phase voltage in A
    		3.06,				//!< max motor phase voltage in V
    		300.0,				//!< motor initial speed [step/s]
    		500.0,				//!< motor acceleration [step/s^2] (comment for infinite acceleration mode)
    		500.0,				//!< motor deceleration [step/s^2] (comment for infinite deceleration mode)
    		400.0,				//!< motor maximum speed [step/s]
    		0.0,				//!< motor minimum speed [step/s]
    		602.7,				//!< motor full-step speed threshold [step/s]
    		3.06,				//!< holding kval [V]
    		3.06,				//!< constant speed kval [V]
    		3.06,				//!< acceleration starting kval [V]
    		3.06,				//!< deceleration starting kval [V]
    		61.52,				//!< intersect speed for bemf compensation curve slope changing [step/s]
    		392.1569e-6,		//!< start slope [s/step]
    		643.1372e-6,		//!< acceleration final slope [s/step]
    		643.1372e-6,		//!< deceleration final slope [s/step]
    		0,					//!< thermal compensation factor (range [0, 15])
    		3.06*1000*1.10,		//!< ocd threshold [ma] (range [375 ma, 6000 ma])
    		3.06*1000*1.00,		//!< stall threshold [ma] (range [31.25 ma, 4000 ma])
    		MICROSTEP_1_128,	//!< step mode selection
    		0xFF,				//!< alarm conditions enable
    		0x2E88				//!< ic configuration
    },
	{
			9.0,				//!< motor supply voltage in V
			400,				//!< min number of steps per revolution for the motor
			1.7,				//!< max motor phase voltage in A
			3.06,				//!< max motor phase voltage in V
			300.0,				//!< motor initial speed [step/s]
			500.0,				//!< motor acceleration [step/s^2] (comment for infinite acceleration mode)
			500.0,				//!< motor deceleration [step/s^2] (comment for infinite deceleration mode)
			400.0,				//!< motor maximum speed [step/s]
			0.0,				//!< motor minimum speed [step/s]
			602.7,				//!< motor full-step speed threshold [step/s]
			3.06,				//!< holding kval [V]
			3.06,				//!< constant speed kval [V]
			3.06,				//!< acceleration starting kval [V]
			3.06,				//!< deceleration starting kval [V]
			61.52,				//!< intersect speed for bemf compensation curve slope changing [step/s]
			392.1569e-6,		//!< start slope [s/step]
			643.1372e-6,		//!< acceleration final slope [s/step]
			643.1372e-6,		//!< deceleration final slope [s/step]
			0,					//!< thermal compensation factor (range [0, 15])
			3.06*1000*1.10,		//!< ocd threshold [ma] (range [375 ma, 6000 ma])
			3.06*1000*1.00,		//!< stall threshold [ma] (range [31.25 ma, 4000 ma])
			MICROSTEP_1_128,	//!< step mode selection
			0xFF,				//!< alarm conditions enable
			0x2E88				//!< ic configuration
	},
  }
};


MotorParameterData_t *GetMotorParameterInitData(void)
{
  return (MotorParameterData_t*)(MotorParameterInitData);
}
