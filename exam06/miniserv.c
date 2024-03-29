#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

void fatal_error()
{
	write(2, "fatal error\n", 12);
	exit(1);
}

int main(int argc, char **argv)
{
	int listen_fd, accepted_fd;
	struct sockaddr_in host_addr, client_addr;

	// if (argc != 2) 
	// {
	// 	write(2, "Wrong number of arguments\n", 26);
	// 	exit(1);
	// }

	bzero(&client_addr, sizeof(struct sockaddr_in));

	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0)
		fatal_error();

	struct sockaddr_in addr;
	socklen_t addr_len = sizeof(addr);
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = htonl(2130706433);
	// addr.sin_port = htons(4444);
	addr.sin_port = htons(atoi(argv[1]));


	if ((bind(sockfd, (const struct sockaddr *)&addr, sizeof(addr))) < 0)
		fatal_error();
	int ret_lis = listen(sockfd, 128);
	if (ret_lis < 0)
		fatal_error();
	
	int len = sizeof(client_addr);
	int cla_sock = accept(sockfd, (struct sockaddr *)&client_addr, (socklen_t *)&len);
	char str[100];
	while (1) {
		int l = recv(cla_sock, str, 100, 0);
		if (l > 0) {
			write(1, str, 100);
		}
	}
}