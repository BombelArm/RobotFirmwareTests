//#include "stm32f4xx_hal.h"
#ifndef STEPPER
#define STEPPER
#include <stdlib.h>
#include <math.h>
#include "encoder_lib.h"


typedef struct POS_TYPE
{
	float map[3];
	struct POS_TYPE *next,*prev;
}pos_type;

typedef struct
{
	int max_period;	//max defined step period - the bigger this val, the slower min speed will be.
	int min_period; // minimal steper period - the smaller the faster motor will turn.
	double acc; //acceleration val, used in calculating ramps.
	float dead_zone;//dead zone of stepper motor. - to small will cause jutter of arm. to big will cause move inaccuracy
	float enc_pos;	//used for ramps, insert data from encoder here.
	int ref_pos; //unused. in future will be used to detect skipped steps.
	float stop_pos;	//destination of move
	float start_pos; //originn of move
	float t_distance; //total distance
	float up_end,down_end;//end stops

}mot_inf_type;
typedef struct
{
	GPIO_TypeDef * GPIO_STEP_PORT,*GPIO_TURN_PORT;
	uint16_t GPIO_STEP_PIN,GPIO_TURN_PIN;

	mot_inf_type info;	//information of destination, restraints and for calculating ramps
	int tim_fin;		//to use in timer interrupt. can only be changed when timer>tim_fin
	int period;			//constrained ramp_period can be changed outside  interrupt loop
	 double ramp_period;	//used to calculate ramps
	int r_dir; //rotation dir.
	int fin;// 1 if movment done 0 if still moving.


}mot_type;





float Dead_zone[3];
//						stepper_0	 stepper_1		stepper_2
float end_stop_up[3]={	1.5,		1.6,			2.53};

float end_stop_down[3]={-2.8,		-1.6,			-1.6};
//////////////////////////////////////////////////////////////////////////////////////////////////

int Stepper_Counter_0=3;
int Stepper_Counter_1=13;
int Stepper_Counter_2=17;


void run_seq(int a)
{

}

void ST_MOT_Init(mot_inf_type *imot,float dead_zone,double Acceleration_, int Min_Period)		//initiates motor with given values
{



	imot->acc=Acceleration_/1000000000;

	imot->max_period=4000;		//Const in #define

	imot->min_period=Min_Period;		// Period from anlge speed //400;

	imot->ref_pos=0;						//internal reference of deveitation from origin point

	imot->dead_zone=dead_zone;			// accuracy of feedback from encoders

	imot->enc_pos=0;

	HAL_GPIO_WritePin(MOT_EABLE_GPIO_Port,MOT_EABLE_Pin,GPIO_PIN_SET);		//enabling mot
	HAL_GPIO_WritePin(FANS_ENABLE_GPIO_Port,FANS_ENABLE_Pin,GPIO_PIN_SET);		//enabling fans

}





///////////////////////////////////////////////////////   Przyspieszenie Linniowe  /////////////////////////////////////////////////////////
void Movement_Prep(mot_type *mot, float set_position)
{
	//if(set_position<mot->info.up_end&&set_position>mot->info.down_end) //BUG
if(1)
	{
		mot->ramp_period=mot->info.max_period;
		mot->info.start_pos=mot->info.enc_pos;
		mot->info.stop_pos=set_position;
		mot->info.t_distance=fabsf(mot->info.start_pos-mot->info.stop_pos);
		mot->fin=0;

	}



	/*Do zrobienia
	 * zwracanie 0.1 w zaleznosci czy Next_Lin_Period sie wykonal czy nie
	 * sprawdzanie czy Next_Lin_Period sie wykonal, czy jeszcze sie wykonuje
	 * bufor. jesli Next_Lin_Period sie wykonal bezzwlocznie dac nowe dane
	 * detekcja uskoku, nowa rampa na podstawie nowego polozenia, kilka prob, przed poddaniem sie.
	 *  funkcja z vectorem, przechowujaca nastepne polozenia, mmozliwosc ustawienia kolejki,
	 *
	 */
}

