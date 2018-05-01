/*
 * Comms.h
 *
 *  Created on: Apr 17, 2018
 *      Author: huber
 */
#include <string.h>
#ifndef COMMS_H_
#define COMMS_H_
#define WORD_LENGTH 16

#define SYN " SYN\n"
#define SYN_ACK "SYN-ACK"
#define ACK "ACK"
#define SYS_INFO "SYS_INFO"
#define MOT_INIT "MOT_INIT"   //	Data send prep
#define MOT_SET_POS "MSP"		//	 Data send prep
#define PING "PING"
#define ERROR "ERROR"

typedef struct
{
int status;
char Last_Msg[16];
char Send_[16];

} incoming_buffer;

// sscanf

void comms(incoming_buffer* connection)
{

if(connection->status==2)
{
	if(strcmp(connection->Last_Msg,SYS_INFO))
	{
		strcpy(&connection->Send_,SYN_ACK);

	}
	else if(strcmp(connection->Last_Msg,MOT_INIT))
	{

		strcpy(&connection->Send_,ACK);

		//waiting for next bits
	}
	else if(strcmp(connection->Last_Msg,MOT_SET_POS) )
	{
		strcpy(&connection->Send_,ACK);

		//waiting for next bits
	}
	else if(strcmp(connection->Last_Msg,PING))
	{
		strcpy(&connection->Send_,PING);

		//count how many bits
	}
	else
	{
		strcpy(&connection->Send_,ERROR);
	}
}

else if(connection->status==1)
{
	if(strcmp(connection->Last_Msg,ACK))
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
	strcpy(&connection->Send_,SYN_ACK);
	connection->status=1;
	}
	else
	{

		strcpy(&connection->Send_,ERROR);
	}
}


}






#endif /* COMMS_H_ */
