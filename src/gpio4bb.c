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

int main(int argc, char *argv[]){

char IP_Out_To_BlackBox[15] = {0};
int Port_Out_To_BlackBox = 0;
int Port_IN_From_BlackBox = 0;
char *New_IO_Status_Value = {0};

char Last_IO_Status_Value[37] = {0};
char IO_Status_Value[37] = {0};
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


printf("\nIP_Out_To_BlackBox = %s\n", IP_Out_To_BlackBox);
printf("Port_Out_To_BlackBox = %d\n", Port_Out_To_BlackBox );
printf("Port_IN_From_BlackBox = %d\n\n", Port_IN_From_BlackBox );

/*
======================================================================================================================
Main Program Loop
======================================================================================================================
*/

while(1){

		if(strcmp(IO_Status_Value, Last_IO_Status_Value) != 0){

		// Deubug Code printf("\nLast_IO_Status_Value = %s\nNew_IO_Status_Value = %s\n",Last_IO_Status_Value,New_IO_Status_Value);

			Send_Data_To_BlackBox(IP_Out_To_BlackBox, Port_Out_To_BlackBox, IO_Status_Value,  Verbose); //Send New Data To BlackBox

		//Last_IO_Status_Value[0] ='\0';

		strncpy(Last_IO_Status_Value,  IO_Status_Value, 38);

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
		New_IO_Status_Value = RaspberryPi_Get_IO_Status(); //are we raspberrypi ?	get I/O from raspberrypi
		}											          //are we raspberrypi ?
//=========================================================================================================================
//=========================================================================================================================
		dif = strcmp(HardwarePlatform, "usbio");          			  //are we usbio ?
				if (dif == 0){								          //are we usbio ?
				New_IO_Status_Value = USB_IO_Get_IO_Status(); //are we usbio ?	get I/O from usbio
				}											          //are we usbio ?
//=========================================================================================================================

// DEBUG !!! printf("\nIO_Status_Value = %s New_IO_Status_Value = %s\n", IO_Status_Value, New_IO_Status_Value);


		strncpy(IO_Status_Value, New_IO_Status_Value,38);

	usleep(500000);								             //This is set to .5 Seconds to keep the CPU usage to a minimum

	//RX_Data_From_BlackBox();                               // DEBUG INCOMING DATA FIRST !!!
}
/*
======================================================================================================================
End of Main Program Loop
=======================================================================================================================
 */

return(0);
}
