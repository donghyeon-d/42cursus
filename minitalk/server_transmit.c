#include <unistd.h>
#include "server.h"

void	reverse_data(unsigned char *from, unsigned char *to)
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

void	receive_start(pid_t client_pid)
{
	write(1, "\n[TEXT]\n", 8);
	kill(client_pid, SIGUSR1);
	init_data(&get);
}

void	receive_check()
{
	write(1, "\n\n[Summary]\nreceive / transmit : ", 33);
	ft_putnbr(get.transmit_cnt);
	write(1, " / ", 3);
	init_data(&get);
}

void	transmit_end(pid_t client_pid)
{
	write(1, "\nreceive complete\n", 19);
	kill(client_pid, SIGUSR2);
	get.transmit_cnt = 0;
	init_data(&get);
}

void	receive_character()
{
	if (get.buf_cnt == 0)
		utf_check(get.reverse_data);
	get.buf[get.buf_cnt] = get.reverse_data;
	get.buf_cnt++;
	get.bit_cnt = 0;
}
