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

	FILE *IO_Config_File = NULL;                            // declare GPIO file Setup Pointer

	IO_Config_File = fopen("/sys/class/gpio/export", "w");  // Open the export file for writing
	fwrite("44",1,sizeof("44"),IO_Config_File);				// Export pin 44
	fclose(IO_Config_File);									// Close the export file


printf("BeagelBone Hardware Initialized... \n");

return ;

}
