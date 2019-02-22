/*
 * dht11Read.h
 *
 *  Created on: Feb 19, 2019
 *      Author: mark
 */

#ifndef DHT11READ_H_
#define DHT11READ_H_



#endif /* DHT11READ_H_ */



char *dht11_Read(int GPIOPIN){



	FILE *IO_Config_File = NULL;                            	// declare GPIO file Setup Pointer

	IO_Config_File = fopen("/sys/class/gpio/gpio61/direction", "w");  	// Open the pin 61 direction file for writing
		fwrite("out",1,sizeof("out"),IO_Config_File);					// Set direction for PIN61 to out
		fclose(IO_Config_File);										    // Close the direction file
	IO_Config_File = fopen("/sys/class/gpio/gpio61/value", "w"); 		// Open the Value for PIN 61
		fwrite("0",1,sizeof("0"),IO_Config_File);						// Set PIN 61 High
		fclose(IO_Config_File);											// Close the Value File
		usleep(18);														// Keep pin 61 LOW for 18ms
	IO_Config_File = fopen("/sys/class/gpio/gpio61/value", "w");		// Open the Value for PIN 61
		fwrite("1",1,sizeof("1"),IO_Config_File);						// Set PIN 61 High
		fclose(IO_Config_File);											// Close the Value File
		usleep(30);														// wait from 20 to 40 ms
	IO_Config_File = fopen("/sys/class/gpio/gpio61/direction", "w");  	// Open the pin 61 direction file for writing
		fwrite("in",1,sizeof("in"),IO_Config_File);						// Set direction for PIN61 to out
		fclose(IO_Config_File);										    // Close the direction file




		return(0);
}
