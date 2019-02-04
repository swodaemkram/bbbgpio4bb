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

printf("\n  bbbgpiobb By Mark Meadows v 00.00.01\n");
printf("          copyright Fireking 2019\n");
printf(" a command line BlackBox interface to the BagelBone I/O hardware\n");
printf(" -A, The I.P. Address for out-going BlackBox communications\n");
printf(" -P, The Port for out-going BlackBox communications\n");
printf(" -p, The Port used for in-coming BlackBox communications\n");
printf("\n Example usage bbbgpiobb -A 192.168.1.15 -P 12000 -p 8080 \n " );

exit(0);
}


