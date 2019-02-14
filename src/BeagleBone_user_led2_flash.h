/*
 * user_led2.h
 *
 *  Created on: Feb 4, 2019
 *      Author: mark
 */

#ifndef BEAGELBONE_USER_LED2_H_
#define BEAGELBONE_USER_LED2_H_



#endif /* BEAGELBONE_USER_LED2_H_ */

#include <unistd.h>
#include <stdio.h>

extern  int user_led_status;


void BeagelBone_user_led2_flash(void){

int user_led2_value;

FILE *user_led2 = NULL; //declare User LED Pointer

user_led2 = fopen("/sys/devices/platform/leds/leds/beaglebone:green:usr2/brightness", "r");
user_led2_value = fgetc(user_led2) - 48;
fclose(user_led2);

if (user_led2_value == 0){
	user_led2 = fopen("/sys/devices/platform/leds/leds/beaglebone:green:usr2/brightness", "w");
	fwrite("1",1,sizeof("1"),user_led2);
fclose(user_led2);
}

if (user_led2_value == 1){
	user_led2 = fopen("/sys/devices/platform/leds/leds/beaglebone:green:usr2/brightness", "w");
	fwrite("0",1,sizeof("0"),user_led2);
fclose(user_led2);
}


return;

}
