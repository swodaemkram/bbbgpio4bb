/*
 * Signal_Handler.h
 *
 *  Created on: Feb 15, 2019
 *      Author: mark
 */

#ifndef SIGNAL_HANDLER_H_
#define SIGNAL_HANDLER_H_



#endif /* SIGNAL_HANDLER_H_ */

void Signal_Handler(int signum){

			remove("/run/gpio4bb.pid");
			char log_message [250] = {0};
			strcat(log_message, "teminate signal received shutting gpio4bb service down" );
			log_Function(log_message);
			exit(0);
}
