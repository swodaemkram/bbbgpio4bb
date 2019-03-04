/*
 * USB_IO_Initialize.h
 *
 *  Created on: Feb 13, 2019
 *      Author: mark
 */

#ifndef USB_IO_INITIALIZE_H_
#define USB_IO_INITIALIZE_H_



#endif /* USB_IO_INITIALIZE_H_ */

#include <termios.h>
#include <fcntl.h>
#include <sys/signal.h>
#include <sys/types.h>

/* baudrate settings are defined in <asm/termbits.h>, which is
included by <termios.h> */
#define BAUDRATE B9600
#define MODEMDEVICE "/dev/ttyACM0" //set the USBGPIO_Port
#define _POSIX_SOURCE 1 /* POSIX compliant source */
#define FALSE 0
#define TRUE 1
volatile int STOP=FALSE;


void USB_IO_Initialize(void){

	char log_message [250] = {0};
	//strncpy(log_message,"Starting USBGPIO Hardware Initialization... ",47);
	log_Function("Starting USBGPIO Hardware Initialization... ");

	int fd;
	int res;
	struct termios oldtio,newtio;
	char buf[255] = {0};
	int numofcr = 1;
	char USBGPIO_Version[255] = {0};
	/*
	Open GPIO device for reading and writing and not as controlling tty
	because we don't want to get killed if linenoise sends CTRL−C.
	*/
	fd = open(MODEMDEVICE, O_RDWR | O_NOCTTY );
	if (fd <0)
			{
		    perror(MODEMDEVICE);
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
	newtio.c_cflag = BAUDRATE | CRTSCTS | CS8 | CLOCAL | CREAD;
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
	/*
	now clean the modem line and activate the settings for the port r
	*/
	tcflush(fd, TCIFLUSH);
	tcsetattr(fd,TCSANOW,&newtio);
	/*
	terminal settings done, now handle input
	In this example, inputting a 'z' at the beginning of a line will
	exit the program.
	*/

	write(fd,"ver\n",4); //Ask for the Version of USB Firmware


	while (STOP==FALSE) {
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
		//printf("%s", buf);                                //Stop printing everything
		strncpy(USBGPIO_Version,buf,strlen(buf)-1);			// Copy our data minus the new line character because we don't want that
	                  }
	                                                        //if (buf[0]=='\n') STOP=TRUE;
	if (buf[0]=='\n'){                                      //if buf has a '\n' new line character increment the line counter
		numofcr = numofcr + 1;								//if there are 2 or more out data is in the buffer so bail out
		if (numofcr >= 3) {
			STOP=TRUE;
		}

					  }
						}

	write(fd,"gpio iodir ffff\n",16);
	//printf("USBGPIO firmware Version is %s\n",USBGPIO_Version);

	close(fd);                                               //close the USBGPIO Port

	sprintf(log_message,"USBGPIO Firmware Version is %s",USBGPIO_Version);
	log_Function(log_message);
	//sprintf(log_message,"USBGPIO Hardware Initialized... ");
	log_Function("USBGPIO Hardware Initialized... ");


	return;
}
