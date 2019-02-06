/*
 * Get_IO_Status.h
 *
 *  Created on: Feb 4, 2019
 *      Author: mark
 */

#ifndef GET_IO_STATUS_H_
#define GET_IO_STATUS_H_
#endif /* GET_IO_STATUS_H_ */

#include <unistd.h>
#include <stdio.h>

char Get_IO_Status(void){

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

	//IO_Status_Value =
	char *IO_Status_fmt = "%d,%d,%d,%d,%d,%d,%d,%d";

	char IO_Status_Value[1024];

	sprintf(IO_Status_Value, IO_Status_fmt, PIN44_Status_Value, PIN65_Status_Value, PIN46_Status_Value, PIN26_Status_Value, PIN68_Status_Value, PIN67_Status_Value, PIN66_Status_Value, PIN69_Status_Value); //Format and apply data

	printf("\n%s\n",IO_Status_Value);

	return (IO_Status_Value);

}


