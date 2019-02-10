/*
 * BeagelBone_Get_IO_Status.h
 *
 *  Created on: Feb 4, 2019
 *      Author: mark
 */

#ifndef BEAGELBONE_GET_IO_STATUS_H_
#define BEAGELBONE_GET_IO_STATUS_H_
#endif /*BEAGELBONE_GET_IO_STATUS_H_ */

#include <unistd.h>
#include <stdio.h>

char *BeagelBone_Get_IO_Status(void){
/*
====================================================================================================================================
Start of Digital INPUT Handler
====================================================================================================================================
 */
	char PIN44_Status_Value = {0};
	FILE *PIN44_Status = NULL; //declare PIN44 Pointer
	PIN44_Status = fopen("/sys/class/gpio/gpio44/value", "r");
	PIN44_Status_Value = fgetc(PIN44_Status);
	PIN44_Status_Value = PIN44_Status_Value - 48;
	fclose(PIN44_Status);

	char PIN65_Status_Value = {0};
	FILE *PIN65_Status = NULL; //declare PIN65 Pointer
	PIN65_Status = fopen("/sys/class/gpio/gpio65/value", "r");
	PIN65_Status_Value = fgetc(PIN65_Status);
	PIN65_Status_Value = PIN65_Status_Value -48;
	fclose(PIN65_Status);

	char PIN46_Status_Value = {0};
	FILE *PIN46_Status = NULL; //declare PIN46 Pointer
	PIN46_Status = fopen("/sys/class/gpio/gpio46/value", "r");
	PIN46_Status_Value = fgetc(PIN46_Status);
	PIN46_Status_Value = PIN46_Status_Value - 48;
	fclose(PIN46_Status);

	char PIN26_Status_Value = {0};
	FILE *PIN26_Status = NULL; //declare PIN26 Pointer
	PIN26_Status = fopen("/sys/class/gpio/gpio26/value", "r");
	PIN26_Status_Value = fgetc(PIN26_Status);
	PIN26_Status_Value = PIN26_Status_Value - 48;
	fclose(PIN26_Status);

	char PIN68_Status_Value = {0};
	FILE *PIN68_Status = NULL; //declare PIN68 Pointer
	PIN68_Status = fopen("/sys/class/gpio/gpio68/value", "r");
	PIN68_Status_Value = fgetc(PIN68_Status);
	PIN68_Status_Value = PIN68_Status_Value - 48;
	fclose(PIN68_Status);

	char PIN67_Status_Value = {0};
	FILE *PIN67_Status = NULL; //declare PIN67 Pointer
	PIN67_Status = fopen("/sys/class/gpio/gpio67/value", "r");
	PIN67_Status_Value = fgetc(PIN67_Status);
	PIN67_Status_Value = PIN67_Status_Value - 48;
	fclose(PIN67_Status);

	char PIN66_Status_Value = {0};
	FILE *PIN66_Status = NULL; //declare PIN66 Pointer
	PIN66_Status = fopen("/sys/class/gpio/gpio66/value", "r");
	PIN66_Status_Value = fgetc(PIN66_Status);
	PIN66_Status_Value = PIN66_Status_Value - 48;
	fclose(PIN66_Status);

	char PIN69_Status_Value = {0};
	FILE *PIN69_Status = NULL; //declare PIN69 Pointer
	PIN69_Status = fopen("/sys/class/gpio/gpio69/value", "r");
	PIN69_Status_Value = fgetc(PIN69_Status);
	PIN69_Status_Value = PIN69_Status_Value - 48;
	fclose(PIN69_Status);
/*
============================================================================================================================================
End of Digital Input Handler
============================================================================================================================================
============================================================================================================================================
Start of Analog Input Handler
============================================================================================================================================
*/
	char ANI00_Value[3] = {0};
	FILE *ANI00_file = NULL;
	ANI00_file = fopen("/sys/bus/iio/devices/iio:device0/in_voltage0_raw", "r");
	fgets(ANI00_Value, 3, ANI00_file);
	//Debug Code
	ANI00_Value[0] = '0' ;
	ANI00_Value[1] = '0' ;
	fclose(ANI00_file);

	char ANI01_Value[3] = {0};
	FILE *ANI01_file = NULL;
	ANI01_file = fopen("/sys/bus/iio/devices/iio:device0/in_voltage1_raw", "r");
	fgets(ANI01_Value, 3, ANI01_file);
	//Debug Code
	ANI01_Value[0] = '0';
	ANI01_Value[1] = '0';
	//End of Debug Code
	fclose(ANI01_file);

	char ANI02_Value[3] = {0};
	FILE *ANI02_file = NULL;
	ANI02_file = fopen("/sys/bus/iio/devices/iio:device0/in_voltage2_raw", "r");
	fgets(ANI02_Value, 3, ANI02_file);
	//Debug Code
	ANI02_Value[0] = '0';
	ANI02_Value[1] = '0';
	//End of Debug Code
	fclose(ANI02_file);

	char ANI03_Value[3] = {0};
	FILE *ANI03_file = NULL;
	ANI03_file = fopen("/sys/bus/iio/devices/iio:device0/in_voltage3_raw", "r");
	fgets(ANI03_Value, 3, ANI03_file);
	//Debug Code
	ANI03_Value[0] = '0';
	ANI03_Value[1] = '0';
	//End of Debug Code
	fclose(ANI03_file);

	char ANI04_Value[3] = {0};
	FILE *ANI04_file = NULL;
	ANI04_file = fopen("/sys/bus/iio/devices/iio:device0/in_voltage4_raw", "r");
	fgets(ANI04_Value, 3, ANI04_file);
	fclose(ANI04_file);

	char ANI05_Value[3] = {0};
	FILE *ANI05_file = NULL;
	ANI05_file = fopen("/sys/bus/iio/devices/iio:device0/in_voltage5_raw", "r");
	fgets(ANI05_Value, 3, ANI05_file);
	//Debug Code
	ANI05_Value[0] = '0';
	ANI05_Value[1] = '0';
	//End of Debug Code
	fclose(ANI05_file);

	char ANI06_Value[3] = {0};
	FILE *ANI06_file = NULL;
	ANI06_file = fopen("/sys/bus/iio/devices/iio:device0/in_voltage6_raw", "r");
	fgets(ANI06_Value, 3, ANI06_file);
	//Debug Code
	ANI06_Value[0] = '0';
	ANI06_Value[1] = '0';
 	//End of Debug Code
	fclose(ANI06_file);

/*
=======================================================================================================================================
   Format the data to be sent to main module
=======================================================================================================================================
*/

	char *IO_Status_fmt = "%d:%d:%d:%d:%d:%d:%d:%d|%s:%s:%s:%s:%s:%s:%s|";
	char IO_Status_Value[1024];
	sprintf(IO_Status_Value, IO_Status_fmt, PIN44_Status_Value, PIN65_Status_Value, PIN46_Status_Value, PIN26_Status_Value, PIN68_Status_Value, PIN67_Status_Value, PIN66_Status_Value, PIN69_Status_Value, ANI00_Value, ANI01_Value, ANI02_Value, ANI03_Value, ANI04_Value, ANI05_Value, ANI06_Value); //Format and apply data
	char *New_IO_Status_Value = {0};
	New_IO_Status_Value = IO_Status_Value;

	return (New_IO_Status_Value);

}


