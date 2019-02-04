/*
===========================================================================================================================
Name		:	bbbgpiobb.c
Author		:	Mark Meadows
Version		:	v 0.0.1
Copyright	:	Fireking Security Group
Description	:	Service to provide GPIO In and Out capability to BlackBox on the BeagelBone Hardware Platform
===========================================================================================================================
*/

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <stdlib.h>

#define VER "v 0.0.01\n"


#include "user_led2_flash.h"




int main(int argc, char *argv[])
{




user_led2_flash(); //flash user LED to show service is running












return(0);
}