double sta(int steps,double angle_of_step)			//steps to angle function
{
	// to do
return 0;
}

void Linear_acceleration(mot_type *mot)		//counts next period using rampup/rampdown algorithm
{

	float distance=fabsf(mot->info.enc_pos-mot->info.stop_pos);

	if(distance > mot->info.t_distance/2)

	{
		//ramp up
		mot->ramp_period=(mot->ramp_period/(1+(mot->info.acc * mot->ramp_period)));

		/*
		https://www.embedded.com/design/mcus-processors-and-socs/4006438/Generate-stepper-motor-speed-profiles-in-real-time
		http://annals.fih.upt.ro/pdf-full/2013/ANNALS-2013-3-06.pdf
		 */

		//checking if period witin limits
		if(mot->ramp_period < mot->info.min_period)
		{
			mot->period= mot->info.min_period;
		}
		else
		{
			mot->period=(int)mot->ramp_period;
		}
	}
	else//ramp down
	{

		mot->ramp_period=(mot->ramp_period/(1-(mot->info.acc * mot->ramp_period)));
		//Ramp_period[Stepper_ID_]=(Ramp_period[Stepper_ID_]/(1-(Stepper_acceleration[Stepper_ID_]*Ramp_period[Stepper_ID_])));
		//checking whether period is within limits

		if (mot->ramp_period > mot->info.max_period)
		{
			mot->ramp_period = mot->period = mot->info.max_period;

		}
		else if(mot->ramp_period < mot->info.min_period)
		{
			mot->period = mot->info.min_period;
		}
		else
		{
			mot->period=(int)mot->ramp_period;
		}


	}

}



void Next_Lin_Period(mot_type *mot)//checks if motor is in set positon, calls Linear_acceleration
{


	if(mot->info.stop_pos<mot->info.enc_pos-mot->info.dead_zone)
	{
		//HAL_GPIO_WritePin(MOT_EABLE_GPIO_Port,MOT_EABLE_Pin,GPIO_PIN_SET);
		mot->r_dir=0;
		mot->info.enc_pos=mot->info.enc_pos-0.0005;	//debug
		Linear_acceleration(mot);
		//Stepper_period[Stepper_ID_]=800;
	}
	else if(mot->info.stop_pos>mot->info.enc_pos+mot->info.dead_zone)
	{
		//HAL_GPIO_WritePin(MOT_EABLE_GPIO_Port,MOT_EABLE_Pin,GPIO_PIN_SET);
		mot->r_dir=1;
		mot->info.enc_pos=mot->info.enc_pos+0.0005;	//debug
		Linear_acceleration(mot);
		//Stepper_period[Stepper_ID_]=200;

	}
	else
	{
		mot->period=0;
		mot->fin=1;
		//HAL_GPIO_WritePin(MOT_EABLE_GPIO_Port,MOT_EABLE_Pin,GPIO_PIN_RESET);
	}
}

void set_spd(mot_type *mot,int Period_, int Turn)		//sets period, without counting ramp
{
	mot->period=Period_;
	mot->r_dir=Turn;

}
 void Period_Control(mot_type *mot,int *counter)	//stears with motor
{


	if(*counter > mot->period)
	{

		//e_read(&position_from_encoder[0],0);
		*counter = 0;
		Next_Lin_Period(mot);

		if(mot->r_dir)
		{
			HAL_GPIO_WritePin(mot->GPIO_TURN_PORT, mot->GPIO_TURN_PIN, GPIO_PIN_SET);
		}
		else
		{
			HAL_GPIO_WritePin(mot->GPIO_TURN_PORT, mot->GPIO_TURN_PIN, GPIO_PIN_RESET);
		}
	}


	if(mot->period!=0)
	{
		if(*counter==0)   {	HAL_GPIO_WritePin(mot->GPIO_STEP_PORT, mot->GPIO_STEP_PIN, GPIO_PIN_SET);		}
		if(*counter==1)   {	HAL_GPIO_WritePin(mot->GPIO_STEP_PORT, mot->GPIO_STEP_PIN, GPIO_PIN_RESET);
		}
	}

}





