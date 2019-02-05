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

void Get_IO_Status(void){


	char PIN44_Status_Value = {0};
	FILE *PIN44_Status = NULL; //declare User LED Pointer

	printf("Getting IO Status ......\n");

	PIN44_Status = fopen("/sys/class/gpio/gpio44/value", "r");
	//fwrite("1",1,sizeof("1"),PIN44_Status);
	PIN44_Status_Value = fgetc(PIN44_Status);
	fclose(PIN44_Status);

	printf("\nPIN44 Value = %c\n\n",PIN44_Status_Value );


return ;

}


