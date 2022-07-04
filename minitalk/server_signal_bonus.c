/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_signal_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 15:13:14 by choidongd         #+#    #+#             */
/*   Updated: 2022/06/28 19:16:41 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "server.h"

void	utf_check(unsigned char reverse_data)
{
	if (g_get.buf_cnt > 0)
		return ;
	if (reverse_data >> 7 == 0)
		g_get.utf_byte = 1;
	else if (reverse_data >> 5 == 6)
		g_get.utf_byte = 2;
	else if (reverse_data >> 4 == 14)
		g_get.utf_byte = 3;
	else if (reverse_data >> 3 == 30)
		g_get.utf_byte = 4;
}

void	server_siguser(int sig)
{
	g_get.client_data = g_get.client_data << 1;
	if (sig == SIGUSR2)
		g_get.client_data++;
}

void	ft_sigaction_usr(int sig, siginfo_t *usr_info, void *v)
{
	v = (char *)v;
	g_get.client_data = g_get.client_data << 1;
	if (sig == SIGUSR2)
		g_get.client_data++;
	g_get.bit_cnt++;
	g_get.transmit_cnt++;
	if (g_get.bit_cnt == 8)
	{
		reverse_data(&g_get.client_data, &g_get.reverse_data);
		if (g_get.reverse_data == START_OF_HEADING)
			receive_start(usr_info->si_pid);
		else if (g_get.reverse_data == END_OF_TEXT)
			receive_check();
		else if (g_get.reverse_data == END_OF_TRANSMISSION)
			transmit_end(usr_info->si_pid);
		else
		{
			receive_character();
			if (g_get.reverse_data > 4 && g_get.buf_cnt == g_get.utf_byte)
				write(1, g_get.buf, g_get.utf_byte);
			if (g_get.reverse_data < 5 || g_get.buf_cnt == g_get.utf_byte)
				init_data(&g_get);
		}
	}
}
