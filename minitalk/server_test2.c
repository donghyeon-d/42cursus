#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
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

void	utf_check(unsigned char reverse_data)
{
	if (get.buf_cnt > 0)
		return ;
	if (reverse_data >> 7 == 0)
		get.utf_byte = 1;
	else if (reverse_data >> 5 == 6)
		get.utf_byte = 2;
	else if (reverse_data >> 4 == 14)
		get.utf_byte = 3;
	else if (reverse_data >> 3 == 30)
		get.utf_byte = 3;
}

// void	utf_check(unsigned char client_data)
// {
// 	if (client_data % 2 == 0)
// 		get.utf_byte = 1;
// 	else
// 		get.utf_byte = 3;
// 	else if (client_data % 2 == 1 && (client_data - 1) % 4 != 0 \
// 	&& (client_data - 3) % 8 != 0 && (client_data - 7) % 16 != 0)
// 		get.utf_byte = 4;
// 	else if (client_data % 2 == 1 && (client_data - 1) % 4 != 0 \
// 	&& (client_data - 3) % 8 != 0)
// 		get.utf_byte = 4;
// 	else if (client_data % 2 == 1 && (client_data - 1) % 4 != 0)
// 		get.utf_byte = 2;
// }

void ft_siguser1(int sum)
{
	get.client_data = get.client_data << 1;
}

void ft_siguser2(int sum)
{
	get.client_data = get.client_data << 1;
	get.client_data++;
}

void ft_sigaction_usr1(int sig, siginfo_t *usr1_info, void *v)
{
	// write(1, "0 ", 2);
	get.client_data = get.client_data << 1;
	get.bit_cnt++;

	if (get.bit_cnt == 8)
	{
		if (get.client_data == '\0')
		{
			write(1, "\nreceive complete\n", 18);
			init_data(&get);
		}
		else
		{
			reverse_data(&get.client_data, &get.reverse_data);
			get.bit_cnt = 0;
			// if (get.utf_byte == 0)
				utf_check(get.reverse_data);	// 유니코드 체크
			get.buf[get.buf_cnt] = get.reverse_data;// 버퍼에 넣어주기
			get.buf_cnt++;
			// printf("\nUTF : %d\n", get.utf_byte);
		}
	}
	if (get.utf_byte && get.client_data != '\0' && get.buf_cnt == get.utf_byte)// 버퍼 다 찼으면 출력해주기
	{
		// printf("\n%s, %d, %d, %d, utf_byte : %d\n", get.buf, get.buf[0], get.buf[1], get.buf[2], get.utf_byte);
		write(1, get.buf, get.utf_byte);
		init_data(&get);
	}
}

void ft_sigaction_usr2(int sig, siginfo_t *usr2_info, void *a)
{
	// write(1, "1 ", 2);
	get.client_data = get.client_data << 1;
	get.client_data++;
	get.bit_cnt++;
	if (get.bit_cnt == 8)
	{
		if (get.client_data == '\0')
		{
			write(1, "\nreceive complete\n", 18);
			init_data(&get);
		}
		else
		{
			reverse_data(&get.client_data, &get.reverse_data);
			// if (get.utf_byte == 0)
				utf_check(get.reverse_data); // 유니코드 체크
			get.buf[get.buf_cnt] = get.reverse_data;// 버퍼에 넣어주기
			get.buf_cnt++;
			get.bit_cnt = 0;
			// printf("\nUTF : %d\n", get.utf_byte);
		}
	}
	if (get.utf_byte && get.client_data != '\0' && get.buf_cnt == get.utf_byte)// 버퍼 다 찼으면 출력해주기
	{
		// printf("\n%s, %d, %d, %d, utf_byte : %d\n", get.buf, get.buf[0], get.buf[1], get.buf[2], get.utf_byte);
		write(1, get.buf, get.utf_byte);
		init_data(&get);
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
	init_data(&get);
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
