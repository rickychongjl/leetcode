#include	"unp.h"

int
main(int argc, char **argv)
{
	int					sockfd;
	// Internet socket address (IPv4)
	struct sockaddr_in	servaddr;

	if (argc != 2)
		err_quit("usage: tcpcli <IPaddress>");

	// Creates TCP socket
	sockfd = Socket(AF_INET, SOCK_STREAM, 0);

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(SERV_PORT);
	// Convert the server IP address string pointed from the command line argument,
	// and store the binary result through the &servaddr.sin_addr
	Inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

	// Establishes connection with the server
	Connect(sockfd, (SA *) &servaddr, sizeof(servaddr));

	str_cli(stdin, sockfd);		/* do it all */

	exit(0);
}
