/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choidongd <choidongd@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 15:07:01 by choidongd         #+#    #+#             */
/*   Updated: 2022/06/18 15:38:13 by choidongd        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "client.h"

int	main(int argc, char *argv[])
{
	char	*transmit_count;
	int		pid;

	if (argc != 3)
	{
		write(1, "You must 2 arguments [server PID] [message]\n", 44);
		return (0);
	}
	pid = ft_atoi(argv[1]);
	g_get.transmit_cnt = 0;
	signal(SIGUSR1, client_siguser);
	signal(SIGUSR2, client_siguser);
	transmit_contol((pid_t)pid, START_OF_HEADING);
	transmit_text((pid_t)pid, argv[2]);
	transmit_contol((pid_t)pid, END_OF_TEXT);
	transmit_count = ft_itoa(g_get.transmit_cnt);
	transmit_text((pid_t)pid, transmit_count);
	transmit_contol((pid_t)pid, END_OF_TRANSMISSION);
	free(transmit_count);
	system("leaks client");
	system("leaks server");
	return (0);
}
