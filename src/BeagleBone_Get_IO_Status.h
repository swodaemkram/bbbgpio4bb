
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
#include "bbb_dht_read.h"
char *BeagelBone_Get_IO_Status(void){
/*
====================================================================================================================================
Start of Digital INPUT Handler
====================================================================================================================================
 */

	char PIN44_Status_Value = {0};
	FILE *PIN44_Status = NULL; //declare PIN44 Pointer
	PIN44_Status = fopen("/sys/class/gpio/gpio44/value", "r");
	if (PIN44_Status == NULL){
		char log_message[0];
		strcat(log_message, "Problem Reading PIN 44!" );
		log_Function(log_message);
		//printf("\nProblem Reading PIN 44!\n");
		remove("/run/gpio4bb.pid");
		exit(1);
		}
	PIN44_Status_Value = fgetc(PIN44_Status);
	PIN44_Status_Value = PIN44_Status_Value - 48;
	fclose(PIN44_Status);

	char PIN65_Status_Value = {0};
	FILE *PIN65_Status = NULL; //declare PIN65 Pointer
	PIN65_Status = fopen("/sys/class/gpio/gpio65/value", "r");
	if (PIN65_Status == NULL){
		//printf("\nProblem Reading PIN 65!\n");
		char log_message[0];
		strcat(log_message, "Problem Reading PIN 65!" );
		log_Function(log_message);
		remove("/run/gpio4bb.pid");
		exit(1);
		}
	PIN65_Status_Value = fgetc(PIN65_Status);
	PIN65_Status_Value = PIN65_Status_Value -48;
	fclose(PIN65_Status);

	char PIN46_Status_Value = {0};
	FILE *PIN46_Status = NULL; //declare PIN46 Pointer
	PIN46_Status = fopen("/sys/class/gpio/gpio46/value", "r");
	if (PIN46_Status == NULL){
		char log_message[0];
		strcat(log_message, "Problem Reading PIN 46!" );
		log_Function(log_message);
		//printf("\nProblem Reading PIN 46!\n");
		remove("/run/gpio4bb.pid");
		exit(1);
		}
	PIN46_Status_Value = fgetc(PIN46_Status);
	PIN46_Status_Value = PIN46_Status_Value - 48;
	fclose(PIN46_Status);

	char PIN26_Status_Value = {0};
	FILE *PIN26_Status = NULL; //declare PIN26 Pointer
	PIN26_Status = fopen("/sys/class/gpio/gpio26/value", "r");
	if (PIN26_Status == NULL){
		//printf("\nProblem Reading PIN 26!\n");
		char log_message[0];
		strcat(log_message, "Problem Reading PIN 26!" );
		log_Function(log_message);
		remove("/run/gpio4bb.pid");
		exit(1);
		}
	PIN26_Status_Value = fgetc(PIN26_Status);
	PIN26_Status_Value = PIN26_Status_Value - 48;
	fclose(PIN26_Status);

	char PIN68_Status_Value = {0};
	FILE *PIN68_Status = NULL; //declare PIN68 Pointer
	PIN68_Status = fopen("/sys/class/gpio/gpio68/value", "r");
	if (PIN68_Status == NULL){
		//printf("\nProblem Reading PIN 68!\n");
		char log_message[0];
		strcat(log_message, "Problem Reading PIN 68!" );
		log_Function(log_message);
		remove("/run/gpio4bb.pid");
		exit(1);
		}
	PIN68_Status_Value = fgetc(PIN68_Status);
	PIN68_Status_Value = PIN68_Status_Value - 48;
	fclose(PIN68_Status);

	char PIN67_Status_Value = {0};
	FILE *PIN67_Status = NULL; //declare PIN67 Pointer
	PIN67_Status = fopen("/sys/class/gpio/gpio67/value", "r");
	if (PIN67_Status == NULL){
		//printf("\nProblem Reading PIN 67!\n");
		char log_message[0];
		strcat(log_message, "Problem Reading PIN 67!" );
		log_Function(log_message);
		remove("/run/gpio4bb.pid");
		exit(1);
		}
	PIN67_Status_Value = fgetc(PIN67_Status);
	PIN67_Status_Value = PIN67_Status_Value - 48;
	fclose(PIN67_Status);

	char PIN66_Status_Value = {0};
	FILE *PIN66_Status = NULL; //declare PIN66 Pointer
	PIN66_Status = fopen("/sys/class/gpio/gpio66/value", "r");
	if (PIN66_Status == NULL){
		//printf("\nProblem Reading PIN 66!\n");
		char log_message[0];
		strcat(log_message, "Problem Reading PIN 66!" );
		log_Function(log_message);
		remove("/run/gpio4bb.pid");
		exit(1);
		}
	PIN66_Status_Value = fgetc(PIN66_Status);
	PIN66_Status_Value = PIN66_Status_Value - 48;
	fclose(PIN66_Status);

	char PIN69_Status_Value = {0};
	FILE *PIN69_Status = NULL; //declare PIN69 Pointer
	PIN69_Status = fopen("/sys/class/gpio/gpio69/value", "r");
	if (PIN69_Status == NULL){
		//printf("\nProblem Reading PIN 69!\n");
		char log_message[0];
		strcat(log_message, "Problem Reading PIN 69!" );
		log_Function(log_message);
		remove("/run/gpio4bb.pid");
		exit(1);
		}
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
	if (ANI00_file == NULL){
		//printf("\nProblem Reading in_voltage0_raw!\n");
		char log_message[0];
		strcat(log_message, "Problem Reading in_voltage0_raw!" );
		log_Function(log_message);
		remove("/run/gpio4bb.pid");
		usleep(5000);
		exit(1);
		}
	fgets(ANI00_Value, 3, ANI00_file);
	//Debug Code
	ANI00_Value[0] = '0' ;
	ANI00_Value[1] = '0' ;
	//End of Debug Code
	fclose(ANI00_file);

	char ANI01_Value[3] = {0};
	FILE *ANI01_file = NULL;
	ANI01_file = fopen("/sys/bus/iio/devices/iio:device0/in_voltage1_raw", "r");
	if (ANI01_file == NULL){
			//printf("\nProblem Reading in_voltage1_raw!\n");
			char log_message[0];
			strcat(log_message, "Problem Reading in_voltage1_raw!" );
			log_Function(log_message);
			remove("/run/gpio4bb.pid");
			exit(1);
			}
	fgets(ANI01_Value, 3, ANI01_file);
	//Debug Code
	ANI01_Value[0] = '0';
	ANI01_Value[1] = '0';
	//End of Debug Code
	fclose(ANI01_file);

	char ANI02_Value[3] = {0};
	FILE *ANI02_file = NULL;
	ANI02_file = fopen("/sys/bus/iio/devices/iio:device0/in_voltage2_raw", "r");
	if (ANI02_file == NULL){
			//printf("\nProblem Reading in_voltage2_raw!\n");
			char log_message[0];
			strcat(log_message, "Problem Reading in_voltage2_raw!" );
			log_Function(log_message);
			remove("/run/gpio4bb.pid");
			exit(1);
			}
	fgets(ANI02_Value, 3, ANI02_file);
	//Debug Code
	ANI02_Value[0] = '0';
	ANI02_Value[1] = '0';
	//End of Debug Code
	fclose(ANI02_file);

	char ANI03_Value[3] = {0};
	FILE *ANI03_file = NULL;
	ANI03_file = fopen("/sys/bus/iio/devices/iio:device0/in_voltage3_raw", "r");
	if (ANI03_file == NULL){
			//printf("\nProblem Reading in_voltage3_raw!\n");
			char log_message[0];
			strcat(log_message, "Problem Reading in_voltage3_raw!" );
			log_Function(log_message);
			remove("/run/gpio4bb.pid");
			exit(1);
			}
	fgets(ANI03_Value, 3, ANI03_file);
	//Debug Code
	ANI03_Value[0] = '0';
	ANI03_Value[1] = '0';
	//End of Debug Code
	fclose(ANI03_file);

	char ANI04_Value[3] = {0};
	FILE *ANI04_file = NULL;
	ANI04_file = fopen("/sys/bus/iio/devices/iio:device0/in_voltage4_raw", "r");
	if (ANI04_file == NULL){
			//printf("\nProblem Reading in_voltage4_raw!\n");
			char log_message[0];
			strcat(log_message, "Problem Reading in_voltage4_raw!" );
			log_Function(log_message);
			remove("/run/gpio4bb.pid");
			exit(1);
			}
	fgets(ANI04_Value, 3, ANI04_file);
	ANI04_Value[0] = '0';
	ANI04_Value[1] = '0';
	fclose(ANI04_file);

	char ANI05_Value[3] = {0};
	FILE *ANI05_file = NULL;
	ANI05_file = fopen("/sys/bus/iio/devices/iio:device0/in_voltage5_raw", "r");
	if (ANI05_file == NULL){
			//printf("\nProblem Reading in_voltage5_raw!\n");
			char log_message[0];
			strcat(log_message, "Problem Reading in_voltage5_raw!" );
			log_Function(log_message);
			remove("/run/gpio4bb.pid");
			exit(1);
			}
	fgets(ANI05_Value, 3, ANI05_file);
	//Debug Code
	ANI05_Value[0] = '0';
	ANI05_Value[1] = '0';
	//End of Debug Code
	fclose(ANI05_file);

	char ANI06_Value[3] = {0};
	FILE *ANI06_file = NULL;
	ANI06_file = fopen("/sys/bus/iio/devices/iio:device0/in_voltage6_raw", "r");
	if (ANI06_file == NULL){
			//printf("\nProblem Reading in_voltage6_raw!\n");
			char log_message[0];
			strcat(log_message, "Problem Reading in_voltage6");
			remove("/run/gpio4bb.pid");
			exit(1);
			}
	fgets(ANI06_Value, 3, ANI06_file);
	//Debug Code
	ANI06_Value[0] = '0';
	ANI06_Value[1] = '0';
 	//End of Debug Code
	fclose(ANI06_file);

/*
======================================================================================================================================
Get Reading from DHT11 Temp/Humidity Sensor
======================================================================================================================================
 */

	   // int type = 11;														  //Type of Sensor 11=DHT11 22=DHT22
		//int gpio_base = 1;                                                    //Connector P8
		//int gpio_number = 29;                                                 //PIN 29 (Physical Pin 26) GPIO_61
		//float humidity = 00.0f;												  //Humidity Pointer
		//float temperature = 00.0f;											  //Temperature Pointer
		//float reported_temperature = 00.0f;									  //Pointer for Converted Temperature


		//bbb_dht_read(type,gpio_base,gpio_number,&humidity,&temperature);

		//while (humidity <= 1){

		//	bbb_dht_read(type,gpio_base,gpio_number,&humidity,&temperature);

		//}


		//reported_temperature = (temperature * 1.8 + 32);                       //convert to Fahrenheit
sleep(1); //Remove if the above lines are enabled for the DHT11 Temp Sensor
/*
=======================================================================================================================================
   Format the data to be sent to main module
=======================================================================================================================================
*/

	//char *IO_Status_fmt = "%d:%d:%d:%d:%d:%d:%d:%d|%s:%s:%s:%s:%s:%s:%s|%2.1f:%2.1f|";
	char *IO_Status_fmt = "%d:%d:%d:%d:%d:%d:%d:%d|%s:%s:%s:%s:%s:%s:%s|00.0:00.0|";
	char IO_Status_Value[1024] = {0};

	//sprintf(IO_Status_Value, IO_Status_fmt, PIN44_Status_Value, PIN65_Status_Value, PIN46_Status_Value, PIN26_Status_Value, PIN68_Status_Value, PIN67_Status_Value, PIN66_Status_Value, PIN69_Status_Value, ANI00_Value, ANI01_Value, ANI02_Value, ANI03_Value, ANI04_Value, ANI05_Value, ANI06_Value,humidity,reported_temperature); //Format and apply data
	sprintf(IO_Status_Value, IO_Status_fmt, PIN44_Status_Value, PIN65_Status_Value, PIN46_Status_Value, PIN26_Status_Value, PIN68_Status_Value, PIN67_Status_Value, PIN66_Status_Value, PIN69_Status_Value, ANI00_Value, ANI01_Value, ANI02_Value, ANI03_Value, ANI04_Value, ANI05_Value,ANI06_Value); //Format and apply data


	char *New_IO_Status_Value = {0};
	New_IO_Status_Value = IO_Status_Value;

	return (New_IO_Status_Value);

}


