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
	char log_message [250] = {0};
	//char LogMessage_From_Send_Data_To_BlackBox[250] = {0};
	int sock;
	struct sockaddr_in server;

	sock = socket(AF_INET , SOCK_STREAM , 0);
		if (sock == -1)
		{
			if (Verbose == 1){
			//printf("Could not create socket");
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
				//log_message[0] = '\0';
				//strcat(log_message, "BlackBox connection failed" );
				log_Function("BlackBox connection failed");
				close(sock);
				return;
				}

				//log_message[0] = '\0';
				//strcat(log_message, "BlackBox connection failed" );
				log_Function("BlackBox connection failed");
				close(sock);
				return;
			}

		//if (Verbose == 1){
		//printf("Connected to BlackBox ....");
		//		}

//log_message[0] = '\0';
//strcat(log_message, "Connected to BlackBox ...." );
log_Function("Connected to BlackBox ....");


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
		//LenOfData = strlen(SendData)+ 175;	//??????     //This is done to get The LenOfData from an Integer to a string for proper formating
		LenOfData = 150;
		sprintf(LENOFData,"%d",LenOfData);		         //This is done to get The LenOfData from an Integer to a string for proper formating

/*
===============================================================================================================================
Break Digital and Analog Data Apart
===============================================================================================================================
 */
		char *Digital_Data = {0};
		char *Analog_Data = {0};
		char *temp = {0};

		Digital_Data = strsep(&Duped_SendData,"|");
		Analog_Data = strsep(&Duped_SendData, "|");
		temp = strsep(&Duped_SendData, "|");
		//printf("\nDigital_Data = %s\n",Digital_Data);
		//printf("\nAnalog_Data = %s\n",Analog_Data);

		//exit(0);

		//char *message_fmt = "POST / HTTP/1.0 content-type: application/json Content-Length: %s\r\n\r\n{\"OnBoardIO\":[{\"id\":\"Digital_I/O\",\"Status\":\"%s\"},{\"id\":\"Analog_I/O\",\"Status\":\"%s\"}]}";

/*
===============================================================================================================================
Break Digital Data Apart
===============================================================================================================================
 */




/*
 ==============================================================================================================================
 Finished Breaking Digital Data Apart
 ==============================================================================================================================
 Old Json Object Sent to BlackBox
-------------------------------------------------------------------------------------------------------------------------------
char *message_fmt = "POST / HTTP/1.0 content-type: application/json Content-Length: %s\r\n\r\n{\"onboard_io\":[{\"id\":\"digital_io\",\"value\":\"%s\"},{\"id\":\"analog_io\",\"value\":\"%s\"}{\"id\":\"humi_temp\",\"value\":\"%s\"}]}";
sprintf(message,message_fmt,LENOFData,Digital_Data,Analog_Data,temp); //Format and apply data
-------------------------------------------------------------------------------------------------------------------------------
================================================================================================================================
New Json Object Below
================================================================================================================================
*/

//GOOD CODE !!!!!!!!!!!!!!!!!!
//char *message_fmt = "POST / HTTP/1.0 content-type: application/json Content-Length: 230 {"service":"[OnBoardIO]","type":"[Digital]","inputs":[{"id":1,"data":["1"]},{"id":2,"data":["4"]},{"id":3,"data":["4"]},{"id":4,"data":["4"]},{"id":5,"data":["4"]},{"id":6,"data":["4"]},{"id":7,"data":["4"]},{"id":8,"data":["5"]}]}"
//sprintf(message,message_fmt,LENOFData,Digital_Data,Analog_Data,temp); //Format and apply data
//GOOD CODE !!!!!!!!!!!!!!!!!!!

		//if(Verbose == 1){
		//printf("\n%s\n",message);
		//}
send(sock , message,strlen(message),0); 		 //Send Built Stream To BlackBox
close(sock);


		//log_message[0] = '\0';                            //debug
		//sprintf(log_message,"\n%s\n",message);			  //debug
		//log_Function(log_message);						  //debug
		//log_message[0] = '\0';							  //debug
		//sprintf(log_message,"\n((%d))\n",strlen(message));//debug
		//log_Function(log_message);						  //debug


return;
}

