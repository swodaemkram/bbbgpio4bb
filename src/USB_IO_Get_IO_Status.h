/*
 * USB_IO_Get_IO_Status.h
 *
 *  Created on: Feb 13, 2019
 *      Author: mark
 */

#ifndef USB_IO_GET_IO_STATUS_H_
#define USB_IO_GET_IO_STATUS_H_

#endif /* USB_IO_GET_IO_STATUS_H_ */

/* baudrate settings are defined in <asm/termbits.h>, which is
included by <termios.h> */
#define FALSE 0
#define TRUE 1

char *USB_IO_Get_IO_Status(void){

		int NEWSTOP=FALSE;
		//char log_message [250] = {0};


		int fd;
		int res;
		struct termios oldtio,newtio;
		char buf[255] = {0};
		int numofcr = 1;
/*
=======================================================================================================================
Define Variables for all PINs
=======================================================================================================================
*/
		char DIGPIN8[255] = {0};
		char DIGPIN9[255] = {0};
		char DIGPIN10[255] = {0};
		char DIGPIN11[255] = {0};
		char DIGPIN12[255] = {0};
		char DIGPIN13[255] = {0};
		char DIGPIN14[255] = {0};
		char DIGPIN15[255] = {0};
//		char ANALOGPIN0[255] = {0};
//		char ANALOGPIN1[255] = {0};
//		char ANALOGPIN2[255] = {0};
//		char ANALOGPIN3[255] = {0};
//		char ANALOGPIN4[255] = {0};
//		char ANALOGPIN5[255] = {0};
//		char ANALOGPIN6[255] = {0};
/*
=======================================================================================================================
All PINs defined
=======================================================================================================================
Open GPIO device for reading and writing and not as controlling tty
because we don't want to get killed if linenoise sends CTRL−C.
*/

		fd = open("/dev/ttyACM0", O_RDWR | O_NOCTTY );
		if (fd <0)
				{
			    perror("/dev/ttyACM0");
			    //strncpy(log_message,"Could not open USBGPIO Hardware",31);
			    log_Function("Could not open USBGPIO Hardware");
			    remove("/run/gpio4bb.pid");
			    exit(1);
				}
		tcgetattr(fd,&oldtio); /* save current serial port settings */
		bzero(&newtio, sizeof(newtio)); /* clear struct for new port settings */
		/*
		BAUDRATE: Set bps rate. You could also use cfsetispeed and cfsetospeed.
		CRTSCTS : output hardware flow control (only used if the cable has
		all necessary lines. See sect. 7 of Serial−HOWTO)
		CS8
		: 8n1 (8bit,no parity,1 stopbit)
		CLOCAL
		CREAD
		: local connection, no modem contol
		: enable receiving characters
		*/
		newtio.c_cflag = B9600 | CRTSCTS | CS8 | CLOCAL | CREAD;
		/*
		IGNPAR
		ICRNL
		: ignore bytes with parity errors
		: map CR to NL (otherwise a CR input on the other computer
		will not terminate input)
		otherwise make device raw (no other input processing)
		*/
		newtio.c_iflag = IGNPAR | ICRNL;
		/*
		Raw output.
		*/
		newtio.c_oflag = 0;
		/*
		ICANON : enable canonical input
		disable all echo functionality, and don't send signals to calling program
		*/
		newtio.c_lflag = ICANON;
		/*
		initialize all control characters
		default values can be found in /usr/include/termios.h, and are given
		in the comments, but we don't need them here
		*/
		newtio.c_cc[VINTR] = 0;
		newtio.c_cc[VQUIT] = 0;
		newtio.c_cc[VERASE] = 0;
		newtio.c_cc[VKILL] = 0 ;
		newtio.c_cc[VEOF] = 4;
		newtio.c_cc[VTIME] = 0;
		newtio.c_cc[VMIN] = 1;
		newtio.c_cc[VSWTC] = 0;
		newtio.c_cc[VSTART] = 0;
		newtio.c_cc[VSTOP] = 0;
		newtio.c_cc[VSUSP] = 0;
		newtio.c_cc[VEOL] = 0;
		newtio.c_cc[VREPRINT] = 0;
		newtio.c_cc[VDISCARD] = 0;
		newtio.c_cc[VWERASE] = 0;
		newtio.c_cc[VLNEXT] = 0;
		newtio.c_cc[VEOL2] = 0;

		//now clean the modem line and activate the settings for the port r

		tcflush(fd, TCIFLUSH);
		tcsetattr(fd,TCSANOW,&newtio);

		//terminal settings done, now handle input
/*
=============================================================================================================================
Get Reading from the first Digital Pin this is Pin 8
=============================================================================================================================
*/
		sleep(1); //slow things dow so we don't  the USBGPIO Board
		write(fd,"gpio read 8\n",12); //Ask for the Value of PIN 8
		while (NEWSTOP==FALSE) {
		/* loop until we have a terminating condition */
		/* read blocks program execution until a line terminating character is
		input, even if more than 255 chars are input. If the number
		of characters read is smaller than the number of chars available,
		subsequent reads will return the remaining chars. res will be set
		to the actual number of characters actually read */
		res = read(fd,buf,255);
		buf[res]=0;
		                                                  /* set end of string, so we can printf */
		if(numofcr >= 2) {										//This is the data we want

			  strncpy(DIGPIN8,buf,strlen(buf)-1);		// Copy our data minus the new line character because we don't want that
			  //strncpy(log_message,DIGPIN8,strlen(DIGPIN8));
			 	//	 log_Function(DIGPIN8);

		}
		                                                        //if (buf[0]=='\n') STOP=TRUE;
		if (buf[0]=='\n'){                                      //if buf has a '\n' new line character increment the line counter
			numofcr = numofcr + 1;								//if there are 2 or more out data is in the buffer so bail out
			if (numofcr >= 3) {
				NEWSTOP=TRUE;
			}

						  }
							}

/*
=================================================================================================================================
Finished PIN 8
=================================================================================================================================
=============================================================================================================================
Get Reading from the first Digital Pin this is Pin 9
=============================================================================================================================
*/
		res = 0;		//reset everything
		NEWSTOP=FALSE;	//reset everything
		buf[0] = '\0';	//reset everything
		numofcr = 1;	//reset everything

		write(fd,"gpio read 9\n",12);
		while (NEWSTOP==FALSE) {
		res = read(fd,buf,255);
		buf[res]=0;

		if(numofcr >= 2) {
        strncpy(DIGPIN9,buf,strlen(buf)-1);

		}

		if (buf[0]=='\n'){
		numofcr = numofcr + 1;
		if (numofcr >= 3) {
		NEWSTOP=TRUE;
			}

						  }
							}

/*
=================================================================================================================================
Finished PIN 9
=================================================================================================================================
=============================================================================================================================
Get Reading from the first Digital Pin this is Pin 10
=============================================================================================================================
*/
		res = 0;
		NEWSTOP=FALSE;
		buf[0] = '\0';
		numofcr = 1;

		write(fd,"gpio read 10\n",13);
		while (NEWSTOP==FALSE) {
		res = read(fd,buf,255);
		buf[res]=0;
		if(numofcr >= 2) {
        strncpy(DIGPIN10,buf,strlen(buf)-1);
			}
			if (buf[0]=='\n'){
				numofcr = numofcr + 1;
		if (numofcr >= 3) {
		NEWSTOP=TRUE;
			}
							  }
							}

/*
=================================================================================================================================
Finished PIN 10
=================================================================================================================================
=============================================================================================================================
Get Reading from the first Digital Pin this is Pin 11
=============================================================================================================================
*/
		res = 0;
		NEWSTOP=FALSE;
		buf[0] = '\0';
		numofcr = 1;

		write(fd,"gpio read 11\n",13);
		while (NEWSTOP==FALSE) {
		res = read(fd,buf,255);
		buf[res]=0;
		if(numofcr >= 2) {
        strncpy(DIGPIN11,buf,strlen(buf)-1);
			}
			if (buf[0]=='\n'){
				numofcr = numofcr + 1;
		if (numofcr >= 3) {
		NEWSTOP=TRUE;
			}
							  }
							}
/*
=================================================================================================================================
Finished PIN 11
=================================================================================================================================
=============================================================================================================================
Get Reading from the first Digital Pin this is Pin 12
=============================================================================================================================
*/
		res = 0;
		NEWSTOP=FALSE;
		buf[0] = '\0';
		numofcr = 1;

		write(fd,"gpio read 12\n",13);
		while (NEWSTOP==FALSE) {
		res = read(fd,buf,255);
		buf[res]=0;
		if(numofcr >= 2) {
        strncpy(DIGPIN12,buf,strlen(buf)-1);
				}
			if (buf[0]=='\n'){
				numofcr = numofcr + 1;
		if (numofcr >= 3) {
		NEWSTOP=TRUE;
			}
							  }
							}
/*
=================================================================================================================================
Finished PIN 12
=================================================================================================================================
=============================================================================================================================
Get Reading from the first Digital Pin this is Pin 13
=============================================================================================================================
*/
		res = 0;
		NEWSTOP=FALSE;
		buf[0] = '\0';
		numofcr = 1;

		write(fd,"gpio read 13\n",13);
		while (NEWSTOP==FALSE) {
		res = read(fd,buf,255);
		buf[res]=0;
		if(numofcr >= 2) {
        strncpy(DIGPIN13,buf,strlen(buf)-1);
				}
			if (buf[0]=='\n'){
				numofcr = numofcr + 1;
		if (numofcr >= 3) {
		NEWSTOP=TRUE;
			}
							  }
							}
/*
=================================================================================================================================
Finished PIN 13
=================================================================================================================================
=============================================================================================================================
Get Reading from the first Digital Pin this is Pin 14
=============================================================================================================================
*/
		res = 0;
		NEWSTOP=FALSE;
		buf[0] = '\0';
		numofcr = 1;

		write(fd,"gpio read 14\n",13);
		while (NEWSTOP==FALSE) {
		res = read(fd,buf,255);
		buf[res]=0;
		if(numofcr >= 2) {
        strncpy(DIGPIN14,buf,strlen(buf)-1);
				}
			if (buf[0]=='\n'){
				numofcr = numofcr + 1;
		if (numofcr >= 3) {
		NEWSTOP=TRUE;
			}
							  }
							}
/*
=================================================================================================================================
Finished PIN 14
=================================================================================================================================
=============================================================================================================================
Get Reading from the first Digital Pin this is Pin 14
=============================================================================================================================
*/
		res = 0;
		NEWSTOP=FALSE;
		buf[0] = '\0';
		numofcr = 1;

		write(fd,"gpio read 15\n",13);
		while (NEWSTOP==FALSE) {
		res = read(fd,buf,255);
		buf[res]=0;
		if(numofcr >= 2) {
        strncpy(DIGPIN15,buf,strlen(buf)-1);
				}
			if (buf[0]=='\n'){
				numofcr = numofcr + 1;
		if (numofcr >= 3) {
		NEWSTOP=TRUE;
			}
							  }
							}
/*
=================================================================================================================================
Finished PIN 14
=================================================================================================================================
=============================================================================================================================
Get Reading from the first Analog Pin this is Pin 0
=============================================================================================================================

		res = 0;
		NEWSTOP=FALSE;
		buf[0] = '\0';
		numofcr = 1;

		write(fd,"adc read 0\n",11);
		while (NEWSTOP==FALSE) {
		res = read(fd,buf,255);
		buf[res]=0;
		if(numofcr >= 2) {
        strncpy(ANALOGPIN0,buf,strlen(buf)-1);
				}
			if (buf[0]=='\n'){
				numofcr = numofcr + 1;
		if (numofcr >= 3) {
		NEWSTOP=TRUE;
			}
							  }
							}

		char SANALOGPIN0[2] = {0};
		strncpy(SANALOGPIN0,ANALOGPIN0,strlen(ANALOGPIN0)-1);
		strncpy(SANALOGPIN0,"00",2);//Remove this line to allow this pin to function

=================================================================================================================================
Finished ANALOG PIN 0
=================================================================================================================================
=============================================================================================================================
Get Reading from Analog Pin 1
=============================================================================================================================

				res = 0;
				NEWSTOP=FALSE;
				buf[0] = '\0';
				numofcr = 1;

				write(fd,"adc read 1\n",11);
				while (NEWSTOP==FALSE) {
				res = read(fd,buf,255);
				buf[res]=0;
				if(numofcr >= 2) {
		        strncpy(ANALOGPIN1,buf,strlen(buf)-1);
						}
					if (buf[0]=='\n'){
						numofcr = numofcr + 1;
				if (numofcr >= 3) {
				NEWSTOP=TRUE;
					}
									  }
									}

				char SANALOGPIN1[2] = {0};
				strncpy(SANALOGPIN1,ANALOGPIN1,strlen(ANALOGPIN1)-1);
				strncpy(SANALOGPIN1,"00",2);//Remove this line to allow this pin to function

=================================================================================================================================
Finished ANALOG PIN 1
=================================================================================================================================
=============================================================================================================================
Get Reading from Analog Pin 2
=============================================================================================================================

				res = 0;
				NEWSTOP=FALSE;
				buf[0] = '\0';
				numofcr = 1;
				write(fd,"adc read 2\n",11);
				while (NEWSTOP==FALSE) {
				res = read(fd,buf,255);
				buf[res]=0;
				if(numofcr >= 2) {
		        strncpy(ANALOGPIN2,buf,strlen(buf)-1);
						}
					if (buf[0]=='\n'){
						numofcr = numofcr + 1;
				if (numofcr >= 3) {
				NEWSTOP=TRUE;
					}
									  }
									}

				char SANALOGPIN2[2] = {0};
				strncpy(SANALOGPIN2,ANALOGPIN2,strlen(ANALOGPIN2)-1);
				strncpy(SANALOGPIN2,"00",2);//Remove this line to allow this pin to function;

=================================================================================================================================
Finished ANALOG PIN 2
=================================================================================================================================
=============================================================================================================================
Get Reading from Analog Pin 3
=============================================================================================================================

				res = 0;
				NEWSTOP=FALSE;
				buf[0] = '\0';
				numofcr = 1;
				write(fd,"adc read 3\n",11);
				while (NEWSTOP==FALSE) {
				res = read(fd,buf,255);
				buf[res]=0;
				if(numofcr >= 2) {
		        strncpy(ANALOGPIN3,buf,strlen(buf)-1);
						}
					if (buf[0]=='\n'){
						numofcr = numofcr + 1;
				if (numofcr >= 3) {
				NEWSTOP=TRUE;
					}
									  }
									}

				char SANALOGPIN3[2] = {0};
				strncpy(SANALOGPIN3,ANALOGPIN3,strlen(ANALOGPIN3)-1);
				strncpy(SANALOGPIN3,"00",2); //Remove this line to allow this pin to function

=================================================================================================================================
Finished ANALOG PIN 3
=================================================================================================================================
=============================================================================================================================
Get Reading from Analog Pin 4
=============================================================================================================================

				res = 0;
				NEWSTOP=FALSE;
				buf[0] = '\0';
				numofcr = 1;
				write(fd,"adc read 4\n",11);
				while (NEWSTOP==FALSE) {
				res = read(fd,buf,255);
				buf[res]=0;
				if(numofcr >= 2) {
		        strncpy(ANALOGPIN4,buf,strlen(buf)-1);
						}
					if (buf[0]=='\n'){
						numofcr = numofcr + 1;
				if (numofcr >= 3) {
				NEWSTOP=TRUE;
					}
									  }
									}

				char SANALOGPIN4[2] = {0};
				strncpy(SANALOGPIN4,ANALOGPIN4,strlen(ANALOGPIN4)-1);
				strncpy(SANALOGPIN4,"00",2); //Remove this line to allow this pin to function

=================================================================================================================================
Finished ANALOG PIN 4
=================================================================================================================================
=============================================================================================================================
Get Reading from  Analog Pin 5
=============================================================================================================================

				res = 0;
				NEWSTOP=FALSE;
				buf[0] = '\0';
				numofcr = 1;
				write(fd,"adc read 5\n",11);
				while (NEWSTOP==FALSE) {
				res = read(fd,buf,255);
				buf[res]=0;
				if(numofcr >= 2) {
		        strncpy(ANALOGPIN5,buf,strlen(buf)-1);
						}
					if (buf[0]=='\n'){
						numofcr = numofcr + 1;
				if (numofcr >= 3) {
				NEWSTOP=TRUE;
					}
									  }
									}

				char SANALOGPIN5[2] = {0};
				strncpy(SANALOGPIN5,ANALOGPIN5,strlen(ANALOGPIN5)-1);
				strncpy(SANALOGPIN5,"00",2); //Remove this line to allow this pin to function

=================================================================================================================================
Finished ANALOG PIN 5
=================================================================================================================================
=============================================================================================================================
Get Reading from Analog Pin 6
=============================================================================================================================

				res = 0;
				NEWSTOP=FALSE;
				buf[0] = '\0';
				numofcr = 1;
				write(fd,"adc read 6\n",11);
				while (NEWSTOP==FALSE) {
				res = read(fd,buf,255);
				buf[res]=0;
				if(numofcr >= 2) {
		        strncpy(ANALOGPIN6,buf,strlen(buf)-1);
						}
					if (buf[0]=='\n'){
						numofcr = numofcr + 1;
				if (numofcr >= 3) {
				NEWSTOP=TRUE;
					}
									  }
									}
					char SANALOGPIN6[2] = {0};
				strncpy(SANALOGPIN6,ANALOGPIN6,strlen(ANALOGPIN6)-1);
				strncpy(SANALOGPIN6,"00",2); //Remove this line to allow this pin to function

=================================================================================================================================
Finished ANALOG PIN 6
=================================================================================================================================
*/
		 //log_Function(DIGPIN15); //DEBUG CODE !!!

			//char *IO_Status_fmt = "%s:%s:%s:%s:%s:%s:%s:%s|%s:%s:%s:%s:%s:%s:%s|00.0:00.0|";
			  char *IO_Status_fmt = "%s:%s:%s:%s:%s:%s:%s:%s|00:00:00:00:00:00:00|00.0:00.0|";
			char IO_Status_Value[1024];

		    //sprintf(IO_Status_Value, IO_Status_fmt,DIGPIN8,DIGPIN9,DIGPIN10,DIGPIN11,DIGPIN12,DIGPIN13,DIGPIN14,DIGPIN15,SANALOGPIN0,SANALOGPIN1,SANALOGPIN2,SANALOGPIN3,SANALOGPIN4,SANALOGPIN5,SANALOGPIN6); //Format and apply data

			sprintf(IO_Status_Value, IO_Status_fmt,DIGPIN8,DIGPIN9,DIGPIN10,DIGPIN11,DIGPIN12,DIGPIN13,DIGPIN14,DIGPIN15); //Format and apply data
			char *New_IO_Status_Value = {0};
			New_IO_Status_Value = IO_Status_Value;
			close(fd);

			return (New_IO_Status_Value);

}
