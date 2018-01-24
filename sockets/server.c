#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // read/write/close
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>


/*
Server			Client
Socket()		Socket()
Bind()	
listen()
accept()		Connection()
read()			write()
write()			read()
close()			close()

*/

/*


// Communication domain Addr family -> AF_INET (IPV4)
// Communication type = (SOCK_STREAM -> TCP) OR (SOCK_DGRAM -> UDP)
// Protocol -> 0 (Default for TCP)
// int sockfd = socket(int domain, int type, int protocol);


// When socket() is created, it has no address assigned to it
// sockfd is returned by socket()
// addrlen -> size of struct pointed to addr
// int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen)
// returns -1 if fail, else 0
struct sockaddr { // Purpose: cast addr pointer?
	sa_family_t sa_family;
	char sa_data[14];
};


// Listens for connection of socket referenced by sockfd
// backlog -> number of connections a system can handle (rejects after backlog is exceeded)
// int listen(int sockfd, int backlog);


// Returns file descriptor (int) for use in later communications
// Waits for connection() function from client side
// newsockfd = accept(sockfd, (struct sockaddr *) &addr, &addrlen);


// Returns 0 if success and -1 if failure
// int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);

// buffer is string we want to pass 
/// size if maximum chars to read/write
// int read(newsockfd, buffer, buffer_size);
// int write(newsockfd, buffer, buffer_size);
// Other options are
// send/receive. Contain one more arg (flag) not really needed

// close() closes socket
*/


#define MAX_CLIENTS 5
#define TCP_CONNECTION_ID 0



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

	while (1) {

		bzero(buffer, buffer_size);
		if (read(newsockfd, buffer, buffer_size) < 0) {
			error("Error in read().");
		}
		printf("Client: %s", buffer);
		bzero(buffer, buffer_size);
		fgets(buffer, buffer_size, stdin);

		if (write(newsockfd, buffer, strlen(buffer)) < 0) {
			error("Error in write().");
		}

		if ( strncmp("bye", buffer, 3) == 0) {
			break;
		}
	}

	close(newsockfd);
	close(sockfd);


	return 0;
}

