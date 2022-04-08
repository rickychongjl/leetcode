#include	"unp.h"
#include	<time.h>

int
main(int argc, char **argv)
{
	int					listenfd, connfd;
	struct sockaddr_in	servaddr;
	char				buff[MAXLINE];
	time_t				ticks;

	// Creates a TCP socket
	listenfd = Socket(AF_INET, SOCK_STREAM, 0);

	// Fills zeros in the internet socket address
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family      = AF_INET;
	// specifies the IP address as INADDR_ANY allowing the server to accept a client connection on any interface
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port        = htons(9999);	/* daytime server */

	Bind(listenfd, (SA *) &servaddr, sizeof(servaddr));

	// The server is converted into a listening socket, on which incoming connections from clients will be accepted by the kernel
	// socket, bind, listen, these hree steps are normal steps for any TCP server to prepare what we call the listening descriptor
	// LISTENQ is a constant defined to specify maximum number of client connections that the kernel will queue 
	// for this listening descriptor
	Listen(listenfd, LISTENQ);

	// 3-way-handshake 
	// When it completes, accept returns a connected descriptor, for communication with the new client
	for ( ; ; ) {
		connfd = Accept(listenfd, (SA *) NULL, NULL);

		// returns the number of seconds since the Unix Epoch
        ticks = time(NULL);
		// ctime converts the number to human-readable string, snprintf appends \r\n
		// using snprintf will not overflow by specifying the size of the destination buffer in the 2nd argument
        snprintf(buff, sizeof(buff), "%.24s\r\n", ctime(&ticks));
		for ( int i = 0; i < strlen(buff); ++i )
        	Write(connfd, buff+i, 1);
		// a FIN is sent in each direction and each FIN is acknowledged by the other end
		Close(connfd);

		// This is a iterative server, iterating through each client one at a time.
		// Concurrent server could be implemented by using fork, threads, or pre-fork.
	}
}
