//#include "stm32f4xx_hal.h"
#ifndef STEPPER
#define STEPPER
#include <stdlib.h>
#include <math.h>
#include "encoder_lib.h"


int Maximal_Pulse_Period[3];

int Current_stepper_position[3];

int steps[3];

float start_position[3];

float end_position[3];

float requested_position[3];

float position_from_encoder[3];

float Stepper_acceleration[3];

int Min_stepper_period[3];

float Dead_zone[3];
//						stepper_0	 stepper_1		stepper_2
float end_stop_up[3]={	1.5,		1.6,			2.5};

float end_stop_down[3]={-1.4,		-1.4,			-1.5};
//////////////////////////////////////////////////////////////////////////////////////////////////

int Stepper_Counter_0=0;
int Stepper_Counter_1=0;
int Stepper_Counter_2=0;

//////////////////////////////////

long int Stepper_period[3];
long double Ramp_period[3];
/*
 Stepper_period[0]=0;
 Stepper_period[1]=0;
 Stepper_period[2]=0;

 */
int rotation_Dir_[3];
const float con=0.005;
/*
 rotation_Dir_[0]=0;
 rotation_Dir_[1]=0;
 rotation_Dir_[2]=0;
 */
///////////////////////////////////
// Timer interupt variables
int Period_memory_0=5000;
int Period_memory_1=5000;
int Period_memory_2=5000;

float total_distance[3];


void ST_MOT_Init(int Stepper_ID_,float dead_zone,double Acceleration_, int Min_Period)
{

	Stepper_period[Stepper_ID_]=4000;			//initial period

	Stepper_acceleration[Stepper_ID_]=Acceleration_/1000000000;

	Maximal_Pulse_Period[Stepper_ID_]=4000;		//Const in #define

	Min_stepper_period[Stepper_ID_]=Min_Period;		// Period from anlge speed //400;

	steps[Stepper_ID_]=0;						//internal reference of deveitation from origin point

	Dead_zone[Stepper_ID_]=dead_zone;			// accuracy of feedback from encoders

	position_from_encoder[Stepper_ID_]=0;

	HAL_GPIO_WritePin(MOT_EABLE_GPIO_Port,MOT_EABLE_Pin,GPIO_PIN_SET);
	HAL_GPIO_WritePin(FANS_ENABLE_GPIO_Port,FANS_ENABLE_Pin,GPIO_PIN_SET);


}





///////////////////////////////////////////////////////   Przyspieszenie Linniowe  /////////////////////////////////////////////////////////
void Movement_Prep(int Stepper_ID_, float set_position)
{
	if(set_position<end_stop_up[Stepper_ID_]&&set_position>end_stop_down[Stepper_ID_])

	{
		Ramp_period[Stepper_ID_]=Maximal_Pulse_Period[Stepper_ID_];
		start_position[Stepper_ID_]=position_from_encoder[Stepper_ID_];
		end_position[Stepper_ID_]=set_position;

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

void Linear_acceleration(int Stepper_ID_, int dir)
{

	float distance=fabsf(position_from_encoder[Stepper_ID_]-end_position[Stepper_ID_]);
	float total_distance=fabsf(start_position[Stepper_ID_]-end_position[Stepper_ID_]);

	if(distance > total_distance/2)
	{
		//ramp up
		Ramp_period[Stepper_ID_]=(Ramp_period[Stepper_ID_]/(1+(Stepper_acceleration[Stepper_ID_]*Ramp_period[Stepper_ID_])));


		/*
		kat Next_Lin_Period od 0 do 2 pi, mozna podzielic na Step znajac ilosc Stepow silnika.
		przeliczenie kata na +/- ilosc Stepow.
		rampy wzgledem ilosci Stepow
		https://www.embedded.com/design/mcus-processors-and-socs/4006438/Generate-stepper-motor-speed-profiles-in-real-time
		http://annals.fih.upt.ro/pdf-full/2013/ANNALS-2013-3-06.pdf
		 */


		//checking if period witin limits
		if(Ramp_period[Stepper_ID_] < Min_stepper_period[Stepper_ID_])
		{
			Stepper_period[Stepper_ID_]=Min_stepper_period[Stepper_ID_];
		}
		else
		{
			Stepper_period[Stepper_ID_]=Ramp_period[Stepper_ID_];
		}

	}
	else//ramp down
	{


		Ramp_period[Stepper_ID_]=(Ramp_period[Stepper_ID_]/(1-(Stepper_acceleration[Stepper_ID_]*Ramp_period[Stepper_ID_])));


		//checking whether period is within limits
		if (Ramp_period[Stepper_ID_]>Maximal_Pulse_Period[Stepper_ID_])
		{
			Stepper_period[Stepper_ID_]=Maximal_Pulse_Period[Stepper_ID_];
			Ramp_period[Stepper_ID_]=Maximal_Pulse_Period[Stepper_ID_];
		}
		else if(Ramp_period[Stepper_ID_] < Min_stepper_period[Stepper_ID_])
		{
			Stepper_period[Stepper_ID_]=Min_stepper_period[Stepper_ID_];
		}
		else
		{
			Stepper_period[Stepper_ID_]=Ramp_period[Stepper_ID_];
		}
	}

}



void Next_Lin_Period(int Stepper_ID_)
{


	if(end_position[Stepper_ID_]<position_from_encoder[Stepper_ID_]-Dead_zone[Stepper_ID_])
	{
		//HAL_GPIO_WritePin(MOT_EABLE_GPIO_Port,MOT_EABLE_Pin,GPIO_PIN_SET);
		rotation_Dir_[Stepper_ID_]=0;
		//position_from_encoder[Stepper_ID_]=position_from_encoder[Stepper_ID_]-0.0005;	//debug
		Linear_acceleration(Stepper_ID_,1);
		//Stepper_period[Stepper_ID_]=800;
	}
	else if(end_position[Stepper_ID_]>position_from_encoder[Stepper_ID_]+Dead_zone[Stepper_ID_])
	{
		//HAL_GPIO_WritePin(MOT_EABLE_GPIO_Port,MOT_EABLE_Pin,GPIO_PIN_SET);
		rotation_Dir_[Stepper_ID_]=1;
		//position_from_encoder[Stepper_ID_]=position_from_encoder[Stepper_ID_]+0.0005;//debug
		Linear_acceleration(Stepper_ID_,0);
		//Stepper_period[Stepper_ID_]=200;

	}
	else
	{
		Stepper_period[Stepper_ID_]=0;
		//HAL_GPIO_WritePin(MOT_EABLE_GPIO_Port,MOT_EABLE_Pin,GPIO_PIN_RESET);
	}
}


 void Period_Control(int Stepper_ID_,int Period_, int Turn)
{
	Stepper_period[Stepper_ID_]=Period_;
	rotation_Dir_[Stepper_ID_]=Turn;
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
