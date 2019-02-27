/*
 * USB_IO_Get_IO_Status.h
 *
 *  Created on: Feb 13, 2019
 *      Author: mark
 */

#ifndef USB_IO_GET_IO_STATUS_H_
#define USB_IO_GET_IO_STATUS_H_



#endif /* USB_IO_GET_IO_STATUS_H_ */

char *USB_IO_Get_IO_Status(void){

	struct termios tio;
	        struct termios stdio;
	        struct termios old_stdio;
	        int tty_fd;

	        //unsigned char c='D';
	        tcgetattr(STDOUT_FILENO,&old_stdio);

	        memset(&stdio,0,sizeof(stdio));
	        stdio.c_iflag=0;
	        stdio.c_oflag=0;
	        stdio.c_cflag=0;
	        stdio.c_lflag=0;
	        stdio.c_cc[VMIN]=1;
	        stdio.c_cc[VTIME]=0;
	        tcsetattr(STDOUT_FILENO,TCSANOW,&stdio);
	        tcsetattr(STDOUT_FILENO,TCSAFLUSH,&stdio);
	        fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK);       // make the reads non-blocking

	        memset(&tio,0,sizeof(tio));
	        tio.c_iflag=0;
	        tio.c_oflag=0;
	        tio.c_cflag=CS8|CREAD|CLOCAL;           // 8n1
	        tio.c_lflag=0;
	        tio.c_cc[VMIN]=1;
	        tio.c_cc[VTIME]=5;

	        char *com_port = "/dev/ttyACM0";

	        tty_fd=open(com_port, O_RDWR | O_NONBLOCK);
	        cfsetospeed(&tio,B9600);            // 9600 baud
	        cfsetispeed(&tio,B9600);            // 9600 baud

	        tcsetattr(tty_fd,TCSANOW,&tio);



	        //while (c!='q')
	        //{
	        //        if (read(tty_fd,&c,1)>0)        write(STDOUT_FILENO,&c,1);              // if new data is available on the serial port, print it out
	        //        if (read(STDIN_FILENO,&c,1)>0)  write(tty_fd,&c,1);                     // if new data is available on the console, send it to the serial port
	        // }



	        close(tty_fd);
	        tcsetattr(STDOUT_FILENO,TCSANOW,&old_stdio);


	return(0);
}
