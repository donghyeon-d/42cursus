#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "client.h"

int main(int argc, char *argv[])
{
	char				*transmit_count;

	if (argc != 3)
	{
		write(1, "You must 2 arguments [server PID] [message]\n", 44);
		return (0);
	}
	int pid = atoi(argv[1]);
	get.transmit_cnt = 0;
	signal(SIGUSR1, client_siguser);
	signal(SIGUSR2, client_siguser);
	transmit_contol((pid_t)pid, START_OF_HEADING);
	transmit_text((pid_t)pid, argv[2]);
	transmit_contol((pid_t)pid, END_OF_TEXT);
	transmit_count = ft_itoa(get.transmit_cnt);
	transmit_text((pid_t)pid, transmit_count);
	transmit_contol((pid_t)pid, END_OF_TRANSMISSION);
	free(transmit_count);
	return (0);
}
