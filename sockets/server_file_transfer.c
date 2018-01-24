#include "connection.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // read/write/close
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>





void error(const char *msg) {
	perror(msg);
	exit(1);
}






int main(int argc, char *argv[]) {

	if (argc < 2) { // No port number given
		fprintf(stderr, "Port# not provided. Program terminated.\n");
		exit(1);
	}

	int sockfd, newsockfd, portno, n;
	int buffer_size = 255;
	char buffer[buffer_size];

	struct sockaddr_in server_addr, client_addr;
	socklen_t client_len; // Why not integer?

	sockfd = socket(AF_INET, SOCK_STREAM, TCP_CONNECTION_ID);
	if (sockfd < 0) {
		error("Error opening Socket.");
	}

	bzero((char *) &server_addr, sizeof(server_addr)); // Clears data/text in anything it references
	portno = atoi(argv[1]);

	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = INADDR_ANY;
	server_addr.sin_port = htons(portno);

	if ( bind(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
		error("Binding Failed.");
	}

	listen(sockfd, MAX_CLIENTS);
	client_len = sizeof(client_addr);

	newsockfd = accept(sockfd, (struct sockaddr *) &client_addr, &client_len);
	if (newsockfd < 0) {
		error("Error on accept().");
	}


	FILE *fp;

	int ch = 0;
	fp = fopen("rnd_file_recieve.txt", "a");
	int numwords ;
	read(newsockfd, &numwords, sizeof(int));


	while ( (ch != numwords)) {

		bzero(buffer, buffer_size);
		if (read(newsockfd, buffer, buffer_size) < 0) {
			error("Error in read().");
		}
		fprintf(fp, "%s ", buffer);
		++ch;
	}

	printf("The file has been successfully recieved.\n");

	close(newsockfd);
	close(sockfd);


	return 0;
}

