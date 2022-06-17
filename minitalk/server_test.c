#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include "server.h"


void ft_siguser1(int sum)
{
	get.client_data = get.client_data << 1;
	printf("0\n");
	
	// usleep(1);
}

void ft_sigaction_usr1(int sig, siginfo_t *usr1_info, void *v)
{
	// write(1, "0", 1);
	get.client_data = get.client_data << 1;
	// printf("0\n");
	// usleep(500);
	get.bit_cnt++;
	if (get.bit_cnt == 8)
	{
		if (get.client_data == '\0')
			write(1, "\n", 1);
		else
		{
			reverse_data(&get.client_data, &get.reverse_data);
		// printf("get : %d\n", get.client_data);
		// printf("to  : %c\n", get.reverse_data);
		// printf("%c", get.reverse_data);
			write(1, &get.reverse_data, 1);
		}
		get.bit_cnt = 0;
		get.client_data = 0;
		get.reverse_data = 0;
	}
	// printf("%d", usr1_info->si_pid);
}

void ft_siguser2(int sum)
{
	// printf("1\n");
	get.client_data = get.client_data << 1;
	get.client_data++;
	// usleep(1);
}

void ft_sigaction_usr2(int sig, siginfo_t *usr2_info, void *a)
{
	// write(1, "1", 1);
	// usleep(500);
	get.client_data = get.client_data << 1;
	get.client_data++;
	get.bit_cnt++;
	if (get.bit_cnt == 8)
	{
		reverse_data(&get.client_data, &get.reverse_data);
		// printf("get : %d\n", get.client_data);
		// printf("to  : %c\n", get.reverse_data);
		write(1, &get.reverse_data, 1);
		// printf("%c", get.reverse_data);
		get.bit_cnt = 0;
		get.client_data = 0;
		get.reverse_data = 0;
	}
}

void reverse_data(unsigned char *from, unsigned char *to)
{
	unsigned char temp = *from;
	for (int i = 0; i < 8; i++)
	{
		if (temp % 2 == 1)
			*to = (*to << 1) + 1;
		else if (temp % 2 == 0)
			*to = (*to << 1);
		temp /= 2;
	}
}

int main()
{
	pid_t a;

	get.client_data = 0;
	get.reverse_data = 0;
	get.bit_cnt = 0;
	char pp;
	struct sigaction usr1;
	struct sigaction old1;
	struct sigaction usr2;
	struct sigaction old2;


	usr1.sa_handler = ft_siguser1;
	sigemptyset(&usr1.sa_mask);
	usr1.sa_sigaction = ft_sigaction_usr1;
	usr1.sa_flags = SIGINFO;

	usr2.sa_handler = ft_siguser2;
	sigemptyset(&usr2.sa_mask);
	usr2.sa_sigaction = ft_sigaction_usr2;
	usr2.sa_flags = SIGINFO;
	printf("%d\n", getpid());
	
	// signal(SIGUSR1, ft_siguser1);
	// signal(SIGUSR2, ft_siguser2);
	while (1)
	{
		sigaction(SIGUSR1, &usr1, NULL);//&old1);
		sigaction(SIGUSR2, &usr2, NULL);//&old2);
		// write(1, "\n", 1);
		pause();
		// convert_2base(&get.client_data, &get.reverse_data);
		// printf("get : %d\n", get.client_data);
		// printf("to  : %d\n", get.reverse_data);
		// revers_print();
		// sleep(1);
	}
}
