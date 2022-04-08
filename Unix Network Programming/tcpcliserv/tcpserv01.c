#include	"unp.h"

int
main(int argc, char **argv)
{
	int					listenfd, connfd;
	pid_t				childpid;
	socklen_t			clilen;
	// IPv4 socket address structure 
	struct sockaddr_in	cliaddr, servaddr;

	// Creates TCP socket
	listenfd = Socket(AF_INET, SOCK_STREAM, 0);

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family      = AF_INET;
	// wildcard address, sin_addr is in in_addr structure, while sin_addr.s_addr is in in_addr_t (unsigned 32-bit integer)
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	// well-known port, defined aws 9877 in the unp.h header
	servaddr.sin_port        = htons(SERV_PORT);

	Bind(listenfd, (SA *) &servaddr, sizeof(servaddr));

	// Convert this socket to listening socket
	Listen(listenfd, LISTENQ);

	for ( ; ; ) {
		clilen = sizeof(cliaddr);
		// blocks to wait for a client connection to complete
		connfd = Accept(listenfd, (SA *) &cliaddr, &clilen);

		// fork spawns a child, and the child handles the new client.
		// child closes the listening socket, parent closes the connected socket
		if ( (childpid = Fork()) == 0) {	/* child process */
			Close(listenfd);	/* close listening socket */
			str_echo(connfd);	/* process the request */
			exit(0);
		}
		Close(connfd);			/* parent closes connected socket */
	}
}
