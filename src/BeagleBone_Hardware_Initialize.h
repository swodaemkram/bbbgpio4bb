/*
 * BeagleBone_Hardware_Initialize.h
 *
 *  Created on: Feb 4, 2019
 *      Author: mark
 */

#ifndef BEAGELBONE_HARDWARE_INITIALIZE_H_
#define BEAGELBONE_HARDWARE_INITIALIZE_H_

#endif /* BEAGELBONE_HARDWARE_INITIALIZE_H_ */

#include <unistd.h>
#include <stdio.h>


void BeagelBone_Hardware_Initialize(void){


/*
====================================================================================================================================
Initialize 8 PINs for Export as Digital Inputs [44,65,46,26,68,67,66,69]
===================================================================================================================================
*/


	char log_message [250] = {0};
		strncpy(log_message,"Starting BeagleBone Hardware Initialization... ",47);
		log_Function(log_message);



	FILE *IO_Config_File = NULL;                            	// declare GPIO file Setup Pointer

	IO_Config_File = fopen("/sys/class/gpio/export", "w");  	// Open the export file for writing
	if (IO_Config_File == NULL){
	printf("\nProblem opening the export file this program must be run as root.\n");
	exit(1);
	}
	fwrite("44",1,sizeof("44"),IO_Config_File);					// Export pin 44
	fclose(IO_Config_File);										// Close the export file

	IO_Config_File = fopen("/sys/class/gpio/export", "w");  	// Open the export file for writing
	if (IO_Config_File == NULL){
		printf("\nProblem opening the export file this program must be run as root.\n");
		exit(1);
		}
	fwrite("65",1,sizeof("65"),IO_Config_File);				// Export pin 65
		fclose(IO_Config_File);									// Close the export file

	IO_Config_File = fopen("/sys/class/gpio/export", "w");  	// Open the export file for writing
	if (IO_Config_File == NULL){
		printf("\nProblem opening the export file this program must be run as root.\n");
		exit(1);
		}
	fwrite("46",1,sizeof("46"),IO_Config_File);				// Export pin 46
		fclose(IO_Config_File);									// Close the export file

	IO_Config_File = fopen("/sys/class/gpio/export", "w");  	// Open the export file for writing
		if (IO_Config_File == NULL){
		printf("\nProblem opening the export file this program must be run as root.\n");
		exit(1);
		}
	fwrite("26",1,sizeof("26"),IO_Config_File);				// Export pin 26
		fclose(IO_Config_File);									// Close the export file

	IO_Config_File = fopen("/sys/class/gpio/export", "w");  	// Open the export file for writing
	    if (IO_Config_File == NULL){
		printf("\nProblem opening the export file this program must be run as root.\n");
		exit(1);
		}
	fwrite("68",1,sizeof("68"),IO_Config_File);				// Export pin 68
		fclose(IO_Config_File);									// Close the export file

	IO_Config_File = fopen("/sys/class/gpio/export", "w");  	// Open the export file for writing
		if (IO_Config_File == NULL){
		printf("\nProblem opening the export file this program must be run as root.\n");
		exit(1);
		}
	fwrite("67",1,sizeof("67"),IO_Config_File);				// Export pin 67
		fclose(IO_Config_File);									// Close the export file

	IO_Config_File = fopen("/sys/class/gpio/export", "w");  	// Open the export file for writing
		if (IO_Config_File == NULL){
		printf("\nProblem opening the export file this program must be run as root.\n");
		exit(1);
		}
	fwrite("66",1,sizeof("66"),IO_Config_File);				// Export pin 66
		fclose(IO_Config_File);									// Close the export file

	IO_Config_File = fopen("/sys/class/gpio/export", "w");  	// Open the export file for writing
		if (IO_Config_File == NULL){
		printf("\nProblem opening the export file this program must be run as root.\n");
		exit(1);
		}
	fwrite("69",1,sizeof("69"),IO_Config_File);				// Export pin 69
		fclose(IO_Config_File);									// Close the export file
/*
=================================================================================================================================
Make sure all the above PINs are set to INPUTS
=================================================================================================================================
 */
		IO_Config_File = fopen("/sys/class/gpio/gpio44/direction", "w");  	// Open the pin 44 direction file for writing
			if (IO_Config_File == NULL){
			printf("\nProblem opening the export file this program must be run as root.\n");
			exit(1);
			}
		fwrite("in",1,sizeof("in"),IO_Config_File);					    // Set direction for PIN44 to in
			fclose(IO_Config_File);										    // Close the direction file

		IO_Config_File = fopen("/sys/class/gpio/gpio65/direction", "w");  	// Open the pin 65 direction file for writing
			if (IO_Config_File == NULL){
			printf("\nProblem opening the export file this program must be run as root.\n");
			exit(1);
			}
		fwrite("in",1,sizeof("in"),IO_Config_File);					    // Set direction for PIN65 to in
			fclose(IO_Config_File);										    // Close the direction file

		IO_Config_File = fopen("/sys/class/gpio/gpio46/direction", "w");  	// Open the pin 46 direction file for writing
			if (IO_Config_File == NULL){
			printf("\nProblem opening the export file this program must be run as root.\n");
			exit(1);
			}
		fwrite("in",1,sizeof("in"),IO_Config_File);					    // Set direction for PIN46 to in
			fclose(IO_Config_File);										    // Close the direction file

		IO_Config_File = fopen("/sys/class/gpio/gpio26/direction", "w");  	// Open the pin 26 direction file for writing
			if (IO_Config_File == NULL){
			printf("\nProblem opening the export file this program must be run as root.\n");
			exit(1);
			}
		fwrite("in",1,sizeof("in"),IO_Config_File);					    // Set direction for PIN26 to in
			fclose(IO_Config_File);										    // Close the direction file

		IO_Config_File = fopen("/sys/class/gpio/gpio68/direction", "w");  	// Open the pin 68 direction file for writing
			if (IO_Config_File == NULL){
			printf("\nProblem opening the export file this program must be run as root.\n");
			exit(1);
			}
		fwrite("low",1,sizeof("low"),IO_Config_File);					    // Set direction for PIN68 to in
			fclose(IO_Config_File);										    // Close the direction file

		IO_Config_File = fopen("/sys/class/gpio/gpio67/direction", "w");  	// Open the pin 67 direction file for writing
			if (IO_Config_File == NULL){
			printf("\nProblem opening the export file this program must be run as root.\n");
			exit(1);
			}
		fwrite("low",1,sizeof("low"),IO_Config_File);					    // Set direction for PIN67 to in
			fclose(IO_Config_File);										    // Close the direction file

		IO_Config_File = fopen("/sys/class/gpio/gpio66/direction", "w");  	// Open the pin 66 direction file for writing
			if (IO_Config_File == NULL){
			printf("\nProblem opening the export file this program must be run as root.\n");
			exit(1);
			}
		fwrite("low",1,sizeof("low"),IO_Config_File);					    // Set direction for PIN66 to in
			fclose(IO_Config_File);										    // Close the direction file

		IO_Config_File = fopen("/sys/class/gpio/gpio69/direction", "w");  	// Open the pin 69 direction file for writing
			if (IO_Config_File == NULL){
			printf("\nProblem opening the export file this program must be run as root.\n");
			exit(1);
			}
		fwrite("low",1,sizeof("low"),IO_Config_File);					    // Set direction for PIN69 to in
			fclose(IO_Config_File);										    // Close the direction file


/*
===================================================================================================================================
Finished Initializing Digital Input PINs
===================================================================================================================================
===================================================================================================================================
Initialize Analog Inputs
===================================================================================================================================
*/

		IO_Config_File = fopen("/sys/devices/platform/bone_capemgr/slots", "w");  	// Enable The Analog Input Driver
			if (IO_Config_File == NULL){
			printf("\nProblem opening the analog pins export file make sure the ADC driver is installed.\n");
			exit(1);
			}
		fwrite("BB-ADC",1,sizeof("BB-ADC"),IO_Config_File);					    // Write the Drivers name in file
			fclose(IO_Config_File);										            // Close the file

/*
===================================================================================================================================
Finished Initializing Analog Inputs
===================================================================================================================================
 */
	//printf("\nBeagleBone Hardware Initialized... \n");
	//char log_message [250] = {0};
	strncpy(log_message,"BeagleBone Hardware Initialized... ",36);
	log_Function(log_message);

return ;

}
