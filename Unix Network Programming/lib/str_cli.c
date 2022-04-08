#include	"unp.h"

void
str_cli(FILE *fp, int sockfd)
{
	char	sendline[MAXLINE], recvline[MAXLINE];

	// fgets reads a line of text from standard input
	while (Fgets(sendline, MAXLINE, fp) != NULL) {

		// writen sends the line to the server
		Writen(sockfd, sendline, strlen(sendline));

		// readline reads the line echoed back from the server
		if (Readline(sockfd, recvline, MAXLINE) == 0)
			err_quit("str_cli: server terminated prematurely");

		// fputs writes the line to standard output
		Fputs(recvline, stdout);
	}

	// Fgets returns a null pointer when encounter EOF
}
