/*
 * RaspberryPi_Hardware_Initialize.h
 *
 *  Created on: Feb 10, 2019
 *      Author: mark
 */

#ifndef RASPBERRYPI_HARDWARE_INITIALIZE_H_
#define RASPBERRYPI_HARDWARE_INITIALIZE_H_



#endif /* RASPBERRYPI_HARDWARE_INITIALIZE_H_ */


void RaspberryPi_Hardware_Initialize(void){


	FILE *IO_Config_File = NULL;                            	// declare GPIO file Setup Pointer

		IO_Config_File = fopen("/sys/class/gpio/export", "w");  	// Open the export file for writing
			if (IO_Config_File == NULL){
			printf("\nProblem opening the export file this program must be run as root.\n");
			exit(1);
			}
			fwrite("0",1,sizeof("0"),IO_Config_File);				// Export pin 0
			fclose(IO_Config_File);									// Close the export file

		IO_Config_File = fopen("/sys/class/gpio/export", "w");  	// Open the export file for writing
			if (IO_Config_File == NULL){
			printf("\nProblem opening the export file this program must be run as root.\n");
			exit(1);
			}
			fwrite("1",1,sizeof("1"),IO_Config_File);				// Export pin 1
			fclose(IO_Config_File);									// Close the export file

		IO_Config_File = fopen("/sys/class/gpio/export", "w");  	// Open the export file for writing
			if (IO_Config_File == NULL){
			printf("\nProblem opening the export file this program must be run as root.\n");
			exit(1);
			}
			fwrite("2",1,sizeof("2"),IO_Config_File);				// Export pin 2
			fclose(IO_Config_File);									// Close the export file

		IO_Config_File = fopen("/sys/class/gpio/export", "w");  	// Open the export file for writing
			if (IO_Config_File == NULL){
			printf("\nProblem opening the export file this program must be run as root.\n");
			exit(1);
			}
			fwrite("3",1,sizeof("3"),IO_Config_File);				// Export pin 3
			fclose(IO_Config_File);									// Close the export file

		IO_Config_File = fopen("/sys/class/gpio/export", "w");  	// Open the export file for writing
			if (IO_Config_File == NULL){
			printf("\nProblem opening the export file this program must be run as root.\n");
			exit(1);
			}
			fwrite("4",1,sizeof("4"),IO_Config_File);				// Export pin 4
			fclose(IO_Config_File);									// Close the export file

		IO_Config_File = fopen("/sys/class/gpio/export", "w");  	// Open the export file for writing
			if (IO_Config_File == NULL){
			printf("\nProblem opening the export file this program must be run as root.\n");
			exit(1);
			}
			fwrite("5",1,sizeof("5"),IO_Config_File);				// Export pin 5
			fclose(IO_Config_File);									// Close the export file

		IO_Config_File = fopen("/sys/class/gpio/export", "w");  	// Open the export file for writing
			fwrite("6",1,sizeof("6"),IO_Config_File);				// Export pin 6
			fclose(IO_Config_File);									// Close the export file

		IO_Config_File = fopen("/sys/class/gpio/export", "w");  	// Open the export file for writing
			if (IO_Config_File == NULL){
			printf("\nProblem opening the export file this program must be run as root.\n");
			exit(1);
			}
			fwrite("7",1,sizeof("7"),IO_Config_File);				// Export pin 7
			fclose(IO_Config_File);									// Close the export file
	/*
	=================================================================================================================================
	Make sure all the above PINs are set to INPUTS
	=================================================================================================================================
	 */
			IO_Config_File = fopen("/sys/class/gpio/gpio0/direction", "w");  	// Open the pin 0 direction file for writing
				if (IO_Config_File == NULL){
				printf("\nProblem opening the export file this program must be run as root.\n");
				exit(1);
				}
				fwrite("in",1,sizeof("in"),IO_Config_File);					    // Set direction for PIN1 to in
				fclose(IO_Config_File);										    // Close the direction file

			IO_Config_File = fopen("/sys/class/gpio/gpio1/direction", "w");  	// Open the pin 1 direction file for writing
				if (IO_Config_File == NULL){
				printf("\nProblem opening the export file this program must be run as root.\n");
				exit(1);
				}
				fwrite("in",1,sizeof("in"),IO_Config_File);					    // Set direction for PIN2 to in
				fclose(IO_Config_File);										    // Close the direction file

			IO_Config_File = fopen("/sys/class/gpio/gpio2/direction", "w");  	// Open the pin 2 direction file for writing
				if (IO_Config_File == NULL){
				printf("\nProblem opening the export file this program must be run as root.\n");
				exit(1);
				}
				fwrite("in",1,sizeof("in"),IO_Config_File);					    // Set direction for PIN3 to in
				fclose(IO_Config_File);										    // Close the direction file

			IO_Config_File = fopen("/sys/class/gpio/gpio3/direction", "w");  	// Open the pin 3 direction file for writing
				if (IO_Config_File == NULL){
				printf("\nProblem opening the export file this program must be run as root.\n");
				exit(1);
				}
				fwrite("in",1,sizeof("in"),IO_Config_File);					    // Set direction for PIN4 to in
				fclose(IO_Config_File);										    // Close the direction file

			IO_Config_File = fopen("/sys/class/gpio/gpio4/direction", "w");  	// Open the pin 4 direction file for writing
				if (IO_Config_File == NULL){
				printf("\nProblem opening the export file this program must be run as root.\n");
				exit(1);
				}
				fwrite("low",1,sizeof("low"),IO_Config_File);					    // Set direction for PIN5 to in
				fclose(IO_Config_File);										    // Close the direction file

			IO_Config_File = fopen("/sys/class/gpio/gpio5/direction", "w");  	// Open the pin 5 direction file for writing
				if (IO_Config_File == NULL){
				printf("\nProblem opening the export file this program must be run as root.\n");
				exit(1);
				}
				fwrite("low",1,sizeof("low"),IO_Config_File);					    // Set direction for PIN6 to in
				fclose(IO_Config_File);										        // Close the direction file

			IO_Config_File = fopen("/sys/class/gpio/gpio6/direction", "w");  	   // Open the pin 6 direction file for writing
				if (IO_Config_File == NULL){
				printf("\nProblem opening the export file this program must be run as root.\n");
				exit(1);
				}
				fwrite("low",1,sizeof("low"),IO_Config_File);					    // Set direction for PIN6 to in
				fclose(IO_Config_File);										        // Close the direction file

			IO_Config_File = fopen("/sys/class/gpio/gpio7/direction", "w");  	    // Open the pin 7 direction file for writing
				if (IO_Config_File == NULL){
				printf("\nProblem opening the export file this program must be run as root.\n");
				exit(1);
				}
				fwrite("low",1,sizeof("low"),IO_Config_File);					    // Set direction for PIN7 to in
				fclose(IO_Config_File);										        // Close the direction file


/*
===================================================================================================================================
Finished Initializing Digital Input PINs
===================================================================================================================================
*/

printf("\nRaspberry Pi Hardware Initialized... \n");

printf("Raspberry Pi");

return;

}
