/*
===========================================================================================================================
Name		:	gpio4bb.c
Author		:	Mark Meadows
Version		:	v 01.00.00
Copyright	:	Fireking Security Group
Description	:	Service to provide GPIO In and Out capability to BlackBox on the Various Hardware Platforms
				BeagleBone, RaspberryPi, USBI/O board
============================================================================================================================
*/
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <signal.h>

#include "BeagleBone_Get_IO_Status.h"
#include "BeagleBone_Hardware_Initialize.h"
#include "BeagleBone_user_led2_flash.h"


#include "RaspberryPi_Hardware_Initialize.h"
#include "RaspberryPi_Get_IO_Status.h"

#include "USB_IO_Initialize.h"
#include "USB_IO_Get_IO_Status.h"

#include "Print_Help.h"
#include "Send_Data_To_BlackBox.h"
#include "RX_Data_From_BlackBox.h"

#include "log_Function.h"
#include "Signal_Handler.h"

#include "dht11Read.h"
#include "get_ip_address.h"

int main(int argc, char *argv[]){

/*
===================================================================================================================
Make Sure We Only Run Once
===================================================================================================================
 */

int Config_File = 0;

FILE *pid_lock = NULL;                            	// declare pid lock file

	pid_lock = fopen("/run/gpio4bb.pid", "r");
	if (pid_lock != NULL){
		fclose(pid_lock);
		printf("\n gpio4bb is all ready running\n");
		exit(1);
	}

	pid_lock = fopen("/run/gpio4bb.pid", "w+");  	// Open the pid file for writing
	if (pid_lock == NULL){
	printf("\ncould not open lock file.\n");
	exit(1);
	}
	char strpid[6] = {0} ;
	int pid;
	pid = getpid();
	sprintf(strpid,"%d",pid);
	fwrite(strpid,1,sizeof(strpid),pid_lock);
	fclose(pid_lock);										// Close pid lock file

/*
======================================================================================================================
end of run once check
======================================================================================================================
 */

char log_message [250] = {0};								  // Send Program Started to the log
//strncpy(log_message,"gpio4bb service started ....",29);       // Send Program Started to the log
log_Function("gpio4bb service started ....");				  // Send Program Started to the log

char IP_Out_To_BlackBox[15] = {0};
int Port_Out_To_BlackBox = 0;
int Port_IN_From_BlackBox = 0;
char *New_IO_Status_Value = {0};

//char Last_IO_Status_Value[37] = "0:0:0:0:0:0:0:0|00:00:00:00:00:00:00|";
char Last_IO_Status_Value[48] = {0};/////!!!!! 47 48?
Last_IO_Status_Value[0] = '\0';
//char IO_Status_Value[38] = {0};
char IO_Status_Value[48] = "0:0:0:0:0:0:0:0|00:00:00:00:00:00:00|00.0:00.0|";
char HardwarePlatform[10] = {0};
int Verbose = 0;

/*
==========================================================================================================================
Load Command line arguments
==========================================================================================================================
 */

	int z;
	for (z=1; z < argc; z++)
		{
			if (argv[z][0] == '-')

			{
				switch (argv[z][1])

				{

				case 'a' :

					strcpy(IP_Out_To_BlackBox, argv[z+1]);
					break;

				case 'p':

					Port_Out_To_BlackBox = atoi(argv[z+1]);
					break;

				case 'P' :

					Port_IN_From_BlackBox = atoi(argv[z+1]);
					break;

				case 'h' :
				   Print_Help();
					break;

				case 'H' :
				   Print_Help();
				    break;

 				case 'v' :
 				   Print_Help();
					break;


 				case 'w' :
 					strcpy(HardwarePlatform, argv[z+1]);
 					break;

 				case 'c':
 					Config_File = 1;
 					break;

				}

			}
		}
/*
======================================================================================================================
Command line arguments Loaded
======================================================================================================================
======================================================================================================================
Simple Argument Verification
======================================================================================================================
*/

if (Config_File != 1){

	if (strlen(IP_Out_To_BlackBox)< 7){
	 Print_Help();
	}

	if (Port_Out_To_BlackBox < 80){
	 Print_Help();
	}

//if (Port_IN_From_BlackBox < 80){
//	 Print_Help();
// }

	int dif;

	dif =  strcmp(HardwarePlatform, "beaglebone");
 	if (dif != 0){
 		 	 dif = strcmp(HardwarePlatform, "raspberrypi");
 		 	 	 if (dif != 0){
 		 	 		 	 dif = strcmp(HardwarePlatform, "usbio");
 		 	 	 	 	 	   }

 		 	 	 	 	 if (dif != 0){
 		 	 	 	 		 // printf("\nThe %s platform is not supported yet ....\n",HardwarePlatform);
 		 	 	 	 		 //char log_message [250] = {0};								  // Send to the log
 		 	 	 	 		 //strncpy(log_message,"platform is not supported yet .... ",35);   // Send to the log
 		 	 	 	 		 log_Function("platform is not supported yet .... ");			  // Send to the log
 		 	 	 	 		 Print_Help();
 		 	 	 	 	 	 	 	 }
 	 	 	 	 }
	}
/*
=======================================================================================================================
Simple Argument Verification Completed
=======================================================================================================================
 Read Configuration from config file c argument provided
=======================================================================================================================
 */

 if (Config_File == 1) {

	        log_message[0] = '\0';
	 		strcat(log_message, "Reading config from /etc/gpio4bb.conf" );
	 		log_Function(log_message);

	 		FILE *Config_File = NULL;                        // declare config file Pointer

	 		Config_File = fopen("/etc/gpio4bb.conf", "r");  	// Open config file
	 		if (Config_File == NULL){
	 			//log_message[0] = '\0';
	 			//strcat(log_message, "Could not open /etc/gpio4bb.conf" );
	 			log_Function("Could not open /etc/gpio4bb.conf");
	 			remove("/run/gpio4bb.pid");
	 			exit(1);
	 		}

	 		fscanf(Config_File,"%s", HardwarePlatform);
	 		fscanf(Config_File,"%s", IP_Out_To_BlackBox);
	 		fscanf(Config_File,"%d",&Port_Out_To_BlackBox);
	 		fscanf(Config_File,"%d",&Port_IN_From_BlackBox);
	 		fclose(Config_File);

 }
//=======================================================================================================================
// Finished Reading Config File
//=======================================================================================================================

		log_message[0] = '\0';
		char *message_fmt = "Port_Out_To_BlackBox = %d";
		sprintf(log_message,message_fmt,Port_Out_To_BlackBox);
		log_Function(log_message);

		log_message[0] = '\0';
		message_fmt = "Port_IN_From_BlackBox = %d";
		sprintf(log_message,message_fmt,Port_IN_From_BlackBox);
		log_Function(log_message);

		log_message[0] = '\0';
		message_fmt = "Hardware Platform is  = %s";
		sprintf(log_message,message_fmt,HardwarePlatform);
		log_Function(log_message);

		log_message[0] = '\0';
	 	message_fmt = "IP Out to BlackBox is  = %s";
	 	sprintf(log_message,message_fmt,IP_Out_To_BlackBox);
	 	log_Function(log_message);
	 	log_message[0] = '\0';
//====================================================================================================================
		int dif;								                    //are we beaglebone ?
		dif = strcmp(HardwarePlatform, "beaglebone");               //are we beaglebone ?
		if (dif == 0){								                //are we beaglebone ?
				BeagelBone_Hardware_Initialize();	                //are we beaglebone ?
		}											                //are we beaglebone ?
//====================================================================================================================
		 	 dif = strcmp(HardwarePlatform, "raspberrypi");         //are we RaspberryPi ?
		 	 if (dif == 0){									        //are we RaspberriPi ?
		 		 RaspberryPi_Hardware_Initialize();			        //are we RaspberryPi ?
		 		  }													//are we RaspberryPi ?
//====================================================================================================================
		 	 dif = strcmp(HardwarePlatform, "usbio");				//are we USBIO ?
		 	 if (dif == 0){											//are we USBIO ?
			 	 USB_IO_Initialize();								//are we USBIO ?
		 }															//are we USBIO ?
//=====================================================================================================================

//printf("\nIP_Out_To_BlackBox = %s\n", IP_Out_To_BlackBox);
//printf("Port_Out_To_BlackBox = %d\n", Port_Out_To_BlackBox );
//printf("Port_IN_From_BlackBox = %d\n\n", Port_IN_From_BlackBox );

/*
======================================================================================================================
Main Program Loop
======================================================================================================================
*/

get_ip_address();						//Lets find out what our I.P. Address is
sleep(5);                            // This delay makes sure everything has settled before the service starts

while(1){

	    signal(SIGTERM,Signal_Handler);

		if(strcmp(IO_Status_Value, Last_IO_Status_Value) != 0){
		//printf("\nLast_IO_Status_Value = %s\n New_IO_Status_Value = %s\n",Last_IO_Status_Value,New_IO_Status_Value);
		log_Function(IO_Status_Value);
		//log_Function(Last_IO_Status_Value);
		Send_Data_To_BlackBox(IP_Out_To_BlackBox, Port_Out_To_BlackBox, IO_Status_Value,  Verbose); //Send New Data To BlackBox
		//Last_IO_Status_Value[0] ='\0';
		strncpy(Last_IO_Status_Value,  IO_Status_Value, 48);/////!!!!!

	}

//=========================================================================================================================
	dif = strcmp(HardwarePlatform, "beaglebone");            	  //are we beaglebone ?
		if (dif == 0){								              //are we beaglebone ?
	    New_IO_Status_Value = BeagelBone_Get_IO_Status();    	  //are we beaglebone ?	get I/O from beagelbone
	    BeagelBone_user_led2_flash();                         	  //flash user LED to show service is running
   	}											             	  //are we beaglebone ?
//=========================================================================================================================
//=========================================================================================================================
		dif = strcmp(HardwarePlatform, "raspberrypi");    	      //are we raspberrypi ?
			if (dif == 0){								          //are we raspberrypi ?
			New_IO_Status_Value = RaspberryPi_Get_IO_Status();    //are we raspberrypi ?	get I/O from raspberrypi
		}											              //are we raspberrypi ?
//=========================================================================================================================
//=========================================================================================================================
		dif = strcmp(HardwarePlatform, "usbio");          			  //are we usbio ?
				if (dif == 0){								          //are we usbio ?
				New_IO_Status_Value = USB_IO_Get_IO_Status();         //are we usbio ?	get I/O from usbio
				}											          //are we usbio ?
//=========================================================================================================================

// DEBUG !!! printf("\nIO_Status_Value = %s New_IO_Status_Value = %s\n", IO_Status_Value, New_IO_Status_Value);

	strncpy(IO_Status_Value, New_IO_Status_Value,48);/////!!!!!
	signal(SIGTERM,Signal_Handler);
	//usleep(200000); //after adding DHT11 this delay was no longer needed //This is set to .5 Seconds to keep the CPU usage to a minimum
	signal(SIGTERM,Signal_Handler);
	//RX_Data_From_BlackBox();                               // DEBUG INCOMING DATA FIRST !!!
}
/*
======================================================================================================================
End of Main Program Loop
=======================================================================================================================
 */
remove("/run/gpio4bb.pid");
return(0);
}
