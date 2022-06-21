/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_transmit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choidongd <choidongd@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 15:14:09 by choidongd         #+#    #+#             */
/*   Updated: 2022/06/18 15:31:50 by choidongd        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "server.h"

void	reverse_data(unsigned char *from, unsigned char *to)
{
	unsigned char	temp;
	int				i;

	temp = *from;
	i = -1;
	while (++i < 8)
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
	write(1, "\nClient : ", 10);
	ft_putnbr((int)client_pid);
	write(1, "\n[TEXT]\n", 8);
	kill(client_pid, SIGUSR1);
	init_data(&g_get);
}

void	receive_check(void)
{
	write(1, "\n[Result]\nreceive / transmit : ", 31);
	ft_putnbr(g_get.transmit_cnt);
	write(1, " / ", 3);
	init_data(&g_get);
}

void	transmit_end(pid_t client_pid)
{
	write(1, "\nreceive complete\n", 19);
	kill(client_pid, SIGUSR2);
	g_get.transmit_cnt = 0;
	init_data(&g_get);
}

void	receive_character(void)
{
	if (g_get.buf_cnt == 0)
		utf_check(g_get.reverse_data);
	g_get.buf[g_get.buf_cnt] = g_get.reverse_data;
	g_get.buf_cnt++;
	g_get.bit_cnt = 0;
}
