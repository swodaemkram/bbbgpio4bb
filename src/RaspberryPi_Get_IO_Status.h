/*
 * RaspberryPi_Get_IO_Status.h
 *
 *  Created on: Feb 10, 2019
 *      Author: mark
 */

#ifndef RASPBERRYPI_GET_IO_STATUS_H_
#define RASPBERRYPI_GET_IO_STATUS_H_



#endif /* RASPBERRYPI_GET_IO_STATUS_H_ */

#include <unistd.h>
#include <stdio.h>

char *RaspberryPi_Get_IO_Status(void){
/*
====================================================================================================================================
Start of Digital INPUT Handler
====================================================================================================================================
 */



	char PIN0_Status_Value = {0};
	FILE *PIN0_Status = NULL; //declare PIN0 Pointer
	PIN0_Status = fopen("/sys/class/gpio/gpio0/value", "r");
	PIN0_Status_Value = fgetc(PIN0_Status);
	PIN0_Status_Value = PIN0_Status_Value - 48;
	fclose(PIN0_Status);

	char PIN1_Status_Value = {0};
	FILE *PIN1_Status = NULL; //declare PIN1 Pointer
	PIN1_Status = fopen("/sys/class/gpio/gpio1/value", "r");
	PIN1_Status_Value = fgetc(PIN1_Status);
	PIN1_Status_Value = PIN1_Status_Value -48;
	fclose(PIN1_Status);

	char PIN2_Status_Value = {0};
	FILE *PIN2_Status = NULL; //declare PIN2 Pointer
	PIN2_Status = fopen("/sys/class/gpio/gpio2/value", "r");
	PIN2_Status_Value = fgetc(PIN2_Status);
	PIN2_Status_Value = PIN2_Status_Value - 48;
	fclose(PIN2_Status);

	char PIN3_Status_Value = {0};
	FILE *PIN3_Status = NULL; //declare PIN3 Pointer
	PIN3_Status = fopen("/sys/class/gpio/gpio3/value", "r");
	PIN3_Status_Value = fgetc(PIN3_Status);
	PIN3_Status_Value = PIN3_Status_Value - 48;
	fclose(PIN3_Status);

	char PIN4_Status_Value = {0};
	FILE *PIN4_Status = NULL; //declare PIN4 Pointer
	PIN4_Status = fopen("/sys/class/gpio/gpio4/value", "r");
	PIN4_Status_Value = fgetc(PIN4_Status);
	PIN4_Status_Value = PIN4_Status_Value - 48;
	fclose(PIN4_Status);


	char PIN5_Status_Value = {0};
	FILE *PIN5_Status = NULL; //declare PIN5 Pointer
	PIN5_Status = fopen("/sys/class/gpio/gpio5/value", "r");
	PIN5_Status_Value = fgetc(PIN5_Status);
	PIN5_Status_Value = PIN5_Status_Value - 48;
	fclose(PIN5_Status);

	char PIN6_Status_Value = {0};
	FILE *PIN6_Status = NULL; //declare PIN6 Pointer
	PIN6_Status = fopen("/sys/class/gpio/gpio6/value", "r");
	PIN6_Status_Value = fgetc(PIN6_Status);
	PIN6_Status_Value = PIN6_Status_Value - 48;
	fclose(PIN6_Status);

	char PIN7_Status_Value = {0};
	FILE *PIN7_Status = NULL; //declare PIN7 Pointer
	PIN7_Status = fopen("/sys/class/gpio/gpio7/value", "r");
	PIN7_Status_Value = fgetc(PIN7_Status);
	PIN7_Status_Value = PIN7_Status_Value - 48;
	fclose(PIN7_Status);
/*
============================================================================================================================================
End of Digital Input Handler
============================================================================================================================================

=======================================================================================================================================
   Format the data to be sent to main module
=======================================================================================================================================
*/



	char *IO_Status_fmt = "%d:%d:%d:%d:%d:%d:%d:%d|00:00:00:00:00:00:00|";
	char IO_Status_Value[1024];

	sprintf(IO_Status_Value, IO_Status_fmt, PIN0_Status_Value, PIN1_Status_Value, PIN2_Status_Value, PIN3_Status_Value, PIN4_Status_Value, PIN5_Status_Value, PIN6_Status_Value, PIN7_Status_Value); //Format and apply data
	char *New_IO_Status_Value = {0};
	New_IO_Status_Value = IO_Status_Value;
	return (New_IO_Status_Value);

}
