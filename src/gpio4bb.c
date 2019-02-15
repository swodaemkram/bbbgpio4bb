/*
===========================================================================================================================
Name		:	gpio4bb.c
Author		:	Mark Meadows
Version		:	v 00.03.30
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


#define SIGHUP  1   /* Hangup the process */
#define SIGINT  2   /* Interrupt the process */
#define SIGQUIT 3   /* Quit the process */
#define SIGILL  4   /* Illegal instruction. */
#define SIGTRAP 5   /* Trace trap. */
#define SIGABRT 6   /* Abort. */



int main(int argc, char *argv[]){

/*
===================================================================================================================
Make Sure We Only Run Once
===================================================================================================================
 */

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
strncpy(log_message,"gpio4bb service started ....",29);       // Send Program Started to the log
log_Function(log_message);									  // Send Program Started to the log

char IP_Out_To_BlackBox[15] = {0};
int Port_Out_To_BlackBox = 0;
int Port_IN_From_BlackBox = 0;
char *New_IO_Status_Value = {0};

//char Last_IO_Status_Value[37] = "0:0:0:0:0:0:0:0|00:00:00:00:00:00:00|";
char Last_IO_Status_Value[38] = {0};
//char IO_Status_Value[38] = {0};
char IO_Status_Value[38] = "0:0:0:0:0:0:0:0|00:00:00:00:00:00:00|";
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

 				case 'V' :
 				   Verbose = 1;
 				    break;

 				case 'w' :
 					strcpy(HardwarePlatform, argv[z+1]);
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
 		 	 	 		 printf("\nThe %s platform is not supported yet ....\n",HardwarePlatform);
 		 	 	 		char log_message [250] = {0};								  // Send to the log
 		 	 	 		strncpy(log_message,"platform is not supported yet .... ",35);// Send to the log
 		 	 	 		log_Function(log_message);									  // Send to the log
 		 	 	 		Print_Help();
 			 }
 	 }

/*
=======================================================================================================================
Simple Argument Verification Completed
======================================================================================================================
 */

//====================================================================================================================
	//int dif;								                //are we beaglebone ?
dif = strcmp(HardwarePlatform, "beaglebone");               //are we beaglebone ?
if (dif == 0){								                //are we beaglebone ?
	BeagelBone_Hardware_Initialize();		                //are we beaglebone ?
}											                //are we beaglebone ?
//====================================================================================================================
 	 dif = strcmp(HardwarePlatform, "raspberrypi");         //are we RaspberryPi ?
 if (dif == 0){										        //are we RaspberriPi ?
 		 RaspberryPi_Hardware_Initialize();			        //are we RaspberryPi ?
 		  }													//are we RaspberryPi ?
//====================================================================================================================
 	 dif = strcmp(HardwarePlatform, "usbio");				//are we USBIO ?
 if (dif == 0){												//are we USBIO ?
	 	 USB_IO_Initialize();								//are we USBIO ?
 }															//are we USBIO ?
//=====================================================================================================================

//printf("\nIP_Out_To_BlackBox = %s\n", IP_Out_To_BlackBox);
//printf("Port_Out_To_BlackBox = %d\n", Port_Out_To_BlackBox );
//printf("Port_IN_From_BlackBox = %d\n\n", Port_IN_From_BlackBox );

	log_message[0] = '\0';
		strcat(log_message, "IP_Out_To_Blackbox  = " );
		strcat(log_message, IP_Out_To_BlackBox);
		log_Function(log_message);

	log_message[0] = '\0';
	char *message_fmt = "Port_Out_To_BlackBox = %d";
	sprintf(log_message,message_fmt,Port_Out_To_BlackBox);
	log_Function(log_message);

	log_message[0] = '\0';
		message_fmt = "Port_IN_From_BlackBox = %d";
		sprintf(log_message,message_fmt,Port_IN_From_BlackBox);
		log_Function(log_message);
/*
======================================================================================================================
Main Program Loop
======================================================================================================================
*/



while(1){

	    signal(SIGTERM,Signal_Handler);


		if(strcmp(IO_Status_Value, Last_IO_Status_Value) != 0){

		//printf("\nLast_IO_Status_Value = %s\n New_IO_Status_Value = %s\n",Last_IO_Status_Value,New_IO_Status_Value);



			log_Function(IO_Status_Value);

			Send_Data_To_BlackBox(IP_Out_To_BlackBox, Port_Out_To_BlackBox, IO_Status_Value,  Verbose); //Send New Data To BlackBox

		//Last_IO_Status_Value[0] ='\0';

		strncpy(Last_IO_Status_Value,  IO_Status_Value, 37);

	}

//=========================================================================================================================
	dif = strcmp(HardwarePlatform, "beaglebone");             //are we beaglebone ?
	if (dif == 0){								              //are we beaglebone ?
	   New_IO_Status_Value = BeagelBone_Get_IO_Status();      //are we beaglebone ?	get I/O from beagelbone
	   BeagelBone_user_led2_flash();                          //flash user LED to show service is running
   	}											              //are we beaglebone ?
//=========================================================================================================================
//=========================================================================================================================
	dif = strcmp(HardwarePlatform, "raspberrypi");            //are we raspberrypi ?
		if (dif == 0){								          //are we raspberrypi ?
		New_IO_Status_Value = RaspberryPi_Get_IO_Status();    //are we raspberrypi ?	get I/O from raspberrypi
		}											          //are we raspberrypi ?
//=========================================================================================================================
//=========================================================================================================================
		dif = strcmp(HardwarePlatform, "usbio");          			  //are we usbio ?
				if (dif == 0){								          //are we usbio ?
				New_IO_Status_Value = USB_IO_Get_IO_Status();         //are we usbio ?	get I/O from usbio
				}											          //are we usbio ?
//=========================================================================================================================

// DEBUG !!! printf("\nIO_Status_Value = %s New_IO_Status_Value = %s\n", IO_Status_Value, New_IO_Status_Value);


		strncpy(IO_Status_Value, New_IO_Status_Value,37);

	signal(SIGTERM,Signal_Handler);
	usleep(500000);								             //This is set to .5 Seconds to keep the CPU usage to a minimum
	signal(SIGTERM,Signal_Handler);
	//RX_Data_From_BlackBox();                               // DEBUG INCOMING DATA FIRST !!!
}
/*
======================================================================================================================
End of Main Program Loop
=======================================================================================================================
 */

return(0);
}
