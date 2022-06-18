#include <unistd.h>
#include <stdlib.h>
#include "client.h"

void client_siguser(int sig)
{
	if (sig == SIGUSR1)
		write(1, "Sending a message\n", 18);
	else if (sig == SIGUSR2)
		write(1, "All the Signal transmitted well\n", 32);
}

void	transmit_text(pid_t server_pid, char *text)
{
	int	i;
	int	j;
	unsigned char	charactor;

	i = -1;
	while (text[++i] != '\0')
	{
		j = -1;
		charactor = text[i];
		while (++j < 8)
		{
			if (charactor % 2 == 0)
				kill((pid_t)server_pid, SIGUSR1);
			else if (charactor % 2 == 1)
				kill((pid_t)server_pid, SIGUSR2);
			charactor /= 2;
			usleep(100);
			get.transmit_cnt++;
		}
	}
}

void	transmit_contol(pid_t server_pid, char control)
{
	int		i;
	int		error;
	char	signal;

	error = 0;
	i = -1;
	signal = control;
	while (++i < 8)
	{
		if (signal % 2 == 0)
			error += kill(server_pid, SIGUSR1);
		else if (signal % 2 == 1)
			error += kill(server_pid, SIGUSR2);
		signal /= 2;
		usleep(100);
		get.transmit_cnt++;
	}
	if (error < 0)
	{
		write(1, "Can not connect (check PID)\n", 28);
		exit(1);
	}
}