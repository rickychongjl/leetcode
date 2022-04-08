#include	"unp.h"

int
main(int argc, char **argv)
{
	int					sockfd, n, counter = 0;
	char				recvline[MAXLINE + 1];
	struct sockaddr_in	servaddr;

	if (argc != 2)
		err_quit("usage: a.out <IPaddress>");

	// Creates a TCP socket, returning a small integer descriptor 
	if ( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		err_sys("socket error");

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	// hton = host to network short
	servaddr.sin_port   = htons(9999);	/* daytime server */

	// pton = presentation to numeric, converting the ASCII command-line argument to proper format
	if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0)
		err_quit("inet_pton error for %s", argv[1]);

	// establishes a TCP connection with the server specified by the socket address structure
	// SA = struct sockaddr, a generic socket address structure
	// void * pointer type was not available earlier hence SA is defined and used here
	if (connect(sockfd, (SA *) &servaddr, sizeof(servaddr)) < 0)
		err_sys("connect error");

	// Byte-stream protocol, no guarantee that all the bytes of data will be returned by a single read
	// need to code the read in a loop and terminate the loop when either read returns 0 (the other end closed connection)
	// or value less than 0 (error)
	// SMTP marks the end of a record with \r\n
	// RPC and DNS place a binary count containing the record length in front of each record that is sent 
	// TCP itself provides NO record markers
	while ( (n = read(sockfd, recvline, MAXLINE)) > 0) {
		++counter;
		recvline[n] = 0;	/* null terminate */
		if (fputs(recvline, stdout) == EOF)
			err_sys("fputs error");
	}
	if (n < 0)
		err_sys("read error");

	printf("Counter is %d", counter);
	// terminates program and closing all open descriptors
	exit(0);
}
