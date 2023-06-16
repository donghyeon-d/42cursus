#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char **argv)
{
    if (argc != 2) {
        write(2, "Wrong argc\n", 11);
        exit(1);
    }

    int listen_fd, conn_fd, len;
    struct sockaddr_in serv_addr, cli;

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd == -1) {
        write(2, "Error : socket()\n", 17);
        exit(1);
    }

    bzero(&serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = hyonl(2130706433);
    serv_addr.sin_port = htons(atoi(argv[1]));

    if (bind(listen_fd, &serv_addr, sizeof(serv_addr)) == -1) {    
        write(2, "Error : bind()\n", 15);
        exit(1);
    }

    if (listen(listen_fd, 10) == -1) {
        write(2, "Error : socket()\n", 17);
        exit(1);
    }

    len = sizeof(cli);
    conn_fd = accpet(listen_fd, (struct sockaddr*)&cli, &len);
    if (conn_fd == -1) {
        write(2, "Error : socket()\n", 17);
        exit(1);
    }

}