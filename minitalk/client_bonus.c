/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 15:07:01 by choidongd         #+#    #+#             */
/*   Updated: 2022/06/21 15:43:19 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "client_bonus.h"

int	main(int argc, char *argv[])
{
	char	*transmit_count;
	int		pid;

	if (argc != 3)
	{
		write(1, "You must put 2 arguments [server PID] [message]\n", 48);
		return (0);
	}
	if (argv[2][0] == '\0')
	{
		write(1, "You must put no empty string\n", 29);
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
	return (0);
}
