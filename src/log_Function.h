/*
 * log_Function.h
 *
 *  Created on: Feb 14, 2019
 *      Author: mark
 */

#ifndef LOG_FUNCTION_H_
#define LOG_FUNCTION_H_



#endif /* LOG_FUNCTION_H_ */


void log_Function(void){


		struct timespec ts;
	    timespec_get(&ts, TIME_UTC);
	    char buff[100];
	    strftime(buff, sizeof buff, "%D %T", gmtime(&ts.tv_sec));

		FILE *gpio4bb_log = NULL; //declare File Pointer
		gpio4bb_log = fopen("/var/log/gpio4bb.log", "a");

		char *Mytime_fmt = "%s.%09ld";
		char MyTime[27];
		sprintf(MyTime, Mytime_fmt, buff,ts.tv_nsec); //Format and apply data

		int MyTimeLen = 0;
		MyTimeLen = strlen(MyTime);

		fwrite(MyTime,1,MyTimeLen,gpio4bb_log);
		fclose(gpio4bb_log);


		return;





}
