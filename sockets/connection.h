#ifndef _CONNECTION_H_
#define _CONNECTION_H_


#define MAX_CLIENTS 5
#define TCP_CONNECTION_ID 0
#define MAX_BUFFER_SIZE 255
#define PORT_NO 4761



void throw_error(const char *msg) {
	perror(msg);
	exit(1);
}




#endif
