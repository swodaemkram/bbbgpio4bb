/*
===========================================================================================================================
Name		:	bbbgpiobb.c
Author		:	Mark Meadows
Version		:	v 0.0.1
Copyright	:	Fireking Security Group
Description	:	Service to provide GPIO In and Out capability to BlackBox on the BeagelBone Hardware Platform
===========================================================================================================================
*/


#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <stdlib.h>


#include "user_led2_flash.h"
#include "Print_Help.h"
#include "Initialize_BeagelBone_Hardware.h"
#include "Get_IO_Status.h"
#include "Send_Data_To_BlackBox.h"
#include "RX_Data_From_BlackBox.h"
#include "Global_Variables.h"


int main(int argc, char *argv[]){

char IP_Out_To_BlackBox[15] = {0};
int Port_Out_To_BlackBox = 0;
int Port_IN_From_BlackBox = 0;
int PIN44_Status_Value = 0;
int Last_PIN44_Status_Value = 0;

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
				}

			}
		}
/*
======================================================================================================================
Command line arguments Loaded
======================================================================================================================
*/

Initialize_BeagelBone_Hardware();

printf("\nIP_Out_To_BlackBox = %s\n", IP_Out_To_BlackBox);
printf("Port_Out_To_BlackBox = %d\n", Port_Out_To_BlackBox );
printf("Port_IN_From_BlackBox = %d\n\n", Port_IN_From_BlackBox );

//user_led2_flash();       //flash user LED to show service is running

/*
======================================================================================================================
Main Program Loop
======================================================================================================================
*/

while(1){

	if(PIN44_Status_Value != Last_PIN44_Status_Value){

		printf("\nPIN44 Value = %d\n",PIN44_Status_Value );
		Last_PIN44_Status_Value = PIN44_Status_Value;
		Send_Data_To_BlackBox();                     //Send Data To BlackBox

	}



	PIN44_Status_Value = Get_IO_Status();           //Get IO Status
	//RX_Data_From_BlackBox();                     // DEBUG IN COMING DATA FIRST !!!

}
/*
======================================================================================================================
End of Main Program Loop
=======================================================================================================================
 */

return(0);
}
