#include "connection.h"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // read/write/close
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> // struct hostent
#include <ctype.h>


void transfer_file(int sockfd, char *filename) {

	char buffer[MAX_BUFFER_SIZE];

	bzero(buffer, MAX_BUFFER_SIZE);
	FILE *fp;
	int numwords = 0;
	char c;

	fp = fopen(filename, "r");
	while ((c = fgetc(fp)) != EOF) {
		fscanf(fp, "%s", buffer);
		if (isspace(c) || c == '\t') {
			++numwords;
		}
	}

	write(sockfd, &numwords, sizeof(int));
	rewind(fp);

	do {
		fscanf(fp, "%s", buffer);
		write(sockfd, buffer, MAX_BUFFER_SIZE);
	} while ((c = fgetc(fp)) != EOF);

	printf("The file has been successfully sent.\n");

	close(sockfd);

}

int connect_to_server(char *hostname, int port) {

	struct sockaddr_in server_addr;
	struct hostent *server;

	int sockfd = socket(AF_INET, SOCK_STREAM, TCP_CONNECTION_ID);
	if (sockfd < 0) {
		throw_error("Error opening Socket.");
	}

	server = gethostbyname(hostname);
	if (! server) {
		fprintf(stderr, "Error, no such host.\n");
	}


	bzero((char *) &server_addr, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	bcopy((char *) server->h_addr, (char *) &server_addr.sin_addr.s_addr, server->h_length);
	server_addr.sin_port = htons(port);

	if ( connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0 ) {
		throw_error("Connection failed.");
	}

	return sockfd
}

int main(int argc, char *argv[]) {

	if (argc < 3) { 
		fprintf(stderr, "%s usage: <hostname> <port>\n", argv[0]);
		exit(1);
	}


	return 0;
}


