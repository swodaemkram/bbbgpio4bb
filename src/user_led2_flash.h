/*
 * user_led2.h
 *
 *  Created on: Feb 4, 2019
 *      Author: mark
 */

#ifndef USER_LED2_H_
#define USER_LED2_H_



#endif /* USER_LED2_H_ */

#include <unistd.h>
#include <stdio.h>
#include "Global_Variables.h"

extern  int user_led_status;


void user_led2_flash(void){



FILE *user_led2 = NULL; //declare User LED Pointer

if (user_led_status == 0){
user_led2 = fopen("/sys/devices/platform/leds/leds/beaglebone:green:usr2/brightness", "w");
fwrite("1",1,sizeof("1"),user_led2);
fclose(user_led2);
user_led_status = 1;
}

if (user_led_status == 1){
user_led2 = fopen("/sys/devices/platform/leds/leds/beaglebone:green:usr2/brightness", "w");
fwrite("0",1,sizeof("0"),user_led2);
fclose(user_led2);
user_led_status = 0;
}


return;

}
