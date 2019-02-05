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

void Send_Data_To_BlackBox(char *IP_Out_To_BlackBox, int Port_Out_To_BlackBox, int PIN44_Status_Value ){

printf("Send_Data_To_BlackBox with IP Address of %s a port of %d Pin 44 value of %i\n",IP_Out_To_BlackBox,Port_Out_To_BlackBox,PIN44_Status_Value);

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

		char SendDataValue;					//This is done to move the data into a pointer
		char *SendData = &SendDataValue;	//This is done to move the data into a pointer
		*SendData = PIN44_Status_Value;		//This is done to move the data into a pointer

		send(sock , "POST  HTTP/1.1\n",20,0);
		send(sock, "Content-Type: application/x-www-form-urlencoded\n",49,0);
		send(sock, "Content-Length: 3\n",19,0);
		send(sock , SendData, strlen(SendData),0);
		send(sock ,"\n",2,0);



		printf(" Sent ... %d\n",PIN44_Status_Value);

		close(sock);

	return;
}

