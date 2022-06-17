#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

/* putnum */
// int main(int argc, char *argv[])
// {
// 	// printf("%d", getpid());
// 	char *arr;

// 	if (argc != 3)
// 		return (0);
// 	int pid = atoi(argv[1]);
// 	int charactor = atoi(argv[2]);
// 	int i = 8;

// 	for (int i = 0; i < 8; i++)
// 	{
// 		if (charactor % 2 == 0)
// 			kill((pid_t)pid, SIGUSR1);
// 		else if (charactor % 2 == 1)
// 			kill((pid_t)pid, SIGUSR2);
// 		charactor /= 2;
// 			sleep(1);
// 	}
// }

int main(int argc, char *argv[])
{
	// printf("%d", getpid());
	char	charactor;
	int		i;

	if (argc != 3)
		return (0);
	int pid = atoi(argv[1]);
	i = 0;
	while ((argv[2][i]) != '\0')
	{
		charactor = argv[2][i];
		for (int j = 0; j < 8; j++)
		{
			if (charactor % 2 == 0)
				kill((pid_t)pid, SIGUSR1);
			else if (charactor % 2 == 1)
				kill((pid_t)pid, SIGUSR2);
			charactor /= 2;
				usleep(150);
		}
		i++;
	}
	for (int i = 0; i < 8; i++)
	{
		kill((pid_t)pid, SIGUSR1);
		usleep(150);
	}
}