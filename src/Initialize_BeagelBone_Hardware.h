/*
 * Initialize_BeagelBone_Hardware.h
 *
 *  Created on: Feb 4, 2019
 *      Author: mark
 */

#ifndef INITIALIZE_BEAGELBONE_HARDWARE_H_
#define INITIALIZE_BEAGELBONE_HARDWARE_H_

#endif /* INITIALIZE_BEAGELBONE_HARDWARE_H_ */

#include <unistd.h>
#include <stdio.h>

void Initialize_BeagelBone_Hardware(void){
/*
===================================================================================================================================
Initialize 8 PINs for Export as Inputs [44,65,46,26,68,67,66,69]
===================================================================================================================================
*/

	FILE *IO_Config_File = NULL;                            	// declare GPIO file Setup Pointer

	IO_Config_File = fopen("/sys/class/gpio/export", "w");  	// Open the export file for writing
	fwrite("44",1,sizeof("44"),IO_Config_File);					// Export pin 44
	fclose(IO_Config_File);										// Close the export file

	IO_Config_File = fopen("/sys/class/gpio/export", "w");  	// Open the export file for writing
		fwrite("65",1,sizeof("65"),IO_Config_File);				// Export pin 65
		fclose(IO_Config_File);									// Close the export file

	IO_Config_File = fopen("/sys/class/gpio/export", "w");  	// Open the export file for writing
		fwrite("46",1,sizeof("46"),IO_Config_File);				// Export pin 46
		fclose(IO_Config_File);									// Close the export file

	IO_Config_File = fopen("/sys/class/gpio/export", "w");  	// Open the export file for writing
		fwrite("26",1,sizeof("26"),IO_Config_File);				// Export pin 26
		fclose(IO_Config_File);									// Close the export file

	IO_Config_File = fopen("/sys/class/gpio/export", "w");  	// Open the export file for writing
		fwrite("68",1,sizeof("68"),IO_Config_File);				// Export pin 68
		fclose(IO_Config_File);									// Close the export file

	IO_Config_File = fopen("/sys/class/gpio/export", "w");  	// Open the export file for writing
		fwrite("67",1,sizeof("67"),IO_Config_File);				// Export pin 67
		fclose(IO_Config_File);									// Close the export file

	IO_Config_File = fopen("/sys/class/gpio/export", "w");  	// Open the export file for writing
		fwrite("66",1,sizeof("66"),IO_Config_File);				// Export pin 66
		fclose(IO_Config_File);									// Close the export file

	IO_Config_File = fopen("/sys/class/gpio/export", "w");  	// Open the export file for writing
		fwrite("69",1,sizeof("69"),IO_Config_File);				// Export pin 69
		fclose(IO_Config_File);									// Close the export file

/*
===================================================================================================================================
Finished Initializing Input PINs
===================================================================================================================================
 */











	printf("\nBeagelBone Hardware Initialized... \n");

return ;

}
