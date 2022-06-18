#include <signal.h>
#include <unistd.h>
#include "server.h"

void	init_data(t_data *data)
{
	int i = 0;

	data->client_data = 0;
	data->reverse_data = 0;
	data->bit_cnt = 0;
	data->utf_byte = 1;
	data->buf_cnt = 0;
	while (i < 4)
	{
		data->buf[i] = 0;
		i++;
	}
}

int main()
{
	struct sigaction server_usr;

	init_data(&get);
	get.transmit_cnt = 0;
	server_usr.sa_handler = server_siguser;
	server_usr.sa_sigaction = ft_sigaction_usr;
	server_usr.sa_flags = SIGINFO;
	write(1, "Server PID : ", 13);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	while (1)
	{
		sigaction(SIGUSR1, &server_usr, NULL);
		sigaction(SIGUSR2, &server_usr, NULL);
		pause();
	}
}
