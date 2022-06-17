#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

void client_siguser1(int sum)
{
	write(1, "You can send message\n", 21);
}

void client_siguser2(int sum)
{
	write(1, "Transmission complete\n", 22);
}

void	is_connect(pid_t server_pid)
{
	int	i;

	i = -1;
	while (++i < 8)
	{
		if (kill(server_pid, SIGUSR2))
		{
			write("Can not connect ");
				
			exit(1);
		}
	}
}

int main(int argc, char *argv[])
{
	struct sigaction client_usr1;
	struct sigaction client_usr2;
	unsigned char	charactor;
	int		i;

	if (argc != 3)
		return (0);
	int pid = atoi(argv[1]);
	i = 0;
	// 서버로 신호 보내보기
	while ((argv[2][i]) != '\0')
	{
		charactor = argv[2][i];
		for (int j = 0; j < 8; j++)
		{
			if (charactor % 2 == 0)
			{
				kill((pid_t)pid, SIGUSR1);
			}
			else if (charactor % 2 == 1)
			{
				kill((pid_t)pid, SIGUSR2);
			}
			charactor /= 2;
			usleep(700);
		}
		i++;
	}
	for (int i = 0; i < 8; i++)
	{
		kill((pid_t)pid, SIGUSR1);
		usleep(700);
	}
}