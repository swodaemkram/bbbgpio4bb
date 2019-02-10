/*
===========================================================================================================================
Name		:	gpio4bb.c
Author		:	Mark Meadows
Version		:	v 00.02.50
Copyright	:	Fireking Security Group
Description	:	Service to provide GPIO In and Out capability to BlackBox on the BeagelBone Hardware Platform
============================================================================================================================
*/


#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <stdlib.h>

#include "BeagelBone_Get_IO_Status.h"
#include "BeagelBone_Hardware_Initialize.h"
#include "BeagelBone_user_led2_flash.h"

#include "RaspberryPi_Hardware_Initialize.h"





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

				case 'A' :

					strcpy(IP_Out_To_BlackBox, argv[z+1]);
					break;

				case 'P':

					Port_Out_To_BlackBox = atoi(argv[z+1]);
					break;

				case 'p' :

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
 				   Print_Help();
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



/*
=======================================================================================================================
Simple Argument Verification Completed
======================================================================================================================
 */

//====================================================================================================================
	int dif;								  //are we beagelbone ?
dif = strcmp(HardwarePlatform, "beagelbone"); //are we beagelbone ?
if (dif == 0){								  //are we beagelbone ?
	BeagelBone_Hardware_Initialize();		  //are we beagelbone ?
}											  //are we beagelbone ?
//====================================================================================================================
 	 dif = strcmp(HardwarePlatform, "raspberrypi"); //are we RaspberryPi ?
 if (dif == 0){										//are we RaspberriPi ?
 		 RaspberryPi_Hardware_Initialize();			//are we RaspberryPi ?
 		  }
//====================================================================================================================
printf("\nIP_Out_To_BlackBox = %s\n", IP_Out_To_BlackBox);
printf("Port_Out_To_BlackBox = %d\n", Port_Out_To_BlackBox );
printf("Port_IN_From_BlackBox = %d\n\n", Port_IN_From_BlackBox );

//BeagelBone_user_led2_flash();       //flash user LED to show service is running

/*
======================================================================================================================
Main Program Loop
======================================================================================================================
*/

while(1){


	if(strcmp(IO_Status_Value, Last_IO_Status_Value) != 0){

		// Deubug Code printf("\nLast_IO_Status_Value = %s\nNew_IO_Status_Value = %s\n",Last_IO_Status_Value,New_IO_Status_Value);



			Send_Data_To_BlackBox(IP_Out_To_BlackBox, Port_Out_To_BlackBox, IO_Status_Value ); //Send New Data To BlackBox



		//Last_IO_Status_Value[0] ='\0';

		strncpy(Last_IO_Status_Value,  IO_Status_Value, 37);

	}


//=========================================================================================================================
	dif = strcmp(HardwarePlatform, "beagelbone");        //are we beagelbone ?
	if (dif == 0){								         //are we beagelbone ?
	   New_IO_Status_Value = BeagelBone_Get_IO_Status(); //are we beagelbone ?	get I/O from beagelbone
	}											         //are we beagelbone ?
//=========================================================================================================================


		strncpy(IO_Status_Value, New_IO_Status_Value,37);

	usleep(500000);								    //This is set to .5 Seconds to keep the CPU usage to a minimum

	//RX_Data_From_BlackBox();                      // DEBUG INCOMING DATA FIRST !!!
}
/*
======================================================================================================================
End of Main Program Loop
=======================================================================================================================
 */

return(0);
}
