#include <unistd.h>
#include <stdlib.h>
#include "server.h"

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

void server_siguser(int sig)
{
	get.client_data = get.client_data << 1;
	if (sig == SIGUSR2)
		get.client_data++;
}

void ft_sigaction_usr(int sig, siginfo_t *usr_info, void *v)
{
	v = (char *)v;
	get.client_data = get.client_data << 1;
	if (sig == SIGUSR2)
		get.client_data++;
	get.bit_cnt++;
	get.transmit_cnt++;
	if (get.bit_cnt == 8)
	{
		reverse_data(&get.client_data, &get.reverse_data);
		if (get.reverse_data == START_OF_HEADING)
			receive_start(usr_info->si_pid);
		else if (get.reverse_data == END_OF_TEXT)
			receive_check();
		else if (get.reverse_data == END_OF_TRANSMISSION)
			transmit_end(usr_info->si_pid);
		else
		{
			receive_character();
			if (get.reverse_data > 4  && get.buf_cnt == get.utf_byte)
				write(1, get.buf, get.utf_byte);
			if (get.reverse_data < 5 || get.buf_cnt == get.utf_byte)
				init_data(&get);
		}
	}
}