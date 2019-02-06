/*
 * Send_Data_To_BlackBox.h
 *
 *  Created on: Feb 4, 2019
 *      Author: mark
 */

#ifndef SEND_DATA_TO_BLACKBOX_H_
#define SEND_DATA_TO_BLACKBOX_H_

#endif /* SEND_DATA_TO_BLACKBOX_H_ */


#include <unistd.h>
#include <stdio.h>

void Send_Data_To_BlackBox(char *IP_Out_To_BlackBox, int Port_Out_To_BlackBox, char *PIN44_Status_Value ){

//printf("Send_Data_To_BlackBox with IP Address of %s a port of %d Pin 44 value of %i\n",IP_Out_To_BlackBox,Port_Out_To_BlackBox,PIN44_Status_Value);

	int sock;
	struct sockaddr_in server;

	sock = socket(AF_INET , SOCK_STREAM , 0);
		if (sock == -1)
		{
			printf("Could not create socket");
		}
		//puts("Socket created");


		server.sin_addr.s_addr = inet_addr(IP_Out_To_BlackBox);
		server.sin_family = AF_INET;
		server.sin_port = htons(Port_Out_To_BlackBox);

		//Connect to remote server
		if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
			{
				perror("connect failed. Error");
			}

		printf("Connected to BlackBox");

		char SendDataValue;						//This is done to move the data into a pointer
		char *SendData = &SendDataValue;		//This is done to move the data into a pointer
		*SendData = *PIN44_Status_Value;		//This is done to move the data into a pointer


		char *message_fmt = "POST / HTTP/1.0 content-type: application/json Content-Length: %s\r\n\r\n%s";
		char message[1024];



		int LenOfData;							//This is done to get The LenOfData from an Integer to a string for proper formating
		char LENOFData[5];						//This is done to get The LenOfData from an Integer to a string for proper formating
		LenOfData = strlen(SendData);			//This is done to get The LenOfData from an Integer to a string for proper formating
		sprintf(LENOFData,"%d",LenOfData);		//This is done to get The LenOfData from an Integer to a string for proper formating


		sprintf(message,message_fmt,LENOFData,SendData); //Format and apply data

		printf("\n%s\n",message);
		send(sock , message,strlen(message),0); 		//Send Built Stream To BlackBox



		close(sock);

	return;
}

