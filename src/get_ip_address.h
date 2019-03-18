/*
 * get_ip_address.h
 *
 *  Created on: Feb 28, 2019
 *      Author: mark
 */

#ifndef GET_IP_ADDRESS_H_
#define GET_IP_ADDRESS_H_



#endif /* GET_IP_ADDRESS_H_ */


#include <netdb.h>
#include <ifaddrs.h>

void get_ip_address(void) {

	log_Function("I.P. Addresses Bound to GPIO4BB hardware are....");
	struct ifaddrs *ifaddr, *ifa;
	    int family, s;
	    char host[NI_MAXHOST];

	    if (getifaddrs(&ifaddr) == -1)
	    {
	    	log_Function("Could Not Get I.P. Address of this unit!");
	    	remove("/run/gpio4bb.pid");
	    	exit(1);
	    }


	    for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next)
	    {
	        if (ifa->ifa_addr == NULL)
	            continue;

	        s=getnameinfo(ifa->ifa_addr,sizeof(struct sockaddr_in),host, NI_MAXHOST, NULL, 0, NI_NUMERICHOST);

	        if( /*(strcmp(ifa->ifa_name,"wlan0")==0)&&( */ ifa->ifa_addr->sa_family==AF_INET) // )
	        {
	            if (s != 0)
	            {
	            	log_Function("Could Not Get I.P. Address of this unit!");
	            	remove("/run/gpio4bb.pid");
	            	exit(1);
	            }
	            //printf("\tInterface : <%s>\n",ifa->ifa_name );
	            //printf("\t  Address : <%s>\n", host);


	            log_Function(host);

	        }
	    }

	    freeifaddrs(ifaddr);


	return;
}
