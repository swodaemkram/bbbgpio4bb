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

void Send_Data_To_BlackBox(char *IP_Out_To_BlackBox, int Port_Out_To_BlackBox, char *IO_Status_Value, int Verbose){

	//printf("IO_Status_Value = %s \n",IO_Status_Value);

	//char LogMessage_From_Send_Data_To_BlackBox[250] = {0};
	int sock;
	struct sockaddr_in server;

	sock = socket(AF_INET , SOCK_STREAM , 0);
		if (sock == -1)
		{
			if (Verbose == 1){
			printf("Could not create socket");
			return;
			}
		}
		//puts("Socket created");

		server.sin_addr.s_addr = inet_addr(IP_Out_To_BlackBox);
		server.sin_family = AF_INET;
		server.sin_port = htons(Port_Out_To_BlackBox);

		//Connect to remote server
		if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
			{
				if (Verbose == 1){
				perror("connect failed. Error");
				return;
				}
			}

		if (Verbose == 1){
		printf("Connected to BlackBox ....");
				}
/*
================================================================================================================================
Connected to BlackBox, Format data into JSON Format
================================================================================================================================
 */
		char *SendData = IO_Status_Value;
		char *Duped_SendData = {0};
		Duped_SendData = strdup(SendData);
		//char *message_fmt = "POST / HTTP/1.0 content-type: application/json Content-Length: %s\r\n\r\n%s";

		char message[1024];

		int LenOfData;							         //This is done to get The LenOfData from an Integer to a string for proper formating
		char LENOFData[5];						         //This is done to get The LenOfData from an Integer to a string for proper formating
		LenOfData = strlen(SendData)+ 78;			     //This is done to get The LenOfData from an Integer to a string for proper formating
		sprintf(LENOFData,"%d",LenOfData);		         //This is done to get The LenOfData from an Integer to a string for proper formating

/*
===============================================================================================================================
Break Digital and Analog Data Apart
===============================================================================================================================
 */
		char *Digital_Data = {0};
		char *Analog_Data = {0};

		Digital_Data = strsep(&Duped_SendData,"|");
		Analog_Data = strsep(&Duped_SendData, "|");

		//printf("\nDigital_Data = %s\n",Digital_Data);
		//printf("\nAnalog_Data = %s\n",Analog_Data);

		//exit(0);

		char *message_fmt = "POST / HTTP/1.0 content-type: application/json Content-Length: %s\r\n\r\n{\"OnBoardIO\":[{\"id\":\"Digital_I/O\",\"Status\":\"%s\"},{\"id\":\"Analog_I/O\",\"Status\":\"%s\"}]}";

		sprintf(message,message_fmt,LENOFData,Digital_Data,Analog_Data); //Format and apply data

		if(Verbose == 1){
		printf("\n%s\n",message);
		}
		send(sock , message,strlen(message),0); 		 //Send Built Stream To BlackBox

		close(sock);

	return;
}

