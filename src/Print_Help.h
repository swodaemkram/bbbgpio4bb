/*
 * Print_Help.h
 *
 *  Created on: Feb 4, 2019
 *      Author: mark
 */

#ifndef PRINT_HELP_H_
#define PRINT_HELP_H_

#include <unistd.h>
#include <stdio.h>
#endif /* PRINT_HELP_H_ */

void Print_Help(void){

printf("\n           gpio4bb By Mark Meadows v 00.03.00\n");
printf(" Copyright (c) 2019 Fireking Security Group. All rights reserved.\n");
printf("         The BlackBox interface to Hardware I/O \n");
printf(" -A, The I.P. Address for out-going BlackBox communications\n");
printf(" -h, Print this help file\n");
printf(" -P, The Port for out-going BlackBox communications\n");
printf(" -p, The Port used for in-coming BlackBox communications\n");
printf(" -w, The Hardware Platform being utilized [ beaglebone, usbio, raspberrypi ...ect.]\n ");
printf("\n Example usage: gpio4bb -A 192.168.1.15 -P 12000 -p 8080 -w beaglebone \n " );

exit(0);
}


