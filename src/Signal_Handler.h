/*
 * Signal_Handler.h
 *
 *  Created on: Feb 15, 2019
 *      Author: mark
 */

#ifndef SIGNAL_HANDLER_H_
#define SIGNAL_HANDLER_H_



#endif /* SIGNAL_HANDLER_H_ */

void Signal_Handler(int signal){


			remove("/run/gpio4bb.pid");
			//strcat(log_message, "Caught terminate Signal" );
			exit(0);
}
