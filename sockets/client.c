#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // read/write/close
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> // struct hostent

#define TCP_CONNECTION_ID 0


void error(const char *msg) {
	perror(msg);
	exit(1);
}

int main(int argc, char *argv[]) {

	if (argc < 3) { 
		fprintf(stderr, "%s usage: <hostname> <port>\n", argv[0]);
		exit(1);
	}


	int sockfd, portno, n;
	int buffer_size = 255;
	char buffer[buffer_size];

	struct sockaddr_in server_addr;
	struct hostent *server;
	portno = atoi(argv[2]);
	sockfd = socket(AF_INET, SOCK_STREAM, TCP_CONNECTION_ID);
	if (sockfd < 0) {
		error("Error opening Socket.");
	}

	server = gethostbyname(argv[1]);
	if (! server) {
		fprintf(stderr, "Error, no such host.\n");
	}


	bzero((char *) &server_addr, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	bcopy((char *) server->h_addr, (char *) &server_addr.sin_addr.s_addr, server->h_length);
	server_addr.sin_port = htons(portno);

	if ( connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0 ) {
		error("Connection failed.");
	}

	while (1) {

		bzero(buffer, buffer_size);
		fgets(buffer, buffer_size, stdin);
		if (write(sockfd, buffer, strlen(buffer)) < 0) {
			error("Error in write().");
		}

		bzero(buffer, buffer_size);
		if (read(sockfd, buffer, buffer_size) < 0) {
			error("Error in read().");
		}
		printf("Server: %s", buffer);

		if ( strncmp("bye", buffer, 3) == 0) {
			break;
		}
	}

	close(sockfd);


	return 0;
}

// netstat -npt to view connections


