/*! \file
 * \brief Task manager source code.
 */


#include "task_manager.h"

void t_taskManagerInit(){
	task newtask;

	HAL_GPIO_WritePin(MOTORS_ENABLE_GPIO_Port,MOTORS_ENABLE_Pin, MOTORS_ENABLED);
	HAL_GPIO_WritePin(FANS_ENABLE_GPIO_Port,FANS_ENABLE_Pin, !FANS_ENABLED);

	buffer_act_size=3;
	newtask.order_type=JOINT_SPACE;
	newtask.f0=0;
	newtask.f1=0;
	newtask.f2=0;

	buffer[0]=newtask;

	newtask.order_type=JOINT_SPACE;
	newtask.f0=-0.5;
	newtask.f1=0.5;
	newtask.f2=0.5;

	buffer[1]=newtask;

	newtask.order_type=JOINT_SPACE;
	newtask.f0=0.5;
	newtask.f1=-0.5;
	newtask.f2=-0.5;

	buffer[2]=newtask;

	t_exec();
}

void t_append_task(uint8_t msg[ORDER_LENGTH]){
	int hw_task_type,order_type;
	int i1,i2,i3;
	float f0,f1,f2;
	task newtask;

	if(buffer_act_size == TASK_BUFFER_SIZE){
		return;
	}

	order_type=(int)first_int(msg[0]);
	newtask.order_type=order_type;


	switch(order_type){
			case HW_CONFIG:
				hw_task_type=(int) 10*second_int(msg[0])+first_int(msg[1]);
				newtask.hw_task_type=hw_task_type;

				break;
			case JOINT_SPACE:
				i1=(int) second_int(msg[0]);
				i2=(int) first_int(msg[1]);
				i3=(int) second_int(msg[1]);
				f0=i1+0.1*i2+0.01*i3;
				i1=(int) first_int(msg[2]);
				i2=(int) second_int(msg[2]);
				i3=(int) first_int(msg[3]);
				f1=i1+0.1*i2+0.01*i3;
				i1=(int) second_int(msg[3]);
				i2=(int) first_int(msg[4]);
				i3=(int) second_int(msg[4]);
				f2=i1+0.1*i2+0.01*i3;

				newtask.f0=f0;
				newtask.f1=f1;
				newtask.f2=f2;
				break;
			case OPERATION_SPACE:
				i1=(int) second_int(msg[0]);
				i2=(int) first_int(msg[1]);
				i3=(int) second_int(msg[1]);
				f0=i1+0.1*i2+0.01*i3;
				i1=(int) first_int(msg[2]);
				i2=(int) second_int(msg[2]);
				i3=(int) first_int(msg[3]);
				f1=i1+0.1*i2+0.01*i3;
				i1=(int) second_int(msg[3]);
				i2=(int) first_int(msg[4]);
				i3=(int) second_int(msg[4]);
				f2=i1+0.1*i2+0.01*i3;

				newtask.f0=f0;
				newtask.f1=f1;
				newtask.f2=f2;
				break;
	}

	buffer[buffer_act_size++]=newtask;
	t_exec();
}


void t_exec(){
	if(buffer_act_size == 0) return;

	task task1=buffer[0];



	switch(task1.order_type){
			case HW_CONFIG:
				switch(task1.hw_task_type){
					case MOTORS_ON:
						HAL_GPIO_WritePin(MOTORS_ENABLE_GPIO_Port,MOTORS_ENABLE_Pin, MOTORS_ENABLED);
						break;
					case MOTORS_OFF:
						HAL_GPIO_WritePin(MOTORS_ENABLE_GPIO_Port,MOTORS_ENABLE_Pin, !MOTORS_ENABLED);
						break;
					case FANS_ON:
						  HAL_GPIO_WritePin(FANS_ENABLE_GPIO_Port,FANS_ENABLE_Pin, FANS_ENABLED);
						break;
					case FANS_OFF:
						  HAL_GPIO_WritePin(FANS_ENABLE_GPIO_Port,FANS_ENABLE_Pin, !FANS_ENABLED);
						break;
				}
				t_shift_buffer(); // removing task that is done
				break;

			case JOINT_SPACE:

				if (motion_nodes[0].position_reached!=1 || motion_nodes[1].position_reached!=1 || motion_nodes[2].position_reached!=1){
					return;
				}
				m_setPosition(0,task1.f0);
				m_setPosition(1,task1.f1);
				m_setPosition(2,task1.f2);
				t_shift_buffer();

				break;
			case OPERATION_SPACE:
				break;
	}
}

void t_shift_buffer(){
	for(int i=0;i<TASK_BUFFER_SIZE-1;i++){
		buffer[i]=buffer[i+1];
	}
	buffer_act_size--;
}