//////////////////////////////////////////////////////////////////////////////

/*
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{

	if(htim->Instance == TIM10){ //




		Stepper_Counter_0++;	 Stepper_Counter_1++ ;	 Stepper_Counter_2++;



		//////////////////////////Stepper_0///////////////////////////////
		///////////      DIR1_Pin-Direction STEP1_Pin-Step              /////////////


		if(Stepper_Counter_0 > Period_memory_0)
		{

			pos_put(0);
			Stepper_Counter_0 = 0;
			Next_Lin_Period(0);
			Period_memory_0 = Stepper_period[0];             //buffored value being loaded if counter reaches requested previous period.


			if(rotation_Dir_[0])
			{
				HAL_GPIO_WritePin(DIR1_GPIO_Port, DIR1_Pin, GPIO_PIN_SET);
			}
			else
			{
				HAL_GPIO_WritePin(DIR1_GPIO_Port, DIR1_Pin, GPIO_PIN_RESET);
			}
		}


		if(Period_memory_0!=0)
		{
			if(Stepper_Counter_0==0)   {	HAL_GPIO_WritePin(STEP1_GPIO_Port, STEP1_Pin, GPIO_PIN_SET);		}
			if(Stepper_Counter_0==1)   {	HAL_GPIO_WritePin(STEP1_GPIO_Port, STEP1_Pin, GPIO_PIN_RESET);	}
		}

		/////////////////////////////Stepper_1/////////////////////////////////////////////////////////////
		//////////////////////			 DIR2_Pin-Direction STEP2_Pin-Step								///////////////
		if(Stepper_Counter_1 > Period_memory_1)
		{

			pos_put(0);
			Stepper_Counter_1 = 0;      	// reset licznika
			Next_Lin_Period(1);
			Period_memory_1 = Stepper_period[1];
			if(rotation_Dir_[1])
			{
				HAL_GPIO_WritePin(DIR2_GPIO_Port, DIR2_Pin, GPIO_PIN_SET);   	\
			}

			else
			{
				HAL_GPIO_WritePin(DIR2_GPIO_Port, DIR2_Pin, GPIO_PIN_RESET);
			}

		}
		if(Period_memory_1!=0){

			if(Stepper_Counter_1==0)   {		HAL_GPIO_WritePin(STEP2_GPIO_Port, STEP2_Pin, GPIO_PIN_SET);			}
			if(Stepper_Counter_1==1)   {		HAL_GPIO_WritePin(STEP2_GPIO_Port, STEP2_Pin, GPIO_PIN_RESET);		}
		}
		/////////////////////////////Stepper_2///////////////////////////////////////
		///////////			 DIR3_Pin-Direction STEP3_Pin-Step			/////////////////////////
		if(Stepper_Counter_2 > Period_memory_2)
		{

			pos_put(0);
			Stepper_Counter_2 = 0;
			Next_Lin_Period(2);
			Period_memory_2 = Stepper_period[2];
			if(rotation_Dir_[2])
			{
				HAL_GPIO_WritePin(DIR3_GPIO_Port, DIR3_Pin, GPIO_PIN_SET);
			}
			else
			{
				HAL_GPIO_WritePin(DIR3_GPIO_Port, DIR3_Pin, GPIO_PIN_RESET);
			}
		}
		if(Period_memory_2!=0){

			if(Stepper_Counter_2==0)   {	HAL_GPIO_WritePin(STEP3_GPIO_Port, STEP3_Pin, GPIO_PIN_SET);		}
			if(Stepper_Counter_2==1)   {	HAL_GPIO_WritePin(STEP3_GPIO_Port, STEP3_Pin, GPIO_PIN_RESET);		}
		}
	}
}
*/

#endif
