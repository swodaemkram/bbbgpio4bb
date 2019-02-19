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

printf("\n             gpio4bb By Mark Meadows v 00.98.00\n");
printf(" Copyright (c)2019 Fireking Security Group. All rights reserved.\n");
printf("         The BlackBox interface to On Board Hardware I/O \n\n");
printf(" -h, Print this help file\n");
printf(" -a, The I.P. Address for out-going BlackBox communications\n");
printf(" -p, The Port for out-going BlackBox communications\n");
printf(" -P, The Port used for in-coming BlackBox communications\n");
printf(" -w, The Hardware Platform being utilized [ beaglebone, usbio, raspberrypi ...ect.]\n");
printf(" -v, The Version of Software \n");
printf("\n Example usage: gpio4bb -a 192.168.1.15 -p 12000 -P 8080 -w beaglebone  -v\n\n" );
remove("/run/gpio4bb.pid");
exit(0);
}


