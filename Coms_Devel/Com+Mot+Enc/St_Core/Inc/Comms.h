/*
 * Comms.h
 *
 *  Created on: Apr 17, 2018
 *      Author: huber
 */
#include <string.h>
#include <stdlib.h>
#include "Steper.h"
#ifndef COMMS_H_
#define COMMS_H_
#define WORD_LENGTH 32

char SYN[]= "SYN";
char SYN_ACK[]= "SYN-ACK";
char ACK[]= "ACK";
char OK[]="OK";
char SYS_INFO[]= "SYS_INFO";
char MOT_INIT[]= "MOT_INIT";   //	Data send prep
char MOT_SET_POS[]= "MSP";		//	 Data send prep
char PING[]= "PING";
char ERR[]= "ERROR";
char FIN[]="FIN";
char FIN_ACK[]="FIN-ACK";

typedef struct
{
	int what;		// 0-Nothing //1-Mot_Init //2-Set_Pos
	int Mot;
	int Min_Per;
	float Deadzone;
	float Position;
	double Acceleration;

} type_container;

typedef struct
{
	int status;
	int flag;
	int Incoming_packets;
	char Byte;
	char Last_Msg[WORD_LENGTH];
	char Send_[WORD_LENGTH];
	type_container container;
} incoming_buffer;

void send(incoming_buffer * connection,char* data)
{
	int a;
	for(a=0;a<WORD_LENGTH;++a)
	{
		connection->Send_[a]='\0' ;
	}

	sprintf(connection->Send_,"%s%c",data,'\n');
	connection->flag=1;
}

void Mot_init_buf(incoming_buffer * connection)
{

	switch (connection->Incoming_packets) {
	case 4:
		connection->container.Mot=atoi(connection->Last_Msg);
		send(connection,ACK);
		break;
	case 3:
		connection->container.Deadzone=atof(connection->Last_Msg);
		send(connection,ACK);
		break;
	case 2:
		connection->container.Acceleration=atof(connection->Last_Msg);
		send(connection,ACK);
		break;
	case 1:
		connection->container.Min_Per=atoi(connection->Last_Msg);
		send(connection,ACK);
		break;
	case 0:
		if(strcmp(connection->Last_Msg, FIN)==0)
		{
		ST_MOT_Init(connection->container.Mot,connection->container.Deadzone,connection->container.Acceleration,connection->container.Min_Per);
		send(connection,FIN_ACK);
		connection->container.what=0;
		}
		else
		{
		send(connection,ERR);
		connection->container.what=0;
		}

		break;

	}
	connection->Incoming_packets--;
}

void Mot_setpoint_buf(incoming_buffer * connection)
{
	switch (connection->Incoming_packets)
	{
		case 2:
			connection->container.Mot=atoi(connection->Last_Msg);
			send(connection,ACK);
			break;
		case 1:
			connection->container.Position=atof(connection->Last_Msg);
			send(connection,ACK);
			break;
		case 0:
			if(strcmp(connection->Last_Msg, FIN)==0)
			{
			Movement_Prep(connection->container.Mot,connection->container.Position);
			send(connection,FIN_ACK);
			connection->container.what=0;
			}
			else
			{
			send(connection,ERR);
			connection->container.what=0;
			}

			break;





	}
	connection->Incoming_packets--;
}

void comms(incoming_buffer* connection)
{
	int a=0;
				for(a=0;a<16;++a)
					{
						connection->Send_[a]='\0' ;
					}



if(connection->status==2)
{

	if(connection->container.what==0)
	{
		if(strcmp(connection->Last_Msg,SYS_INFO)==0)
		{

					char string[16];
					sprintf(string, "M1: %4.3f\nM2: %4.3f\nM3: %4.3f\n"  ,position_from_encoder[0],position_from_encoder[1],position_from_encoder[2]);
					send(connection, string);


		}
		else if(strcmp(connection->Last_Msg,MOT_INIT)==0)
		{

			send(connection, OK);
			connection->Incoming_packets=4;
			connection->container.what=1;
			//waiting for next bits
		}
		else if(strcmp(connection->Last_Msg,MOT_SET_POS)==0 )
		{
			send(connection, OK);
			connection->Incoming_packets=2;
			connection->container.what=2;
			//waiting for next bits
		}
		else if(strcmp(connection->Last_Msg,PING)==0)
		{
			send(connection, PING);
			//count how many bits

		}
		else if(strcmp(connection->Last_Msg,"TEST")==0)
			{
				send(connection, "COMMENCING");
				run_seq(1);
				//count how many bits

			}
		else if(strcmp(connection->Last_Msg,"TEST_STOP")==0)
				{
					send(connection, "STOPING");
					run_seq(0);
					//count how many bits

				}
		else if(strcmp(connection->Last_Msg,"HOME")==0)
					{
						send(connection, "HOMING");
						Movement_Prep(0,0);
						Movement_Prep(1,-1);
						Movement_Prep(2,2.55);
						//count how many bits

					}
		else if(strcmp(connection->Last_Msg,"INIT_ALL")==0)
						{
							send(connection, "INITING WITH DEF VAL");
							ST_MOT_Init(0,0.025,5000,50);
							ST_MOT_Init(1,0.002,8000,20);
							ST_MOT_Init(2,0.01,5000,100);
							Movement_Prep(0,0);
																				Movement_Prep(1,0);
																				Movement_Prep(2,0);

							//count how many bits

						}
		else if(strcmp(connection->Last_Msg,"POS1")==0)
						{
							send(connection, "INITING POS1");
									Movement_Prep(0,0);
														Movement_Prep(1,0);
														Movement_Prep(2,0);

							//count how many bits

						}
		else if(strcmp(connection->Last_Msg,"REST")==0)
						{
							send(connection, "MOT=OFF, FAN=ON ");
							HAL_GPIO_WritePin(MOT_EABLE_GPIO_Port,MOT_EABLE_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(FANS_ENABLE_GPIO_Port,FANS_ENABLE_Pin,GPIO_PIN_SET);

							//count how many bits

						}
		else
		{
			send(connection, ERR);
		}
	}
	else if(connection->container.what==1)
	{
		Mot_init_buf(connection);
	}
	else if(connection->container.what==2)
	{
		Mot_setpoint_buf(connection);
	}

}

else if(connection->status==1)
{
	if(strcmp(connection->Last_Msg,ACK)==0)
	{
		send(connection, OK);
	connection->status=2;
	connection->container.what=0;
	}
	else
	{
		connection->status=0;
	}
}

else if(connection->status==0)
{
	if(strcmp(connection->Last_Msg, SYN)==0)
	{
		send(connection, SYN_ACK);
		connection->status=1;

	}
	else
	{

		send(connection, ERR);

	}
}

}


void gather (incoming_buffer* connection)
{
	static int iter=0;
	int a=0;
if(connection->Byte=='\n')
{
	connection->Last_Msg[iter]='\0';
	comms(connection);

	for(a=0;a<WORD_LENGTH;)
	{
		connection->Last_Msg[a]='\0' ;
		a++;
	}
	iter=0;
}
else if(connection->Byte=='\0')
		{
		}
else
{
	connection->Last_Msg[iter]=connection->Byte;
	iter++;
}


if(iter>WORD_LENGTH-1)
{

for(a=0;a<WORD_LENGTH;++a)
{
	connection->Last_Msg[a]='\0' ;
}
iter=0;
send(connection, ERR);
}

}




#endif /* COMMS_H_ */
