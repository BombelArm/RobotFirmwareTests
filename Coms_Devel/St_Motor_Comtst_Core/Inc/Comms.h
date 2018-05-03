/*
 * Comms.h
 *
 *  Created on: Apr 17, 2018
 *      Author: huber
 */
#include <string.h>
#ifndef COMMS_H_
#define COMMS_H_
#define WORD_LENGTH 17

uint8_t SYN[]= "SYN";
uint8_t SYN_ACK[]= "SYN-ACK";
uint8_t ACK[]= "ACK";
uint8_t SYS_INFO[]= "SYS_INFO";
uint8_t MOT_INIT[]= "MOT_INIT";   //	Data send prep
uint8_t MOT_SET_POS[]= "MSP";		//	 Data send prep
uint8_t PING[]= "PING";
uint8_t ERR[]= "ERROR";

typedef struct
{
int status;
int flag;
char Byte;
char Last_Msg[WORD_LENGTH];
char Send_[WORD_LENGTH];

} incoming_buffer;

// sscanf

void comms(incoming_buffer* connection)
{

	int a=0;
	for(a=0;a<WORD_LENGTH;++a)
		{
			connection->Send_[a]='\0' ;

		}


if(connection->status==2)
{
	if(strcmp(connection->Last_Msg,SYS_INFO)==0)
	{
		strcpy(&connection->Send_,&SYN_ACK);

	}
	else if(strcmp(connection->Last_Msg,MOT_INIT)==0)
	{

		strcpy(&connection->Send_,&ACK);

		//waiting for next bits
	}
	else if(strcmp(connection->Last_Msg,MOT_SET_POS)==0 )
	{
		strcpy(&connection->Send_,&ACK);

		//waiting for next bits
	}
	else if(strcmp(connection->Last_Msg,PING)==0)
	{
		strcpy(&connection->Send_,&PING);

		//count how many bits
	}
	else
	{
		strcpy(&connection->Send_,&ERR);
	}
}

else if(connection->status==1)
{
	if(strcmp(connection->Last_Msg,ACK)==0)
	{
	strcpy(&connection->Send_,ACK);
	connection->status=2;
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
	strcpy(&connection->Send_,&SYN_ACK);
	connection->status=1;

	}
	else
	{

		strcpy(&connection->Send_,&ERR);
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

/*
if(iter>WORD_LENGTH-1)
{

for(a=0;a<WORD_LENGTH;++a)
{
	connection->Last_Msg[a]='\0' ;
}
iter=0;
connection->flag=1;
strcpy(&connection->Send_,&ERR);
}
*/
}





#endif /* COMMS_H_ */
